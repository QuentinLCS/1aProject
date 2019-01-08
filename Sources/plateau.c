#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Header/plateau.h"
#define TAILLE_PLATEAU 15 
#define TAILLE_ECURIE 6 

#define ROUGE "\033[1;41m"

// VARIABLES GLOBALES
int i, j, k;

cellule plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];

void creationPlateau() // Creation du plateau des petits chevaux
{

// CREATION DU PLATEAU (en fonction des dimensions)

    for (i = 0; i < TAILLE_PLATEAU; i++) { //Lignes
        for(j = 0; j < TAILLE_PLATEAU; j++) { // Colonnes
            if (j < TAILLE_ECURIE && i < TAILLE_ECURIE) {
                plateau[i][j].nbChevaux  = 0;      // Ecurie haut gauche
                strcpy(plateau[i][j].couleur, "bleu"); // strcpy obligatoire pour de la gestion de chaînes plus facilement
                plateau[i][j].ecurie     = 1;
                plateau[i][j].echelle    = 0;
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i < TAILLE_ECURIE) {
                plateau[i][j].nbChevaux  = 0;      // Ecurie haut droite
                strcpy(plateau[i][j].couleur, "rouge");
                plateau[i][j].ecurie     = 1;
                plateau[i][j].echelle    = 0;
            } else if (j < TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) {
                plateau[i][j].nbChevaux  = 0;      // Ecurie bas gauche
                strcpy(plateau[i][j].couleur, "vert");
                plateau[i][j].ecurie     = 1;
                plateau[i][j].echelle    = 0;
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) {
                plateau[i][j].nbChevaux  = 0;      // Ecurie bas droite
                strcpy(plateau[i][j].couleur, "jaune");
                plateau[i][j].ecurie     = 1;
                plateau[i][j].echelle    = 0;
            } else if ((j == TAILLE_PLATEAU / 2 && i == TAILLE_PLATEAU / 2)) {
                plateau[i][j].nbChevaux  = 0;      // Centre du plateau
               strcpy(plateau[i][j].couleur, " ");
                plateau[i][j].ecurie     = 0;
                plateau[i][j].echelle    = 0;
            } else if ((j == TAILLE_PLATEAU / 2 || i == TAILLE_PLATEAU / 2) && (i != 0 && i != TAILLE_PLATEAU - 1 && j != 0 && j != TAILLE_PLATEAU - 1)) {
                plateau[i][j].nbChevaux = 0;      // Echelles jusqu'au centre
                plateau[i][j].ecurie    = 0;
                plateau[i][j].echelle   = 1;
                if (j == TAILLE_PLATEAU / 2 && i < TAILLE_PLATEAU / 2) {
                    strcpy(plateau[i][j].couleur, "rouge");
                } else if (i == TAILLE_PLATEAU / 2 && j < TAILLE_PLATEAU / 2) {
                    strcpy(plateau[i][j].couleur, "bleu");
                } else if (i == TAILLE_PLATEAU / 2 && j > TAILLE_PLATEAU / 2) {
                    strcpy(plateau[i][j].couleur, "jaune");
                } else { 
                    strcpy(plateau[i][j].couleur, "vert");
                }   
            } else {
                plateau[i][j].nbChevaux  = 0; // Chemin utilisable par les chevaux
                strcpy(plateau[i][j].couleur, " ");
                plateau[i][j].ecurie     = 0;
                plateau[i][j].echelle    = 0;
            }
        }
    } 
}

// AFFICHAGE DU PLATEAU

void affichagePlateau() // Fonction d'affichage du plateau en fonction des données dans le tableau plateau[][]
{

    system("clear");
    
    for (i = 0; i < TAILLE_PLATEAU; i++) {

        for (k = 0; k < 3; k++) {
            printf("\n     ");
            for(j = 0; j < TAILLE_PLATEAU; j++) {

                // AFFICHAGE DES ECURIES 

                if (!strcmp(plateau[i][j].couleur, "bleu") && plateau[i][j].ecurie) {
                    if (plateau[i][j].nbChevaux && k == 1) {
                        printf("\033[1;44m    %d\u265e\033[0m", plateau[i][j].nbChevaux); 
                    } else 
                        {
                            printf("\033[34;44m      \033[0m");
                        }

                } else if (!strcmp(plateau[i][j].couleur, "rouge") && plateau[i][j].ecurie) {
                    if (plateau[i][j].nbChevaux && k == 1) {
                        printf("\033[1;41m    %d\u265e\033[0m", plateau[i][j].nbChevaux); 
                    } else {
                        printf("\033[31;41m      \033[0m");
                    }

                } else if (!strcmp(plateau[i][j].couleur, "jaune") && plateau[i][j].ecurie) {
                    if (plateau[i][j].nbChevaux && k == 1) {
                        printf("\033[1;43m    %d\u265e\033[0m", plateau[i][j].nbChevaux); 
                    } else {
                        printf("\033[33;43m      \033[0m");
                    }

                } else if (!strcmp(plateau[i][j].couleur, "vert") && plateau[i][j].ecurie) {
                    if (plateau[i][j].nbChevaux && k == 1) {
                        printf("\033[1;42m    %d\u265e\033[0m", plateau[i][j].nbChevaux); 
                    } else 
                        {
                            printf("\033[32;42m      \033[0m");
                        } 
                
                // AFFICHAGE DES ECHELLES
                
                } else if (!strcmp(plateau[i][j].couleur, "bleu") && plateau[i][j].echelle) {
                    if (k == 1) {
                        if (plateau[i][j].nbChevaux) {
                            printf("\033[1;44m  %d\u265e  \033[0m", j); 
                        } else {
                            printf("\033[1;44m   %d  \033[0m", j);  
                        }
                    } else {
                        printf("\033[1;44m      \033[0m");  
                    }    

                } else if (!strcmp(plateau[i][j].couleur, "rouge") && plateau[i][j].echelle) {
                    if (k == 1) {
                        if (plateau[i][j].nbChevaux) {
                            printf("\033[1;41m  %d\u265e  \033[0m", i); 
                        } else {
                            printf("\033[1;41m  %d   \033[0m", i);   
                        }    
                    } else {
                        printf("\033[1;41m      \033[0m");  
                    }    

                } else if (!strcmp(plateau[i][j].couleur, "jaune") && plateau[i][j].echelle) {
                    if (k == 1) {
                        if (plateau[i][j].nbChevaux) {
                            printf("\033[1;43m  %d\u265e  \033[0m", TAILLE_PLATEAU - j - 1); 
                        } else {
                            printf("\033[1;43m  %d   \033[0m", TAILLE_PLATEAU - j - 1);
                        }
                    } else {
                        printf("\033[1;43m      \033[0m");  
                    }    

                } else if (!strcmp(plateau[i][j].couleur, "vert") && plateau[i][j].echelle) {
                    if (k == 1) {
                        if (plateau[i][j].nbChevaux) {
                            printf("\033[1;42m  %d\u265e  \033[0m", TAILLE_PLATEAU - i - 1); 
                        } else {
                            printf("\033[1;42m  %d   \033[0m", TAILLE_PLATEAU - i - 1);  
                        }
                    } else {
                        printf("\033[1;42m      \033[0m"); 
                    }
                            
                }
                
                // AFFICHAGE DU CENTRE ( VICTOIRE )

                else if (i == TAILLE_PLATEAU / 2 && j == TAILLE_PLATEAU / 2) {
                    if (k == 1) {
                        printf("\033[1;40m WIN! \033[0m");
                    } else {
                        printf("\033[1;40m      \033[0m");
                    }
                }
                
                // AFFICHAGE DES CASES BLANCHES
                
                else { 
                    if (!k) {
                        printf("\033[7m\u02F9    \u02FA\033[0m");
                    } else if (k == 1) {
                        if (plateau[i][j].nbChevaux >= 1) {
                            if (!strcmp(plateau[i][j].couleur, "bleu")) {
                                printf("\033[7;44m  %d\u265e  \033[0m", plateau[i][j].nbChevaux);
                            }  else if (!strcmp(plateau[i][j].couleur, "rouge")) {
                                printf("\033[7;41m  %d\u265e  \033[0m", plateau[i][j].nbChevaux);
                            }  else if (!strcmp(plateau[i][j].couleur, "jaune")) {
                                printf("\033[7;43m  %d\u265e  \033[0m", plateau[i][j].nbChevaux);
                            } else {
                                printf("\033[7;42m  %d\u265e  \033[0m", plateau[i][j].nbChevaux);
                            }
                        } else {
                            printf("\033[7m      \033[0m");
                        }
                    } else {
                        printf("\033[7m\u02FB    \u02FC\033[0m");
                    }
                }
            } 
        }
    } 
    printf ("\n");
}
