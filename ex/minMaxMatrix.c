/*
    Scrivere un programma C che:
    1) Prende da linea di comando due interi n e m, e n*m interi successivi.
    Alloca una matrice di interi M di dimensioni nxm e la inizializza con gli
    interi letti in input

    2) Implementa la funzione
    mini_max_pari_dispari(int **M, int n, int m, int *row, int *col)
    che individua la riga la cui somma degli elementi sia minima
    e la colonna la cui somma degli elementi sia massima


    input:
        3 4 12 33 22 11 3 67 1 23 76 34 12 1
    output:
        La riga con somma minima e': 0
        La colonna con somma massima e': 1
*/

#include <stdio.h>
#include <stdlib.h>

void take_dim(int *R, int *C);
int **create_matrix(int R, int C);
void display_matrix(int **mat, int R, int C);
void min_max_row_col(int **mat, int R, int C, int* min_R, int* max_C);
void free_matrix(int **mat, int R);
int main()
{
    // Prende da linea di comando due interi r e c
    int R, C;
    take_dim(&R, &C);

    int **mat = create_matrix(R, C);
    display_matrix(mat, R, C);

    int min_R, max_C;
    min_max_row_col(mat, R, C, &min_R, &max_C);

    printf("\nMin row: %d\nMax col: %d\n", min_R, max_C);

    free_matrix(mat, R);
    return 0;
}

void take_dim(int *R, int *C)
{
    printf("Insert R: ");
    scanf("%d", R);

    printf("Insert C: ");
    scanf("%d", C);
}

int **create_matrix(int R, int C)
{
    int **mat;
    // for allocating, you need to allocate for the rows first, 
    mat = malloc(sizeof(int*) * R);
    // and then for every row, you allocate for the columns in the rows
    for (int i = 0; i < R; i++)
        mat[i] = malloc(sizeof(int) * C);

    int input = 0;
    for (int i = 0; i < ( R * C ); i++)
    {
        printf("Input nella casella (%d, %d): ", i / C, i % C);
        scanf("%d", &input);

        mat[i / C][i % C] = input;
    }

    return mat;
}

void display_matrix(int **mat, int R, int C)
{
    for ( int i = 0; i < ( R * C ); i++ )
        printf("%d ", mat[i / C][i % C]);
}

void min_max_row_col(int **mat, int R, int C, int *min_R, int *max_C)
{
    // per le row abbiamo i / C e sommiamo tutti questi
    // per le columns abbiamo i % C e sommiamo tutti
    int row_sum = 0;
    int col_sum = 0;
    int max_sum = -__INT_MAX__;
    int min_sum = __INT_MAX__;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            row_sum += mat[i][j];
        }
        if ( row_sum < min_sum )
        {
            min_sum = row_sum;
            *min_R = i;
        }
        row_sum = 0;
    } 

    for(int j = 0; j < C; j++)
    {
        for(int i = 0; i < R; i++)
        {
            col_sum += mat[i][j];
        }
        if ( col_sum > max_sum )
        {
            max_sum = col_sum;
            *max_C = j;
        }
        col_sum = 0;
    } 
}

void free_matrix(int **mat, int R)
{
    // per liberare una matrice ragioni col senso opposto
    // ci sono 2 puntatori, ergo 2 address
    // il primo sono le rows che puntano alle columns, e il resto é la matrice che punta alle rows
    for (int i = 0; i < R; i++)
        free(mat[i]);

    free(mat);
}