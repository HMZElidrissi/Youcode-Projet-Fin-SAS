#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(){
	int mode, operation;
	int N = 0;
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
				T = (Task *)malloc(sizeof(Task));
				add_tasks(T, &N);
				break;
			case 2:
				printf("Choisir votre mode d'utilisation (Saisir le nombre): \n");
				printf("1. Trier les taches par ordre alphabetique \n");
				printf("2. Trier les taches par deadline \n");
				printf("3. Afficher les taches dont le deadline est dans 3 jours ou moins \n");
				printf("0. Quitter\n");
				scanf("%d", &operation);
				if(operation == 1){
					sort_by_alphabet(T, N);
				} else if(operation == 2){
					sort_by_deadline(T, N);
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
				printf("2. Modifier le statut d'une tache \n");
				printf("3. Modifier le deadline d'une tache \n");
				printf("0. Quitter\n");
				scanf("%d", &operation);
				if(operation == 1){
					printf("Choisir la tache que vous voulez modifer (Saisir l'identifiant): \n");
					scanf("%d", &id);
					edit_description(T, N, id);
				} else if(operation == 2){
					printf("Choisir la tache que vous voulez modifer (Saisir l'identifiant): \n");
					scanf("%d", &id);
					edit_statut(T, N, id);
				} else if(operation == 3){
					printf("Choisir la tache que vous voulez modifer (Saisir l'identifiant): \n");
					scanf("%d", &id);
					edit_deadline(T, N, id);
				} else if(operation == 0){
					mode = 0;
				} else{
					printf("\nChoix Invalide.\n");
				}
				break;
			case 4:
				printf("Choisir la tache que vous voulez supprimer (Saisir l'identifiant): \n");
				scanf("%d", &id);
				delete_by_id(T, &N, id);
				break;
			case 5:
				printf("Choisir votre mode d'utilisation (Saisir le nombre): \n");
				printf("1. Rechercher une tache par son Identifiant \n");
				printf("2. Rechercher une tache par son Titre \n");
				printf("0. Quitter\n");
				scanf("%d", &operation);
				if(operation == 1){
					printf("Saisir l'identifiant: \n");
					scanf("%d", &id);
					search_by_id(T, N, id);
				} else if(operation == 2){
					printf("Saisir le titre: \n");
					char title_to_search[50];
					scanf("%s", title_to_search);
					search_by_title(T, N, title_to_search);
				} else if(operation == 0){
					mode = 0;
				} else{
					printf("\nChoix Invalide.\n");
				}
				break;
			case 6:
				printf("Choisir votre mode d'utilisation (Saisir le nombre): \n");
				printf("1. Afficher le nombre total des taches \n");
				printf("2. Afficher le nombre de taches completes et incompletes \n");
				printf("3. Afficher le nombre de jours restants jusqu'au delai de chaque tache \n");
				printf("0. Quitter\n");
				scanf("%d", &operation);
				if(operation == 1){
					printf("Nombre total de taches : %d\n", N);
				} else if(operation == 2){
					show_completed_incompleted_tasks(T, N);
				} else if(operation == 3){
					show_days_remaining(T, N);
				} else if(operation == 0){
					mode = 0;
				} else{
					printf("\nChoix Invalide.\n");
				}
				break;
			default:
				printf("\nChoix Invalide.\n");
		}
	}while(mode!=0);

	free(T);

	return 0;
}