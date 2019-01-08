#include <stdio.h>
#include <stdlib.h>
#include "../Header/init.h"
#include "../Header/menu.h"
#include "../Header/plateau.h"



int menu(int *jouer) // Affiche le menu et interpète où veut aller le joueur
{
    int gameMode = 0, valide = 0, nbJoueur;

    do {
        system("clear");
        printf("\n[Projet 1A] PETITS CHEVAUX \nPar : CHAVAS Nathan & LECHASLES Quentin\n\nChoisissez votre mode de jeu :\n  [1] Nouvelle partie\n  [2] Continuer\n  [3] Options\n  [4] Quitter \n\nMode [entrez une valeur]: ");
        valide = scanf("%d", &gameMode);
        viderBuffer();
        if (gameMode < 1 || gameMode > 4 || !valide ) afficherErreur(1);
    } while ( gameMode < 1 || gameMode > 4 || !valide );

    switch (gameMode)
    {
        case 1 :
            creationPlateau();
            nbJoueur = init(1);
            *jouer = 1;
            break;
        case 2 :
            continuerPartie();
            *jouer = 1;
            break;
        case 3 :
            option();
            break;
        case 4 :
            nbJoueur = 0;
            break;
    }
    return nbJoueur;
}






void continuerPartie () // pas terminé pour la rente du projet mais presque fonctionnel, est censé charger les données renseignées par charger();
{
    charger(0);
}





void option () // Menu option
{

    int optionNb = 0, valide = 0;

    do {
        system("clear");
        printf("\n[OPTIONS] A quelle option souhaitez-vous accéder ?\n  [1] Scénarios\n  [2] Plus d'infos\n  [3] RETOUR\n\nOption [entrez une valeur]: ");
        valide = scanf("%d", &optionNb);
        printf("\n\n%d - %d\n\n", valide, optionNb);
        viderBuffer();
        if (optionNb < 1 || optionNb > 3 || !valide ) afficherErreur(1);
    } while ( optionNb < 1 || optionNb > 3 || !valide );

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





void scenarios() // Menu des scénarios
{

    int scenarioNb = 0, valide = 0;

    do {
        system("clear");
        printf("\n[SCENARIOS] Voici la liste des scénarios :\n  [1] ...\n  [2] ...\n  [3] ...\n  [4] ...\n  [5] RETOUR\n\nChoix du scénario [entrez une valeur]: ");
        valide = scanf("%d", &scenarioNb);
        printf("\n\n%d - %d\n\n", valide, scenarioNb);
        viderBuffer();
        if (scenarioNb < 1 || scenarioNb > 5 || !valide ) afficherErreur(1);
    } while ( scenarioNb < 1 || scenarioNb > 5 || !valide );

    switch (scenarioNb)
    {
        case 1 :
            charger(1);
            break;
        case 2 :
            charger(2);
            break;
        case 3 :
            charger(3);
            break;
        case 4 :
            charger(4);
            break;
    }
}




void plusInfos() // Fonction non terminée, est censée renseigner davantage sur les conditions de réalisation de ce projet
{
    printf("PLUS DINFOS ICI\n");
}





void afficherErreur(int erreurType) // Affiche à l'utilisateur l'erreur en fonction du type entré
{
    system("clear");
    switch (erreurType)
    {
        case 1 :
            printf("\033[31mERREUR : entrée non conforme à la demande.\033[0m\n");
            break;

        case 2 :
            printf("\033[31mERREUR : lecture du fichier impossible.\033[0m\n");
            break;
    }
    system("sleep 2");
}




void charger(int numFichier) // Charge les données d'un fichier pré-créé (non fonctionnel pour le moment)
{
    int curseur = 0, nbJoueur, i, j;

    init(0);

    FILE* fichier = NULL;
    switch (numFichier)
    {
      case 0:
          fichier = fopen( "../Saves/last-game.txt", "r+" );
          break;
      case 1:
          fichier = fopen( "../Saves/scenario1.txt", "r+" );
          break;
      case 2:
          fichier = fopen( "../Saves/scenario2.txt", "r+" );
          break;
      case 3:
          fichier = fopen( "../Saves/scenario3.txt", "r+" );
          break;
      case 4:
          fichier = fopen( "../Saves/scenario4.txt", "r+" );
          break;
    }

    if (fichier != NULL)
    {
        for (i = 0; i < 4; i++)
        {
            fseek(fichier, curseur, SEEK_SET);
            fscanf(fichier, "%d %d %d %s %s", &nbJoueur, &ordrePassage[i], &players[i].numJoueur, players[i].nomJoueur, players[i].couleur);

            for (j = 0; j < 4; j++)
            {
                fscanf(fichier, "%d %d %d %d",&players[i].cheval[j].numCheval, &players[i].cheval[j].position[0], &players[i].cheval[j].position[1], &players[i].cheval[j].numCase);
            }
            curseur -= 3;
        }

        for (i = 0; i < 15; i++)
        {
            //curseur += 1;
            for (j = 0; j < 15; j++)
            {
                fseek(fichier, curseur, SEEK_SET);
                fscanf(fichier, "%d %s %d %d", &plateau[i][j].nbChevaux, plateau[i][j].couleur, &plateau[i][j].ecurie, &plateau[i][j].echelle);
            }
        }
        
        fclose(fichier);
    }
    else
    {
        afficherErreur(2);
    }
}


void sauvegarder(int nbJoueur) // Sauvegarde les données à la fin de chaque tour dans "last-game.txt" pour continuer la partie à terme
{
    int i, j;

    FILE* fichier = NULL;

    fichier = fopen( "../Saves/last-game.txt", "r+" );

    system(">../Saves/last-game.txt");

    if (fichier != NULL)
    {
        for (i = 0; i < 4; i++)
        {
            fseek(fichier, 0, SEEK_END);

            fprintf(fichier, " %d %d %d %s %s ", nbJoueur, ordrePassage[i], players[i].numJoueur, players[i].nomJoueur, players[i].couleur);

            for (j = 0; j < 4; j++)
            {
                fprintf(fichier, " %d %d %d %d ",players[i].cheval[j].numCheval, players[i].cheval[j].position[0], players[i].cheval[j].position[1], players[i].cheval[j].numCase);
            }
        }

        for (i = 0; i < 15; i++)
        {
          for (j = 0; j < 15; j++)
          {
              fprintf(fichier, " %d %s %d %d ",plateau[i][j].nbChevaux, plateau[i][j].couleur, plateau[i][j].ecurie, plateau[i][j].echelle);
          }
        }
        fclose(fichier);
    }
    else
    {
        afficherErreur(2);
    }
}

void afficheVainqueur() // Affiche le vainqueur de la partie
{
    int somme;
    for (int i=0; i<4; i++)
    {
        somme=0;
        for (int j=0; j<4; j++)
        {
            somme+=players[i].cheval[j].numCase;
        }
        if (somme==408)
        {
            printf ("Bravo au joueur n°%d, %s qui a remporté la partie !",i+1, players[i+1].nomJoueur);
        }
    }
}
