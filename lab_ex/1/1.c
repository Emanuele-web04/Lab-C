/*
    Si scriva una funzione ricorsiva che, data in input una lista di numeri interi, 
    stabilisca se la lista è ordinata in maniera strettamente decrescente. 
    Si testi, quindi, la funzione nel main.
*/

#include <stdio.h>
#include <stdlib.h>

void insert(int *v, int N);
void check_decrescending(int *v, int N, int i, int *count);

int main()
{
    int N;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &N);

    int *v = malloc(sizeof(int) * N);
    if ( !v ) return -1;

    insert(v, N);

    int i = 0, count = 0;
    check_decrescending(v, N, i, &count);

    count == ( N - 1 ) ? printf("List is decrescending\n") : printf("List is not decrescending\n");

    free(v);
    return 0;
}

void insert(int *v, int N)
{
    int input = 0;
    for (int i = 0; i < N; i++)
    {
        printf("Inserisci n%d: ", i + 1);
        scanf("%d", &input);

        v[i] = input;
    }
}

void check_decrescending(int *v, int N, int i, int *count)
{
    // il caso base é quando finisce l'array e ritorna l'ultimo elemento
    if ( i == N - 1 ) return;

    if ( v[i] > v[i + 1] ) *(count) += 1;
    printf("%d > %d; Count: %d\n", v[i], v[i + 1], *count);
    check_decrescending(v, N, ++i, count);
}