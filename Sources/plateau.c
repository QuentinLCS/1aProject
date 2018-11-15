#include <stdio.h>
#define TAILLE_PLATEAU 15
#define TAILLE_ECURIE 6

void main()
{
    int i, j;
    //plateau cases[];

    for (i = 0; i < TAILLE_PLATEAU; i++) {
        for(j = 0; j < TAILLE_PLATEAU; j++)
        {
            if (j < TAILLE_ECURIE && i < TAILLE_ECURIE) {
                printf("1 ");
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i < TAILLE_ECURIE) {
                printf("2 ");
            } else if (j < TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) {
                printf("3 ");
            } else if (j >= TAILLE_PLATEAU - TAILLE_ECURIE && i >= TAILLE_PLATEAU - TAILLE_ECURIE) {
                printf("4 ");
            } else 
            if (j == TAILLE_PLATEAU / 2 && TAILLE_PLATEAU % 2 != 0 || TAILLE_PLATEAU % 2 == 0 && (j == TAILLE_PLATEAU / 2 || j == TAILLE_PLATEAU / 2 + 1) ) {
                printf("9 ");
            }
            
            else {
                printf("0 ");
            } 
        } printf("\n");
    }
}
