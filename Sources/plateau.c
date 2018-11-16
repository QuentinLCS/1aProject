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
                matrice[i][j].couleur[0] = "bleu";
                matrice[i][j].ecurie = 1;
                matrice[i][j].echelle = 0;
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i < TAILLE_ECURIE) {
                matrice[i][j].nbChevaux = 0; // Ecurie haut droite
                matrice[i][j].couleur[0] = "rouge";
                matrice[i][j].ecurie = 1;
                matrice[i][j].echelle = 0;
            } else if (j < TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) {
                matrice[i][j].nbChevaux = 0; // Ecurie bas gauche
                matrice[i][j].couleur[0] = "vert";
                matrice[i][j].ecurie = 1;
                matrice[i][j].echelle = 0;
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) {
                matrice[i][j].nbChevaux = 0; // Ecurie bas droite
                matrice[i][j].couleur[0] = "jaune";
                matrice[i][j].ecurie = 1;
                matrice[i][j].echelle = 0;
            } else if (j == TAILLE_PLATEAU / 2 && i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0 || j == TAILLE_PLATEAU / 2 && i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 == 0) {
                matrice[i][j].nbChevaux = 0; // Centre du plateau
                matrice[i][j].couleur[0] = " ";
                matrice[i][j].ecurie = 0;
                matrice[i][j].echelle = 0;
            } else if (((j == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0) || (i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0)) && (i != 0 && i != TAILLE_PLATEAU - 1 && j != 0 && j != TAILLE_PLATEAU - 1)) {
                matrice[i][j].nbChevaux = 0; // Echelles jusqu'au centre
                matrice[i][j].couleur[0] = " ";
                matrice[i][j].ecurie = 0;
                matrice[i][j].echelle = 1;
            } else {
                matrice[i][j].nbChevaux = 0; // Chemin utilisable par les chevaux
                matrice[i][j].couleur[0] = " ";
                matrice[i][j].ecurie = 0;
                matrice[i][j].echelle = 0;
            }
        }
    }

// AFFICHAGE DU PLATEAU

    for (i = 0; i < TAILLE_PLATEAU; i++) {
        for(j = 0; j < TAILLE_PLATEAU; j++) {

            // AFFICHAGE DES ECURIES 

            if (matrice[i][j].couleur[0] == "bleu" && matrice[i][j].ecurie) {
                if (j == 0) {
                    printf("\033[34;44m \033[0m");
                } if (j == TAILLE_ECURIE - 1) {
                    printf("\033[34;44m \033[0m\033[7m \033[0m");
                } else {
                    printf("\033[34;44m   \033[0m");
                }
            } else if (matrice[i][j].couleur[0] == "rouge" && matrice[i][j].ecurie) {
                printf("\033[31;41m   \033[0m");
            } else if (matrice[i][j].couleur[0] == "jaune" && matrice[i][j].ecurie) {
                printf("\033[33;43m   \033[0m");
            } else if (matrice[i][j].couleur[0] == "vert" && matrice[i][j].ecurie) {
                if (j == 0) {
                    printf("\033[32;42m \033[0m");
                } if (j == TAILLE_ECURIE - 1) {
                    printf("\033[32;42m \033[0m\033[7m \033[0m");
                } else {
                    printf("\033[32;42m   \033[0m");
                } 
            } 

            else if (matrice[i][j].echelle) {
                printf("\033[1;40m   \033[0m");
            }
            
            
            
            else { // AFFICHAGE DES CASES BLANCHES ( chemin )
                printf("\033[7m 0 \033[0m");
            }
        } printf("\n");
    }
}
