#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Header/init.h"
#include "../Header/deplacement.h"
#include "../Header/plateau.h"
#include "../Header/menu.h"
#include "../Header/tours.h"

    joueur players[4]; int ordrePassage[4];
    
int init() 
{
    
    int nbJoueur;

    char listeCouleurs[4][6] = {"bleu", "rouge", "vert", "jaune"};

    for (int i = 0; i < 4; i++)
    {
        players[i].numJoueur = i;
        strcpy(players[i].couleur, listeCouleurs[i]);
        for (int j = 0; j < 4; j++)
        {
            players[i].cheval[j].numCheval = j;
        }
    }

    nbJoueur = nbJoueurs();
    nomJoueurs(nbJoueur);
    ordreJeu(nbJoueur);

    return nbJoueur;
}




int nbJoueurs()
{
    int nbJoueur = 0, valide = 0; 

    do  {
        system("clear");
        printf ("Combien de Joueurs souhaitez-vous ? \n   --> 1 JOUEUR\n   --> 2 JOUEURS\n   --> 3 JOUEURS\n   --> 4 JOUEURS\n\nReponse [entrez une valeur]: ");
        valide = scanf ("%d",&nbJoueur);
        viderBuffer();
        if (nbJoueur < 1 || nbJoueur > 4 || !valide ) afficherErreur(1);
    } while ( nbJoueur < 1 || nbJoueur > 4 || !valide);
    return nbJoueur;
}





void nomJoueurs( int nbJoueur) {
    int valide = 0, i, continuer = 0; 

    for (i = 0 ; i < nbJoueur; i++) {
        valide = 0;
        do  {
            system("clear");
            printf ("\n\nEntrez le nom du joueur %s : ", players[i].couleur);
            scanf("%s", players[i].nomJoueur);
            viderBuffer(); 
            do {
                system("clear");
                printf("\n\nC'est %s, c'est bien ca ?\n[1] Oui !\n[2] Non, recommencer.\n\nReponse [entrez une valeur]: ", players[i].nomJoueur);
                valide = scanf("%d", &continuer);
                viderBuffer();
                if ((continuer < 1 || continuer > 2) || !valide ) afficherErreur(1);
            } while ( (continuer < 1 || continuer > 2) || !valide );
        } while ( continuer == 2 );
    }
}




void ordreJeu( int nbJoueur ) {
    int tirage[4], i, j, tempI = 0; 
    
    system("clear");

    printf("\n\nPour tirer l'ordre de jeu, jetez votre de !\n");
    for (i = 0; i < 4; i++) 
    {
        if (i < nbJoueur) 
        {
            printf("\n    %s, lance ton de ! [appuyez sur entrer] ", players[i].nomJoueur);
            getchar();
        }
        tirage[i] = de();
        printf("\n   \u2192 Resultat (%s) : %d !\n", players[i].couleur, tirage[i]);
    } 
        
        // TRI DU NOMBRE DE JOUEURS (ordrePassage[]) EN FONCTION DU TIRAGE (tirage[])

    for (i = 0; i < nbJoueur; i++) {
        for (j = 0; j < nbJoueur; j++) {
            if (tirage[j]) {
                if (tirage[tempI] < tirage[j]) {
                    tempI = j;
                } 
            }
        } ordrePassage[i] = tempI;
        tirage[tempI] = 0;
        printf("\n%de : %s (%s)\n", i+1, players[ordrePassage[i]].nomJoueur, players[ordrePassage[i]].couleur);
    }
    system("sleep 7");
}




void viderBuffer() 
{
    char c;
    while ( (c=getchar()) != EOF && c != '\n');
}