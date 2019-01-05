#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/menu.h"
#include "../Header/plateau.h"
#include "../Header/deplacement.h"
#include "../Header/init.h"

void main()
{

    int jouer = 0, nbJoueur, i, *ordrePassageP = ordrePassage;

    srand(time(NULL));

    while (nbJoueur) 
    {
        if (!jouer)
        {
            nbJoueur = menu(&jouer);
        }
        else
        {
            for (i = 0; i < nbJoueur; i++)
            {
                
                printf("Joueur num %d :  (%s)\n",i+1, players[ordrePassage[i]].nom, players[ordrePassage[i]].couleur);
                /*do
                {
                    // En cours de réflexion...
                } while (0);*/
            }
        }
    }
}