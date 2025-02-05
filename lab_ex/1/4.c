/*
Si scriva un programma per simulare una partita a bocce. Ogni partita sia composta di 3 manches.
All'inizio di ogni manche, viene lanciato un boccino che atterra casualmente in uno spazio identificato da due coordinate X e Y e limitato in entrambi i casi tra 0 e 100. 
Vince la manche il giocatore che, lanciando la propria boccia, la manda più vicina al boccino. Vince la partita chi vince più manches. 
Si ricordi che la formula per calcolare la distanza tra due punti è
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MANCHES 3
#define LAUNCHES 2

typedef struct Coordinate Coordinate;
struct Coordinate {
    int X;
    int Y;
};

typedef struct Giocatore Giocatore;
struct Giocatore {
    int points;
    Coordinate *lancio;
};

Coordinate *lancio_boccino();
int distance(Coordinate *giocatore, Coordinate *boccino);
void lancia(Coordinate *lancio);
void game(Giocatore *giocatore_1, Giocatore *giocatore_2);

int main()
{
    srand(time(NULL));
    // dopo lanciato il boccino si starta il game con 3 manches
    // con 2 lanci totali, 1 ciascuno
    Giocatore *giocatore_1 = malloc(sizeof(Giocatore));
    Giocatore *giocatore_2 = malloc(sizeof(Giocatore));
    game(giocatore_1, giocatore_2);
    printf("Giocatore %d vince la manche\n", (giocatore_1 -> points > giocatore_2 -> points) ? 1 : 2);

    free(giocatore_1);
    free(giocatore_2);
    return 0;
}

Coordinate *lancio_boccino()
{
    Coordinate *boccino = malloc(sizeof(Coordinate));
    boccino -> X = rand() % 100;
    boccino -> Y = rand() % 100;

    return boccino;
}

int distance(Coordinate *giocatore, Coordinate *boccino)
{   
    int dis = 0;

    dis = sqrt(pow((boccino -> X - giocatore -> X), 2) + pow((boccino -> Y - giocatore -> Y), 2));

    return dis;
}

void lancia(Coordinate *lancio)
{
    lancio -> X = rand() % 100;
    lancio -> Y = rand() % 100;
}

void game(Giocatore *giocatore_1, Giocatore *giocatore_2)
{
    int dis_1 = 0, dis_2 = 0;
    for (int k = 0; k < MANCHES; k++)
    {
        Coordinate *boccino = lancio_boccino();
        printf("Lancio Boccino Manche %d\nX: %d; Y: %d\n", k + 1, boccino -> X, boccino -> Y);
        for (int i = 0; i < LAUNCHES; i++)
        {
            if ( i % 2 == 0 ) 
            {
                giocatore_1 -> lancio = malloc(sizeof(Coordinate));
                lancia(giocatore_1 -> lancio);
                dis_1 = distance(giocatore_1 -> lancio, boccino);
                printf("Distance 1: %d\n\n", dis_1);
                free(giocatore_1 -> lancio);
            } else
            {
                giocatore_2 -> lancio = malloc(sizeof(Coordinate));
                lancia(giocatore_2 -> lancio);
                dis_2 = distance(giocatore_2 -> lancio, boccino);
                printf("Distance 2: %d\n", dis_2);
                free(giocatore_2 -> lancio);
            }
        }
        if (dis_1 < dis_2) giocatore_1 -> points += 1;
        else giocatore_2 -> points += 1;
        printf("Giocatore 1: %d\n", giocatore_1 -> points);
        printf("Giocatore 2: %d\n\n", giocatore_2 -> points);
        dis_1 = 0;
        dis_2 = 0;
         free(boccino);
    }
}