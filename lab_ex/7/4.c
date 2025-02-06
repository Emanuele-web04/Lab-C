/*
    Si scriva un programma che accetti in input un elenco di persone identificate da un numero univoco intero e alle quali siano associate l'età e il grado di istruzione. 
    Il programma salvi l'elenco in un file di testo e legga, quindi, l'elenco dal file salvato stampando la lista registrata.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Person Person;
struct Person {
    int id;
    int age;
    char grade[30];
};

void insert_person(Person *person, int N, FILE * file);

int main()
{
    int N = 0;
    printf("Quante persone vuoi inserire? ");
    scanf("%d", &N);

    FILE * file;
    file = fopen("people.txt", "w");

    Person *people = malloc(sizeof(Person) * N);
    insert_person(people, N, file);
    fclose(file);

    FILE * fptr;
    fptr = fopen("people.txt", "r");
    char buffer[256];
    while( fgets(buffer, 256, fptr) ) printf("%s", buffer);

    fclose(fptr);
    free(people);
    return 0;
}

void insert_person(Person *person, int N, FILE * file)
{
    // devo salvarlo nel file
    // quindi apro il file il write e abbij a scrivr
    for(int i = 0; i < N; i++)
    {
        printf("ID: ");
        scanf("%d", &person -> id);
        

        printf("Age: ");
        scanf("%d", &person -> age);

        printf("Instuction Grade: ");
        scanf("%s", person -> grade);

        fprintf(file, "%d\n%d\n%s\n", person -> id, person -> age, person -> grade);
    }
}