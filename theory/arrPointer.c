#include <stdio.h>

int main()
{
    int a[] = {1,2,3};
    // l'array non é soltanto un insieme di valori
    // é in realtá un puntatore all'indirizzo del primo elemento dell'array
    // il fatto che l'array sia cosi é perché é built in.
    int *p = a;

    //but i cannot do
    a = p;
    // i cannot change a memory address cause its not a pointer, its an array of elements

    // il fatto é che tu non devi pensare ad un puntatore come un valore
    // ceh se p punta ad un valore, oppure punta al primo elemento di un array, sempre un'address é
    // quindi a te poco importa di cosa stora, relativamente
    printf("indirizzo a: %p\n", a);
    printf("valore con puntatore%d\n", p[0]);

    // se invece facessi
    // pointer notation
    printf("*(p + 1) = %d\n", *(p + 1));
    // é come se stessi dicendo a[1], ergo 2
    
    return 0;
}