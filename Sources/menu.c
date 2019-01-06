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
            nbJoueur = init();
            *jouer = 1;
            break;
        case 2 :
            continuerPartie();
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
    //charger(0, nbJoueur);
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
            charger(1, 4);
            break;
        case 2 :
            charger(2, 4);
            break;
        case 3 :
            charger(3, 4);
            break;
        case 4 :
            charger(4, 4);
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




void charger(int numFichier, int nbJoueur) // Charge les données d'un fichier pré-créé (non fonctionnel pour le moment)
{
    char listeFichiers[5][25] = {"\"../Saves/last-game.txt\"", "\"../Saves/scenario1.txt\"", "\"../Saves/scenario2.txt\"", "\"../Saves/scenario3.txt\"", "\"../Saves/scenario4.txt\""};

    FILE* fichier = NULL;
    printf("%s", listeFichiers[numFichier]);
    fichier = fopen( listeFichiers[numFichier], "r+" );
    fichier = fopen( "../Saves/scenario1.txt", "r+" );

    if (fichier != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i) fseek(fichier, 1, SEEK_END);

            fscanf(fichier, "%d %d %d %s %s ", &nbJoueur, &ordrePassage[i], &players[i].numJoueur, players[i].nomJoueur, players[i].couleur);
            printf("%d %d %d %s %s ", nbJoueur, ordrePassage[i], players[i].numJoueur, players[i].nomJoueur, players[i].couleur);

            for (int j = 0; j < 4; j++) 
            {
                fscanf(fichier, "%d %d %d %d ",&players[i].cheval[j].numCheval, &players[i].cheval[j].position[0], &players[i].cheval[j].position[1], &players[i].cheval[j].numCase);
                printf("%d %d %d %d ",players[i].cheval[j].numCheval, players[i].cheval[j].position[0], players[i].cheval[j].position[1], players[i].cheval[j].numCase);
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
    FILE* fichier = NULL;

    fichier = fopen( "../Saves/last-game.txt", "r+" );

    system(">../Saves/last-game.txt");

    if (fichier != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            fseek(fichier, 0, SEEK_END);
            
            fprintf(fichier, "%d %d %d %s %s ", nbJoueur, ordrePassage[i], players[i].numJoueur, players[i].nomJoueur, players[i].couleur);

            for (int j = 0; j < 4; j++) 
            {
                fprintf(fichier, "%d %d %d %d ",players[i].cheval[j].numCheval, players[i].cheval[j].position[0], players[i].cheval[j].position[1], players[i].cheval[j].numCase);
            }
        } 
        fclose(fichier);
        system("sleep 5");
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
