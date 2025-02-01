/*
    Scrivere un programma in C che:
    1) Prende in input dalla linea di comando una parola.
    2) Definisce uno stack AStack a capacità limitata il cui array interno sia allocato dinamicamente 
    con capacità pari alla lunghezza della parola in input
    3) Usi lo stack per invertire la parola
    4) Usi lo stack per verificare se la parola è palindroma

    Input: onorarono
    Output:
    La parola è palindroma e la sua inversione è: onorarono
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack Stack;
struct Stack {
    int top;
    char *arr;
};

Stack *create_stack(int len);
void push(Stack *s, char *string, int len);
int pop_and_append_inverse(Stack *s);

int main()
{
    char *string = malloc(sizeof(char) * 50);

    printf("Inserisci stringa:\n");
    // l'array é di built in un puntatore al suo primo elemento
    scanf("%s", string);
    int len = strlen(string);

    Stack *stack = NULL;
    stack = create_stack(len);
    push(stack, string, len);

    printf("\nOriginal: %s\n", stack -> arr);

    int palindrome = pop_and_append_inverse(stack);
    printf("%d\n", palindrome);
    printf("Inverse: %s\n", stack -> arr);

    palindrome == len ? printf("Palindrome\n") : printf("Not Palindrome\n");

    free(stack -> arr);
    free(stack);
    free(string);
    return 0;
}

Stack *create_stack(int len)
{
    Stack *s = malloc(sizeof(Stack));
    s -> top = -1;
    s -> arr = malloc(sizeof(char) * len);

    return s;
}

void push(Stack *s, char *string, int len)
{
    for (int i = 0; i < len; i++)
    {
        s -> top += 1;
        s -> arr[ s -> top ] = string[i];
    }
}

int pop_and_append_inverse(Stack *s)
{
    // per poppare devo prendere il valore nell s -> arr a s -> top e poi scendere mano mano con s -> top -= 1
    int stack_lenght = s -> top;
    char *inverse = malloc(sizeof(char) * s -> top);

    printf("%d\n", stack_lenght);
    int count = 0;
    for (int i = 0; i < stack_lenght; i++)
    {
        inverse[i] = s -> arr [ s -> top ];
        if ( inverse[i] == s -> arr [ s -> top ] ) count += 1;

        s -> top -= 1;
    }

    free(inverse)
    return count;
}