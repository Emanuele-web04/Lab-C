/*
    Si scriva una funzione che restituisca una matrice di dimensione NxN, con N dato in input da tastiera e inizializzata con 0 o con 1, in ogni casella, in maniera casuale. 
    Si costruisca la matrice in maniera tale che la probabilità che venga assegnato un 1 in ogni casella sia del 70% e che la probabilita che venga assegnato 0 del 30%.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_mat(int **mat, int N);
int **init_matrix(int N);
void assign_values(int **mat, int N);
void free_mat(int N, int **mat);
int main()
{ 
    int N = 0;
    printf("N: ");
    scanf("%d", &N);
    srand(time(NULL));
    int **mat = NULL;

    mat = init_matrix(N);

    printf("\n");
    assign_values(mat, N);

    free_mat(N, mat);
    return 0;
}

int **init_matrix(int N)
{   
    int **mat = malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++)
        mat[i] = malloc(sizeof(int) * N);

    // init la matrice
    for (int i = 0; i < N * N; i++)
        mat[i / N][i % N] = rand() % 2;

    display_mat(mat, N);
    return mat;
}

void display_mat(int **mat, int N)
{
    for(int i = 0; i < N * N; i++)
    {
        printf("%d ", mat[i / N][i % N]);
        if ((i + 1) % N == 0) printf("\n");
    }
}

void assign_values(int **mat, int N)
{
    int seventy = (N * N) * 0.70;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (count <= seventy) mat[i][j] = 1;
            else mat[i][j] = 0;
            count++;
        }
    }

    display_mat(mat, N);
}

void free_mat(int N, int **mat)
{
    for(int i = 0; i < N; i++)
        free(mat[i]);

    free(mat);
}