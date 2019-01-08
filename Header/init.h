#if !defined(INIT_H)
#define INIT_H

    typedef struct {
        int numCheval;
        int numCase;
        int position[2];
    } pion ;

    typedef struct {
        int isJoueur; // booléen ( vrai ou faux )
        int numJoueur;
        char nomJoueur[30];
        char couleur[6];
        pion cheval[4];
    } joueur ;

    int init(int);
    int nbJoueurs();
    void nomJoueurs(int);
    void ordreJeu(int);
    void viderBuffer();

    extern joueur players[4];
    extern int ordrePassage[4];

#endif // INIT_H
