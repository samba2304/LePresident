#include <stdlib.h>
#include <stdio.h>
#include "carte.h"

struct Joeur;
struct Joeur * creerJoeur(int id , struct listeCartes * listeC);
void afficherCartesJoeur(struct Joeur * joeur);
void ajouterCarteJoeur(struct Carte * carte,struct Joeur * joeur);