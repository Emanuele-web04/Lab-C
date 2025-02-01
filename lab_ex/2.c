/*
    Si scriva un programma che, 
    generata casualmente una matrice di numeri reali compresi tra 0 e 100 di dimensione NxN, con N dato da tastiera, 
    stabilisca se la somma dei numeri al di sopra della diagonale principale è maggiore di quella dei numeri al di sotto della diagonale principale.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void assign_matrix_values(int N, int **mat);
void print_matrix(int N, int **mat);
void upper_diagonal(int *upper, int N, int **mat);
void invert_matrix(int N, int invMat[N][N], int **mat);
void down_diagonal(int *down, int N, int invMat[N][N]);
int main() 
{
    // la funzione srand si prende un unsigned seed che inizializza poi la rand()
    srand(time(NULL));
    int N;
    printf("Inserisci N: ");
    scanf("%d", &N);

    // alloca le rows
    int **mat = malloc(N * sizeof(int*));

    if (!mat) 
        exit(0);

    // alloca le col
    for(int i = 0; i < N; i++)
    {
        mat[i] = malloc(sizeof(int) * N);
        if (!mat[i]) 
            exit(0);
    }

    assign_matrix_values(N, mat);

    print_matrix(N, mat);
    
    // devo partire da 0 fino ad R - 1 e prendere i valori di C - 1
    // 1 2 /
    // 4 / /
    // / / /
    int R = N;
    int C = N;
    int count = 0;
    int upper[N];
    int *upperDiag;
    for(int i = 0; i < (C - 1); i++)
    {
        for(int i = 0; i < (R - 1); i++)
        {
            upperDi
            upperDiag = realloc(upperDiag, sizeof(int) )
            count++;
        }
        R--;
    }

    upperDiag = malloc(sizeof(int) * count);
    R = N;
    C = N;
    int step = 0;
    for(int j = 0; j < (C - 1); j++)
    {
        for(int i = 0; i < (R - 1); i++)
        {
            upperDiag[step] = mat[i][j];
            printf("\nmat[%d][%d] = %d", i, j, mat[i][j]);
            step++;
        }
        R--;
    }

    printf("\nUPPER:\t");
    for(int i = 0; i < count; i++)
        printf("%d, ", upperDiag[i]);

    printf("COUNT: %d", count);
    upper_diagonal(upper, N, mat);

    int totalUp = 0;
    for(int i = 0; i < N; i++)
       totalUp += upper[i];

    printf("\n\n%d\n", totalUp);
    // inverto la matrice perché non so come altro fare
    int invMat[N][N];
    
    // part da N * N -1 e arrivo a 0
    invert_matrix(N, invMat, mat);


    int down[N];
    down_diagonal(down, N, invMat);

    printf("\n");

    int totalDown = 0;
    for(int i = 0; i < N; i++)
       totalDown += down[i];

    printf("%d\n", totalDown);

    totalUp > totalDown ? printf("Upper\n") : printf("Down\n");

    // free mat
    for(int i = 0; i < N; i++)
        free(mat[i]);

    free(upperDiag);
    return 0;
}

void assign_matrix_values(int N, int **mat) 
{
    for(int i = 0; i < (N * N); i++) 
        mat[i / N][i % N] = rand() % 100;
}

void print_matrix(int N, int **mat) 
{
    for(int i = 0; i < (N * N); i++) 
    {
        if (i % N == 0)
            printf("\n");
        
        printf("%d\t", mat[i / N][i % N]);
    }
}

void upper_diagonal(int *upper, int N, int **mat) 
{
    for(int i = 0; i < ((N - 1) * (N - 1)); i++)
        upper[i] = mat[i / (N - 1)][i % (N - 1)];
}

void invert_matrix(int N, int invMat[N][N], int **mat)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            invMat[(N - 1) - i][(N - 1) - j] = mat[i][j];
}

void down_diagonal(int *down, int N, int invMat[N][N]) 
{
    for(int i = 0; i < ((N - 1) * (N - 1)); i++)
        down[i] = invMat[i / (N - 1)][i % (N - 1)];
}