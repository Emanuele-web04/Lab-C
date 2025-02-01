/*
    Si scriva un programma che, dati in input N numeri reali da tastiera, stabilisca quali, tra i
    numeri inseriti, sono multipli di qualche altro numero inserito.
*/

#include <stdlib.h>
#include <stdio.h>

int main () {
    int n = 0;
    printf("Quante pizze vuoi? ");
    // perche si prende l'indirizzo?
    // io prendo il numero e la butto nell'indirizzo
    scanf("%d", &n);

    int value = 0;
    // ti salvi dinamicamente in memoria n slot con type int
    int* v = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        printf("\nInserisci n %d ", i + 1);
        scanf("%d", &value);
        v[i] = value;
    }
    
    int i = 0;
    while(i < n) {
        printf("%d ", v[i]);
        i++;
    }
    
    
    for(int i = 0; i < n; i++) {
        printf("\nNumber %d is a multiple of: ", v[i]);
        for(int j = 0; j < n; j++) {
            if ((v[i] % v[j] == 0) && (i != j)) {
                printf(" %d", v[j]);
            }
        }
    }
    return 0;
}
