/*
    Scrivere un programma C che:
    1) Prende in input dalla linea di comando una parola
    2) definisce un nodo Carattere come record che contine un
    carattere e un punatore al nodo successivo
    3) implmenta la funzione
    Intero *crea_lista(char parola[]) (penso che qua il tipo e' sbagliato)
    che prende in input una parola e
    restituisce il puntatore alla testa di una lista 
    di caratteri

    input
    imprescindibile
    output
    La lista e':i->m->p->r->e->s->c->i->n->d->i->b->i->l->e->NULL
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node {
    char c;
    Node *next;
};

Node *create_list(char *string, int len);
Node *append_node(Node *head, Node *new_node);
void display(Node *head);
void free_list(Node *head);

int main()
{
    char *string = malloc(sizeof(char) * 50);
    printf("Insert a word:\n");
    scanf("%s", string);

    int len = strlen(string);

    Node *list = NULL;
    list = create_list(string, len);

    display(list);

    free(string);
    free(list);
    return 0;
}

Node *create_list(char *string, int len)
{
    Node *head = NULL;
    for(int i = 0; i < len; i++)
    {
        Node *new_node = malloc(sizeof(Node));
        new_node -> c = string[i];
        new_node -> next = NULL;
        head = append_node(head, new_node);
    }

    return head;
}

Node *append_node(Node *head, Node *new_node)
{
    if( !head ) return new_node;

    // se head esiste significa che devo assegnare il valore al suo head -> next
    // controlliamo il suo head -> next se esiste o meno, se non esiste la funzione prende valore di new_node
    head -> next = append_node(head -> next, new_node);
    return head; // che rimane invariato
}

void display(Node *head)
{
    if ( !head ) return;

    printf("%c -> ", head -> c);
    display(head -> next);
}

void free_list(Node *head)
{
    // se head é nullo, finisci
    if ( !head ) return;

    // controlla head -> next finche non é null
    free_list(head -> next);
    // ora dato che hai raggiunto il null, quindi l ultimo elemento, la funzione andra a ritroso
    // cosi potrai eliminare ogni nodo della lista
    free(head);
}