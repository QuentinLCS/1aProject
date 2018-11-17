#include <stdio.h>
#include "../Header/pion.h"

void init ()
{
    int i; 

    joueur players[4];

    players[0].numJoueur = 1;
    players[0].couleur[0]   = "bleu";
    players[1].numJoueur = 2;
    players[1].couleur[0]   = "rouge";
    players[2].numJoueur = 3;
    players[2].couleur[0]   = "jaune";
    players[3].numJoueur = 4;
    players[3].couleur[0]   = "vert";

    for (i = 0 ; i < nbJoueur() ; i++) {
        printf ("\n\nEntrez le nom du joueur n°%d (couleur %s, 30 caractères max.) : ", i+1, players[i].couleur);
    }
}