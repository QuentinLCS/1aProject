
#if !defined(INIT_H)
#define INIT_H

    typedef struct {
        char *nomJoueur[30];
        char *couleur[6];
        int cheval[4];
    } joueur ;

    int nbJoueurs();
    void nomJoueurs();
    int ordreJeu();
    void viderBuffer();

#endif // INIT_H
