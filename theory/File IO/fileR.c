#include <stdio.h>

int main()
{
    // reading from a file
    FILE* fh_input;

    fh_input = fopen("io.txt", "r");
    // you read data with fscanf
    int f_input = 0;
    // read the first integer and store it inside f_input
    // fscanf(fh_input, "%d\n", &f_input);
    printf("%d\n", f_input);

    // possiamo anche leggere e inserire valori in un array
    // qua che succede
    // praticamente fscanf prende i valori interi
    // poi quando incotra una new line ricomincia
    // e quando finiscono le line raggiunge EOF = End Of File
    int numbers[100];
    int lines = 0;
    while ( fscanf(fh_input, "%d", &f_input) != EOF )
    {
        printf("Number: %d\n", f_input);
        numbers[lines];
        lines += 1;
    }

    fclose(fh_input);
    return 0;
}