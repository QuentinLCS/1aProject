#include <stdio.h>
#include <stdlib.h>
#include "../Header/init.h"
#include "../Header/menu.h"

int menu()
{
    int gameMode = 0, valide = 0, stop = 0;

    do {
        printf("\n[Projet 1A] PETITS CHEVAUX \nPar : CHAVAS Nathan & LECHASLES Quentin\n\nChoisissez votre mode de jeu :\n  [1] Nouvelle partie\n  [2] Continuer\n  [3] Options\n  [4] Quitter \n\nMode [entrez une valeur]: ");
        valide = scanf("%d", &gameMode);
        viderBuffer();
    } while ( gameMode < 1 || gameMode > 4 || valide == 0 );
    
    switch (gameMode) {
        case 1 :
            init();
            break;
        case 2 :
            continuer();
            break;
        case 3 :
            option();
            break;
        case 4 :
            stop = 1;
            break;
    }
    return stop;
}

void nouvellePartie ()
{
    int valide = 0;
    //Jeu();
}

void continuer ()
{
    //Jeu();
}

void option ()
{

    int optionNb = 0, valide = 0;
    system("clear");
    do {
        printf("\n[OPTIONS] A quelle option souhaitez-vous accéder ?\n  [1] Scénarios\n  [2] xxx\n  [3] RETOUR\n\nOption [entrez une valeur]: ");
        valide == scanf("%d", &optionNb);
        getchar();
    } while ( optionNb < 1 || optionNb > 3 || valide == 0 );
    switch (optionNb) {
        case 1 :
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n[v] SCENARIOS : SELECTIONNE !\n\n");
            break;
        case 2 :
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n[v] xxx : SELECTIONNE !\n\n");
            break;
        case 3 :
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n[v] RETOUR : SELECTIONNE !\n\n");
            nouvellePartie(); //menu();
            break;
    }
}