#include <stdlib.h>
#include <stdio.h>
#include "carte.h"
#include "joeur.h"

int main(void){
struct Carte * carte1 = creerCarte('R',4,'C');
struct Carte * carte2=creerCarte('N',6,'S');
struct Carte * carte3=creerCarte('Z',88,'T');

struct listeCartes * liste=creerListeCartes();
struct listeCartes * liste2=creerListeCartes();

struct Joeur * joeur1=creerJoeur(01,liste);
struct Joeur * joeur2=creerJoeur(02,liste2);

ajouterCarteJoeur(carte2,joeur1);
ajouterCarteJoeur(carte1,joeur2);
ajouterCarteJoeur(carte3,joeur1);


//printf("%d \n" , liste->debut->valeur);
//printf("%d \n" , liste->fin->valeur);

afficherCartesJoeur(joeur1);
printf("Jooeur 2\n");
afficherCartesJoeur(joeur2);

return 0;
}