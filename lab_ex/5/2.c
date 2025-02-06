/*
    Si scriva un programma che, dati in input un numero N di righe ed un numero M di colonne,
    generi una matrice NxM di numeri interi casuali compresi tra 0 e 100, Il programma
    stabilisca, quindi, quali cele contengono un masimo locale (un numero maggiore di tutti i
    numeri contenuti nelle celle adiacenti).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_MAX 100
#define RANGE_MIN 0

int **create_mat(int R, int C);
void local_max(int **mat, int R, int C);
void free_mat(int **mat, int R);

int main()
{ 
    int R = 0, C = 0;
    srand(time(NULL));
    printf("Rows: ");
    scanf("%d", &R);

    printf("Cols: ");
    scanf("%d", &C);

    int **mat = NULL;
    mat = create_mat(R, C);
    local_max(mat, R, C);
    free_mat(mat, R);
    return 0;
}

int **create_mat(int R, int C)
{
    int **mat = malloc(sizeof(int*) * R);
    for(int i = 0; i < R; i++)
        mat[i] = malloc(sizeof(int) * C);

    for(int i = 0; i < R * C; i++)
        mat[i / C][i % C] = rand() % (RANGE_MAX - RANGE_MIN + 1) + RANGE_MIN;

    for(int i = 0; i < R * C; i++)
    {
        printf("%d ",  mat[i / C][i % C]);
        if ((i + 1) % C == 0) printf("\n");
    }

    return mat;
}

void local_max(int **mat, int R, int C)
{
    int max = mat[0][0];
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {   
            if ( max < mat[i][j] ) max = mat[i][j];
        }
        printf("Max at row %d: %d\n", i, max);
        max = mat[i][0];
    }
}

void free_mat(int **mat, int R)
{
    for(int i = 0; i < R; i++)
        free(mat[i]);

    free(mat);
}