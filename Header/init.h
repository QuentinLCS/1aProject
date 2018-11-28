
#if !defined(INIT_H)
#define INIT_H

    typedef struct {
        int numcheval;
        int position[2];
        int parcouru[2];
    } pion ;
   
    typedef struct {
        int numJoueur;
        char *nomJoueur[30];
        char *couleur[6];
        pion cheval[4];
    } joueur ;

    void init();
    void viderBuffer();

#endif // INIT_H
