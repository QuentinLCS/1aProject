#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../Header/plateau.h"
#include "../Header/deplacement.h"
#include "../Header/init.h"

int chemin[56][2]={ {14,6}, {13,6}, {12,6}, {11,6}, {10,6}, {9,6}, {8,6}, {8,5}, {8,4}, {8,3}, {8,2}, {8,1}, {8,0}, {7,0}, /*Cases de l'écurie en bas à gauche*/
                    {6,0}, {6,1}, {6,2}, {6,3}, {6,4}, {6,5}, {6,6}, {5,6}, {4,6}, {3,6}, {2,6}, {1,6}, {0,6}, {0,7}, /*Cases de l'écurie en haut à gauche*/
                    {0,8}, {1,8}, {2,8}, {3,8}, {4,8}, {5,8}, {6,8}, {6,9}, {6,10}, {6,11}, {6,12}, {6,13}, {6,14}, {7,14}, /*Cases de l'écurie en haut à droite*/
                    {8,14}, {8,13}, {8,12}, {8,11}, {8,10}, {8,9}, {8,8}, {9,8}, {10,8}, {11,8}, {12,8}, {13,8}, {14,8}, {14,7} /*Cases de l'écurie en bas à droite*/
} ;

int de()
{
    return rand() % 6 + 1;
}

int verification(int numJoueur, int numPion, int distance){
    int res=1, i=1;
    while (i<= distance && res==1){
        if (matrice[chemin[ players[numJoueur].cheval[numPion].num_case + i][0]][chemin[ players[numJoueur].cheval[numPion].num_case + i][1]].nbChevaux != 0){
            if (matrice[chemin[ players[numJoueur].cheval[numPion].num_case + i][0]][chemin[ players[numJoueur].cheval[numPion].num_case + i][1]].couleur == players[numJoueur].couleur ){
                i++;
            }
            else {
                if (i==distance){
                    res=2;
                }
                else {
                    res=0;
                }
            }
        }    
    }
    return res;
}

/* si return 0 : déplacement impossible
   si return 1 : déplacement simple possible
   si return 2 : capture possible */

void deplacement(int numJoueur, int numPion, int distance)
{
    matrice[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].nbChevaux -= 1;
    if(matrice[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].nbChevaux == 0)
    {
        strcpy(matrice[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].couleur, " ");
    }
    players[numJoueur].cheval[numPion].num_case += distance % 56;
    players[numJoueur].cheval[numPion].position[0] = chemin[players[numJoueur].cheval[numPion].num_case - 1][0];
    players[numJoueur].cheval[numPion].position[1] = chemin[players[numJoueur].cheval[numPion].num_case - 1][1];
    matrice[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].nbChevaux += 1;
    strcpy(matrice[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].couleur, players[numJoueur].couleur); 
}

/*void capture*/