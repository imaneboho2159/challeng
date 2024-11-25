#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define MAX_TACHES 40


typedef struct {
    char Titre [20];
    char Description [200];
    char DateDEcheance [20];
    char Priorite [6];


}TACHE;


TACHE tache[40];
int  nombreDeTache=0;
int N= nombreDeTache;


void AjouterTache(){
    
    if( N < MAX_TACHES){


        printf("Titer:");
        scanf("%19s",tache[N].Titre);
        printf(" Description :");
        scanf(" %[^\n]",tache[N].Description);
        printf(" DateDEcheance ( YYYY/MM/DD) :" );
        scanf("%10s",tache[N].DateDEcheance);
        printf("  Entrez la Priorite (high/low) :");
        scanf("%s",tache[N].Priorite);
        N++;
     }
    else {
        printf(" la limite des taches !" );
    }
}



void AffichierTache(){


    int i;
    for(i=0 ; i < N ; i++){
        printf("\n Tache %d:",i+1);
        printf("\nTitre :%s\n",tache[i].Titre);
        printf("Description :%s\n",tache[i].Description);
        printf("DateDEcheance :%s\n",tache[i].DateDEcheance);
        printf("Priorite :%s\n",tache[i].Priorite);
        printf("\n ");
    }
   
}


void ModifierTache (){
    int index;
    
    printf("entrez l index de la tache a modifier:");
    scanf("%d",&index);
   
    if(index >0 && index <= N){
        index -=1;
        printf("Nouveau Titre :");
        scanf("%s",tache[index].Titre);
        printf(" Nouvelle Description :");
        scanf("%s",tache[index].Description);
        printf("Nouvelle DateDEcheance ():");
        scanf("%s",tache[index].DateDEcheance);
        printf("Nouvelle priorite (high/low):");
        scanf("%s",tache[index].Priorite);

        
    }
    else {
        printf(" invalide index !");
    }
}


void SupprimerTache(){
    int index ;


    printf("entrez l index de la tache pour supprimer :");
    scanf("%d",&index);
    if (index >0 && index <= N){
        for(int i=index ;i<N-1 ;i++){
            tache[i]=tache[i+1];
        }
        N--;
    }
    else {
        printf("invalide index !");
    }
}


void FilterTache(){
    char priorite[6];
    int found =0;

    printf("entrez la priorite a filtrer(High / Low):");
    scanf("%5s",priorite);


    for(int i=0; i< N ; i++){
        int cmp= strcmp (tache[i].Priorite,  priorite);
        if(cmp == 0){
        found =1;
        printf("\n    \n"); 
        printf("\nTache %d:",i+1);
        printf("\nTitre :%s",tache[i].Titre);
        printf("\nDescription :%s",tache[i].Description);
        printf("\nDateDEcheance :%s",tache[i].DateDEcheance);
        printf("\nPriorite :%s",tache[i].Priorite);
        }
    }
    if (found!=1){
        printf("Aucune tache trouvee avec la priorite invalide: %s\n", priorite);
    }
}



int main(){
    int choix;
    do{
        printf("\n       \n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher les taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Filtrer les taches\n");
        printf("6. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);


         switch(choix){
            case 1:AjouterTache();break;
            case 2:AffichierTache();break;
            case 3:ModifierTache();break;
            case 4:SupprimerTache();break;
            case 5:FilterTache();break;
            case 6:
            printf("Quitter !");
            default:printf("\n choix invalid !");
         }
    }
    while (choix !=7);
   
   
  return 0;
}
