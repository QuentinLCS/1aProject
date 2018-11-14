#include <stdio.h>
#include "../Header/jeu.h"

// void menu()
void menu()
{
    int gameMode, nbJoueurs;

    printf("\n[Projet 1A] PETITS CHEVAUX \nPar : CHAVAS Nathan & LECHASLES Quentin\n\nChoisissez votre mode de jeu :\n  [1] Mode SEUL\n  [2] Mode MULTIJOUEUR\n  [3] Mode IA \n\nMode [entrez une valeur]: ");
    scanf("%d", &gameMode);

    
    switch (gameMode) {
        case 1 :
            printf("\n\n[v] Mode SEUL : SELECTIONNE !\n\n");
            solo();
            break;
        case 2 :
            printf("\n\n[v] Mode MULTIJOUEUR : SELECTIONNE !\n\n");
            multi();
            break;
        case 3 :
            printf("\n\n[v] Mode IA : SELECTIONNE !\n\n");
            IA();
            break;
    }
}

int solo() {

    return 0;
}

int multi() {

    return 0;
}

int IA () {

    return 0;
}