#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct date {
    int day;
    int month;
    int year;
};
typedef struct date Date;

struct task {
    int Id_task;
    char title[50];
    char description[100];
    Date deadline;
    int statut;
};
typedef struct task Task;

//Ajouter nouvelles taches
void add_tasks(Task *T, int *N){
	int new_task;
	int flag, i;
	T = (Task *)realloc(T, ((*N) + 1) * sizeof(Task));
    do{
        do{
        	//On commence par le Id_task en respectant la condition qu'il soit unique
        	printf("\nSaisir l'identifiant du tache: ");
        	scanf("%d", &T[*N].Id_task);
        	flag = 0;
        	for(i = 0; i < *N; i++){
        		if(T[i].Id_task == T[*N].Id_task){
        			flag = 1;
        			break;
				}
			}
		}while(flag == 1);
		
		printf("Saisir le titre de la tache: ");
		getchar();
		gets(T[*N].title);

        printf("Saisir la description de la tache: ");
        gets(T[*N].description);

        do{
        printf("Saisir la deadline de la tache: (jj-mm-aaaa) ");
        scanf("%d-%d-%d", &T[*N].deadline.day, &T[*N].deadline.month, &T[*N].deadline.year);
		}while(T[*N].deadline.day > 31 || T[*N].deadline.month > 12 || T[*N].deadline.year > 2050);
		
		do{
			printf("Saisir le statut de la tache: (0 pour A realiser, 1 pour en cours de realisation, 2 pour finalisee) ");
			scanf("%d", &T[*N].statut);
		}while(T[*N].statut < 0 && T[*N].statut > 2);

		(*N)++;

		printf("\nVoulez vous ajouter une autre tache ? (1 pour Oui, 0 pour Non) : ");
        scanf("%d", &new_task);
    }while(new_task == 1);
}

//Afficher une tache
void show_task(Task task) {
    printf("\nIdentifiant de la tache: %d\n", task.Id_task);
    printf("Titre de la tache: %s\n", task.title);
    printf("Description de la tache: %s\n", task.description);
    printf("Deadline: %d-%d-%d\n", task.deadline.day, task.deadline.month, task.deadline.year);
    
    switch (task.statut) {
        case 0:
            printf("Statut de la tache: A realiser\n");
            break;
        case 1:
            printf("Statut de la tache: En cours de realisation\n");
            break;
        case 2:
            printf("Statut de la tache: Finalisee\n");
            break;
        default:
            printf("Statut de la tache: Inconnu\n");
    }
}

//Afficher les taches
void show_tasks(Task *T, int N){
	int i;
	for(i = 0; i < N; i++){
		show_task(T[i]);
		printf("\n");
	}
}

//Trier les taches par ordre alphabetique
void sort_by_alphabet(Task *T, int N){
	int i,j;
	Task tmp;
	for(i = 0; i < N - 1; i++)
		for (j = 0; j < N - i - 1; j++){
			if(strcmp(T[j].title, T[j+1].title) > 0){
				tmp = T[j];
				T[j] = T[j+1];
				T[j+1] = tmp;
			}
		}
	show_tasks(T, N);
}

//calculer le delai d'une tache
int deadline(Task task, Date current_date) {
    int days1 = current_date.year * 365 + current_date.month * 30 + current_date.day;
    int days2 = task.deadline.year * 365 + task.deadline.month * 30 + task.deadline.day;

    int difference = labs(days2 - days1);
    return difference;
}

//Trier les taches par deadline
void sort_by_deadline(Task *T, int N, Date current_date){
	int i,j;
	Task tmp;
	for(i = 0; i < N - 1; i++)
		for (j = 0; j < N - i - 1; j++){
			if(deadline(T[j], current_date) > deadline(T[j+1], current_date)){
				tmp = T[j];
				T[j] = T[j+1];
				T[j+1] = tmp;
			}
		}
	show_tasks(T, N);
}

//Afficher les taches dont le deadline est dans 3 jours ou moins
void display_tasks_within_three_days(Task *T, int N, Date current_date){
	int i;
	for(i = 0; i < N; i++){
		if(deadline(T[i], current_date) <= 3){
			show_task(T[i]);
		}
	}
}

//Rechercher une tache par son Identifiant et retourner son indice
int find_task(Task *T, int N, int id){
	int i = 0;
	while(i < N && id != T[i].Id_task){
		i++;
	}
	if(i < N){
		return i;
	} else {
		return -1;
	}
}

//Rechercher une tache par son Identifiant
void search_by_id(Task *T, int N, int id){
	int S = find_task(T, N, id);
	if(S < N && S != -1){
		show_task(T[S]);
	} else{
		printf("\nTache non trouve!!");
	}
}

//Rechercher une tache par son Titre
void search_by_title(Task *T, int N, char title[50]){
	int i = 0;
	while(i < N && strcmp(title, T[i].title) != 0){
		i++;
	}
	if(i < N && i != -1){
		show_task(T[i]);
	} else{
		printf("\nTache non trouve!!");
	}
}

//Modifier la description d'une tache
void edit_description(Task *T, int N, int id){
	int S = find_task(T, N, id);
    if (S < N && S != -1) {
		char new_description[100];
	    printf("\nSaisir la nouvelle description de la tache: ");
	    getchar();
	    gets(new_description);
	    strcpy(T[S].description, new_description);
		show_task(T[S]);
    } else {
        printf("\nTache non trouve!!");
    }
}

//Modifier le statut d'une tache
void edit_statut(Task *T, int N, int id){
    int S = find_task(T, N, id);
    if (S < N && S != -1) {
        int new_statut;
        printf("\nSaisir le nouveau statut de la tache: (0 pour A realiser, 1 pour en cours de realisation, 2 pour finalisee) ");
        scanf("%d", &new_statut);
        T[S].statut = new_statut;
		show_task(T[S]);
    } else {
        printf("\nTache non trouve!!");
    }
}

//Modifier le deadline d'une tache
void edit_deadline(Task *T, int N, int id){
	int S = find_task(T, N, id);
    if (S < N && S != -1) {
        Date new_deadline;
        printf("\nSaisir la nouvelle deadline de la tache: (jj-mm-aaaa) ");
        scanf("%d-%d-%d", &new_deadline.day, &new_deadline.month, &new_deadline.year);
        T[S].deadline.day = new_deadline.day;
        T[S].deadline.month = new_deadline.month;
        T[S].deadline.year = new_deadline.year;
		show_task(T[S]);
    } else {
        printf("\nTache non trouve!!");
    }
}

//Supprimer une tache par identifiant
void delete_by_id(Task *T, int *N, int id_to_delete){
    int S = find_task(T, *N, id_to_delete);
    int i;
    if (S < *N && S != -1) {
        for(i = S; i < (*N) - 1; i++){
        	T[i] = T[i+1];
		}
		(*N)--;
		T = (Task *)realloc(T, (*N) * sizeof(Task));
		printf("Tache avec l'identifiant %d supprimee.\n", id_to_delete);
    } else {
        printf("Tache non trouve!!");
    }
}

// Afficher le nombre de taches completes et incompletes
void show_completed_incompleted_tasks(Task *T, int N) {
	int i;
    int completed = 0;
    int incompleted = 0;
    for (i = 0; i < N; i++) {
        if (T[i].statut == 2) {
            completed++;
        } else {
            incompleted++;
        }
    }
    printf("\nNombre de taches completes : %d\n", completed);
    printf("Nombre de taches incompletes : %d\n", incompleted);
}

// Afficher le nombre de jours restants jusqu'au delai de chaque tache
void show_days_remaining(Task *T, int N, Date current_date) {
	int i;
    for (i = 0; i < N; i++) {
        if (deadline(T[i], current_date) >= 0) {
            printf("\nTache %d : Jours restants jusqu'au delai : %d\n", T[i].Id_task, deadline(T[i], current_date));
        } else {
            printf("Tache %d : Delai depasse de %d jours\n", T[i].Id_task, deadline(T[i], current_date));
        }
    }
}
