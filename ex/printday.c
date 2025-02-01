/*

Write a program lab2-print-day.c which takes a single Command-line Argument (an integer) 
and prints the name of the day of the week to which it corresponds. The details are:

    1 = Sunday

    2 = Monday

    3 = Tuesday

    4 = Wednesday

    5 = Thursday

    6 = Friday

    7 = Saturday

    Build the program as before and upload to einstein.

    Remember to add a newline character \n at the end.

*/

#include <stdio.h>

int main() {
    char week[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int day;
    printf("Day number -> ");
    scanf("%d", &day);


    printf("\n%s\n", week[day - 1]);
    return 0;
}