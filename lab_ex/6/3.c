/*
    Si scriva un programma che consenta di Inserire un numero non precisato inizialmente di record rappresentanti gli studenti
    di un corso. Per ogni studente, sia possibile inserire nome, cognome e, nel caso in cui l'esame sia stato superato, il voto
    ottenuto. Scrivere, quindi, una funzione che, data in input la struttura dati contenente i record degli studenti, stampi a
    video la percentuale di studenti che hanno superato l'esame e quella di coloro che non lo hanno superato.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;
struct Student {
    char name[50];
    char surname[50];
    int score;
};

void add_student(Student *students, int *size);
void input(Student* student, char *stop);
void check_allocation(Student *students);
int passed_exams(Student *students, int size);
int main()
{
    int size = 1;
    Student *students = malloc(sizeof(Student) * (size));
    check_allocation(students);
    
    add_student(students, &size);

    int percent = passed_exams(students, size);
    printf("Studenti promossi: %d\n", percent);

    free(students);
    return 0;
}

void check_allocation(Student *students)
{
    if ( !students ) exit(0);
}

void add_student(Student *students, int *size)
{
    char stop;
    while ( 1 )
    {
        input(students, &stop);
        if ( stop == 'y' ) break;
        *(size) += 1;
        students = realloc(students, sizeof(Student) * *(size));
        check_allocation(students);
    }
}

void input(Student* students, char *stop)
{
    printf("Score < 18 per bocciare\n");

    printf("Name: ");
    scanf("%s", students->name);
    fflush(stdin);  // Pulisce il buffer

    printf("Surname: ");
    scanf("%s", students->surname);
    fflush(stdin);  // Pulisce il buffer

    printf("Score: ");
    scanf(" %d", &students->score);
    fflush(stdin);  // Pulisce il buffer

    printf("Do you want to stop? (y/n) ");
    scanf(" %c", stop);
    fflush(stdin);  // Pulisce il buffer
}


int passed_exams(Student *students, int size)
{
    int total_scores = size;
    int passed = 0;
    for (int i = 0; i < size; i++)
        if ( students[i].score >= 18 )
            passed += 1;

    int percentage = ( passed / total_scores ) * 100;

    return percentage;
}