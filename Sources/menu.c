#include <stdio.h>
#include "../Header/jeu.h"

// void menu()
void main()
{
    int gameMode, nbJoueurs;

    printf("\n[Projet 1A] PETITS CHEVAUX \nPar : CHAVAS Nathan & LECHASLES Quentin\n\nChoisissez votre mode de jeu :\n  [1] Nouvelle partie\n  [2] Continuer\n  [3] Options\n  [4] Quitter \n\nMode [entrez une valeur]: ");
    scanf("%d", &gameMode);

    
    switch (gameMode) {
        case 1 :
            printf("\n\n[v] NOUVELLE PARTIE : SELECTIONNE !\n\n");
            NvPartie();
            break;
        case 2 :
            printf("\n\n[v] CONTINUER : SELECTIONNE !\n\n");
            Continue();
            break;
        case 3 :
            printf("\n\n[v] OPTION : SELECTIONNE !\n\n");
            Option();
            break;
        case 4 :
            printf("\n\n[v] QUITTER : SELECTIONNE !\n\n");
            break;
    }
}

int NvPartie (){

    return 0;
}

int Continue (){

    return 0;
}

int Option (){

    return 0;
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
