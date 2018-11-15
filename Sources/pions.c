#include <stdio.h>
#include "../Header/pion.h"
int main (){
    typedef struct {
        int num_pion; 
        int position[2];
    } pion; 

    typedef struct {
        int num_joueur;
        char nom_joueur[30];
        int couleur;
        pion Cheval[4];
    } Joueur;

    Joueur Players[4];

  /*  pion cheval={1,{3,8}};
    Players[0].Cheval[0]=cheval;
    Players[0].Cheval[0]={1,{3,8}};

    Players[0]={1,"Nathan",2};


    printf ("%d",Players[0].couleur);
    puts (Players[0].nom_joueur);
  */

} 