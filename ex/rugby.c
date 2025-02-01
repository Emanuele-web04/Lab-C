/*

Rugby has several ways of scoring points. They are:

    A try (worth 5 points)

    A conversion (worth 2 points)

    A penalty (worth 3 points)

    A drop-goal (worth 3 points).

Write a program called lab1-rugby.c which does the following:

    Take four inputs (try, conversion, penalty, drop-goal) from command lines;

    Calculate the total point;

    Print the total point;

A Sample run might look like the following:

Input:

./lab1-rugby 2 1 1 3

Output:

24

*/

#include<stdio.h>

//define init
#define TRY 5
#define CONVERSION 2
#define PENALTY 3
#define DROPGOAL 3

int main() {
    char pointsNames[4][11] = {"Try", "Conversion", "Penalty", "Dropgoal"};

    int points[] = {TRY, CONVERSION, PENALTY, DROPGOAL};
    int size = sizeof(points) / sizeof(points[0]);
    printf("Array size:%d\n", size);

    int value = 0;
    int totalPoints = 0;

    for (int i = 0; i < size; i++)
    {
        printf("Insert %s:\n", pointsNames[i]);
        scanf("%d", &value);

        value *= points[i];
        totalPoints += value;
    }

    printf("\nTotal points: %d\n", totalPoints);

    return 0;
}