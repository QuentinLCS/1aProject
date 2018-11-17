#ifndef PION_H
#define PION_H

typedef struct {
        int numPion; 
        int *position[2];
    } pion ; 

    typedef struct {
        int numJoueur;
        char *nomJoueur[30];
        char *couleur[6];
        pion cheval[4];
    } joueur ;

#endif // JEU_H