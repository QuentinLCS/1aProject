
#if !defined(INIT_H)
#define INIT_H

    typedef struct {
        int numJoueur;
        char *nomJoueur[30];
        char *couleur[6];
        int cheval[4][2];
    } joueur ;

    void viderBuffer();

#endif // INIT_H
