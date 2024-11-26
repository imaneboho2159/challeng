#include <stdio.h>
#include <string.h>

#define MAX_TACHES 40

typedef struct {
    char Titre[20];
    char Description[200];
    char Priorite[6];
    char date[11];  1
} TACHE;

TACHE tache[MAX_TACHES];
int nombreDeTache = 0;
int N = 0;     

void AjouterTache() {
    int annee, mois, jour;

    if (N < MAX_TACHES) {
        printf("Titre: ");
        scanf("%19s", tache[N].Titre);
        printf("Description: ");
        scanf(" %[^\n]", tache[N].Description);

        while (1) {
            printf("Date de cheance (YYYY/MM/DD): ");
            scanf("%10s",&tache[N].date);

            if (sscanf(tache[N].date, "%04d/%02d/%02d", &annee, &mois, &jour) != 3 ||annee <2024 || mois < 1 || mois > 12 || jour <1 || jour > 31) {
                printf("Invalide\n");
            } else {
                break;
            }
        }

        while (1) {
            printf("Entrez la Priorite (high/low): ");
            scanf("%s", tache[N].Priorite);

            if (strcmp(tache[N].Priorite, "high") == 0 || strcmp(tache[N].Priorite, "low") == 0) {
                break;
            } else {
                printf("\nInvalide. Veuillez entrer 'low' ou 'high': \n");
            }
        }
        N++;  
    } else {
        printf("La limite des taches a ete atteinte \n");
    }
}

void AfficherTache() {
    for (int i = 0; i < N; i++) {
        printf("\nTache %d:\n", i + 1);
        printf("Titre: %s\n", tache[i].Titre);
        printf("Description: %s\n", tache[i].Description);
        printf("DateDEcheance: %s\n", tache[i].date);
        printf("Priorite: %s\n", tache[i].Priorite);
    }
}

void ModifierTache() {
    int index;

    printf("Entrez l'index de la tache a modifier: ");
    scanf("%d", &index);

    if (index > 0 && index <= N) {
        index -= 1; 
        
        printf("Nouvelle DateDEcheance (YYYY/MM/DD): ");
        scanf("%10s", tache[index].date);
        printf("Nouvelle Priorite (high/low): ");
        scanf("%5s", tache[index].Priorite);
    } else {
        printf("Index invalide!\n");
    }
}

void SupprimerTache() {
    int index;

    printf("Entrez l'index de la tache a supprimer: ");
    scanf("%d", &index);

    if (index > 0 && index <= N) {
        for (int i = index - 1; i < N - 1; i++) {
            tache[i] = tache[i + 1];
        }
        N--;  
    } else {
        printf("Index invalide!\n");
    }
}

void FiltrerTache() {
    char priorite[6];
    int found = 0;

    printf("Entrez la priorite a filtrer (high/low): ");
    scanf("%5s", priorite);

    for (int i = 0; i < N; i++) {
        if (strcmp(tache[i].Priorite, priorite) == 0) {
            found = 1;
            printf("\nTache %d:\n", i + 1);
            printf("Titre: %s\n", tache[i].Titre);
            printf("Description: %s\n", tache[i].Description);
            printf("DateDEcheance: %s\n", tache[i].date);
            printf("Priorite: %s\n", tache[i].Priorite);
        }
    }
    if (!found) {
        printf("Aucune tache trouvee avec la priorite: %s\n", priorite);
    }
}

int main() {
    int choix;

    do {
        printf("\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher les taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Filtrer les taches\n");
        printf("6. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: AjouterTache(); break;
            case 2: AfficherTache(); break;
            case 3: ModifierTache(); break;
            case 4: SupprimerTache(); break;
            case 5: FiltrerTache(); break;
            case 0: printf("Quitter!\n"); break;
            default: printf("\nChoix invalide!\n");
        }
    } while (choix != 0);

    return 0;
}