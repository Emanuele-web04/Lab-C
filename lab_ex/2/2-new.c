/*
    Si scriva un programma che, letto da un file di testo un elenco di impiegati identificati da
    nome, cognome, numero di matricola e salario, stampi a video il nome, il cognome e il numero di matricola
    dell'impiegato o degli impiegati con il salario più alto.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Employee Employee;
struct Employee {
    char name[30];
    int id;
    int salary;
};

int main()
{
    Employee e;
    Employee max;

    max.salary = 0;

    FILE * file;
    file = fopen("employees.txt", "r");

    while ( fscanf(file, "%[^\n] %d %d", e.name, &e.id, &e.salary) == 3 )
    {
        if (max.salary < e.salary)
            max = e;
    }

    printf("Richer:\n%s, %d, %d\n", max.name, max.id, max.salary);

    fclose(file);
    return 0;
}