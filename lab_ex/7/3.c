/*
    Si scriva una funzione ricorsiva che, data in input una list di numeri interi, 
    stabilisca se la lista è ordinata in maniera strettamente crescente. 
    Si testi, quindi, la funzione nel main.
*/

#include <stdio.h>
#include <stdlib.h>

void crescend_list(int *v, int N, int i, int *count);

int main()
{
    int v[50];
    int input = 0, i = 0;
    do 
    {
        printf("Inserisci valore: ");
        scanf("%d", &input);
        if (input == -1) break;
        v[i] = input;
        i++;
    } while(input != -1);

    for (int j = 0; j < i; j++)
        printf("%d ", v[j]);

    int count = 0;
    crescend_list(v, i, 0, &count);

    printf("\n%d == %d", count, i - 1);

    return 0;
}

void crescend_list(int *v, int N, int i, int *count)
{
    if (i >= N) return;

    if (v[i] < v[i + 1]) *count += 1;

    printf("%d ", v[i]);
    crescend_list(v, N, ++i, count);
}