/*
    Si scriva un programma che, dato in input un intero N da tastiera, generi una lista puntata di
    lunghezza N contenente caratteri casuali e la stampi. Si scriva, quindi, una funzione ricorsiva che
    restituisca la posizione di tutti i caratteri alfanumerici presenti nella lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHAR 256

typedef struct Node Node;
struct Node {
    char c;
    Node *next;
};

Node *create_list(int N);
Node *append_node(Node *head, Node* new);
void display_list(Node *head);
void indeces(Node *head, int i);
void free_list(Node *head);

int main()
{
    int N = 0; 
    printf("N: ");
    scanf("%d", &N);

    srand(time(NULL));
    Node *list = NULL;
    list = create_list(N);

    display_list(list);
    int i = 0;
    indeces(list, i);

    free_list(list);
    return 0;
}

Node *create_list(int N)
{
    Node *head = NULL;
    for (int i = 0; i < N; i++)
    {
        Node *new = malloc(sizeof(Node));
        new -> c = rand() % MAX_CHAR;
        new -> next = NULL;
        head = append_node(head, new);
    }

    return head;
}

Node *append_node(Node *head, Node* new)
{
    if ( !head ) return new;
    head -> next = append_node(head -> next, new);
    return head;
}

void display_list(Node *head)
{
    if ( !head ) return;
    printf("%c\n", head -> c);
    display_list(head -> next);
}

void indeces(Node *head, int i)
{
    if ( !head ) return;
    printf("%c at %d\n", head -> c, i);
    indeces(head -> next, ++i);
}

void free_list(Node *head)
{
    if ( !head ) return;
    free_list(head -> next);
    free(head);
}