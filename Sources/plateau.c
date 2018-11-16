#include <stdio.h>
#include "../Header/plateau.h"
#include "../Header/jeu.h"
#define TAILLE_PLATEAU 15 // IMPAIR 
#define TAILLE_ECURIE 6 // Calculable ?

// void creation_plateau()
void main()
{
    int i, j;
    char *couleurSyntaxe[10];
    cellule matrice[TAILLE_PLATEAU][TAILLE_PLATEAU];

// CREATION DU PLATEAU (en fonction des dimensions)

    for (i = 0; i < TAILLE_PLATEAU; i++) {
        for(j = 0; j < TAILLE_PLATEAU; j++) {
            if (j < TAILLE_ECURIE && i < TAILLE_ECURIE) { 
                matrice[i][j].nbChevaux = 0; // Ecurie haut gauche
                matrice[i][j].couleur[0] = "bleu";
                matrice[i][j].ecurie = 1;
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i < TAILLE_ECURIE) { 
                matrice[i][j].nbChevaux = 0; // Ecurie haut droite
                matrice[i][j].couleur[0] = "rouge";
                matrice[i][j].ecurie = 1; 
            } else if (j < TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) { 
                matrice[i][j].nbChevaux = 0; // Ecurie bas gauche
                matrice[i][j].couleur[0] = "vert";
                matrice[i][j].ecurie = 1; 
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) { 
                matrice[i][j].nbChevaux = 0; // Ecurie bas droite
                matrice[i][j].couleur[0] = "jaune";
                matrice[i][j].ecurie = 1; 
            } else if (j == TAILLE_PLATEAU / 2 && i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0 || j == TAILLE_PLATEAU / 2 && i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 == 0) {
                matrice[i][j].nbChevaux = 0; // Centre du plateau
                matrice[i][j].couleur[0] = " ";
                matrice[i][j].ecurie = 0; 
            } else if (((j == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0) || (i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0)) && (i != 0 && i != TAILLE_PLATEAU - 1 && j != 0 && j != TAILLE_PLATEAU - 1)) {
                matrice[i][j].nbChevaux = 0; // Echelles jusqu'au centre
                matrice[i][j].couleur[0] = " ";
                matrice[i][j].ecurie = 0; 
            } else {
                matrice[i][j].nbChevaux = 0; // Chemin utilisable par les chevaux
                matrice[i][j].couleur[0] = " ";
                matrice[i][j].ecurie = 0;
            } 
        }
    }

// AFFICHAGE DU PLATEAU 

    for (i = 0; i < TAILLE_PLATEAU; i++) {
        for(j = 0; j < TAILLE_PLATEAU; j++) {
            if (matrice[i][j].couleur[0] = "bleu") {
                couleurSyntaxe[0] = "\033[35m";
            }
            printf("%s %d \033[0m", couleurSyntaxe, matrice[i][j]);
        } printf("\n");
    }
}