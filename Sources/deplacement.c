#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/jeu.h"
#include "../Header/plateau.h"
#include "../Header/pion.h"

//int de()
int main()
{
    srand(time(NULL));
    return rand() % 6;
}

int deplacer(int numJoueur, int numPion, int distance) {
    // Nombre de cases parcourables : 56

    int coordonnees[2], i;

    // CALCUL DE LA COORDONNEE

    for (i = 1; i <= distance; i++) {
        // position : players[numJoueur - 1].cheval[numPion - 1];
        // couleur : players[numJoueur - 1].couleur[0]
        if (players[numJoueur - 1].couleur[0] == "bleu") {
            coordonnees = {6,0};
        }
    } return 0;
}