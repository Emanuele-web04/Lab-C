/*
    Tipo fai la media degli elementi di un array, 
    fai il prodotto scalare degli elementi di un array
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insert_inputs(int *v, int *input, int *count);
int sum_array(int *v, int count);

int main()
{
    int input = 0;
    int count = 0;
    int *v = malloc(sizeof(int));
    // inserisci quanti ne vuoi, -1 per stoppare
    printf("Insert numbers (-1 to quit): \n");
    insert_inputs(v, &input, &count);
    // devi prenderti il totale con la recursion
    int sum = 0;
    sum = sum_array(v, count);

    float avg = sum / count;

    printf("%.2f\n", avg);

    free(v);
    return 0;
}

void insert_inputs(int *v, int *input, int *count)
{
    
    while(*input != -1) 
    {
        int size = *count + 1;
        scanf("%d", input);
        if (*input == -1)
            break;

        v = realloc(v, sizeof(int) * size);
        v[*count] = *input;
        *count += 1;
    } 
}

int sum_array(int *v, int n)
{
    if (n == 0)
        return n;

    printf("%d ", v[n - 1]);
    return v[n - 1] + sum_array(v, n - 1);
}