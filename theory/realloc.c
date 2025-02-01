#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int size = 2;
    int *numbers = malloc( sizeof(int) * size );
    // ho creato spazio in memoria per 2 int
    // ora voglio prendere in input quanti numeri l'utente vuole inserire
    // e reallocare la memoria se i numeri eccedono lo spazio corrente
    int input = 0;
    int inputs = 0;
    do {
        if (inputs == size) {
            size += 2;
            numbers = realloc(numbers, sizeof(int) * size);
        }
        printf("\nEnter (-1 to q) -> ");
        // scanf si prende l'indirizzo cosi puo andare a modificare il valore in memoria
        scanf("%d", &input);
        if (input != -1) {
            numbers[inputs] = input;
            inputs += 1;
        }
    } while(input != -1);

    //total
    int total = 0;
    for(int i = 0; i < inputs; i++)
        total += numbers[i];

    int avg = total / inputs;

    printf("Avg: %d\n", avg);

    free(numbers);
    return 0;
}