#include <stdio.h>
#include "../Header/pion.h"

void init ()
{
    int i; 

    joueur players[4];

    // NumJoueur pas utile puisque on peut se 
    // servir de l'indice du tableau players[]

    players[0].couleur[0]   = "bleu";
    players[1].couleur[0]   = "rouge";
    players[2].couleur[0]   = "jaune";
    players[3].couleur[0]   = "vert";

    for (i = 0 ; i < nbJoueur() ; i++) {
        printf ("\n\nEntrez le nom du joueur n°%d (couleur %s, 30 caractères max.) : ", i+1, players[i].couleur);
    }
}