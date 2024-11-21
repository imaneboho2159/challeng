#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char rue[50];
    char ville[20];
    int codePostal;
} adresse;

typedef struct {
    char nom[100];
    int age;
    adresse ad;
} personne;

personne p[100];
int compteur = 0;

void ajouter_personne() {
    int n, i;

    printf("Donner le nombre des personnes à ajouter: ");
    scanf("%d", &n);

    if (compteur + n <= 100) {  
        for (i = 0; i < n; i++) {
            printf("Donner les informations de la personne numero %d :\n", compteur + 1);
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
            compteur++;  
        }
    } else {
        printf("La liste est pleine !\n");
    }
}

void read_personne() {
    int i;
    if (compteur == 0) {
        printf("Aucune personne à afficher !\n");
        return;
    }
    for (i = 0; i < compteur; i++) {
        printf("Nom: %s\nAge: %d\nRue: %s\nVille: %s\nCode Postal: %d\n",
               p[i].nom, p[i].age, p[i].ad.rue, p[i].ad.ville, p[i].ad.codePostal);
    }
}

void metterAJour_personne(int index) {
    if (index >= 0 && index < compteur) {
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
        printf("Index introuvable !\n");
    }
}

void supprimer_personne(int index) {
    if (index >= 0 && index < compteur) {
        for (int i = index; i < compteur - 1; i++) {
            p[i] = p[i + 1];  
        }
        compteur--;  
        printf("La personne a été supprimée.\n");
    } else {
        printf("Index introuvable !\n");
    }
}

int main() {
    int choix, index;

    while (1) {
        printf("\n1 : Ajouter une personne\n");
        printf("2 : Afficher les personnes\n");
        printf("3 : Mettre à jour une personne\n");
        printf("4 : Supprimer une personne\n");
        printf("5 : Quitter\n");
        printf("Choisir: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_personne();
                break;
            case 2:
                read_personne();
                break;
            case 3:
                printf("Entrez l'index de la personne à mettre à jour : ");
                scanf("%d", &index);
                metterAJour_personne(index);
                break;
            case 4:
                printf("Entrez l'index de la personne à supprimer : ");
                scanf("%d", &index);
                supprimer_personne(index);
                break;
            case 5:
                printf("Quitter\n");
                return 0;
            default:
                printf("Choix invalide !\n");
        }
    }

    return 0;
}