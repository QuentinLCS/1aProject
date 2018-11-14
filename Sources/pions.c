#include <stdio.h>
#include "../Header/pion.h"
int main (){

    Joueur Players[4];

    pion cheval={1,{3,8}};
    Players[0].Cheval[0]=cheval;



    printf ("%d",Players[0].couleur);
    puts (Players[0].nom_joueur);


} 