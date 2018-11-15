#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//int de()
int main()
{
    srand(time(NULL));
    return rand() % (max + 1 - min) + min;
}
