#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"
static void nettoyer(char *mot) { int j = 0; for (int i = 0; mot[i]; i++) { if (isalpha((unsigned char)mot[i])) mot[j++] = tolower((unsigned char)mot[i]); } mot[j] = '\0'; }
int main(int argc, char *argv[]) { if (argc < 2) { printf("Usage : ./motcompte fichier.txt\n"); return 1; } FILE *f = fopen(argv[1], "r"); if (!f) { printf("Impossible d'ouvrir %s\n", argv[1]); return 1; } TableHash t; hash_init(&t); char mot[256]; while (fscanf(f, "%255s", mot) == 1) { nettoyer(mot); if (strlen(mot) > 0) hash_inserer(&t, mot); } fclose(f); printf("=== Occurrences ===\n"); hash_afficher(&t); hash_detruire(&t); return 0; }
