#include <stdlib.h>
#include <stdio.h>

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

struct Carte * creerCarte(char couleur , int valeur , char forme){
    struct Carte * carte = malloc(sizeof(struct Carte *));
    if (carte==NULL)
    {
        printf("Erreur d'allocation \n");
        return 1 ;
    }
    else
    {
        carte->couleur=couleur;
        carte->valeur=valeur;
        carte->forme=forme;
        carte->suivant=NULL;
        return carte;
    }

}

void libererCarte(struct Carte *carte ){
    carte->suivant= NULL;
    free(carte);
}

struct listeCartes * creerListeCartes (void)
{
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
        printf("%c %d %d \n", carteCourante->couleur, carteCourante->valeur, carteCourante->forme);
        carteCourante= carteCourante->suivant;
    }
    
}

int main(void){

struct Carte *carte1=creerCarte('R',4,'C');
struct Carte *carte2=creerCarte('N',5,'T');
struct Carte *carte3=creerCarte('Z',88,'T');

struct listeCartes *liste=creerListeCartes();
ajouterCarte(carte1,liste);
ajouterCarte(carte3,liste);

ajouterCarte(carte2,liste);
printf("%d \n" , liste->debut->valeur);
printf("%d \n" , liste->fin->valeur);

afficherCartes(liste);

return 0;
}