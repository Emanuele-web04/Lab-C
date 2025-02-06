/*
    Si scriva una funzione che, dato in input un array di interi di lunghezza non prestabilita, consenta di
    inserire in una posizione qualsiasi dell'array un nuovo intero, restituendo l'array modificato alla
    funzione chiamante. 
*/

#include <stdio.h>
#include <stdlib.h>

int *populate_array(int *N);
void display(int *v, int N);
void insert(int *v, int value, int index, int N);
int main()
{
    int *v;
    int N = 0;
    v = populate_array(&N);
    display(v, N);

    int value = 0, index = 0; 
    insert(v, value, index, N);

    display(v, N + 1);

    free(v);
    return 0;
}

int *populate_array(int *N)
{   
    int size = 1;
    int *v = malloc(sizeof(int) * size);
    if ( !v ) exit(0);
    int input = 0;
    printf("-1 to break\n");
    do
    {
        printf("Inserisci valore: ");
        scanf("%d", &input);

        if (input == -1) break;

        v[*N] = input;

        size += 1;
        v = realloc(v, sizeof(int) * size);
        if ( !v ) exit(0);

       *N += 1;
    } while( input != -1 );

    return v;
}

void display(int *v, int N)
{
    for (int i = 0; i < N; i++)
        printf("%d\n", v[i]);
}

void insert(int *v, int value, int index, int N)
{
    printf("Value: ");
    scanf("%d", &value);
    printf("At: ");
    scanf("%d", &index);

    int new_lenght = N + 1;
    v = realloc(v, sizeof(int) * new_lenght);
    
    for (int i = index; i < new_lenght; i++)
    {
        v[i + 1] = v[i];
        v[index] = value;
    }
}