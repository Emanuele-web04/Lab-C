#include <stdio.h>
#include <stdlib.h>

int main()
{
    // keeps a reference to the file
    FILE* fh_output;

    // we choose a mode to what we can do with the file
    // ex: w, r etc...

    // if the file doesnt exist, the function will create it
    // if the file already exists, with w, it will destroy the initial one, and create a blank page
    fh_output = fopen("io.txt", "w");
    
    // there are some functions for the files:
    // fputs -> 1 arg = the string we want to add, 2 arg = where to add
    fputs("A string\n", fh_output);
    // cat io.txt for viewing and printing the content of the file

    // fprintf -> 1 arg = where, 2 arg like a printf, 3 arg like te values of a printf
    int data = 5;
    fprintf(fh_output, "data: %d\n", data);
    
    // remember to close the file
    fclose(fh_output);
    return 0;
}