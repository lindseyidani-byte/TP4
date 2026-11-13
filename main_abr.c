#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "abr.h"
#include "hash.h"
int main(void) {
    Noeud *racine = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) racine = abr_inserer(racine, vals[i]);
    printf("Infixe (doit etre trie) : "); abr_infixe(racine);
    printf("\nHauteur : %d (attendu 2)\n", abr_hauteur(racine));
    printf("Recherche 40 : %s\n", abr_rechercher(racine, 40) ? "trouve" : "absent");
    printf("Recherche 99 : %s\n", abr_rechercher(racine, 99) ? "trouve" : "absent");
    abr_detruire(racine);
    printf("\n=== BENCH 10000 cles ===\n");
    Noeud *abr = NULL; TableHash th; hash_init(&th);
    srand(42);
    for (int i = 0; i < 10000; i++) { int v = rand() % 100000; abr = abr_inserer(abr, v); char buf[16]; sprintf(buf, "%d", v); hash_inserer(&th, buf); }
    clock_t d, f; int trouve = 0;
    d = clock(); for (int i = 0; i < 10000; i++) if (abr_rechercher(abr, rand() % 100000)) trouve++; f = clock();
    printf("ABR : %f s (trouve=%d)\n", (double)(f-d)/CLOCKS_PER_SEC, trouve);
    d = clock(); trouve = 0; for (int i = 0; i < 10000; i++) { char buf[16]; sprintf(buf, "%d", rand() % 100000); int val; if (hash_rechercher(&th, buf, &val)) trouve++; } f = clock();
    printf("HASH : %f s (trouve=%d)\n", (double)(f-d)/CLOCKS_PER_SEC, trouve);
    abr_detruire(abr); hash_detruire(&th); return 0;
}
