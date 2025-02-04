/*
    Si scriva una funzione che, dato un array in input, restituisca due puntatori all'elemento con valore massimo ed a quello
    con valore minimo. Si scriva, quindi, un programma che, generato un array di lunghezza N, inserita da tastiera, e riempito
    con numeri reali casuali, stampi a video l'array e I valori degli elementi associati ai puntatori restituiti dalla funzione
    realizzata.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_array(int *v, int N);
void max_min(int *min, int *max, int *v, int N);

int main()
{
    int N = 0;
    printf("N: ");
    scanf("%d", &N);
    int *v = malloc(sizeof(int) * N);
    populate_array(v, N);

    int max, min;
    max_min(&min, &max, v, N);

    free(v);
    return 0;
}

void populate_array(int *v, int N)
{
    srand(time(NULL));
        for (int i = 0; i < N; i++)
        {
            v[i] = rand() % 100 + 1;
            printf("%d ", v[i]);
        }
}

void max_min(int *min, int *max, int *v, int N)
{
    *max = v[0];
    *min = v[0];
    for (int i = 0; i < N; i++)
    {
        if ( *max < v[i] )
            *max = v[i];

        if ( *min > v[i] )
            *min = v[i];
    }

    printf("\nMin: %d\n", *min);
    printf("Max: %d\n", *max);
}