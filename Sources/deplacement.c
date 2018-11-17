#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/jeu.h"
#include "../Header/plateau.h"
#include "../Header/pion.h"

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