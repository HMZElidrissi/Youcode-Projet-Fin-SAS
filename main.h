#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    A_REALISER,
    EN_COURS,
    FINALISEE  
} Statut;

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
    Date start_date;
    Date end_date;
    Statut statut;
};
typedef struct task Task;

//Ajouter nouvelles taches
void add_tasks(Task *T, int N){
	int drp, i, j;
    for (i = 0; i < N; i++) {
        do{
        	//On commence par le Id_task en respectant la condition qu’il soit unique
        	printf("\nSaisir l'identifiant du tache: ");
        	scanf("%d", &T[i].Id_task);
        	drp = 0;
        	for(j = 0; j < i; j++){
        		if(T[j].Id_task == T[i].Id_task){
        			drp = 1;
        			break;
				}
			}
		}while(drp == 1);
		
		printf("Saisir le titre de la tache: ");
		getchar();
		gets(T[i].title);

        printf("Saisir la description de la tache: ");
        getchar();
        gets(T[i].description);

        printf("Saisir la date de debut de la tache: (jj-mm-aaaa) ");
        scanf("%d-%d-%d", &T[i].start_date.day, &T[i].start_date.month, &T[i].start_date.year);
        
        printf("Saisir la date de fin de la tache: (jj-mm-aaaa) ");
        scanf("%d-%d-%d", &T[i].end_date.day, &T[i].end_date.month, &T[i].end_date.year);

        printf("Saisir le statut de la tache: (0 pour A realiser, 1 pour en cours de realisation, 2 pour finalisee) ");
        scanf("%d", (int *)&T[i].statut);
    }
}

//Afficher une tache
void show_task(Task task) {
    printf("Identifiant de la tache: %d\n", task.Id_task);
    printf("Titre de la tache: %s\n", task.title);
    printf("Description de la tache: %s\n", task.description);
    printf("Date de debut: %d-%d-%d\n", task.start_date.day, task.start_date.month, task.start_date.year);
    printf("Date de fin: %d-%d-%d\n", task.end_date.day, task.end_date.month, task.end_date.year);
    
    switch (task.statut) {
        case 0:
            printf("\nStatut de la tache: A realiser\n");
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
	}
}

//Trier les tâches par ordre alphabétique
void alphabetical_sort(Task *T, int N){
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

//calculer le délai d'une tâche
int deadline(Task task) {
    int days1 = task.start_date.year * 365 + task.start_date.month * 30 + task.start_date.day;
    int days2 = task.end_date.year * 365 + task.end_date.month * 30 + task.end_date.day;

    int difference = labs(days2 - days1);
    return difference;
}


//Trier les tâches par deadline
void deadline_sort(Task *T, int N){
	int i,j;
	Task tmp;
	for(i = 0; i < N - 1; i++)
		for (j = 0; j < N - i - 1; j++){
			if(deadline(T[j]) > deadline(T[j+1])){
				tmp = T[j];
				T[j] = T[j+1];
				T[j+1] = tmp;
			}
		}
	show_tasks(T, N);
}

//Afficher les tâches dont le deadline est dans 3 jours ou moins
void display_tasks_within_three_days(Task *T, int N){
	int i;
	Task tmp;
	for(i = 0; i < N; i++){
		if(deadline(T[i]) <= 3){
			show_task(T[i]);
		}
	}
}

//Modifier la description d'une tâche
void edit_description(Task *T, int N){
}

//Modifier le statut d’une tâche
void edit_statut(Task *T, int N){
}

//Modifier le deadline d’une tâche
void edit_deadline(Task *T, int N){
}

//Supprimer une tâche par identifiant
void delete_by_id(int id){
}

//Rechercher une tâche par son Identifiant
void search_by_id(Task *T, Task x){
}

//Rechercher une tâche par son Titre
void search_by_title(Task *T, Task x){
}

//le nombre total des tâches
int tasks_total_number(Task *T){
}

//le nombre de tâches incomplètes
int incomplete_tasks(Task *T){
}

//le nombre de tâches complètes
int complete_tasks(Task *T){
}

//le nombre de jours restants jusqu'au délai de chaque tâche
void remaining_days_tasks(Task *T){
}
