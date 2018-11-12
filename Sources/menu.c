#include <stdio.h>

int main()
{
    int gameMode, nbJoueurs;

    printf("\n[Projet 1A] PETITS CHEVAUX \nPar : CHAVAS Nathan & LECHASLES Quentin\n\nChoisissez votre mode de jeu :\n  [1] Mode SEUL\n  [2] Mode MULTIJOUEUR\n  [3] Mode IA \n\nMode [entrez une valeur]: ");
    scanf("%d", &gameMode);

    
    switch (gameMode) {
        case 1 :
            printf("\n\n[v] Mode SEUL : SELECTIONNE !");
            break;
        case 2 :
            printf("\n\n[v] Mode MULTIJOUEUR : SELECTIONNE !\n\n Nombre de joueurs [1;4]: ");
            scanf("%d", &nbJoueurs);
            break;
        case 3 :
            printf("\n\n[v] Mode IA : SELECTIONNE !");
            break;
    }
    return 0;
}
