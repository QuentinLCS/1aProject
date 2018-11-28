#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/plateau.h"
#include "../Header/deplacement.h"

int de()
{
    srand(time(NULL));
    return rand() % 6;
}


int deplacer(int numJoueur, int numPion, int distance) 
{

    int coordonnees[2], preCoordonnees[2], avancer, continuer, i, x, y;
    coordonnees[0] = players[numJoueur - 1].cheval[numPion - 1][0];
    coordonnees[1] = players[numJoueur - 1].cheval[numPion - 1][1];

    // CALCUL DE LA COORDONNEE

    for (i = 1; i <= distance; i++) {
        x = 1;
        y = 0;
        preCoordonnees[0] = coordonnees[0]; 
        preCoordonnees[1] = coordonnees[1];
        printf("(%d,%d)", preCoordonnees[0], preCoordonnees[1]);
        
        // PATH FINDING
        
        while (continuer != 1) {
            if (matrice[coordonnes[1] + y][coordonnees[0] + x].couleur[0] == " " || (matrice[coordonnees[1] + y][coordonnees[0] + x].couleur[0] == players[numJoueur].couleur[0] && !(matrice[coordonnees[1] + y][coordonnees[0] + x].ecurie) && !(matrice[coordonnees[y]][coordonnees[x]].echelle))) {
                coordonnees[0] = coordonnees[0] + x;
                coordonnees[1] = coordonnees[1] + y;
                continuer = 1;
            } else {
                if (x && !y) {
                    x--; y++;
                } else if (!x && y) {
                    x--; y--;
                } else {
                    x++; y--;
                }
            }
        } 
        
        // VERIFICATIONS

        if (i != distance && matrice[coordonnes[1]][coordonnees[0].couleur[0]] != players[numJoueur].couleur[0]) {
            // Alors déplacement impossible
        } else {
            if (i == distance && matrice[coordonnes[1]][coordonnees[0].couleur[0]] != players[numJoueur].couleur[0]) {
            // Autre couleur à l'écurie
            }
        // Alors déplacement possible
        }

    } return 0;
}

__________________________________________________________________________________________________________________

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/plateau.h"
#include "../Header/deplacement.h"

int de()
{
    srand(time(NULL));
    return rand() % 6;
}

int verificationX(int numJoueur, int numPion, int distance, int i){
    int test=0
    if (matrice[Players[numJoueur-1].cheval[numPion-1].destination[1]+i][Players[numJoueur-1].cheval[numPion-1].destination[0]].nbChevaux == 0){
        test=1;
    }
    else if (matrice[Players[numJoueur-1].cheval[numPion-1].destination[1]+i][Players[numJoueur-1].cheval[numPion-1].destination[0]].couleur[0] == Players[numJoueur-1].couleur[0]){
        test=1;
    }
    else {
    }
    return test;
}

int verificationY(int numJoueur, int numPion, int distance, int i){
int test=0
    if (matrice[Players[numJoueur-1].cheval[numPion-1].destination[1]][Players[numJoueur-1].cheval[numPion-1].destination[0]+i].nbChevaux == 0){
        test=1;
    }
    else if (matrice[Players[numJoueur-1].cheval[numPion-1].destination[1]][Players[numJoueur-1].cheval[numPion-1].destination[0]+i].couleur[0] == Players[numJoueur-1].couleur[0]){
        test=1;
    }
    else {
    }
    return test;
}

int deplacement(cellule matrice[], int numJoueur, int numPion, int distance){
    int destination[2], i=-1, ver=1, final=1;
    destination[0]=Players[numJoueur-1].cheval[numPion-1].position[0];
    destination[1]=Players[numJoueur-1].cheval[numPion-1].position[1];
    while (distance != 0 && final != 0 ){
        i=-1;
        ver=1;
        if (Players[numJoueur-1].cheval[numPion-1].destination[0] == 0){   
            for (int i=0; i<1; i++){
                

                
            }        
        }
        else if (Players[numJoueur-1].cheval[numPion-1].destination[0] == 14){
            for (int i=-1; i<1; i++){
                

            
            }
        }
        else if (Players[numJoueur-1].cheval[numPion-1].destination[1] == 0){
            for (int i=-1; i<1; i++){
                

            
            }
        }
        else if (Players[numJoueur-1].cheval[numPion-1].destination[1] == 14){
            for (int i=-1; i<1; i++){
                

            
            }
        }
        else {
            while (i<2 && ver != 0){
                if (matrice[Players[numJoueur-1].cheval[numPion-1].destination[1]+i][Players[numJoueur-1].cheval[numPion-1].destination[0]].ecurie != 1 
                && matrice[Players[numJoueur-1].cheval[numPion-1].destination[1]+i][Players[numJoueur-1].cheval[numPion-1].destination[0]].echelle != 1
                && (Players[numJoueur-1].cheval[numPion-1].destination[1]+i == Players[numJoueur-1].cheval[numPion-1].parcouru[1] && Players[numJoueur-1].cheval[numPion-1].destination[0] == Players[numJoueur-1].cheval[numPion-1].parcouru[0] ){
                    if (verificationX(numJoueur, numPion, distance, i)){
                        Players[numJoueur-1].cheval[numPion-1].parcouru[1]=Players[numJoueur-1].cheval[numPion-1].destination[1];
                        Players[numJoueur-1].cheval[numPion-1].parcouru[0]=Players[numJoueur-1].cheval[numPion-1].destination[0];
                        Players[numJoueur-1].cheval[numPion-1].destination[1]=Players[numJoueur-1].cheval[numPion-1].destination[1]+i;
                        Players[numJoueur-1].cheval[numPion-1].destination[0]=Players[numJoueur-1].cheval[numPion-1].destination[0];
                        ver = 0;
                    }
                    else {
                        final=0;
                    }
                }
                else if (matrice[Players[numJoueur-1].cheval[numPion-1].destination[1]][Players[numJoueur-1].cheval[numPion-1].destination[0]+i].ecurie != 1 
                && matrice[Players[numJoueur-1].cheval[numPion-1].destination[1]][Players[numJoueur-1].cheval[numPion-1].destination[0]+i].echelle != 1
                && (Players[numJoueur-1].cheval[numPion-1].destination[1] == Players[numJoueur-1].cheval[numPion-1].parcouru[1] && Players[numJoueur-1].cheval[numPion-1].destination[0]+i == Players[numJoueur-1].cheval[numPion-1].parcouru[0] ){

                    Players[numJoueur-1].cheval[numPion-1].parcouru[1]=Players[numJoueur-1].cheval[numPion-1].destination[1];
                    Players[numJoueur-1].cheval[numPion-1].parcouru[0]=Players[numJoueur-1].cheval[numPion-1].destination[0];
                    Players[numJoueur-1].cheval[numPion-1].destination[1]=Players[numJoueur-1].cheval[numPion-1].destination[1];
                    Players[numJoueur-1].cheval[numPion-1].destination[0]=Players[numJoueur-1].cheval[numPion-1].destination[0]+i;
                    ver = 0;
                }
                else {
                    i+=2;

                }
            }
        }
        distance-=1;
    }
    if (final=0){
        //Le déplacement est impossible dû à la présence d'un cheval sur la route
        return 0;
    }
    else {
        // Le déplacement c'est bien passé jusqu'à la case d'arrivée déterminée grâce au lancer de dé
        return 1;
    }


}