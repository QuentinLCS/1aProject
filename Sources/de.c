#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//int de(int nbDe)
int main(int nbDe)
{
    int max, min;
    srand(time(NULL));

    min = nbDe;
    max = nbDe * 6;
    
    return rand() % (max + 1 - min) + min;
}
