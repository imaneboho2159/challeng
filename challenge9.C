#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Définition de la structure adresse pour stocker l'adresse d'une personne
typedef struct {
    char rue[50];      // Rue de l'adresse
    char ville[20];    // Ville de l'adresse
    int codePostal;    // Code postal
} adresse;

// Définition de la structure personne pour stocker les informations d'une personne
typedef struct {
    char nom[100];     // Nom de la personne
    int age;           // Âge de la personne
    adresse ad;        // Adresse associée à la personne
} personne;

// Tableau de personnes et un compteur pour suivre le nombre de personnes ajoutées
personne p[100];
int compteur = 0; // Le compteur suit le nombre de personnes dans le tableau

// Fonction pour ajouter des personnes
void ajouter_personne() {
    int n, i;

    // Demande le nombre de personnes à ajouter
    printf("Donner le nombre des personnes à ajouter: ");
    scanf("%d", &n);

    // Vérifie si on peut ajouter ces personnes sans dépasser la limite
    if (compteur + n <= 100) {  
        // Boucle pour ajouter chaque personne
        for (i = 0; i < n; i++) {
            printf("Donner les informations de la personne numero %d :\n", compteur + 1);

            // Demande le nom, l'âge et l'adresse de la personne
            printf("Entrer le nom : ");
            scanf("%s", p[compteur].nom);
            printf("Entrer l'âge : ");
            scanf("%d", &p[compteur].age);
            printf("Entrer l'adresse :\n");
            printf("Rue: ");
            scanf("%s", p[compteur].ad.rue);
            printf("Ville: ");
            scanf("%s", p[compteur].ad.ville);
            printf("Code Postal: ");
            scanf("%d", &p[compteur].ad.codePostal);

            // Incrémenter le compteur de personnes
            compteur++;  
        }
    } else {
        // Si la liste est pleine, afficher un message d'erreur
        printf("La liste est pleine !\n");
    }
}

// Fonction pour afficher toutes les personnes enregistrées
void read_personne() {
    int i;

    // Vérifie si aucune personne n'a été ajoutée
    if (compteur == 0) {
        printf("Aucune personne à afficher !\n");
        return;
    }

    // Affiche les informations de chaque personne
    for (i = 0; i < compteur; i++) {
        printf("Nom: %s\nAge: %d\nRue: %s\nVille: %s\nCode Postal: %d\n",
               p[i].nom, p[i].age, p[i].ad.rue, p[i].ad.ville, p[i].ad.codePostal);
    }
}

// Fonction pour mettre à jour les informations d'une personne en fonction de l'index
void metterAJour_personne(int index) {
    if (index >= 0 && index < compteur) {
        // Demander à l'utilisateur de saisir les nouvelles informations
        printf("Entrez le nom : ");
        scanf("%s", p[index].nom);
        printf("Entrez l'âge : ");
        scanf("%d", &p[index].age);
        printf("Entrez rue : ");
        scanf("%s", p[index].ad.rue);
        printf("Entrez la ville : ");
        scanf("%s", p[index].ad.ville);
        printf("Entrez le code postal : ");
        scanf("%d", &p[index].ad.codePostal);
    } else {
        // Si l'index est invalide, afficher un message d'erreur
        printf("Index introuvable !\n");
    }
}

// Fonction pour supprimer une personne en fonction de son index
void supprimer_personne(int index) {
    if (index >= 0 && index < compteur) {
        // Décaler les éléments suivants pour supprimer la personne
        for (int i = index; i < compteur - 1; i++) {
            p[i] = p[i + 1];  
        }
        compteur--;  // Décrémenter le compteur
        printf("La personne a été supprimée.\n");
    } else {
        // Si l'index est invalide, afficher un message d'erreur
        printf("Index introuvable !\n");
    }
}

// Fonction principale qui offre un menu pour l'utilisateur
int main() {
    int choix, index;

    // Boucle infinie pour afficher le menu tant que l'utilisateur ne choisit pas de quitter
    while (1) {
        // Affichage du menu avec les différentes options
        printf("\n1 : Ajouter une personne\n");
        printf("2 : Afficher les personnes\n");
        printf("3 : Mettre à jour une personne\n");
        printf("4 : Supprimer une personne\n");
        printf("5 : Quitter\n");
        printf("Choisir: ");
        scanf("%d", &choix);

        // Selon le choix de l'utilisateur, appeler la fonction correspondante
        switch (choix) {
            case 1:
                ajouter_personne(); // Ajouter une personne
                break;
            case 2:
                read_personne(); // Afficher les personnes
                break;
            case 3:
                // Demander l'index de la personne à mettre à jour
                printf("Entrez l'index de la personne à mettre à jour : ");
                scanf("%d", &index);
                metterAJour_personne(index); // Mettre à jour la personne
                break;
            case 4:
                // Demander l'index de la personne à supprimer
                printf("Entrez l'index de la personne à supprimer : ");
                scanf("%d", &index);
                supprimer_personne(index); // Supprimer la personne
                break;
            case 5:
                // Quitter le programme
                printf("Quitter\n");
                return 0;
            default:
                // Si un choix invalide est effectué
                printf("Choix invalide !\n");
        }
    }

    return 0;
}
