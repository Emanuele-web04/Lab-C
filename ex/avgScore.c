#include <stdio.h>
#include <stdlib.h>

void populate_month(int *month, int days);
double avg(int *month, int days);

int main()
{   
    int days = 0;
    printf("How many days? ");
    scanf("%d", &days);
    int *month = malloc(sizeof(int) * days);

    populate_month(month, days);

    double avgMonth = avg(month, days);

    printf("\nAverage Score: %.2f\n", avgMonth);

    free(month);
    return 0;
}

void populate_month(int *month, int days)
{   
    int input = 0;
    for (int i = 0; i < days; i++)
    {
        printf("Day %d: ", i + 1);
        scanf("%d", &input);
        month[i] = input;
    }
}

double avg(int *month, int days)
{
    int total = 0;
    for (int i = 0; i < days; i++)
        total += month[i];

    double avg = total / days;

    return avg;
}