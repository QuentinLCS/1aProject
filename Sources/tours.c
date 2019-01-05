#include <stdio.h>
#include "../Header/init.h"
#include "../Header/deplacement.h"
#include "../Header/menu.h"


void gestionTours(int nbJoueur, int *ordrePassage[])
{
    int i, j, ver=0, valde, rejouer, etat[4];

    for (i = 0; i < nbJoueur; i++)
    {
                
        printf("Joueur num %d : %s (%s)\n",i+1, players[*ordrePassage[i]].nomJoueur, players[*ordrePassage[i]].couleur);
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
                        etat[j]=verification(matrice, players[*ordrePassage[i]].nomJoueur, j, valde, players);
                    }
                }  
            }
            else {
                for (j = 0; j< 4; j++){
                    if (players[i].cheval[j].num_case == 0){
                        etat[j]=0;
                    }
                    else {
                        etat[j]=verification(matrice, players[*ordrePassage[i]].nomJoueur, j, valde, players);
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
        int z, d, choix=1, action, possib[4];
        printf ("\n_____________________________________________\nJoueur n°%d : %s (%s), que souhaitez-vous faire ? (Entrez la touche correspondante)\n",i+1, players[*ordrePassage[i]].nomJoueur, players[*ordrePassage[i]].couleur);
        if (i < nbJoueur){ 
            j = 1, z=0;                           /* C'est le tour d'un joueur */
            while (j<4 && !ver){
                while (z<4 && !ver){
                    if (j==etat[z]){
                        switch (j){
                            case 1 :
                                printf ("[%d]Souhaitez-vous déplacer le pion n°%d ?\n", choix, z+1);
                                possib[choix-1]=j;
                                choix++;
                                break;
                            case 2 :
                                printf ("[%d]Souhaitez-vous capturer avec le pion n°%d ?\n", choix, z+1);
                                possib[choix-1]=j;
                                choix++;
                                break;
                            case 3 :
                                printf ("[%d]Souhaitez-vous sortir un cheval de l'écurie ?\n");
                                possib[choix-1]=j;
                                ver = 1;
                                break;
                        }
                    }
                    z++;
                }
                j++ ;
            }
            do{
                d=scanf("%d",&action);
            } while (action > choix || action < 0 || !d);

            switch (possib[action-1]) {
                case 1 : 
                    deplacement();
                    break;
                case 2 :
                    capture();
                    break;
                case 3 :
                    sortieecurie();
                    break;
            }
        }

        else {                              /* C'est le tour d'une IA */

        }
    }
}