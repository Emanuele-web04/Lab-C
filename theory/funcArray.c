#include <stdio.h>

void add_one(int x);
void map_plusone(int a[], int lenght);

int main()
{
    // a differenza delle variabili, nelle funzioni non si passa il valore dell'array
    // bensí si passa il suo indirizzo di memoria, ecco per cui possiamo modificare direttamente l'array

    int a[] = {2, 4, 10, 5, 7, 8};
    printf("a address: %p\n", a);
    int lenght = 6;

    int x = 0;
    printf("x address %p\n", &x);
    add_one(x);
    printf("%d\n", x);

    map_plusone(a, lenght);
    for(int i = 0; i < lenght; i++) printf("a[%d]: %d\n", i, a[i]);
}

void add_one(int x)
{
    printf("x address %p\n", &x);
    x += 1;
}

void map_plusone(int a[], int lenght)
{
    printf("a address: %p\n", a);
    for(int i = 0; i < lenght; i++) a[i] += 1;
}