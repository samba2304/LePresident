#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "carte.h"
#include "joeur.h"

void melangerCartes(struct Carte *cartes[], int n) {
    srand(time(NULL)); // Initialiser le générateur de nombres aléatoires
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Carte *temp = cartes[i];
        cartes[i] = cartes[j];
        cartes[j] = temp;
    }
}

void distribuerCartes(struct Carte *cartes[], int n, struct Joeur *joeur1, struct Joeur *joeur2) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ajouterCarteJoeur(cartes[i], joeur1);
        } else {
            ajouterCarteJoeur(cartes[i], joeur2);
        }
    }
}

int main(void) {
    // Création des 52 cartes du jeu Président
    char couleurs[] = {'R', 'N'}; // Rouge et Noir
    char formes[] = {'H', 'D', 'S', 'C'}; // Coeurs, Carreaux, Piques, Trèfles
    int valeurs[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}; // 2 à As (As = 14)


    struct Carte *cartes[52];
    int index = 0;
    for (int j = 0; j < 4; j++) { // Pour chaque forme
        for (int k = 0; k < 13; k++) { // Pour chaque valeur
            cartes[index] = creerCarte(couleurs[j/2], valeurs[k], formes[j]);
            index++;
        }
    }


    // Mélanger les cartes
    melangerCartes(cartes, 52);

    // Créer deux joueurs
    struct listeCartes *liste1 = creerListeCartes();
    struct listeCartes *liste2 = creerListeCartes();
    struct Joeur *joeur1 = creerJoeur(1, liste1);
    struct Joeur *joeur2 = creerJoeur(2, liste2);

    // Distribuer les cartes mélangées aux deux joueurs
    distribuerCartes(cartes, 52, joeur1, joeur2);

    // Afficher les cartes des joueurs
    printf("Joueur 1\n");
    afficherCartesJoeur(joeur1);
    printf("Joueur 2\n");
    afficherCartesJoeur(joeur2);

    // Libérer la mémoire (à implémenter)

    return 0;
}
