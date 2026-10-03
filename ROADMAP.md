# Feuille de route

État au 4 octobre 2026.

Ce dépôt est un fork d'OpenBoard-org/OpenBoard. Il ajoute à l'amont
l'ouverture de la fenêtre principale sur l'écran sous le curseur et teste
l'outil de formes éditables de la PR amont
[#1541](https://github.com/OpenBoard-org/OpenBoard/pull/1541).

## Branches

| Branche | Base | Contenu | Format des documents | État |
|---|---|---|---|---|
| `master` | amont | miroir de l'amont, 1.7.7 | 4.8.0 | jamais modifiée |
| `projet` | `master` | documents du projet, dont ce fichier | 4.8.0 | branche par défaut du fork |
| `feat-main-window-on-active-screen` | `dev` | modif écrans, PR amont [#1512](https://github.com/OpenBoard-org/OpenBoard/pull/1512) | 4.9.0 | en attente de revue amont |
| `feat-main-window-on-active-screen-1.7` | `master` | la même modif, portée sur la 1.7.7 | 4.8.0 | compile, à tester sur un multi-écran, pas encore poussée |
| `test-shapes` | `dev` | formes de la PR 1541, modif écrans, correctifs, traductions françaises | 4.9.0 | pré-release `v1.7.4-shapes.3` (Ubuntu 24.04) |
| `win-build` | `test-shapes` | branchement qmake et workflow de compilation Windows | 4.9.0 | compile sous Windows, jamais lancé |

## Contraintes

Les builds basés sur `dev` enregistrent les documents au format 4.9.0,
celui de la future version 1.8. Ils mettent à niveau tout document qu'ils
ouvrent. Seule la version officielle 1.7.7 sait reconvertir un tel
document. L'essai du 4 octobre 2026 sur trois documents réels a rendu les
textes, les traits et les images.

Les formes ne s'affichent dans aucun OpenBoard officiel, quelle que soit
la base du build. Elles restent dans le fichier tant que la page n'est pas
réenregistrée.

Un dossier de documents synchronisé entre plusieurs postes propage la
mise à niveau à tous les postes.

## Étapes

### 1.7 avec la modif écrans

Version stable du projet : les documents restent au format 1.7.

- tester le portage sur un multi-écran, sous X11 et sous Wayland ;
- construire le `.deb` pour Ubuntu 24.04 et le build Windows ;
- publier.

### 1.7 avec la modif écrans et les formes

En attente : savoir si le besoin existe. Un essai à blanc du report de la
PR 1541 sur la 1.7.7 donne 19 blocs en conflit dans 14 fichiers. La PR ne
dépend ni du thème sombre ni du nouveau format de document. Le code
d'enregistrement des documents est touché, donc cette étape demande des
essais d'enregistrement et de relecture avant toute diffusion.

### Retours à l'amont

Défauts relevés dans la PR 1541, à signaler à son auteur :

- quatre erreurs de compilation avec Qt 6.4 (Ubuntu 24.04), dont une
  vient de `dev` ;
- palette de style mal placée quand la barre d'outils est en bas ;
- fichiers de la PR absents du projet qmake, donc pas de compilation
  possible pour Windows ni macOS ;
- un `!=` sur `UBItemStyle` qui ne compile qu'en C++20 ;
- chaînes anglaises à corriger avant traduction ("octogon", casse).

La question du redimensionnement des formes (poignées visibles seulement
après un second clic) est mise de côté.

## Décisions en attente

- le besoin d'une 1.7 avec formes ;
- le sort de la branche `win-build`.
