/*
    Si scriva un programma che, generata casualmente una matrice di numeri reali compresi tra 0 e 100 di dimensione NxN, con N dato da tastiera,    
    stabilisca se la somma dei numeri al di sopra della diagonale principale è maggiore di quella dei numeri al di sotto della diagonale principale.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **create_matrix(int N);
void display_mat(int **mat, int N);
void diagonal_check(int **mat, int N);
void free_mat(int N, int **mat);

int main()
{
    int N = 0;
    printf("Inserisci N: ");
    scanf("%d", &N);

    srand(time(NULL));
    int **mat = NULL;
    mat = create_matrix(N);
    display_mat(mat, N);
    diagonal_check(mat, N);

    free_mat(N, mat);
    return 0;
}

int **create_matrix(int N)
{   
    int **mat = malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++)
        mat[i] = malloc(sizeof(int) * N);

    for (int i = 0; i < N * N; i++)
        mat[i / N][i % N] = rand() % 100;

    return mat;
}

void display_mat(int **mat, int N)
{
    for (int i = 0; i < N * N; i++)
    {
        printf("%d\t", mat[i / N][i % N]);
        if ((i + 1) % N == 0) printf("\n");
    }
}

void diagonal_check(int **mat, int N)
{
    int upper = 0, lower = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ( j > i ) upper += mat[i][j];
            else if ( j < i ) lower += mat[i][j];
        }
    }
    printf("\nUpper: %d\nLower: %d\n", upper, lower);
    printf("\n%s is greater\n", upper > lower ? "Upper" : "Lower");
}

void free_mat(int N, int **mat)
{
    for(int i = 0; i < N; i++)
        free(mat[i]);

    free(mat);
}