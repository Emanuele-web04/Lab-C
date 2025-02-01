// le struct possono anche essere allocate dinamicamente
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    char second_name[50];
    int age;
};

// il typedef é un sinonimo o un nome dato ad un tipo
typedef struct Student Student;

int main() 
{
    // creo il puntatore 
    Student *s1;
    // libero spazio se c'é garbage data, e alloco la dimensione della struct -> 104 byte
    s1 = calloc(1, sizeof(Student));
    // dereference per modificare il value
    (*s1).age = 20;
    printf("Age %d\n", (*s1).age);
    // al posto di usare questa sintassi, puoi usare le arrows
    s1 -> age = 21;
    // nel blocco di memoria di s1 vammi a prendere il blocco di age, questo é quello che significa l'arrow
    printf("Age %d\n", s1 -> age);

    free(s1);
    return 0;
}
