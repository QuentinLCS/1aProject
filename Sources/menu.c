#include <stdio.h>
#include "../Header/jeu.h"

// void menu()
void main()
{
    int gameMode, nbJoueurs;

    printf("\n[Projet 1A] PETITS CHEVAUX \nPar : CHAVAS Nathan & LECHASLES Quentin\n\nQue souhaitez-vous faire ?\n  [1] JOUER\n  [2] SCENARIOS\n  [3] OPTIONS\n  [4] QUITTER\n\nMode [entrez une valeur]: ");
    scanf("%d", &gameMode);

    
    switch (gameMode) {
        case 1 :
            printf("\n\n[v] Mode SEUL : SELECTIONNE !\n\n");
            break;
        case 2 :
            printf("\n\n[v] Mode MULTIJOUEUR : SELECTIONNE !\n\n");
            break;
        case 3 :
            printf("\n\n[v] Mode IA : SELECTIONNE !\n\n");
            break;
    }
}
