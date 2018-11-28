#include <stdio.h>
#include "../Header/plateau.h"
#define TAILLE_PLATEAU 15 // IMPAIR
#define TAILLE_ECURIE 6 // Calculable ?

#define ROUGE "\033[1;41m"

// VARIABLES GLOBALES
int i, j, k;
cellule matrice[TAILLE_PLATEAU][TAILLE_PLATEAU];

// void creationPlateau()
void main()
{

// CREATION DU PLATEAU (en fonction des dimensions)

    for (i = 0; i < TAILLE_PLATEAU; i++) {
        for(j = 0; j < TAILLE_PLATEAU; j++) {
            if (j < TAILLE_ECURIE && i < TAILLE_ECURIE) {
                matrice[i][j].nbChevaux  = 0;      // Ecurie haut gauche
                matrice[i][j].couleur[0] = "bleu";
                matrice[i][j].ecurie     = 1;
                matrice[i][j].echelle    = 0;
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i < TAILLE_ECURIE) {
                matrice[i][j].nbChevaux  = 0;      // Ecurie haut droite
                matrice[i][j].couleur[0] = "rouge";
                matrice[i][j].ecurie     = 1;
                matrice[i][j].echelle    = 0;
            } else if (j < TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) {
                matrice[i][j].nbChevaux  = 0;      // Ecurie bas gauche
                matrice[i][j].couleur[0] = "vert";
                matrice[i][j].ecurie     = 1;
                matrice[i][j].echelle    = 0;
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) {
                matrice[i][j].nbChevaux  = 0;      // Ecurie bas droite
                matrice[i][j].couleur[0] = "jaune";
                matrice[i][j].ecurie     = 1;
                matrice[i][j].echelle    = 0;
            } else if (j == TAILLE_PLATEAU / 2 && i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0 || j == TAILLE_PLATEAU / 2 && i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 == 0) {
                matrice[i][j].nbChevaux  = 0;      // Centre du plateau
                matrice[i][j].couleur[0] = " ";
                matrice[i][j].ecurie     = 0;
                matrice[i][j].echelle    = 0;
            } else if (((j == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0) || (i == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0)) && (i != 0 && i != TAILLE_PLATEAU - 1 && j != 0 && j != TAILLE_PLATEAU - 1)) {
                matrice[i][j].nbChevaux = 0;      // Echelles jusqu'au centre
                matrice[i][j].ecurie    = 0;
                matrice[i][j].echelle   = 1;
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
                matrice[i][j].nbChevaux  = 0; // Chemin utilisable par les chevaux
                matrice[i][j].couleur[0] = " ";
                matrice[i][j].ecurie     = 0;
                matrice[i][j].echelle    = 0;
            }
        }
    } affichagePlateau();
}

// AFFICHAGE DU PLATEAU

void affichagePlateau() 
{

    printf("\n\n\n"); 
    
    for (i = 0; i < TAILLE_PLATEAU; i++) {

        for (k = 0; k < 3; k++) {
            printf("\n     ");
            for(j = 0; j < TAILLE_PLATEAU; j++) {

                // AFFICHAGE DES ECURIES 

                if (matrice[i][j].couleur[0] == "bleu" && matrice[i][j].ecurie) {
                    if (matrice[i][j].nbChevaux && k == 1) {
                        printf("\033[1;44m   \u265e  \033[0m"); 
                    } else {
                        if (j == 0) {
                            printf("\033[34;44m \033[0m");
                        } if (j == TAILLE_ECURIE - 1) {
                            printf("\033[34;44m     \033[0m");
                        } else {
                            printf("\033[34;44m      \033[0m");
                        }
                    }

                } else if (matrice[i][j].couleur[0] == "rouge" && matrice[i][j].ecurie) {
                    if (matrice[i][j].nbChevaux && k == 1) {
                        printf("\033[1;41m  \u265e   \033[0m"); 
                    } else {
                        printf("\033[31;41m      \033[0m");
                    }

                } else if (matrice[i][j].couleur[0] == "jaune" && matrice[i][j].ecurie) {
                    if (matrice[i][j].nbChevaux && k == 1) {
                        printf("\033[1;43m  \u265e   \033[0m"); 
                    } else {
                        printf("\033[33;43m      \033[0m");
                    }

                } else if (matrice[i][j].couleur[0] == "vert" && matrice[i][j].ecurie) {
                    if (matrice[i][j].nbChevaux && k == 1) {
                        printf("\033[1;42m   \u265e  \033[0m"); 
                    } else {
                        if (j == 0) {
                            printf("\033[32;42m \033[0m");
                        } if (j == TAILLE_ECURIE - 1) {
                            printf("\033[32;42m     \033[0m");
                        } else {
                            printf("\033[32;42m      \033[0m");
                        } 
                    }
                } 

                // AFFICHAGE DES ECHELLES
                
                else if (matrice[i][j].couleur[0] == "bleu" && matrice[i][j].echelle) {
                    if (k == 1) {
                        if (matrice[i][j].nbChevaux) {
                            printf("\033[1;44m  %d\u265e  \033[0m", j); 
                        } else {
                            printf("\033[1;44m   %d  \033[0m", j);  
                        }
                    } else {
                        printf("\033[1;44m      \033[0m");  
                    }    

                } else if (matrice[i][j].couleur[0] == "rouge" && matrice[i][j].echelle) {
                    if (k == 1) {
                        if (matrice[i][j].nbChevaux) {
                            printf("\033[1;41m  %d\u265e  \033[0m", i); 
                        } else {
                            printf("\033[1;41m  %d   \033[0m", i);   
                        }    
                    } else {
                        printf("\033[1;41m      \033[0m");  
                    }    

                } else if (matrice[i][j].couleur[0] == "jaune" && matrice[i][j].echelle) {
                    if (k == 1) {
                        if (matrice[i][j].nbChevaux) {
                            printf("\033[1;43m  %d\u265e  \033[0m", TAILLE_PLATEAU - j - 1); 
                        } else {
                            printf("\033[1;43m  %d   \033[0m", TAILLE_PLATEAU - j - 1);
                        }
                    } else {
                        printf("\033[1;43m      \033[0m");  
                    }    

                } else if (matrice[i][j].couleur[0] == "vert" && matrice[i][j].echelle) {
                    if (k == 1) {
                        if (matrice[i][j].nbChevaux) {
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
                        if (matrice[i][j].nbChevaux >= 1) {
                            if (matrice[i][j].couleur[0] == "bleu") {
                                printf("\033[7;44m  %d\u265e  \033[0m", matrice[i][j].nbChevaux);
                            }  else if (matrice[i][j].couleur[0] == "rouge") {
                                printf("\033[7;41m  %d\u265e  \033[0m", matrice[i][j].nbChevaux);
                            }  else if (matrice[i][j].couleur[0] == "jaune") {
                                printf("\033[7;43m  %d\u265e  \033[0m", matrice[i][j].nbChevaux);
                            } else {
                                printf("\033[7;42m  %d\u265e  \033[0m", matrice[i][j].nbChevaux);
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
    } printf("\n\n\n");
}
