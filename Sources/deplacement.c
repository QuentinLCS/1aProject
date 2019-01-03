#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/plateau.h"
#include "../Header/deplacement.h"

int verification(cellule matrice[], int numJoueur, int numPion, int distance, joueur players[]){
    int res=1, i=1;
    while (i<= distance && res=1){
        if (matrice[chemin[ *players[numJoueur]->cheval[numPion]->num_case + i][0]][chemin[ *players[numJoueur]->cheval[numPion]->num_case + i][1]].nbChevaux == 0 ^ matrice[chemin[ *players[numJoueur]->cheval[numPion]->num_case + i][0]][chemin[ *players[numJoueur]->cheval[numPion]->num_case + i][1]].couleur == *players[numJoueur].couleur ){
            i++;
        }
        else if (i==distance) {
            res=2;
        }
        else {
            res=0;
        }
    }
    return res;
}

/* si return 0 : déplacement impossible
   si return 1 : déplacement simple possible
   si return 2 : capture possible */

void deplacement(cellule *matrice[], int numJoueur, int numPion, int distance, joueur *players[]){
    *matrice[*players[numJoueur]->cheval[numPion]->position[0]][*players[numJoueur]->cheval[numPion]->position[1]]->nbChevaux - = 1;
    *matrice[*players[numJoueur]->cheval[numPion]->position[0]][*players[numJoueur]->cheval[numPion]->position[1]]->couleur = ' ';
    *players[numJoueur]->cheval[numPion]->num_case + = distance % /*nb de case total*/;
    *players[numJoueur]->cheval[numPion]->position[0] = chemin[*players[numJoueur]->cheval[numPion]->num_case - 1][0];
    *players[numJoueur]->cheval[numPion]->position[1] = chemin[*players[numJoueur]->cheval[numPion]->num_case - 1][1];
    *matrice[*players[numJoueur]->cheval[numPion]->position[0]][*players[numJoueur]->cheval[numPion]->position[1]]->nbChevaux + = 1;
    *matrice[*players[numJoueur]->cheval[numPion]->position[0]][*players[numJoueur]->cheval[numPion]->position[1]]->couleur = *players[numJoueur]->couleur; 
}

void capture