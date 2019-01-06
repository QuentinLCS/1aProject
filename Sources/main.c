#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/menu.h"
#include "../Header/plateau.h"
#include "../Header/deplacement.h"
#include "../Header/init.h"
#include "../Header/tours.h"

int main()
{

    int jouer = 0, nbJoueur=1;

    srand(time(NULL));
    
    while (nbJoueur) 
    {
        if (!jouer)
        {
            nbJoueur = menu(&jouer);
        }
        else
        {
            do
            {
                printf("do while main\n");
                gestionTours(&nbJoueur);
            } while ( !victoire() && !quitter(&jouer) );
            if (victoire())
            {
                afficheVainqueur();
            }  
        }
    }
    return 0;
}