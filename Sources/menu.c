#include <stdio.h>
#include <stdlib.h>
#include "../Header/init.h"
#include "../Header/menu.h"

int menu()
{
    int gameMode = 0, valide = 0, continuer = 1;

    do {
        system("clear");
        printf("\n[Projet 1A] PETITS CHEVAUX \nPar : CHAVAS Nathan & LECHASLES Quentin\n\nChoisissez votre mode de jeu :\n  [1] Nouvelle partie\n  [2] Continuer\n  [3] Options\n  [4] Quitter \n\nMode [entrez une valeur]: ");
        valide = scanf("%d", &gameMode);
        viderBuffer();
        if (gameMode < 1 || gameMode > 4 || !valide ) afficherErreur(1);
    } while ( gameMode < 1 || gameMode > 4 || valide == 0 );
    
    switch (gameMode) 
    {
        case 1 :
            init();
            break;
        case 2 :
            continuerPartie();
            break;
        case 3 :
            option();
            break;
        case 4 :
            continuer = 0;
            break;
    }
    return continuer;
}

void nouvellePartie ()
{
    int valide = 0;
    //Jeu();
}

void continuerPartie ()
{
    //Jeu();
}

void option ()
{

    int optionNb = 0, valide = 0;

    do {
        system("clear");
        printf("\n[OPTIONS] A quelle option souhaitez-vous accéder ?\n  [1] Scénarios\n  [2] Plus d'infos\n  [3] RETOUR\n\nOption [entrez une valeur]: ");
        valide = scanf("%d", &optionNb);
        printf("\n\n%d - %d\n\n", valide, optionNb);
        viderBuffer();
        if (optionNb < 1 || optionNb > 3 || !valide ) afficherErreur(1);
    } while ( optionNb < 1 || optionNb > 3 || valide == 0 );

    switch (optionNb) 
    {
        case 1 :
            scenarios();
            break;
        case 2 :
            plusInfos();
            break;
    }
}

void scenarios()
{

    int scenarioNb = 0, valide = 0;

    do {
        system("clear");
        printf("\n[CENARIOS] Voici la liste des scénarios :\n  [1] ...\n  [2] ...\n  [3] ...\n  [4] ...\n  [5] RETOUR\n\nChoix du scénario [entrez une valeur]: ");
        valide = scanf("%d", &scenarioNb);
        printf("\n\n%d - %d\n\n", valide, scenarioNb);
        viderBuffer();
        if (scenarioNb < 1 || scenarioNb > 5 || !valide ) afficherErreur(1);
    } while ( scenarioNb < 1 || scenarioNb > 5 || valide == 0 );

    switch (scenarioNb) 
    {
        case 1 :
            // Charger scénario 1
            break;
        case 2 :
            // Charger scénario 2
            break;
        case 3 :
            // Charger scénario 3
            break;
        case 4 :
            // Charger scénario 4
            break;
    }
}

void plusInfos()
{
    printf("PLUS DINFOS ICI\n");
}