#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
int main() {
    // Write C code here
    char *filename = "stocazzo.txt";

    FILE* fh_output;
    fh_output = fopen(filename, "w");
    
    if ( fh_output ) printf("File: %s opened\n", filename);
    else printf("File did not open\n");
    
    // how can i loop a fputs?
    // if the new line string is equal to :wq -> quit
    char buffer[MAX_CHAR];
    while ( 1 )
    {
        printf("> ");  // Prompt for user input
        if ( !fgets(buffer, MAX_CHAR, stdin) ) break;

        // string complement span
        // sostanzialmente che fa
        // se l user va a capo, viene inserito \n
        // con questa funzione lo prendiamo  e lo sostituiamo a \0 
        // buffer[strcspn(buffer, "\n")] = '\0';

        if ( strcmp(buffer, ":quit\n") == 0 ) break;

        fputs(buffer, fh_output);
    }

    fclose(fh_output);

    FILE* fh_input;
    fh_input = fopen("stocazzo.txt", "r");

    printf("\n");
    while ( fgets(buffer, MAX_CHAR, fh_input) ) printf("%s", buffer);

    fclose(fh_input);
    return 0;
}