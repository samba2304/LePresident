#include <stdlib.h>
#include <stdio.h>
#include "joeur.h" 
#include "carte.h"


struct Joeur{
  int id;
  struct listeCartes * mesCartes;

};

struct Joeur *creerJoeur(int id , struct listeCartes * listeC){
    struct Joeur * joeur = malloc(sizeof(struct Joeur ));
    if (joeur==NULL)
    {
        printf("Erreur d'allocation \n");
        return ;
    }
    else
    {
          joeur->id = id;
          joeur->mesCartes=listeC;
          return joeur;
    }

}

void afficherCartesJoeur(struct Joeur * joeur){
    struct Carte * carteCourante = joeur->mesCartes;
    afficherCartes(carteCourante);
}

void ajouterCarteJoeur(struct Carte * carte,struct Joeur * joeur){
    ajouterCarte(carte,joeur->mesCartes);

}