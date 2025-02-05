/*
  Si scriva una funzione che restituisca una matrice di dimensione NxN, 
  con N dato in input da tastiera e inizializzata con un intero casuale tra 0 e 100, in ogni casella. 
  Ottenuta la matrice, si stabilisca se la somma dei numeri su ogni riga è pari o dispari tramite un'altra funzione.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **create_matrix(int N);
void display_mat(int **mat, int N);
void free_mat(int **mat, int N);
void check_odd_even(int **mat, int N);

int main()
{
    int N = 0;
    printf("N: ");
    scanf("%d", &N);

    int **mat = NULL;
    mat = create_matrix(N);
    display_mat(mat, N);
    check_odd_even(mat, N);

    free_mat(mat, N);
    return 0;
}

int **create_matrix(int N)
{
    int **mat = malloc(sizeof(int*) * N);
    for (int i= 0; i < N; i++)
        mat[i] = malloc(sizeof(int) * N);

    srand(time(NULL));

    for (int i = 0; i < (N * N); i++)
        mat[i / N][i % N] = rand() % 100;

    return mat;
}

void display_mat(int **mat, int N)
{
    for (int i = 0; i < (N * N); i++)
        printf("%d ", mat[i / N][i % N]);
}

void check_odd_even(int **mat, int N)
{
    int sum_row = 0;
    for (int i = 0; i < N; i++)
    { 
        for (int j = 0; j < N; j++)
        {
            sum_row += mat[i][j];
        }
        printf("\nSum Row %d: %s", i, ( sum_row % 2 == 0 ) ? "Even" : "Odd");
        sum_row = 0;
    }
}

void free_mat(int **mat, int N)
{
    for (int i = 0; i < N; i++)
        free(mat[i]);

    free(mat);
}