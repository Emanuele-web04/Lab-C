/*
    Si scriva una funzione ricorsiva tale che, data in input una sequenza di stringhe inserite da tastiera, 
    stabilisca se le stringhe sono ordinate in senso decrescente per lunghezza oppure no. 
    Si testi, inoltre, tale funzione all'interno del main.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_decr(int *str_len, int n);

int main()
{
    int n = 0;
    printf("Quante stringhe si vuole inserire? ");
    scanf("%d", &n);

    // creo l inpur per lo scanf
    char input[20];

    // un array che posso iterare dopo che contiene le lunghezze delle stringhe
    // di dimensione n
    int str_len[n];

    for ( int i = 0; i < n; i++ )
    {
        printf("> ");
        scanf("%19s", input);

        // mi salvo cosi per ogni stringa la sua lunghezza
        str_len[i] = strlen(input);
    }

    int counter = check_decr(str_len, n);
    // se il mio count é uguale alla dimensione - 1 allora é decrescente
    counter == n - 1 ? printf("Decrescente\n") : printf("Not D\n");

    return 0;
}

int check_decr(int *str_len, int n)
{
    int count = 0;

    // finisci a -1 perché cosi non abbiamo idx out of range
    for (int i = 0; i < n - 1; i++)
    {
        // se il valore di adesso é piu grande di quello dopo aumenta
        if (str_len[i] > str_len[i + 1])
            count += 1;
    }

    return count;
}
