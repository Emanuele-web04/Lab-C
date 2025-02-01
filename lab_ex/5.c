/*
    Si scriva un programma che, data in input una sequenza di caratteri di lunghezza non
    specificata da tastiera, stabilisca la lungheza dele sottosequenza più lunga di caratteri
    uguali presenti nela stringa e la stampi a video.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *string = malloc(sizeof(char) * 50);
    if (!string)
        return 1;

    printf("Inserisci dei caratteri:\n");
    scanf("%s", string);

    printf("%s\n", string);
    int len = strlen(string);

    char checked[50];   
    int lung = 1;
    int max = 1;
    for(int i = 0; i < len; i++)
    {
        
            checked[i] = string[i]; 
            if (string[i] == string[i + 1]) {
                lung += 1;
            } else {
                if (lung >= max) {
                    max = lung;
                }
                lung = 1;
            }
    }

    printf("max: %d", max);
    
    free(string);
    return 0;
}