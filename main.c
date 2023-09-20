#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(){
	int mode, operation;
	int N;
	int id;
	Task *T;
	
	do{
		printf("\nChoisir votre mode d'utilisation (Saisir le nombre): \n");
		printf("1. Ajouter nouvelles taches \n");
		printf("2. Afficher la liste de toutes les taches \n");
		printf("3. Modifier une tache \n");
		printf("4. Supprimer une tache \n");
		printf("5. Rechercher les taches \n");
		printf("6. Statistiques\n");
		printf("0. Quitter\n");
		scanf("%d", &mode);
		switch(mode){
			case 1:
				do{
					printf("\nSaisir le nombre de taches a saisir: \n");
					scanf("%d",&N);
				}while(N <= 0);
				T = (Task *)malloc(N * sizeof(Task));
				add_tasks(T, N);
				break;
			case 2:
				printf("Choisir votre mode d'utilisation (Saisir le nombre): \n");
				printf("1. Trier les taches par ordre alphabetique \n");
				printf("2. Trier les taches par deadline \n");
				printf("3. Afficher les tâches dont le deadline est dans 3 jours ou moins \n");
				printf("0. Quitter\n");
				scanf("%d", &operation);
				if(operation == 1){
					alphabetical_sort(T, N);
				} else if(operation == 2){
					deadline_sort(T, N);
				} else if(operation == 3){
					display_tasks_within_three_days(T, N);
				} else if(operation == 0){
					mode = 0;
				} else{
					printf("\nChoix Invalide.\n");
				}
				break;
			case 3:
				printf("Choisir votre mode d'utilisation (Saisir le nombre): \n");
				printf("1. Modifier la description d'une tache \n");
				printf("2. Modifier le statut d’une tache \n");
				printf("3. Modifier le deadline d’une tache \n");
				printf("0. Quitter\n");
				scanf("%d", &operation);
				if(operation == 1){
					printf("Choisir la tache que vous voulez modifer (Saisir l'identifiant): \n");
					alphabetical_sort(T, N);
					scanf("%d", &id);
				} else if(operation == 2){
					deadline_sort(T, N);
				} else if(operation == 3){
					display_tasks_within_three_days(T, N);
				} else if(operation == 0){
					mode = 0;
				} else{
					printf("\nChoix Invalide.\n");
				}
				break;
			case 4:
				//
				break;
			case 5:
				//
				break;
			case 6:
				//
				break;
			default:
				printf("\nChoix Invalide.\n");
		}
		}while(mode!=0);

	return 0;
}
