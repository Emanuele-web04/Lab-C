/*
    Si scriva un programma che, dato in input un intero N, generi N stringhe di caratteri alfabetici casuali di lunghezza variabile tra 1 e 10. 
    Il programma stampi, quindi, per ogni stringa il carattere meno frequente nella stringa stessa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int N = 0;
    printf("How many strings? ");
    scanf("%d", &N);

    char strings[N][11];
    srand(time(NULL));

    int str_lenghts[N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < rand() % 10; j++)
        {
            strings[i][j] = (char)(rand() % 256);
            
        }
    }

    return 0;
}