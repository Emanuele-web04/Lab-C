#include <stdio.h>
#include <stdlib.h>

int main()
{
    // keeps a reference to the file
    FILE* fh_output;

    // append mode with a
    // al posto di creare un file blank, append ti fa aggiungere al file gia esistente quello che scrivi
    fh_output = fopen("io.txt", "a");
    
    // we can also add data with a loop
    // for (int i = 0; i < 10; i++)
    //     fprintf(fh_output, "%d ", i);

    // we can also write data to the file while we ask the user to add it
    int input = 0;
    while( 1 )
    {
        printf("Enter # (-1 to quit): ");
        scanf("%d", &input);

        if ( input == -1 ) break;
        else fprintf(fh_output, "%d\n", input);
    }

    // remember to close the file
    fclose(fh_output);
    return 0;
}