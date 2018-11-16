#ifndef PION_H
#define PION_H

typedef struct {
        int num_pion; 
        int position[2];
    } Pion ; 

    typedef struct {
        int num_joueur;
        char nom_joueur[30];
        int couleur;
        Pion Cheval[4];
    } Joueur ;

#endif // PION_H