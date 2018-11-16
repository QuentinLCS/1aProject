#include <stdio.h>
#include "../Header/plateau.h"
#include "../Header/jeu.h"
#define TAILLE_PLATEAU 15 // IMPAIR 
#define TAILLE_ECURIE 6 // Calculable ?

// void creation_plateau()
void main()
{
    int i, j;
    cellule matrice[TAILLE_PLATEAU][TAILLE_PLATEAU];

// CREATION DU PLATEAU (en fonction des dimensions)

    for (i = 0; i < TAILLE_PLATEAU; i++) {
        for(j = 0; j < TAILLE_PLATEAU; j++) {
            if (j < TAILLE_ECURIE && i < TAILLE_ECURIE) { 
                matrice[i][j].nbChevaux = 0; // Ecurie haut gauche
                matrice[i][j].couleur[] = "bleu";
                matrice[i][j].ecurie = 1;
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i < TAILLE_ECURIE) { 
                matrice[i][j] = 2; // Ecurie haut droite
            } else if (j < TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) { 
                matrice[i][j] = 3; // Ecurie bas gauche
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) { 
                matrice[i][j] = 4; // Ecurie bas droite
            } else if (j == TAILLE_PLATEAU / 2 && i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0 || j == TAILLE_PLATEAU / 2 && i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 == 0) {
                matrice[i][j] = 7; // Centre du plateau
            } else if (((j == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0) || (i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0)) && (i != 0 && i != TAILLE_PLATEAU - 1 && j != 0 && j != TAILLE_PLATEAU - 1)) {
                matrice[i][j] = 9; // Echelles jusqu'au centre
            } else {
                matrice[i][j] = 0;
            } 
        }
    }

// AFFICHAGE DU PLATEAU 

    for (i = 0; i < TAILLE_PLATEAU; i++) {
        for(j = 0; j < TAILLE_PLATEAU; j++) {
            printf("%d ", matrice[i][j]);
        } printf("\n");
    }
}