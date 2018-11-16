#include <stdio.h>
#include "../Header/jeu.h"
#include "../Header/plateau.h"
#define TAILLE_PLATEAU 15 // IMPAIR
#define TAILLE_ECURIE 6 // Calculable ?

// VARIABLES GLOBALES
int i, j;
cellule matrice[TAILLE_PLATEAU][TAILLE_PLATEAU];

// void creation_plateau()
void main()
{

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
                matrice[i][j].ecurie = 0;
                matrice[i][j].echelle = 1;
                if (j == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0 && i < TAILLE_PLATEAU / 2) {
                    matrice[i][j].couleur[0] = "rouge";
                } else if (i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0 && j < TAILLE_PLATEAU / 2) {
                    matrice[i][j].couleur[0] = "bleu";
                } else if (i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0 && j > TAILLE_PLATEAU / 2) {
                    matrice[i][j].couleur[0] = "jaune";
                } else { 
                    matrice[i][j].couleur[0] = "vert";
                }   
            } else {
                matrice[i][j].nbChevaux = 0; // Chemin utilisable par les chevaux
                matrice[i][j].couleur[0] = " ";
                matrice[i][j].ecurie = 0;
                matrice[i][j].echelle = 0;
            }
        }
    } affichage_plateau(); // A DEPLACER DANS LE PROGRAMME PRINCIPAL QUAND TERMINE
}

// AFFICHAGE DU PLATEAU

void affichage_plateau() 
{
    printf("\n\n\n"); 
    for (i = 0; i < TAILLE_PLATEAU; i++) {
        for(j = 0; j < TAILLE_PLATEAU; j++) {

            // AFFICHAGE DES ECURIES 

            if (matrice[i][j].couleur[0] == "bleu" && matrice[i][j].ecurie) {
                if (matrice[i][j].nbChevaux) {
                    printf("\033[1;44m X \033[0m"); 
                } else {
                    if (j == 0) {
                        printf("\033[34;44m \033[0m");
                    } if (j == TAILLE_ECURIE - 1) {
                        printf("\033[34;44m \033[0m\033[7m \033[0m");
                    } else {
                        printf("\033[34;44m   \033[0m");
                    }
                }

            } else if (matrice[i][j].couleur[0] == "rouge" && matrice[i][j].ecurie) {
                if (matrice[i][j].nbChevaux) {
                    printf("\033[1;41m X \033[0m"); 
                } else {
                    printf("\033[31;41m   \033[0m");
                }

            } else if (matrice[i][j].couleur[0] == "jaune" && matrice[i][j].ecurie) {
                if (matrice[i][j].nbChevaux) {
                    printf("\033[1;43m X \033[0m"); 
                } else {
                    printf("\033[33;43m   \033[0m");
                }

            } else if (matrice[i][j].couleur[0] == "vert" && matrice[i][j].ecurie) {
                if (matrice[i][j].nbChevaux) {
                    printf("\033[1;42m X \033[0m"); 
                } else {
                    if (j == 0) {
                        printf("\033[32;42m \033[0m");
                    } if (j == TAILLE_ECURIE - 1) {
                        printf("\033[32;42m \033[0m\033[7m \033[0m");
                    } else {
                        printf("\033[32;42m   \033[0m");
                    } 
                }
            } 

            // AFFICHAGE DES ECHELLES
            
            else if (matrice[i][j].couleur[0] == "bleu" && matrice[i][j].echelle) {
                if (matrice[i][j].nbChevaux) {
                    printf("\033[1;44m X \033[0m"); 
                } else {
                    printf("\033[1;44m %d \033[0m", j);  
                }     

            } else if (matrice[i][j].couleur[0] == "rouge" && matrice[i][j].echelle) {
                if (matrice[i][j].nbChevaux) {
                    printf("\033[1;41m X \033[0m"); 
                } else {
                    printf("\033[1;41m %d \033[0m", i);   
                }    

            } else if (matrice[i][j].couleur[0] == "jaune" && matrice[i][j].echelle) {
                if (matrice[i][j].nbChevaux) {
                    printf("\033[1;43m X \033[0m"); 
                } else {
                    printf("\033[1;43m %d \033[0m", TAILLE_PLATEAU - j - 1);
                }     

            } else if (matrice[i][j].couleur[0] == "vert" && matrice[i][j].echelle) {
                if (matrice[i][j].nbChevaux) {
                    printf("\033[1;42m X \033[0m"); 
                } else {
                    printf("\033[1;42m %d \033[0m", TAILLE_PLATEAU - i - 1);  
                }     
                         
            }
            
            // AFFICHAGE DU CENTRE ( VICTOIRE )

            else if (i == TAILLE_PLATEAU / 2 && j == TAILLE_PLATEAU / 2) {
                printf("\033[1;40mWIN\033[0m");
            }
            
            // AFFICHAGE DES CASES BLANCHES
            
            else { 
                if (matrice[i][j].nbChevaux >= 1) {
                     if (matrice[i][j].couleur[0] == "bleu") {
                        printf("\033[7;44m %d \033[0m", matrice[i][j].nbChevaux);
                    }  else if (matrice[i][j].couleur[0] == "rouge") {
                        printf("\033[7;41m %d \033[0m", matrice[i][j].nbChevaux);
                    }  else if (matrice[i][j].couleur[0] == "jaune") {
                        printf("\033[7;43m %d \033[0m", matrice[i][j].nbChevaux);
                    } else {
                        printf("\033[7;42m %d \033[0m", matrice[i][j].nbChevaux);
                    }
                } else {
                    printf("\033[7m _ \033[0m");
                }
            }
        } printf("\n");
    } printf("\n\n\n");
}
