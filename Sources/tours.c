#include <stdio.h>
#include "../Header/init.h"
#include "../Header/deplacement.h"
#include "../Header/menu.h"


void gestionTours(int nbJoueur, int *ordrePassage[], joueur players[])
{
    int i, j, valde, rejouer, etat[4];

    for (i = 0; i < nbJoueur; i++)
    {
                
        printf("Joueur num %d : %s (%s)\n",i+1, players[ordrePassage[i]].nomJoueur, players[ordrePassage[i]].couleur);
        do
        {
            rejouer=0;
            printf ("Appuyez sur Entrée pour lancer votre dé !\n");
            getchar();
            valde=de();
            if (valde==6){
                rejouer = 1;
                for (j = 0; j< 4; j++){
                    if (players[i].cheval[j].num_case == 0){
                        etat[j]=3;
                    }
                    else {
                        etat[j]=verification(matrice, players[ordrePassage[i]].nomJoueur, j, valde, players);
                    }
                }  
            }
            else {
                for (j = 0; j< 4; j++){
                    if (players[i].cheval[j].num_case == 0){
                        etat[j]=0;
                    }
                    else {
                        etat[j]=verification(matrice, players[ordrePassage[i]].nomJoueur, j, valde, players);
                    }
                }
            }
        } while (rejouer!=0);
        
        for (j = 0; j < 4; j++){
            switch (etat[j]){
                case 0 : 
                    printf ("Le pion n°%d ne peut pas se déplacer.\n", j+1);
                    break;
                case 1 :
                    printf ("Le pion n°%d peut effectuer un déplacement !\n", j+1);
                    break;
                case 2 :
                    printf ("Le pion n°%d peut effectuer la capture d'un cheval adverse !\n", j+1);
                    break;
                case 3 :
                    printf ("Le pion n°%d peut sortir de l'écurie !\n", j+1);
                    break;
            } 
        }
    }
}