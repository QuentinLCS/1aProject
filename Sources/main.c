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

    int jouer = 0, nbJoueur;

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
            // Fonction pour recharger la partie (continuer partie) car la première entrée dans gestionTours() est dans init.c -> ordreJeu
        }
    }
    return 0;
}