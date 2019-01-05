#include <stdio.h>
#include "../Header/init.h"
#include "../Header/deplacement.h"
#include "../Header/menu.h"
#include "../Header/plateau.h"


void gestionTours(int *nbJoueur, int *ordrePassage[])
{
    int i, j, ver=0, valde, rejouer, etat[4];

    for (i = 0; i < *nbJoueur; i++)
    {
                
        printf("Joueur num %d : %s (%s)\n",i+1, players[*ordrePassage[i]].nomJoueur, players[*ordrePassage[i]].couleur);
        do
        {
            rejouer=0;
            printf ("Appuyez sur Entrée pour lancer votre dé !\n");
            getchar();
            valde=de();
            printf ("Vous avez fait un %d !\n", valde);
            if (valde==6)
            {
                rejouer = 1;
                checkEcurie(etat, 3, 1, players[*ordrePassage[i]].numJoueur);
            }
            else {
                checkEcurie(etat, 0, 1, players[*ordrePassage[i]].numJoueur);
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
        int z, valide, choix=1, action, possib[4][2];
        printf ("\n_____________________________________________\nJoueur n°%d : %s (%s), que souhaitez-vous faire ? (Entrez la touche correspondante)\n",i+1, players[*ordrePassage[i]].nomJoueur, players[*ordrePassage[i]].couleur);
        if (i < *nbJoueur){ 
            j = 1, z=0;
            do{                           /* C'est le tour d'un joueur */
                while (j<4 && !ver){
                    while (z<4 && !ver){
                        if (j==etat[z]){
                            switch (j){
                                case 1 :
                                    printf ("[%d]Souhaitez-vous déplacer le pion n°%d ?\n", choix, z+1);
                                    possib[choix-1][0]=j;
                                    possib[choix-1][1]=z+1;
                                    choix++;
                                    break;
                                case 2 :
                                    printf ("[%d]Souhaitez-vous capturer avec le pion n°%d ?\n", choix, z+1);
                                    possib[choix-1][0]=j;
                                    possib[choix-1][1]=z+1;
                                    choix++;
                                    break;
                                case 3 :
                                    printf ("[%d]Souhaitez-vous sortir un cheval de l'écurie ?\n", choix);
                                    possib[choix-1][0]=j;
                                    possib[choix-1][1]=z+1;
                                    ver = 1;
                                    break;
                            }
                        }
                        z++;
                    }
                    j++ ;
                }
                
                valide=scanf("%d",&action);
                viderBuffer();
                
                if (action > choix || action < 0 || !valide) afficherErreur(1);

            } while (action > choix || action < 0 || !valide);

            switch (possib[action-1][0]) {
                case 1 : 
                    deplacement(players[*ordrePassage[i]].numJoueur, possib[action-1][1], valde);
                    break;
                case 2 :
                    capture(players[*ordrePassage[i]].numJoueur, possib[action-1][1], valde);
                    break;
                case 3 :
                    sortieEcurie(players[*ordrePassage[i]].numJoueur);
                    break;
            }
        }

        else {                              /* C'est le tour d'une IA */
            j=3;
            z=0;
            action = 0;
            while (j>0 && action == 0){
                while (z < 4 && action == 0){
                    if (etat[z]==j){
                        switch (etat[z]) {
                            case 1 : 
                                deplacement(players[*ordrePassage[i]].numJoueur, possib[action-1][1], valde);
                                break;
                            case 2 :
                                capture(players[*ordrePassage[i]].numJoueur, possib[action-1][1], valde);
                                break;
                            case 3 :
                                sortieEcurie(players[*ordrePassage[i]].numJoueur);
                                break; 
                        }
                    }
                    z++;
                } 
                j--;  
            }
        }
    }
    sauvegarder(*nbJoueur , *ordrePassage);
}

int victoire() 
{
    return 0;
}

int quitter()
{
    int state = 0, d;
    do
    {
        printf ("Voulez-vous quitter la partie ?\n [1] Non\n[2] Oui\n");
        d=scanf ("%d",&state);
    } while (state != 1 || state != 2 || d!=1);
    state -=1;
    return state;
}
