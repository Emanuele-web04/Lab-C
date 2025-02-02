/*
Scrivere un programma C che:

1) Prede una parola da linea di comando

2) Definisce un nodo Elemento come un record che contine une
intero pos e un carattere c, e un punattore al nodo successivo

3) Implementa la funzione
Elemento *crea_vettore_sparso(char vettore[], int len)
-che crea una lista di nodi Elemento,
-ovvero scorre il vettore in input e se l'elemento in posizione i-esima del vettore e' una vocale, 
crea un node, imposta il campo pos a i
e il campo c a vettore[i] e lo inserisce nella lista.

Input:
Indissolubilmente
Output:
(0, i) -> (3, i) -> (6, o) -> (8, u) -> (10, i) -> (13, e) -> (16, e) -> NULL
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node Node;
struct Node {
    int pos;
    char c;
    Node *next;
};

void take_input(char *input);
Node *create_list(int len, char* string);
Node *append_node(Node *head, Node *new_c);
void display_vowls(Node* head, int vowels[]);
void free_list(Node *head);
int main()
{
    int vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    
    char *string = malloc(sizeof(char) * 50);
    take_input(string);
    int len = strlen(string);
    
    Node *list = NULL;
    list = create_list(len, string);

    display_vowls(list, vowels);

    free_list(list);
    free(string);
    return 0;
}

void take_input(char *input)
{
    printf("Input:\n");
    scanf("%s", input);
}

Node *create_list(int len, char* string)
{
    Node* head = NULL;
    for (int i = 0; i < len; i++)
    {
        Node *new_c = malloc(sizeof(Node));
        new_c -> pos = i;
        new_c -> c = string[i];
        head = append_node(head, new_c);
    }

    return head;
}

Node *append_node(Node *head, Node *new_c)
{
    if ( !head ) return new_c;

    head -> next = append_node(head -> next, new_c);
    return head;
}

void display_vowls(Node* head, int vowels[])
{
    // se l head raggiunge il NULL, ferma
    if ( !head ) return;

    for (int i = 0; i < 5; i++)
    {
        if ( isupper( head -> c ) )
            head -> c = tolower( head -> c );

        if ( head -> c == vowels[i] )
            printf("(%d, %c) -> ", head -> pos, head -> c);
    }
    // vai avanti fino a che non é null
    display_vowls(head -> next, vowels);
}

void free_list(Node *head)
{
    if ( !head ) return;

    free_list(head -> next);
    free(head);
}