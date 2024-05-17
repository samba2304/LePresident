#include <stdlib.h>
#include <stdio.h>
#include <time.h>


struct Carte;

struct listeCartes;

struct Carte * creerCarte(char c, int v , char f);

void libererCarte(struct Carte * carte );

struct listeCartes * creerListeCartes (void);

void ajouterCarte(struct Carte * carte, struct listeCartes * liste);

void afficherCartes(struct listeCartes * liste);

