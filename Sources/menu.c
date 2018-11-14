#include <stdio.h>
#include "jeu.h"

void main()
{
    int gameMode, nbJoueurs;

    printf("\n[Projet 1A] PETITS CHEVAUX \nPar : CHAVAS Nathan & LECHASLES Quentin\n\nChoisissez votre mode de jeu :\n  [1] Mode SEUL\n  [2] Mode MULTIJOUEUR\n  [3] Mode IA \n\nMode [entrez une valeur]: ");
    scanf("%d", &gameMode);

    
    switch (gameMode) {
        case 1 :
            printf("\n\n[v] Mode SEUL : SELECTIONNE !\n\n");
            modeSolo();
            break;
        case 2 :
            printf("\n\n[v] Mode MULTIJOUEUR : SELECTIONNE !\n\n");
            modeMulti();
            break;
        case 3 :
            printf("\n\n[v] Mode IA : SELECTIONNE !\n\n");
            modeIA();
            break;
    }
}

int solo() {

    return 0;
}

int multijoueur() {

    return 0;
}

int IA () {

    return 0;
}