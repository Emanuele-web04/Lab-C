#include <stdio.h>

int main() 
{
    int mat[3][3] = {1,2,3,4,5,6,7,8,9};

    // al posto di usare un for innestato
    for(int i = 0; i < 9; i++) 
    {
        if (i % 3 == 0)
            printf("\n");
        
        printf("%d ", mat[i / 3][i % 3]);
    }
    printf("\n");
    return 0;
}