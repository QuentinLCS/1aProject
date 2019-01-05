#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/menu.h"
#include "../Header/plateau.h"
#include "../Header/deplacement.h"
#include "../Header/init.h"
#include "../Header/tours.h"

void main()
{

    int jouer = 0, nbJoueur, i;

    srand(time(NULL));

    while (nbJoueur) 
    {
        if (!jouer)
        {
            nbJoueur = menu(&jouer);
        }
        else
        {
            
        }
    }
}