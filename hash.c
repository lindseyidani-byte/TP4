#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash.h"
void hash_init(TableHash *t) { for (int i = 0; i < TAILLE_TABLE; i++) t->cases[i] = NULL; }
unsigned long hash_fonction(const char *cle) { unsigned long h = 5381; int c; while ((c = *cle++)) h = ((h << 5) + h) + c; return h % TAILLE_TABLE; }
void hash_inserer(TableHash *t, const char *cle) { unsigned long idx = hash_fonction(cle); Cellule *cur = t->cases[idx]; while (cur) { if (strcmp(cur->cle, cle) == 0) { cur->valeur++; return; } cur = cur->suivant; } Cellule *nv = malloc(sizeof(Cellule)); if (!nv) exit(1); nv->cle = strdup(cle); nv->valeur = 1; nv->suivant = t->cases[idx]; t->cases[idx] = nv; }
int hash_rechercher(TableHash *t, const char *cle, int *valeur) { unsigned long idx = hash_fonction(cle); Cellule *cur = t->cases[idx]; while (cur) { if (strcmp(cur->cle, cle) == 0) { if (valeur) *valeur = cur->valeur; return 1; } cur = cur->suivant; } return 0; }
void hash_afficher(TableHash *t) { for (int i = 0; i < TAILLE_TABLE; i++) { Cellule *cur = t->cases[i]; while (cur) { printf("%s : %d\n", cur->cle, cur->valeur); cur = cur->suivant; } } }
void hash_detruire(TableHash *t) { for (int i = 0; i < TAILLE_TABLE; i++) { Cellule *cur = t->cases[i]; while (cur) { Cellule *tmp = cur; cur = cur->suivant; free(tmp->cle); free(tmp); } t->cases[i] = NULL; } }
