#if !defined(PLATEAU_H)
#define PLATEAU_H
    typedef struct 
    {
        int nbChevaux;
        char couleur[6];
        int ecurie; // booléen ( vrai ou faux )
        int echelle; // booléen ( vrai ou faux )
    } cellule;

    void creationPlateau();
    void affichagePlateau();

    extern cellule plateau[15][15];

#endif // PLATEAU_H
