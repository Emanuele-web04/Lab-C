#include <stdio.h>

int main()
{
    FILE* fh_input;
    fh_input = fopen("in.txt", "r");

    if ( fh_input ) printf("File opened successful");
    else printf("File openend unsuccessful");

    // fgets si prende 3 arguements
    // buffer, la sizeo_t del buffer, e da dove prendere la string
    // fgets only works with buffer
    char buffer[256];
    // vediamo se dopo funziona col while nello stesso modo in cui funziona fscanf
    // fgets prende solo la stringa che finisce con un a capo o alla fine del file
    while ( fgets(buffer, 256, fh_input) )
    {
        printf("%s", buffer);
    }

    fclose(fh_input);
    return 0;
}