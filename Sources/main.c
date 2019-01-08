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
    
    while (nbJoueur) // Renvoyé par le menu() dans menu.c, devient 0 seulement si le joueur entre 4 (quitter) dans le menu
    {
        if (!jouer) // Affichage du menu en boucle tant que la partie n'a pas commencé
        {
            nbJoueur = menu(&jouer);
        }
        else // Sinon, gestion de la partie et de ses tours.
        {
            do
            {
                gestionTours(&nbJoueur);
            } while ( !victoire(&jouer) && !quitter(&jouer) );
            if (victoire(&jouer)) // Si les conditions de victoire sont remplies, afficher le vainqueur.
            {
                afficheVainqueur();
            }  
        }
    }
    return 0;
}
