/*
    Si scriva un programma che, data in input una sequenza di caratteri di lunghezza non
    specificata da tastiera, stabilisca la lungheza dele sottosequenza più lunga di caratteri
    uguali presenti nela stringa e la stampi a video.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    char c;
    Node *next;
};

Node *create_list();
Node *append(Node *head, Node *new);
void substring(Node *head, int *max, char *sub);
void free_list(Node *head);

int main()
{
    Node *list = NULL;
    
    list = create_list();
    int max = 0;
    char sub;

    substring(list, &max, &sub);

    for (int i = 0; i < max; i++)
        printf("%c", sub);

    free_list(list);
    return 0;
}

Node *create_list()
{   
    Node *head = NULL;
    char input;
    printf("'q' to quit\n");
    while ( 1 )
    {
        scanf(" %c", &input);
        if ( input == 'q' ) break;
        Node *new = malloc(sizeof(Node));
        new -> c = input;
        new -> next = NULL;
        head = append(head, new);
    }
    return head;
}

Node *append(Node *head, Node *new)
{   
    if ( !head ) return new;
    head -> next = append(head -> next, new);
    return head;
}

void substring(Node *head, int *max, char *sub)
{
    if ( !head ) return;

    int count = 1;
    Node *curr = head;
    while(curr -> next != NULL && curr -> c == curr -> next -> c)
    {
        count += 1;
        curr = curr -> next;
    }
    if (*max < count)
    {
        *max = count;
        *sub = curr -> c;
    }

    substring(head -> next, max, sub);
}

void free_list(Node *head)
{   
    if ( !head ) return;
    free_list(head -> next);
    free(head);
}