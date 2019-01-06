#include <stdio.h>
#include <stdlib.h>
#include "../Header/init.h"
#include "../Header/deplacement.h"
#include "../Header/menu.h"
#include "../Header/plateau.h"


void gestionTours(int *nbJoueur)
{
    int i, j, ver, valde, rejouer, etat[4], z, valide = 1, choix, action, possib[4][2];
    affichagePlateau();
    for (i = 0; i < 4; i++)
    {
              
        printf("Joueur num %d : %s (%s)\n",i+1, players[ordrePassage[i]].nomJoueur, players[ordrePassage[i]].couleur);
        if (players[i].isJoueur)  
        {
            do
            {
                rejouer=0;
                printf("\n    %s, lance ton dé ! [appuyez sur entrer] \n", players[i].nomJoueur);
                  getchar();
                  valde=de();
                  printf ("Résultat du dé : %d !\n", valde);
                  if (valde==6)
                {
                    rejouer = 1;
                    checkEcurie(etat, 3, 1, players[ordrePassage[i]].numJoueur);
                }
                else {
                    checkEcurie(etat, 0, 1, players[ordrePassage[i]].numJoueur);
                }
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
                
                ver=0, choix=1, valide=1;
                do{
                    j = 1;                       /* C'est le tour d'un joueur */
                    while (j<4 && !ver){
                        z=0;
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
                                        choix++;
                                        break;
                                }
                            }
                            z++;
                        }
                        j++ ;
                    }
                    if (choix == 1)
                    {
                        possib[choix-1][0]=4;
                        action=1;
                        choix++;
                    }
                    else 
                    {
                        valide=scanf("%d",&action);
                        viderBuffer();
                        if (action > choix || action < 0 || !valide) afficherErreur(1);
                    }
                } while (action > choix || action < 0 || !valide);
                switch (possib[action-1][0]) {
                    case 1 : 
                        deplacement(players[ordrePassage[i]].numJoueur, possib[action-1][1], valde);
                        break;
                    case 2 :
                        capture(players[ordrePassage[i]].numJoueur, possib[action-1][1], valde);
                        break;
                    case 3 :
                        sortieEcurie(etat, players[ordrePassage[i]].numJoueur);
                        break;
                    case 4 :
                        printf ("Vous passez votre tour.\n");
                        break;
                }
                system("sleep 5");
                affichagePlateau();  
            } while (rejouer!=0); 
        }   
    
        


            
        else { 
            do{
                rejouer=0;
                valde=de();
                printf ("Vous avez fait un %d !\n", valde);
                if (valde==6)
                {
                    rejouer = 1;
                    checkEcurie(etat, 3, 1, players[ordrePassage[i]].numJoueur);
                }
                else {
                    checkEcurie(etat, 0, 1, players[ordrePassage[i]].numJoueur);
                }
                j=3;
                z=0;
                action = 0;
                while (j>0 && action == 0){
                    while (z < 4 && action == 0){
                        if (etat[z]==j){
                            switch (etat[z]) {
                                case 1 : 
                                    deplacement(players[ordrePassage[i]].numJoueur, possib[action-1][1], valde);
                                    break;
                                case 2 :
                                    capture(players[ordrePassage[i]].numJoueur, possib[action-1][1], valde);
                                    break;
                                case 3 :
                                    sortieEcurie(etat, players[ordrePassage[i]].numJoueur);
                                    break; 
                            }
                        }
                        z++;
                    } 
                    j--;  
                }
                printf ("\nici\n");
                system("sleep 5");
                affichagePlateau();  
            } while (rejouer!=0);
        } 
        printf ("\nici\n");
        system("sleep 5");
        affichagePlateau();  
    }    
    printf ("\nici\n");                      /* C'est le tour d'une IA */
    sauvegarder(*nbJoueur);
}

int victoire() 
{
    int i=0,somme, vic=0;
    while ((i < 4) && (vic == 0))
    {
        somme=0;
        vic=0;
        for (int j=0; j<4; j++)
        {
            somme+=players[i].cheval[j].numCase;
        }
        if (somme==408)
        {
            vic=1;
        }
        i++;
    }
    return vic;
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