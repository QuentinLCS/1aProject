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

    int jouer = 0, nbJoueur=1, ordrePassage[4];

    srand(time(NULL));
    
    while (nbJoueur) 
    {
        if (!jouer)
        {
            sauvegarder();
            nbJoueur = menu(&jouer);
        }
        else
        {
            while ( !victoire() && !quitter() )
            {
                gestionTours(&nbJoueur, ordrePassage);
            } 
        }
    }
    return 0;
}