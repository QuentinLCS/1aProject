#include <stdio.h>
#include "../Header/pion.h"

void init (){
    Joueur Players[4];
    Players[0].num_joueur=1;
    Players[0].couleur="bleu";
    Players[0].num_joueur=2;
    Players[1].couleur="rouge";
    Players[0].num_joueur=3;
    Players[2].couleur="jaune";
    Players[0].num_joueur=4;
    Players[3].couleur="vert";


    int nbJoueur=nbJoueur();
    for (int i=0; i<nbJoueur; i++){
        printf ("\n\nEntrez le nom du joueur n°%d (couleur %s, 30 caractères max.) : ",i+1, Players[i].couleur);
    }
}