/*
    Si scriva una funzione ricorsiva tale che, data in input una sequenza di stringhe inserite da tastiera, 
    stabilisca se le stringhe sono ordinate in senso decrescente per lunghezza oppure no. 
    Si testi, inoltre, tale funzione all'interno del main.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char quit[3] = ":q";

typedef struct Node Node;
struct Node {
    char str[30];
    int len;
    Node *next;
};

Node *create_list();
Node *create_node(Node *head, char *input);
Node *append_node(Node *head, Node *new);
void display(Node *head);
void len_decr(Node *head);
// approccio ricorsivo
void len_decr_recursive(Node *head, int *counter, int *i);
void free_list(Node *head);

int main()
{
    Node *list = NULL;
    list = create_list();

    display(list);
    
    int counter = 0, i = 0;
    len_decr(list);
    len_decr_recursive(list, &counter, &i);
    printf("%s\n", counter == i ? "Decrescente" : "Not Decr");

    free_list(list);
    return 0;
}

Node *create_list()
{
    printf("Inserisci tot stringhe.\n(:quit to stop)\n");
    Node *head = NULL;
    char input[30];
    while ( 1 )
    {
        printf("> ");
        scanf("%29s", input);
        if ( strcmp(input, quit) == 0 )
            break;

        // funzione che crea la lista
        head = create_node(head, input);
    } 
        
    return head;
}

Node *create_node(Node *head, char *input)
{   
    Node *new = malloc(sizeof(Node));
    if ( !new ) exit(EXIT_FAILURE);
    strcpy(new -> str, input);
    new -> len = strlen(input);
    new -> next = NULL;
    head = append_node(head, new);
    return head;
}

Node *append_node(Node *head, Node *new)
{
    if ( !head ) return new;
    head -> next = append_node(head -> next, new);
    return head;
}

void display(Node *head)
{
    if ( !head ) return;
    printf("%d: %s\n", head -> len, head -> str);
    display(head -> next);
}

void len_decr(Node *head)
{
    int count = 0;
    int i = 0;
    Node *curr = head;
    while ( !(curr -> next) )
    {
        if (curr -> len > curr -> next -> len)
            count += 1;

        i++;
        curr = curr -> next;
    }

    printf("%s\n", count == i ? "Decrescente" : "Not Decr");
}

void len_decr_recursive(Node *head, int *counter, int *i)
{
    if ( !(head -> next) ) return;

    if (head -> len > head -> next -> len)
        counter += 1;
    i++;

    len_decr_recursive(head -> next, counter, i);
}

void free_list(Node *head)
{
    if ( !head ) return;
    free_list(head -> next);
    free(head);
}