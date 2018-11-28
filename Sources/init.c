#include <stdio.h>
<<<<<<< HEAD
#include "../Header/pion.h"

void init (){
    Joueur Players[4];
    Players[0].num_joueur=1;
    Players[0].couleur="bleu";
    Players[1].num_joueur=2;
    Players[1].couleur="rouge";
    Players[2].num_joueur=3;
    Players[2].couleur="jaune";
    Players[3].num_joueur=4;
    Players[3].couleur="vert";


    int nbJoueur=nbJoueur();
    for (int i=0; i<nbJoueur; i++){
        printf ("\n\nEntrez le nom du joueur n°%d (couleur %s, 30 caractères max.) : ",i+1, Players[i].couleur);
    }
}
=======
#include "../Header/init.h"
#include "../Header/deplacement.h"

///// TEMPORAIRE ( pour le dé qui est temporaire dans ce fichier )/////
#include <stdlib.h>
#include <time.h>

int de()
{
    srand(time(NULL));
    return rand() % 6 + 1;
}

//void init ()
void main()
{
    int nbJoueur = 0, valide = 0, continuer = 0, tirage[4], ordrePassage[4], i, j, tempI = 0; 
    joueur players[4];

    // NumJoueur pas utile puisque on peut se 
    // servir de l'indice du tableau players[]

    players[0].couleur[0]   = "bleu";
    players[1].couleur[0]   = "rouge";
    players[2].couleur[0]   = "jaune";
    players[3].couleur[0]   = "vert";
    do  {
        printf ("Combien de Joueurs souhaitez-vous ? \n   --> 1 JOUEUR\n   --> 2 JOUEURS\n   --> 3 JOUEURS\n   --> 4 JOUEURS\n\nReponse [entrez une valeur]: ");
        valide = scanf ("%d",&nbJoueur);
        viderBuffer();
    } while ( nbJoueur < 1 || nbJoueur > 4 || valide == 0 );

    for (i = 0 ; i < nbJoueur ; i++) {
        valide = 0;
        do  {
            printf ("\n\nEntrez le nom du joueur %s : ", players[i].couleur[0]);
            scanf("%s", players[i].nomJoueur);
            viderBuffer(); 
            do {
                printf("\n\nC'est %s, c'est bien ca ?\n[1] Oui !\n[2] Non, recommencer.\n\nReponse [entrez une valeur]: ", players[i].nomJoueur);
                valide = scanf("%d", &continuer);
                viderBuffer();
            } while ( (continuer < 1 || continuer > 2) || valide == 0 );
        } while ( continuer == 2 );
    }

    // ORDRE DE JEU ( tirage )

    
    if (nbJoueur > 1) {
        printf("\n\nPour tirer l'ordre de jeu, jetez votre de !\n");
        for (i = 0; i < nbJoueur; i++) {
            printf("\n    %s, lance ton de ! [appuyez sur entrer] ", players[i].nomJoueur);
            getchar();
            tirage[i] = de();
            printf("\n   \u2192 Resultat : %d !\n", tirage[i]);
            
            // TRIER L'ORDRE DE PASSAGE EN FONCTION DU NOMBRE TIRE PAR JOUEUR
        } 
        
        for (i = 0; i < nbJoueur; i++) {
            for (j = 0; j < nbJoueur; j++) {
                if (tirage[j]) {
                    if (tirage[tempI] < tirage[j]) {
                        tempI = j;
                    } 
                }
            } ordrePassage[i] = tempI;
            tirage[tempI] = 0;
            printf("\n%de : %s", i+1, players[ordrePassage[i]].couleur[0]);
        }
    }
}

void viderBuffer() 
{
    char c;
    while ( (c=getchar()) != EOF && c != '\n');
}
>>>>>>> a91af98b06edf1a7ea9b839f21c63e83a826f7a3
