#ifndef ABR_H
#define ABR_H
typedef struct Noeud { int cle; struct Noeud *gauche; struct Noeud *droite; } Noeud;
Noeud* abr_inserer(Noeud *racine, int cle);
int abr_rechercher(Noeud *racine, int cle);
void abr_infixe(Noeud *racine);
int abr_hauteur(Noeud *racine);
void abr_detruire(Noeud *racine);
#endif
