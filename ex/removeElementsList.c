/*
    Si scriva un programma che aggiunga in una linked list valori che l utente mette
    Si scriva poi una funzione che 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int value;
    Node *next;
};

Node *create_list();
Node *create_new_node(int input, Node *head);
Node *append(Node *head, Node* new);

Node *removeNode(int num, Node *head);

void display(Node *head);
void free_list(Node *head);

int main()
{
    Node *LINKED_LIST = NULL;  
    LINKED_LIST = create_list();
    display(LINKED_LIST);

    int num = 0;
    printf("\nWhat number do you want to delete?\n> ");
    scanf("%d", &num);
    
    LINKED_LIST = removeNode(num, LINKED_LIST);

    display(LINKED_LIST);

    free_list(LINKED_LIST);
    return 0;
}

Node *create_list()
{
    Node *head = NULL;
    printf("Enter (-1 to quit)\n");
    int input = 0;
    while ( 1 )
    {
        printf("> ");
        scanf("%d", &input);
        if ( input == -1 ) break;
        head = create_new_node(input, head);
    }

    return head;
}

Node *create_new_node(int input, Node *head)
{
    Node *new = malloc(sizeof(Node));
    new -> value = input;
    new -> next = NULL;
    head = append(head, new);
    
    return head;
}

Node *append(Node *head, Node* new)
{
    if ( !head ) return new;
    head -> next = append(head -> next, new);
    return head;
}

void display(Node *head)
{
    if ( !head ) 
    {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head -> value);
    display(head -> next);
}

Node *removeNode(int num, Node *head)
{
    Node *tmp = NULL, *tmp_head = NULL;
    while ( head && head -> next && head -> value == num )
    {
        tmp_head = head;
        if ( head && head -> next && head -> value == num ) head = head -> next;
        free(tmp_head);
    }

    Node *curr = head;
    // é finita o no la lista per i primi 2 valori
    // num = 3
    // 1 -> 2 -> 3 -> 4 -> NULL
    // si mette curr perché se la lista é vuota bum col pc
    // se curr non esiste prima di curr -> next --> memory leak
    // per checkare se una cosa successiva esiste, devo checkare se prima esiste
    // la cosa di base
    while( curr && curr -> next )
    {
        while ( curr && curr -> next && curr -> next -> value != num )
            curr = curr -> next;

        if ( curr && curr -> next )
        {
            tmp = curr -> next;
            curr -> next = curr -> next -> next;
            free(tmp);
        }       
    }
 
    return head;
}

void free_list(Node *head)
{
    if ( !head ) return;
    free_list(head -> next);
    free(head);    
}