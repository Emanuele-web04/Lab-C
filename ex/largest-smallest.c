/*
 
 Write a program ex1-largest-smallest.c which accepts a requirement and an array of float numbers. 
 The first argument is a requirement which can be largest or smallest.
 The following arguments are a set of floating numbers. If the requirement is largest, the program find the largest element in the array and print it.
 If the requirement is smallest, the program find the smallest element in the array and print it.
 Limit the displayed float number to 2 digits after the decimal point. You can assume the maximum number of elements in the array is 50.
 You are asked to use functions as much as you can when design the solutions.

 Example:

 Input:

 ./ex1-largest-smallest largest 4.2 4.5 12.3 6.7 93.5 87.6
 Output

 93.50
 Input:

 ./ex1-largest-smallest smallest 4.2 4.5 12.3 6.7 93.5 87.6
 Output

 4.20
 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int count = 0;
    double input = 0;
    double v[50];
    do {
        printf("\nEnter float number (-1 to quit) -> ");
        scanf("%lf", &input);
        if ((int)input == -1) {
            break;
        }
        v[count] = input;
        count++;
    } while(count < 50);

    char l_s[9];
    printf("\nLargest or Smallest? ");
    scanf("%s", l_s);
    double largest = 0;
    double smallest = 0;    
    int len = strlen(l_s);
    for(int i = 0; i < len; i++)
        if (isupper(l_s[i]))
            l_s[i] = tolower(l_s[i]);

    printf("%s\n", l_s);
    
        if (strcmp(l_s, "largest") == 0) {
            for(int i = 0; i < count; i++)
            {
                if (largest < v[i])
                    largest = v[i];
            }
        } else if (strcmp(l_s, "smallest") == 0)  {
            for(int i = 0; i < count; i++)
            {
                if (smallest > v[i])
                    smallest = v[i];
            }
        } else {
            printf("Insert Largest or Smallest. ");
        }
    printf("%s: %.2f\n", l_s, strcmp(l_s, "largest") == 0 ? largest : smallest);
    
    return 0;
}