#ifndef HASH_H
#define HASH_H
#define TAILLE_TABLE 1009
typedef struct Cellule { char *cle; int valeur; struct Cellule *suivant; } Cellule;
typedef struct { Cellule *cases[TAILLE_TABLE]; } TableHash;
void hash_init(TableHash *t);
unsigned long hash_fonction(const char *cle);
void hash_inserer(TableHash *t, const char *cle);
int hash_rechercher(TableHash *t, const char *cle, int *valeur);
void hash_afficher(TableHash *t);
void hash_detruire(TableHash *t);
#endif
