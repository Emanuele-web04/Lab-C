#include <stdio.h>
#include <stdlib.h>

struct Info {
    int data;
    int *arr;
};

// il typedef é un sinonimo o un nome dato ad un tipo
typedef struct Info Info;

int main() 
{
    // creo il puntatore 
    Info a;
    a.data = 3;
    a.arr = malloc(sizeof(int)*5);
    
    // e poi faccio 
    Info b;
    b = a;
    // io cosi mi copio solo il valore dell int
    // ma non mi copio tutta la dimensione dell array
    // bensi solo il puntatore che ha dimensione fissa
    // quindi al posto di copiarmi i 5*4 byte, me ne passo solo 4
    // perché é n puntatore, che dunque punta ad un memory address che dunque ha dimensione fissa

    free(a.arr);
    return 0;
}
