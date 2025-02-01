/*

Write a program lab2-count-odd-number.c to count the number of odd numbers in an array of integers. 
Note that for learning purpose, you need to use array to store the input elements in this exercise.

Input: Each argument is an integer element of the array 
Output: The total number of odd elements in the array followed by a new line character.

You may assume the max length of the array is 10. Upload to Einstein to test your code.

For example: Input:

./lab1-count-odd-number 3 5 12 43 4 2 5

Output:

4

*/

#include <stdio.h>
#define MAX 10

int store_and_check(int v[], int i, int value, int oddCount);

int main(void) {

    int v[MAX];
    int n;

    printf("How many numbers you want to enter? -> ");
    scanf("%d", &n);
    printf("\n");

    int value;
    int oddCount;
    // take the numbers from input
    for(int i = 0; i < n; i++)
    {
        printf("Value %d -> ", i + 1);
        scanf("%d", &value);

        oddCount = store_and_check(v, i, value, oddCount);
    }

    printf("\nOdd numbers in the array -> %d\n", oddCount);

    return 0;
}

int store_and_check(int v[], int i, int value, int *oddCount)
{
    v[i] = value;

    if (value % 2 != 0)
        oddCount += 1; 

    return oddCount;
}

 