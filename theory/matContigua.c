#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

int main()
{   
    srand(time(NULL));
    int *mat = malloc(sizeof(int) * (N * N));
    for (int i = 0; i < N * N; i++)
    {
        mat[i] = rand() % 10;
        printf("%d\n", mat[i]);
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d\t", mat[i * N + j]);

        printf("\n\n");
    }

    return 0;
}