#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/menu.h"
#include "../Header/plateau.h"
#include "../Header/deplacement.h"
#include "../Header/init.h"

void main()
{

    srand(time(NULL));

    int jouer = 0, nbJoueur, i;
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
                system("sleep 5");
                printf("%d\n",i+1);
                do
                {
                    // En cours de réflexion...
                } while (0);
            }
        }
    }
}