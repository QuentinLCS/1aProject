#include <stdio.h>
#include "../Header/jeu.h"
#define TAILLE_PLATEAU 15
#define TAILLE_ECURIE 6

// void creation_plateau()
void main()
{
    int i, j;
    int matrice[TAILLE_PLATEAU][TAILLE_PLATEAU];

    for (i = 0; i < TAILLE_PLATEAU; i++) {
        for(j = 0; j < TAILLE_PLATEAU; j++) {
            if (j < TAILLE_ECURIE && i < TAILLE_ECURIE) {
                matrice[i][j] = 1;
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i < TAILLE_ECURIE) {
                matrice[i][j] = 2;
            } else if (j < TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) {
                matrice[i][j] = 3;
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) {
                matrice[i][j] = 4;
            } else if (j == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0 || TAILLE_PLATEAU % 2 == 0 && (j == TAILLE_PLATEAU / 2 || j == TAILLE_PLATEAU / 2 + 1) ) {
                matrice[i][j] = 9;
            } else {
                matrice[i][j] = 0;
            } 
        }
    }

    for (i = 0; i < TAILLE_PLATEAU; i++) {
        for(j = 0; j < TAILLE_PLATEAU; j++) {
            printf("%d ", matrice[i][j]);
        } printf("\n");
    }
}