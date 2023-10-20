#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

struct task{
    char description[100];
    int is_done; // 1 pour complète, 0 pour incomplète
};

//Ajouter une tâche
void add(struct task list[], int *task_number){

    if(*task_number < MAX_TASKS){
        printf("Quelle est la description de votre tâche ? \n");
        scanf(" %[^\n]",list[*task_number].description);
        list[*task_number].is_done = 0;
        (*task_number)++;
        printf("Votre tâche a été ajoutée à la liste. \n");
    } else {
        printf("La liste des tâche est pleine. \n");
    }
}

// Afficher la liste entière
void show_list(struct task list[], int task_number){

    if (task_number == 0){
        printf("Il n'y a actuellement aucune tâche dans la liste. \n");
    } else {
        printf("Liste des tâches :\n");
        for (int i = 0; i < task_number; i++) {
            printf("%d. %s [%s]\n", i + 1, list[i].description, list[i].is_done ? "Complète" : "Non complète");
        }
    }
}

//Marquer une tâche comme complète
void done(struct task list[], int task_number){
    int value;
    show_list(list, task_number);

    if (task_number == 0) {
        return;
    }

    printf("Entrez le numéro de la tâche à marquer comme complète : ");
    scanf("%d",&value);

    if (value >= 1 && value <= task_number) {
        list[value-1].is_done = 1;
        printf("La tâche a bien été marquée comme complète. \n");
    } else {
        printf("Numéro de tâche invalide. \n");
    }
}

//Lister les tâches non terminées
void task_to_do (){

}

//Lister les tâches terminées
void task_done (){

}

int main () {
    struct task list[MAX_TASKS];
    int task_number = 0;
    int choice;

    while (1) {
        printf("\nMenu :\n");
        printf("1. Ajouter une tâche\n");
        printf("2. Marquer une tâche comme complète\n");
        printf("3. Afficher la liste de toutes les tâches\n");
        printf("4. Afficher la liste des tâches non effectuées\n");
        printf("5. Afficher la liste des tâches terminées\n");
        printf("6. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(list, &task_number);
                break;
            case 2:
                done(list, task_number);
                break;
            case 3:
                show_list(list, task_number);
                break;
            case 4:
                task_to_do(list, task_number);
                break;
            case 5:
                task_done(list, task_number);
                break;
            case 6:
                printf("Au revoir !\n");
                exit(0);
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }
    return 0;
}