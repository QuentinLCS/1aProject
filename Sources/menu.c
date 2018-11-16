#include <stdio.h>
#include "../Header/jeu.h"

// void menu()
void main()
{
    int gameMode, valide = 0;

    do {
        printf("\n[Projet 1A] PETITS CHEVAUX \nPar : CHAVAS Nathan & LECHASLES Quentin\n\nChoisissez votre mode de jeu :\n  [1] Nouvelle partie\n  [2] Continuer\n  [3] Options\n  [4] Quitter \n\nMode [entrez une valeur]: ");
        valide = scanf("%d", &gameMode);
    } while ( (gameMode < 1 || gameMode > 4) && valide == 0 );
    
    switch (gameMode) {
        case 1 :
            printf("\n\n[v] NOUVELLE PARTIE : SELECTIONNE !\n\n");
            //init();
            break;
        case 2 :
            printf("\n\n[v] CONTINUER : SELECTIONNE !\n\n");
            //Continue();
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

    int nbJoueur, valide = 0;

    do {
        printf ("À combien de joueur voulez-vous jouer ? \n --> 1 JOUEUR\n\n --> 2 JOUEURS\n\n --> 3 JOUEURS\n\n --> 4 JOUEURS\n\n");
        valide = scanf ("%d",&nbJoueur);
    } while ( (nbJoueur < 1 || nbJoueur > 4) && valide == 0 );
    printf ("\n\n[Nombre %d Joueur(s) séléctionné]\n\n", nbJoueur);
    //Jeu();
    return nbJoueur;
}

int Continue (){
    //Jeu();
    return 0;
}

int Option (){

    int optionNb, valide = 0;

    printf("\n[OPTIONS] A quelle option souhaitez-vous accéder ?\n  [1] Scénarios\n  [2] xxx\n  [3] xxx\n\nOption [entrez une valeur]: ");
    scanf("%d", &optionNb);

    switch (optionNb) {
        case 1 :
            printf("\n\n[v] NOUVELLE PARTIE : SELECTIONNE !\n\n");
            break;
        case 2 :
            printf("\n\n[v] CONTINUER : SELECTIONNE !\n\n");
            break;
        case 3 :
            printf("\n\n[v] OPTION : SELECTIONNE !\n\n");
            break;
        case 4 :
            printf("\n\n[v] QUITTER : SELECTIONNE !\n\n");
            break;
    }
}

