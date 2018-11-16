#include <stdio.h>
#include "../Header/jeu.h"

// void menu()
void menu()
{
    int gameMode;

    printf("\n[Projet 1A] PETITS CHEVAUX \nPar : CHAVAS Nathan & LECHASLES Quentin\n\nChoisissez votre mode de jeu :\n  [1] Nouvelle partie\n  [2] Continuer\n  [3] Options\n  [4] Quitter \n\nMode [entrez une valeur]: ");
    scanf("%d", &gameMode);

    
    switch (gameMode) {
        case 1 :
            printf("\n\n[v] NOUVELLE PARTIE : SELECTIONNE !\n\n");
            init();
            break;
        case 2 :
            printf("\n\n[v] CONTINUER : SELECTIONNE !\n\n");
            Continue();
            break;
        case 3 :
            printf("\n\n[v] OPTION : SELECTIONNE !\n\n");
            Option();
            break;
        case 4 :
            printf("\n\n[v] QUITTER : SELECTIONNE !\n\n");
            break;
    }
}

int NvPartie (){
    int nbJoueur, d;
    do{
        printf ("À combien de joueur voulez-vous jouer ? \n --> 1 JOUEUR\n\n --> 2 JOUEURS\n\n --> 3 JOUEURS\n\n --> 4 JOUEURS\n\n");
        d=scanf ("%d",&nbJoueur);
    } while (nbJoueur <1 || nbJoueur>4 || d=0);
    printf ("\n\n[Nombre %d Joueur(s) séléctionné]\n\n",nbJoueur);
    Jeu();
    return nbJoueur;
}

int Continue (){
    Jeu();
    return 0;
}

int Option (){

    return 0;
}

