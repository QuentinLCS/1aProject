#if !defined(MENU_H)
#define MENU_H

    int menu(int *);
    void nouvellePartie();
    void continuerPartie();
    void option();
    void scenarios();
    void plusInfos();
    void afficherErreur(int);
    void charger(char *, int, int *);
    void sauvegarder(int, int ordrePassage[4]);
    void afficheVainqueur();

#endif // MENU_H
