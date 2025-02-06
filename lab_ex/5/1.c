/*
    Si scriva un programma che, dati in input N numeri reali da tastiera, stabilisca quali, tra i
    numeri inseriti, sono multipli di qualche altro numero inserito.
*/

#include <stdio.h>
#include <stdlib.h>

int *populate_array(int N);
void check_for_multiple(int *v, int N);

int main()
{
    int N = 0;
    printf("N: ");
    scanf("%d", &N);

    int *v = NULL;
    v = populate_array(N);
    check_for_multiple(v, N);
    free(v);
    return 0;
}

int *populate_array(int N)
{
    int *v = malloc(sizeof(int) * N);
    int input = 0;
    for(int i = 0; i < N; i++)
    {
        printf("Inserisci: ");
        scanf("%d", &input);

        v[i] = input;
    }

    return v;
}

void check_for_multiple(int *v, int N)
{
    int multiple = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (i != j && v[i] % v[j] == 0) multiple = v[i];
        }
        printf("multiple: %d\n", multiple);
        multiple = 0;
    }
}