#include <stdio.h>
#include <stdlib.h>

int main()
{   
    // int *v = malloc(sizeof(int) * 5);

    // for (int i = 0; i < 5; i++)
    //     scanf("%d", &v[i]);

    int v[5];

    FILE * file;
    // file = fopen("file.bin", "wb");
    // if ( !file ) return -1;

    // fwrite(v, sizeof(v), 1, file);

    // fclose(file);

    file = fopen("file.bin", "rb");
    if ( !file ) return -1;

    fread(v, sizeof(v), 1, file);
    fclose(file);

    for (int i = 0; i < 5; i++)
        printf("v[%d] = %d\n", i, v[i]);
    // free(v);
    return 0;
}