#include <stdio.h>
#include "../Header/init.h"
#include "../Header/deplacement.h"
#include "../Header/menu.h"


void gestionTours(int nbJoueur, int *ordrePassage[], joueur players[])
{
    int i;

    for (i = 0; i < nbJoueur; i++)
    {
                
        printf("Joueur num %d : %s (%s)\n",i+1, players[ordrePassage[i]].nomJoueur, players[ordrePassage[i]].couleur);
        /*do
        {
            // En cours de réflexion...
        } while (0);*/
    }
}