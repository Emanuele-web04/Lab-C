/*
     Si scriva un programma che, dato in input da tastiera un intero N, generi una lista puntata contenente N interi generati
    casualmente, stampandola a video. Si scriva, quindi, una funzione ricorsiva che, data in input la lista ed un intero X,
    restituisca la posizione nella quale si trova l'intero dato in input. La funzione restituisca un messaggio di errore nel caso in
    cui l'intero ricercato non esista nella lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node Node;
struct Node {
    int ele;
    Node *next;
};

Node *create_list(int N);
Node *append_node(Node *head, Node *new_node);
void display_list(Node *head);
int linear_search(Node *head, int X, int i);
void free_list(Node *head);

int main()
{
    int N = 0;
    printf("Inserisci N: ");
    scanf("%d", &N);

    Node *list = NULL;
    list = create_list(N);
    display_list(list);

    int X = 0;
    printf("\nInserisci X da trovare -> ");
    scanf("%d", &X);
    int i = 1;
    int found_at = linear_search(list, X, i);

    found_at == -1 ? printf("Value not found.\n") : printf("X: %d found @ pos: %d\n", X, found_at);
    
    free_list(list);
    return 0;
}

Node *create_list(int N)
{
    Node *head = NULL;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        Node *new_node = malloc(sizeof(Node));
        new_node -> ele = rand() % 100;
        new_node -> next = NULL;
        head = append_node(head, new_node);
    }

    return head;
}

Node *append_node(Node *head, Node *new_node)
{
    if ( !head ) return new_node;

    head -> next = append_node(head -> next, new_node);

    return head;
}

void display_list(Node *head)
{
    if ( !head ) return;

    printf("%d -> ", head -> ele);
    display_list(head -> next);
}

int linear_search(Node *head, int X, int i)
{
    // se raggiunge null return -1
    if ( !head ) return -1;

    if ( X == head -> ele ) return i;

    return linear_search(head -> next, X, ++i);
}

void free_list(Node *head)
{
    if ( !head ) return;

    free_list(head -> next);
    free(head);
}