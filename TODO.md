# LISTE DES CHOSES RESTANTES A FAIRE

    Pour les problèmes de tableaux et variables nécessaires d'un .c à un autre faut utiliser les pointeurs.
    Du coup dès qu'on pourra on se plongera dedans.

    On va commencer à arriver à un stade où on ne vas plus pouvoir tester en compilant nos .c séparéments 
    vu qu'on va devoir utiliser des ressources venant des autres fichiers.

-------------------------------------------------------------------------------

## Il reste à faire :

* Toute l'initialisation du début :
    - [X] Demander le nombre de joueurs.
    - [X] Demander le nom et la couleur de chaque joueur.
    - [x] Demander s'il veulent tirer au sort l'ordre de jeu ou choisir.
    - [x] Trier l'ordre de passage en fonction du dé tiré.
* Le coeur du jeu :
    - [X] Création de la boucle principale responsable de la gestion des tours (For dans un While).
    - [X] Gestion de victoire.
    - [X] Sauvegarde des informations de la partie pour pouvoir "Continuer la partie".
    - [X] Permettre de quitter en pleine partie. (sauvegarde à ce moment là)
* L'Affichage :
    - [x] Designer le menu pour le rendre plus attirant malgré le SHELL.
    - [x] Essayer de faire afficher des chevaux dans le SHELL (plateau.c).
    - [X] Afficher qui doit jouer ?
    - [ ] Gestion du podium ? ( 1er , 2e, ... )
    - [x] Penser à l'utilisation des commandes SHELL (clear, ...)
* Deplacement :
    - [X] Finir les vérifications de déplacement. [en cours]
    - [X] Gérer le renvoie à l'écurie.
    - [X] Gérer la relance du dé si un 6 est effectué.
    - [X] Gérer le point d'apparition.
    - [X] Gérer l'arrivée devant les échelles.
    - [X] Gérer le comportement dans les échelles en fonction des règles imposées par M. Loudni.
* La fin du jeu :
    - [X] Afficher le résultat.
    - [X] Rediriger sur le menu.
    - [X] Supprimer les informations sauvegardées pour continuer la partie.
* Autre : 
    - [ ] Sauvegarder les temps de victoire pour afficher un classement ?
