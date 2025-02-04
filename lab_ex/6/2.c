/*
    Si scriva un programma che, dato in input un intero N'inserito da tastiera, generi una matrice quadrata di dimensione NxN
    che simuli un'immagine. Ogni cella della matrice contenga, quindi, tre valori interi, generati casualmente, compresi tra 0 e
    255 a rappresentare i colori rosso, verde e blu. Terminata la generazione della matrice, la si stampi a video.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Colors Colors;
struct Colors {
    int red;
    int green;
    int blue;
};

Colors ** generate_matrix(int N);
void display_image(Colors **mat, int N);
void free_mat(Colors **mat, int N);
int main()
{
    int N = 0;
    printf("Inserisci dimension -> ");
    scanf("%d", &N);

    Colors **mat_colors = generate_matrix(N);
    display_image(mat_colors, N);

    free_mat(mat_colors, N);
    return 0;
}

Colors **generate_matrix(int N)
{
    Colors **gen_mat = malloc(sizeof(Colors*) * N);
    for (int i = 0; i < N; i++)
        gen_mat[i] = malloc(sizeof(Colors) * N);

    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            gen_mat[i][j].red = rand() % 256;
            gen_mat[i][j].green = rand() % 256;
            gen_mat[i][j].blue = rand() % 256;
        }
    }

    return gen_mat;
}

void display_image(Colors **mat, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("\n");
        for (int j = 0; j < N; j++)
            printf("(%d, %d, %d)\t", mat[i][j].red, mat[i][j].green, mat[i][j].blue);
        printf("\n");
    }
}

void free_mat(Colors **mat, int N)
{
    for (int i = 0; i < N; i++)
        free(mat[i]);

    free(mat);
}