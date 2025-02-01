/*

Write a program lab3-string-reverse.c to reverse a given string. The program take one argument as an input string and print out the reversed one. 
You may assume the maximum character is 50. Then upload your solution to Einstein!

For example:

    Input

./lab3-string-reverse "to be or not to be"

    Output

eb ot ton ro eb ot

*/

#include <stdio.h>
#include <string.h>
#define MAX 50

int main() 
{
    char text[50];
    printf("Write -> \n");
    fgets(text, sizeof(text), stdin); // Legge fino a 49 caratteri (il 50° è per '\0')

    printf("\n%s\n", text);

    int len = strlen(text);
    printf("%d\n", len);
    for(int i = len; i >= 0; i--)
        printf("%c", text[i]);

    printf("\n");

    
    return 0;
}