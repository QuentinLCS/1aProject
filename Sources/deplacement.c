#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../Header/plateau.h"
#include "../Header/deplacement.h"
#include "../Header/init.h"

int chemin[57][2]=
{   
    {14,6}, {13,6}, {12,6}, {11,6}, {10,6}, {9,6}, {8,6}, {8,5}, {8,4}, {8,3}, {8,2}, {8,1}, {8,0}, {7,0}, /*Cases de l'écurie en bas à gauche*/
    {6,0}, {6,1}, {6,2}, {6,3}, {6,4}, {6,5}, {6,6}, {5,6}, {4,6}, {3,6}, {2,6}, {1,6}, {0,6}, {0,7}, /*Cases de l'écurie en haut à gauche*/
    {0,8}, {1,8}, {2,8}, {3,8}, {4,8}, {5,8}, {6,8}, {6,9}, {6,10}, {6,11}, {6,12}, {6,13}, {6,14}, {7,14}, /*Cases de l'écurie en haut à droite*/
    {8,14}, {8,13}, {8,12}, {8,11}, {8,10}, {8,9}, {8,8}, {9,8}, {10,8}, {11,8}, {12,8}, {13,8}, {14,8}, {14,7} /*Cases de l'écurie en bas à droite*/
} ;

int echelle[4][6][2]=
{ 
    {   {13,7}, {12,7}, {11,7}, {10,7}, {9,7}, {8,7}  },
    {   {7,1}, {7,2}, {7,3}, {7,4}, {7,5}, {7,6}   },
    {   {1,7}, {2,7}, {3,7}, {4,7}, {5,7}, {6,7}   },
    {   {7,13}, {7,12}, {7,11}, {7,10}, {7,9}, {7,8}    }
};

int listeSorties[4][3] = { {6,0,15}, {0,8,29}, {14,6,1}, {8,14,43} };

int listeEcuries[4][2] = { {2,2}, {2,11}, {12,2}, {12,11} };

int de()
{
    return rand() % 6 + 1;
}

void initPositionChevaux(int i, int j)
{
    players[i].cheval[j].position[0] = listeEcuries[i][0];
    players[i].cheval[j].position[1] = listeEcuries[i][1];
}

int verification(int numJoueur, int numPion, int distance){
    int res=1, i=1;
    printf("\nnumJoueur=%d ; numPion = %d; distance = %d; numCase = %d\n",numJoueur, numPion, distance,players[numJoueur].cheval[numPion].numCase);
    printf ("\n nbchevaux = %d",plateau[chemin[ (players[numJoueur].cheval[numPion].numCase -1 + i)%56][0]][chemin[ (players[numJoueur].cheval[numPion].numCase -1 + i)%56][1]].nbChevaux);
    printf ("\n pos0 : %d ; pos1 : %d",chemin[ (players[numJoueur].cheval[numPion].numCase -1 + i)%56][0],chemin[ (players[numJoueur].cheval[numPion].numCase -1 + i)%56][1]);
    if (players[numJoueur].cheval[numPion].numCase < 100)
    {
        while (i<= distance && res==1){
        
            
            if (plateau[chemin[ (players[numJoueur].cheval[numPion].numCase -1 + i)%56][0]][chemin[ (players[numJoueur].cheval[numPion].numCase -1 + i)%56][1]].nbChevaux != 0){
                printf ("\npbchevaux\n");
                if (strcmp(plateau[chemin[ (players[numJoueur].cheval[numPion].numCase -1 + i)%56][0]][chemin[ (players[numJoueur].cheval[numPion].numCase -1 + i)%56][1]].couleur , players[numJoueur].couleur) || strcmp(plateau[chemin[ (players[numJoueur].cheval[numPion].numCase -1 + i)%56][0]][chemin[ (players[numJoueur].cheval[numPion].numCase -1 + i)%56][1]].couleur," ")){
                    i++;
                    printf ("\npbcouleur\n");
                }   
                else {
                    if (i==distance){
                        res=2;
                    }
                    else {
                        res=0;
                    }
                }
            }  

            if (((players[numJoueur].cheval[numPion].numCase -1 + i)%56)+1 == ((listeSorties[numJoueur][2]+54) % 56) + 1) {
                if (i < distance){
                    res = 0;
                }
            }  
        }
    }
    else if (players[numJoueur].cheval[numPion].numCase - 100 == distance)
    {
        res=0;
    }
    else if (plateau[echelle[numJoueur][distance-1][0]][echelle[numJoueur][distance-1][0]].nbChevaux != 0)
    {
        res=0;
    }
    
    return res;
}

/* si return 0 : déplacement impossible
   si return 1 : déplacement simple possible
   si return 2 : capture possible */

void mouvement (int numJoueur, int numPion, int distance)
{
    if ((players[numJoueur].cheval[numPion].numCase == ((listeSorties[numJoueur][2]+54) % 56) + 1) || (players[numJoueur].cheval[numPion].numCase > 100))
    {
        deplacementEchelle(numJoueur, numPion, distance);
    }
    else
    {
        deplacement(numJoueur, numPion, distance);
    }
}

void deplacementEchelle(int numJoueur, int numPion, int distance)
{
    plateau[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].nbChevaux = 0;
    strcpy(plateau[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].couleur, " ");
    players[numJoueur].cheval[numPion].numCase = 100+distance;
    players[numJoueur].cheval[numPion].position[0] = echelle[numJoueur-1][distance-1][0];
    players[numJoueur].cheval[numPion].position[1] = echelle[numJoueur-1][distance-1][1];
    plateau[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].nbChevaux = 1;
    strcpy(plateau[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].couleur, players[numJoueur].couleur); 
}

void deplacement(int numJoueur, int numPion, int distance)
{
    plateau[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].nbChevaux -= 1;
    if(plateau[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].nbChevaux == 0)
    {
        strcpy(plateau[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].couleur, " ");
    }
    players[numJoueur].cheval[numPion].numCase = ((players[numJoueur].cheval[numPion].numCase + distance) % 56) + 1;
    players[numJoueur].cheval[numPion].position[0] = chemin[players[numJoueur].cheval[numPion].numCase - 1][0];
    players[numJoueur].cheval[numPion].position[1] = chemin[players[numJoueur].cheval[numPion].numCase - 1][1];
    plateau[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].nbChevaux += 1;
    strcpy(plateau[players[numJoueur].cheval[numPion].position[0]][players[numJoueur].cheval[numPion].position[1]].couleur, players[numJoueur].couleur); 
}

void capture(int numJoueur, int numPion, int distance)
{
    int i = 0, ver = 0;
    while (i < 4 && !ver)
    {
        if (!strcmp(plateau[chemin[(((players[numJoueur].cheval[numPion].numCase - 1)+ distance) %56) +1][0]] [chemin[(((players[numJoueur].cheval[numPion].numCase - 1)+ distance) %56) +1][1]].couleur , players[i].couleur))
        {
            for (int j = 0; j < 4; j++)
            {
                if (players[i].cheval[j].numCase ==(((players[numJoueur].cheval[numPion].numCase - 1)+ distance) %56) +1)
                {
                    players[i].cheval[j].numCase = 0;
                }
            }
            ver=1;
        }
        i++;
    }  
}

int checkEcurie(int etat[4], int numEtat, int needVerif, int numJoueur, int distance) 
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        if (players[numJoueur].cheval[i].numCase == 0)
        {
            printf ("\n%d\n",i);
            etat[i]=numEtat;
            res = i;
        }
        else if (needVerif)
        {
            printf ("\ntest1\n");
            etat[i]=verification(numJoueur, i, distance);
            printf ("\ntest2 res=%d\n",etat[i]);
        }
    }
    return res;
}

void sortieEcurie(int etat[4], int numJoueur) 
{
    int numPion = checkEcurie(etat, 0, 0, numJoueur, 0);
    
    plateau[listeEcuries[numJoueur][0]][listeEcuries[numJoueur][1]].nbChevaux -= 1;
    players[numJoueur].cheval[numPion].numCase = listeSorties[numJoueur][2];
    players[numJoueur].cheval[numPion].position[0] = listeSorties[numJoueur][0];
    players[numJoueur].cheval[numPion].position[1] = listeSorties[numJoueur][1];
    if (!strcmp(plateau[listeSorties[numJoueur][0]][listeSorties[numJoueur][1]].couleur, players[numJoueur].couleur) || !strcmp(plateau[listeSorties[numJoueur][0]][listeSorties[numJoueur][1]].couleur, " "))
    {
        plateau[listeSorties[numJoueur][0]][listeSorties[numJoueur][1]].nbChevaux += 1;
        strcpy(plateau[listeSorties[numJoueur][0]][listeSorties[numJoueur][1]].couleur, players[numJoueur].couleur);
    } 
    else
    {
        capture(numJoueur, numPion, 0);
    }
}

