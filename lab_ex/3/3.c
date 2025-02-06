/*
    Si scriva una funzione che restituisca una matrice allocata dinamicamente di dimensione NxN, 
    con N dato in input da tastiera e inizializzata con interi casuali tra 1 e 101, Si calcoli, quindi, la somma
    degli elementi presenti sulle righe dispari della matrice.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 101
#define MIN 1

int **create_matrix(int N);
void calculate_sum_odd_rows(int **mat, int N);
void free_mat(int **mat, int N);

int main()
{
    srand(time(NULL));
    int N = 0;
    printf("N: ");
    scanf("%d", &N);

    int **mat = NULL;
    mat = create_matrix(N);

    calculate_sum_odd_rows(mat, N);

    free_mat(mat, N);
    return 0;
}

int **create_matrix(int N)
{
    int **mat = malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++)
        mat[i] = malloc(sizeof(int) * N);

    for (int i = 0; i < N * N; i++)
        mat[i / N][i % N] = rand() % (MAX - MIN + 1) + 1;

    for(int i = 0; i < N * N; i++)
    {
        printf("%d ", mat[i / N][i % N]);
        if ( (i + 1) % N == 0 ) printf("\n");
    }

    return mat;
}

void calculate_sum_odd_rows(int **mat, int N)
{
    int sum_odd_row = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i % 2 != 0) sum_odd_row += mat[i][j];
        }
        printf("%d\n", sum_odd_row);
        sum_odd_row = 0;
    }    
}

void free_mat(int **mat, int N)
{
    for(int i = 0; i < N; i++)
        free(mat[i]);

    free(mat);
}