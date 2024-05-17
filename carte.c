#include <stdlib.h>
#include <stdio.h>
#include "carte.h"
#include <time.h>
#include "joeur.h" 

struct Carte{
    char couleur;
    int valeur;
    char forme;
    struct Carte *suivant;
};

struct listeCartes{
    struct Carte * debut;
    struct Carte * fin;  

};


struct Carte * creerCarte(char c, int v , char f){
    struct Carte * carte = malloc(sizeof(struct Carte ));
    if (carte==NULL)
    {
        printf("Erreur d'allocation \n");

    }
    else
    {
        carte->couleur=c;
        carte->valeur=v;
        carte->forme=f;
        carte->suivant=NULL;
        return carte;
    }

}

void libererCarte(struct Carte *carte ){
    carte->suivant= NULL;
    free(carte);
}

struct listeCartes * creerListeCartes (void){
    struct listeCartes * liste = malloc(sizeof(struct listeCartes *));

    liste->debut=NULL;
    liste->fin=NULL;
    return liste;
}

void ajouterCarte(struct Carte * carte, struct listeCartes * liste){
    if (liste->debut==NULL)
    {
        liste->debut=carte;
        liste->fin=carte;
    }
    else
    {
        struct Carte * courant = liste->debut;
        while (courant!=NULL)
        {
            courant = courant->suivant;
        }
        liste->fin->suivant= carte;
        liste->fin = carte;
    }


}

void afficherCartes(struct listeCartes * liste){
    struct Carte * carteCourante = liste->debut;
    while (carteCourante!=NULL)
    {
        printf("%c %d %c \n", carteCourante->couleur, carteCourante->valeur, carteCourante->forme);
        carteCourante= carteCourante->suivant;
    }
}

