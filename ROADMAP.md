# Feuille de route

État au 10 octobre 2026.

Ce dépôt est un fork d'OpenBoard-org/OpenBoard. Il propose la version
stable amont 1.7.7 avec deux ajouts : l'ouverture de la fenêtre principale
sur l'écran sous le curseur et l'outil de formes éditables de la PR amont
[#1541](https://github.com/OpenBoard-org/OpenBoard/pull/1541).

## Version proposée

La pré-release
[v1.7.7-shapes.2](https://github.com/obook/OpenBoard/releases/tag/v1.7.7-shapes.2)
est construite pour KDE neon, Ubuntu 24.04 et Windows. Elle garde le
format de document de la 1.7 : les documents ne sont pas convertis et
restent lisibles par la 1.7.7 officielle.

## Travail à faire

Essais de la pré-release `v1.7.7-shapes.2`. Seul le `.deb` KDE neon a été
lancé, le 10 octobre 2026 : formes, palette de style, duplication. Le
`.deb` Ubuntu 24.04 et le zip Windows n'ont été lancés par personne.

- [ ] lancer le build Windows pour la première fois : démarrage, tracé et
      modification de formes, textes en français, ouverture d'un document
      existant ;
- [ ] travailler avec le `.deb` KDE neon sur de vrais documents ;
- [ ] vérifier la modif écrans sur un poste à plusieurs écrans, sous X11
      et sous Wayland ;
- [ ] transmettre le `.deb` Ubuntu 24.04 au collègue, avec un message à
      jour : cette version ne convertit plus les documents ;
- [ ] ouvrir avec la 1.7.7 officielle un document contenant des formes,
      modifier la page, puis regarder si les formes ont survécu.

Retours à l'amont :

- [x] ouvrir la PR amont
      [#1545](https://github.com/OpenBoard-org/OpenBoard/pull/1545),
      demandée par l'auteur de la PR 1541 pour l'erreur de compilation
      Qt 6.4 qui vient de `dev` ;
- [x] rédiger et poster sur la PR 1541 le message qui regroupe les défauts
      restant à signaler, avec les liens vers les commits de `shapes-1.7` ;
- [ ] signaler sur la PR 1541 la forme dupliquée qui garde l'identifiant
      de l'original, avec le lien vers `53a8bdeb` ;
- [ ] vérifier sur la PR les deux autres défauts du 10 octobre (qmake,
      largeur de la palette de style), puis les signaler s'ils se
      confirment.

Rangement :

- [ ] retirer du fork les tags `v1.7.4-shapes.1`, `.2` et `.3`, qui n'ont
      plus de release ;
- [ ] supprimer l'ancien dossier `divers/OpenBoard` et relancer les
      sessions de travail depuis le nouvel emplacement du clone ;
- [ ] supprimer ou reconstruire le dossier `build/` du clone, dont les
      chemins compilés pointent vers l'ancien emplacement.

## Branches

| Branche | Base | Contenu | Format des documents | État |
|---|---|---|---|---|
| `master` | amont | miroir de l'amont, 1.7.7 | 4.8.0 | jamais modifiée |
| `projet` | `master` | documents du projet, dont ce fichier | 4.8.0 | branche par défaut du fork |
| `shapes-1.7` | `master` | modif écrans, formes reportées de la PR 1541, correctifs, traductions françaises, compilation Windows | 4.8.0 | pré-release `v1.7.7-shapes.2` |
| `feat-main-window-on-active-screen` | `dev` | modif écrans, PR amont [#1512](https://github.com/OpenBoard-org/OpenBoard/pull/1512) | 4.9.0 | en attente de revue amont |
| `fix-qt64-colorscheme` | `dev` | compilation avec Qt 6.4, PR amont [#1545](https://github.com/OpenBoard-org/OpenBoard/pull/1545) | 4.9.0 | en attente de revue amont |
| `test-shapes` | `dev` | PR 1541 telle quelle, avec la modif écrans et nos correctifs | 4.9.0 | sans binaire, sert à signaler les défauts à l'amont |

## Contraintes

Les formes ne s'affichent dans aucun OpenBoard officiel. La 1.7.7
officielle affiche le reste de la page et laisse les formes dans le
fichier tant que la page n'est pas réenregistrée.

Les builds basés sur `dev` enregistrent les documents au format 4.9.0,
celui de la future version 1.8, et mettent à niveau tout document qu'ils
ouvrent. Seule la 1.7.7 officielle sait reconvertir un tel document.
L'essai du 4 octobre 2026 sur des documents réels a rendu les textes, les
traits et les images. C'est pourquoi le projet ne publie plus de binaire
basé sur `dev`.

## Adaptations du report sur la 1.7

La PR 1541 est écrite pour `dev`. Son report sur la 1.7.7 a demandé :

- une palette de couleurs de taille fixe, la 1.7 n'ayant pas de palette
  configurable ;
- un aperçu de style sans quadrillage de fond ;
- le groupe de boutons de la barre d'outils repris de `dev` ;
- le signalement des clics de palette aligné sur celui de `dev`, sans
  quoi le sous-menu des formes se refermait ;
- une palette claire imposée à l'application, la 1.7 n'ayant de couleurs
  que pour un thème clair ;
- une palette de style posée contre la barre d'outils et non à cheval
  dessus, la barre de la 1.7 n'ayant pas de marge libre.

Ce report est à refaire quand la PR évolue. Il a été refait le 10 octobre
2026 jusqu'au commit `e1b5bbcb` de la PR, publié dans `v1.7.7-shapes.2`.
`test-shapes` est restée à `647a9dd3`, six commits plus tôt.

Un push sur `shapes-1.7` lance deux workflows : le build Windows et les
paquets `.deb` pour Ubuntu 24.04 et KDE neon. KDE neon se compile en
C++20, son poppler ne passant pas en C++17. Un tag `v*` relance les
paquets `.deb` avec le numéro de version du tag. Le zip Windows d'une
release vient de l'artefact du build de la branche, sur le même commit.

## Étapes

### Passer la pré-release en version normale

- l'utiliser en classe sous Linux ;
- lancer une première fois le build Windows, que personne n'a encore
  exécuté ;
- vérifier ce que deviennent les formes quand la 1.7.7 officielle
  réenregistre une page qui en contient.

### Retours à l'amont

Défauts signalés les 3 et 5 octobre 2026 à l'auteur de la PR 1541. Il les
a repris dans la PR entre le 6 et le 7 octobre. Reportés sur
`shapes-1.7`, ces correctifs compilent sous KDE neon, Ubuntu 24.04
(Qt 6.4, C++17) et Windows. Essais du 10 octobre sous KDE neon : pas de
plantage après un clic sans glisser, sélection et style des lignes
corrects.

- quatre erreurs de compilation avec Qt 6.4 (Ubuntu 24.04) : trois sont
  corrigées dans `466b5ebb`, celle qui vient de `dev` est dans la PR
  [#1545](https://github.com/OpenBoard-org/OpenBoard/pull/1545), sans
  revue à ce jour ;
- palette de style mal placée quand la barre d'outils est en bas :
  corrigée dans `466b5ebb` ;
- plantage à la fermeture après un clic sans glisser avec un outil de
  forme : `466b5ebb` corrige une double destruction des formes créées
  partiellement ;
- interfaces d'extension SVG sans destructeur virtuel : corrigé dans
  `466b5ebb` ;
- fichiers de la PR absents du projet qmake : ajoutés dans `d6cc74fc` ;
- un `!=` sur `UBItemStyle` qui ne compile qu'en C++20 : opérateur ajouté
  dans `466b5ebb` ;
- chaînes anglaises à corriger avant traduction : "octogon" a disparu
  avec `4d129d51`, la casse des autres chaînes n'est pas vérifiée.

Défaut signalé le 9 octobre 2026 par un autre testeur, sans réponse : sur
une ligne brisée tracée avec l'outil polygone, les cercles des points de
départ et d'arrivée peuvent rester affichés après l'édition.

Défauts trouvés le 10 octobre 2026, à signaler sur la PR 1541 :

- une forme dupliquée garde l'identifiant de l'original, corrigé dans
  `shapes-1.7` (`53a8bdeb`) ;
- `src/domain/domain.pri` : `HEADERS +=` et `SOURCES +=` sans barre de
  continuation, à confirmer par un qmake sur la PR ;
- palette de style plus large que le bloc des couleurs quand la palette
  n'a que 5 couleurs, hypothèse non vérifiée sur `dev`.

La question du redimensionnement des formes (poignées visibles seulement
après un second clic) est mise de côté.

### À la sortie de la 1.8 amont

Réévaluer le fork. Si les PR 1541 et 1512 y sont fusionnées, il n'a plus
rien à ajouter.
