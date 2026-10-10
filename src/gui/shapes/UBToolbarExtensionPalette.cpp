/*
 * Copyright (C) 2015-2026 Département de l'Instruction Publique (DIP-SEM)
 * and contributors.
 *
 * This file is part of OpenBoard.
 *
 * OpenBoard is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License,
 * with a specific linking exception for the OpenSSL project's
 * "OpenSSL" library (or with modified versions of it that use the
 * same license as the "OpenSSL" library).
 *
 * OpenBoard is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenBoard. If not, see <http://www.gnu.org/licenses/>.
 */


#include "UBToolbarExtensionPalette.h"

#include "core/UBSettings.h"

#include <QPainter>
#include <QStyleOption>

// no overlap on 1.7: the toolbar has no free margin, the palette would cover its labels and buttons
constexpr int topOverlap = 0;
constexpr int bottomOverlap = 0;

UBToolbarExtensionPalette::UBToolbarExtensionPalette(QToolBar* toolBar, QWidget* parent)
    : QWidget{parent, Qt::WindowStaysOnTopHint}
    , mToolBar{toolBar}
{
    connect(UBSettings::settings()->appToolBarPositionedAtTop, &UBSetting::changed, this,
            &UBToolbarExtensionPalette::updatePosition);
}

void UBToolbarExtensionPalette::setSpan(QWidget* from, QWidget* to)
{
    mFromWidget = from;

    if (from->parentWidget() != mToolBar || to->parentWidget() != mToolBar)
    {
        qDebug() << "UBToolbarExtensionPalette::setSpan: widgets must be children of toolbar";
        return;
    }

    const auto fromPos = from->pos();
    const auto toPos = to->pos();

    if (fromPos.x() > toPos.x())
    {
        qDebug() << "UBToolbarExtensionPalette::setSpan: from widget must not be right of to widget";
        return;
    }

    const int width{toPos.x() + to->width() - fromPos.x()};

    resize(width, size().height());
    updatePosition(UBSettings::settings()->appToolBarPositionedAtTop->get());
}

void UBToolbarExtensionPalette::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 1.7 has no application palette: take the background from the style sheet like
    // the toolbar does, because the system palette may belong to a dark desktop theme
    QStyleOption option;
    option.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);

    QPen pen{QColor{0x88, 0x88, 0x88}, 3};
    painter.setPen(pen);

    if (mToolbarAtTop)
    {
        painter.drawLine(0, topOverlap, 0, height());
        painter.drawLine(0, height(), width(), height());
        painter.drawLine(width(), topOverlap, width(), height());
    }
    else
    {
        painter.drawLine(0, 0, 0, height() - bottomOverlap);
        painter.drawLine(0, 0, width(), 0);
        painter.drawLine(width(), 0, width(), height() - bottomOverlap);
    }
}

void UBToolbarExtensionPalette::showEvent(QShowEvent* event)
{
    // toolbar and main window may not have had their final geometry when the span was set
    updatePosition(UBSettings::settings()->appToolBarPositionedAtTop->get());
    QWidget::showEvent(event);
}

void UBToolbarExtensionPalette::resizeEvent(QResizeEvent* event)
{
    // with the toolbar at the bottom, the position depends on the height of the palette
    updatePosition(UBSettings::settings()->appToolBarPositionedAtTop->get());
    QWidget::resizeEvent(event);
}

void UBToolbarExtensionPalette::updatePosition(QVariant atTop)
{
    mToolbarAtTop = atTop.toBool();

    if (!mFromWidget)
    {
        return;
    }

    QPoint pos{mFromWidget->pos().x(), mToolBar->height() - topOverlap};

    if (!mToolbarAtTop)
    {
        // move to bottom
        pos.setY(parentWidget()->height() - mToolBar->height() - height() + bottomOverlap);
    }

    move(pos);
}
