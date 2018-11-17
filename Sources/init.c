#include <stdio.h>
#include "../Header/pion.h"
#include "../Header/init.h"

//void init ()
void main()
{
    int nbJoueur = 0, valide = 0, continuer = 0, i; 
    joueur players[4];

    // NumJoueur pas utile puisque on peut se 
    // servir de l'indice du tableau players[]

    players[0].couleur[0]   = "bleu";
    players[1].couleur[0]   = "rouge";
    players[2].couleur[0]   = "jaune";
    players[3].couleur[0]   = "vert";
    do  {
        printf ("Combien de Joueurs souhaitez-vous ? \n   --> 1 JOUEUR\n   --> 2 JOUEURS\n   --> 3 JOUEURS\n   --> 4 JOUEURS\n\nJoueurs [entrez une valeur]: ");
        valide = scanf ("%d",&nbJoueur);
        getchar();
    } while ( nbJoueur < 1 || nbJoueur > 4 || valide == 0 );

    for (i = 0 ; i < nbJoueur ; i++) {
        valide = 0;
        do  {
            printf ("\n\nEntrez le nom du joueur %s : ", players[i].couleur[0]);
            scanf("%s", players[i].nomJoueur);
            getchar();
            do {
                printf("\n\nC'est %s, c'est bien ca ?\n[1] Oui !\n[2] Non, recommencer.\n\n", players[i].nomJoueur);
                valide = scanf("%d", &continuer);
                viderBuffer();
            } while ( (continuer < 1 || continuer > 2) || valide == 0 );
        } while ( continuer == 2 );
    }
}

void viderBuffer() 
{
    char c;
    while ( (c=getchar()) != EOF && c != '\n');
}