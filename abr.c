#include <stdlib.h>
#include <stdio.h>
#include "abr.h"
static Noeud* nouveau_noeud(int cle) { Noeud *n = malloc(sizeof(Noeud)); if (!n) exit(1); n->cle = cle; n->gauche = NULL; n->droite = NULL; return n; }
Noeud* abr_inserer(Noeud *racine, int cle) { if (racine == NULL) return nouveau_noeud(cle); if (cle < racine->cle) racine->gauche = abr_inserer(racine->gauche, cle); else if (cle > racine->cle) racine->droite = abr_inserer(racine->droite, cle); return racine; }
int abr_rechercher(Noeud *racine, int cle) { if (racine == NULL) return 0; if (cle == racine->cle) return 1; if (cle < racine->cle) return abr_rechercher(racine->gauche, cle); return abr_rechercher(racine->droite, cle); }
void abr_infixe(Noeud *racine) { if (racine == NULL) return; abr_infixe(racine->gauche); printf("%d ", racine->cle); abr_infixe(racine->droite); }
int abr_hauteur(Noeud *racine) { if (racine == NULL) return -1; int hg = abr_hauteur(racine->gauche); int hd = abr_hauteur(racine->droite); return 1 + (hg > hd ? hg : hd); }
void abr_detruire(Noeud *racine) { if (racine == NULL) return; abr_detruire(racine->gauche); abr_detruire(racine->droite); free(racine); }
