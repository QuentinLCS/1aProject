#include <stdio.h>
#include <stdlib.h>
#include "../Header/init.h"
#include "../Header/menu.h"



int menu(int *jouer)
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





void scenarios()
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





void afficherErreur(int erreurType) 
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



/*
void charger(char *nomFichier[15], int nbJoueur, int *ordrePassage[])
{
    FILE* fichier = NULL;

    fichier = fopen( *nomFichier, "r+" );

    if (fichier != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i) fseek(fichier, 1, SEEK_END);
            
            fscanf(fichier, "%d %d %d %s %s ", &nbJoueur, ordrePassage[i], &players[i].numJoueur, players[i].nomJoueur, players[i].couleur);

            for (int j = 0; j < 4; j++) 
            {
                fscanf(fichier, "%d %d %d %d ",&players[i].cheval[j].numCheval, &players[i].cheval[j].position[0], &players[i].cheval[j].position[1], &players[i].cheval[j].numCase);
            }
        } 
        fclose(fichier);
    }
    else
    {
        afficherErreur(2);
    }
}
*/

void sauvegarder(int nbJoueur, int ordrePassage[4])
{
    FILE* fichier = NULL;

    fichier = fopen( "../Saves/last-game.txt", "r+" );

    if (fichier != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i) fseek(fichier, 1, SEEK_END);
            
            fprintf(fichier, "%d %d %d %s %s ", nbJoueur, ordrePassage[i], players[i].numJoueur, players[i].nomJoueur, players[i].couleur);

            for (int j = 0; j < 4; j++) 
            {
                fprintf(fichier, "%d %d %d %d ",players[i].cheval[j].numCheval, players[i].cheval[j].position[0], players[i].cheval[j].position[1], players[i].cheval[j].numCase);
            }
        } 
        fclose(fichier);
    }
    else
    {
        afficherErreur(2);
    }
}

void afficheVainqueur()
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