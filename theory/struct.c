#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char second_name[50];
    int age;
};

// il typedef é un sinonimo o un nome dato ad un tipo
typedef struct Student Student;

void print_student(Student s);

int main() 
{
    // la sizeof della struct dovrebbe essere tutto messo insieme
    // si, il char é un byte -> 100 byte; 1 int é 4 byte -> 104 byte
    long int size = sizeof(Student);
    printf("%lu byte\n", size);
    Student s1;
    s1.age = 20;
    strcpy(s1.name, "Emanuele");
    strcpy(s1.second_name, "Di Pietro");

    // print
    printf("Sizeof char: %lu\n", sizeof(char));

    return 0;
}

void print_student(Student s)
{
    // non funziona, poiché la struct é di default passata "by value"
    // quindi non vado a modificare la struct originale
    s.age = 21;
    
    // una cosa della struct passata by value é che crea una copia della struct stessa nello stack
    // quindi per esempio, la struct s1 originale occupa 50 + 50 + 1 che poi vb devi moltiplicare per il size delle variabili
    // anche questo Student s verrá inserito nello stack come copia e quindi occuperai il doppio della memoria che ti serve
}