/*
    Si scriva un programma che, dati in input un numero N, 
    generi una matrice NN di numeri interi casuali compresi tra 1 e 100. 
    Il programma stabilisca, quindi, 
    quali celle contengono un massimo locale 
    (un numero maggiore di tutti i numeri contenuti nelle celle adiacenti).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_MAX 100
#define RANGE_MIN 1

int **create_mat(int N);
void free_mat(int **mat, int N);
void find_is_local_max(int **mat, int N);
int main()
{
    int N = 0;
    printf("Matrice con NxN: ");
    scanf("%d", &N);

    srand(time(NULL));
    int **mat = NULL;

    mat = create_mat(N);
    find_is_local_max(mat, N);

    free_mat(mat, N);
    return 0;
}

int **create_mat(int N)
{
    int **mat = malloc(sizeof(int*) * N);
    if (!mat) exit(EXIT_FAILURE);

    for (int i = 0; i < N; i++)
    {
        mat[i] = malloc(sizeof(int) * N);
        if ( !mat[i] ) exit(EXIT_FAILURE);
    }

    for(int i = 0; i < N * N; i++)
        mat[i / N][i % N] = rand() % (RANGE_MAX - RANGE_MIN + 1) + RANGE_MIN;

    for(int i = 0; i < N * N; i++)
    {
        printf("%d\t", mat[i / N][i % N]);
        if ((i + 1) % N == 0) printf("\n");
    }

    return mat;
}

void find_is_local_max(int **mat, int N)
{
    int is_local_max;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            is_local_max = 1;
            for (int row_offset = -1; row_offset <= 1; row_offset++)
            {
                for(int col_offset = -1; col_offset <= 1; col_offset++)
                {
                    if (row_offset == 0 && col_offset == 0)
                        continue;

                    int row_cell = i + row_offset;
                    int col_cell = j + col_offset;

                    if (row_cell >= 0 && row_cell < N && col_cell >= 0 && col_cell < N)
                    {
                        if (mat[row_cell][col_cell] >= mat[i][j])
                        {
                            is_local_max = 0;
                            break;
                        }
                    }
                }
                if ( is_local_max == 0 )
                    break;
            }
            if (is_local_max == 1)
                    printf("Local Max -> %d found @: (%d, %d)\n", mat[i][j], i, j);
        }
    }
}

void free_mat(int **mat, int N)
{   
    for (int i = 0; i < N; i++)
        free(mat[i]);

    free(mat);
}