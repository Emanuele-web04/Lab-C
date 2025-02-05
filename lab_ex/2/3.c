/*
    Si scriva una funzione ricorsiva che, data in input una sequenza di N numeri interi generati casualmente e compresi tra 10 e 20, 
    stampi la sequenza al contrario restituendo, inoltre, un valore che indichi se esistono duplicati nella lista.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_array(int *v, int N);
void reverse_display(int *v, int N, int i, int *same);

int main()
{
    int N = 0;
    printf("N: ");
    scanf("%d", &N);

    srand(time(NULL));
    int *v = malloc(sizeof(int) * N);
    populate_array(v, N);

    int same = 0, i = -1, boh = 0;

    reverse_display(v, N, i, &same);
    same == 0 ? printf("No double\n") : printf("Double is: %d\n", same);

    free(v);
    return 0;
}

void populate_array(int *v, int N)
{
    for (int i = 0; i < N; i++)
    {
        v[i] = rand() % 11 + 10;
        printf("%d ", v[i]);
    }
}

void reverse_display(int *v, int N, int i, int *same)
{
    if (i == N - 1) return;

    for (int j = i + 1; j < N; j++)
        if ( v[i] == v[j] )
            *same = v[i];
  
    reverse_display(v, N, ++i, same);
    printf("\n%d", v[i]);
}