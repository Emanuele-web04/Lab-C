/*
    Creare una lista semplicemente concatenata 
    di interi con n numeri inseriti dall’utente 
    e stampare la lista normale e al rovescio
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int input;
    Node *next;
};

Node *create_list(int N, int *input);
Node *append_node(Node *head, Node *new_node);
void display(Node *head);
void free_ite(Node *head);

int main() 
{
    int N = 0;
    printf("Quanti valori vuoi inserire? ");
    scanf("%d", &N);
    if (N <= 0)
        return -1;

    
    int input = 0;
    Node *list = create_list(N, &input);
    
    display(list);

    free(list);
    return 0;
}

Node *create_list(int N, int *input)
{
    Node *head = NULL;
    for(int i = 0; i < N; i++)
    {
        printf("Inserisci n%d: ", i + 1);
        scanf("%d", input);

        Node *new_node = malloc(sizeof(Node));
        new_node -> input = *input;
        new_node -> next = NULL;
        head = append_node(head, new_node);
    }

    return head;
}

Node *append_node(Node *head, Node *new_node)
{
    if ( !head )
        return new_node;

    // dato che head -> next = NULL
    // la funzione fa diventare head -> next = NULL = head (argomento della funzione)
    // essendo null, la funzione assume valore di new_node e quindi head -> next = new_node
    head -> next = append_node(head -> next, new_node);
    return head; // che non varia mai
}

//Ceh praticamente printando la lista al contrario é il comportamento visivo della ricorsione
// Perche dato che printo prima, al ritorno incontri prima il return cosi il print non viene chiamato
// Invece mettendolo dopo si
void display(Node *head)
{
    // definiamo il caso base e da li poi buildi la funzione
    // caso base é se head é null
    // poiche significa che abbiamo raggiunto la fine della lista

    if( head == NULL )
    {
        printf("NULL");
        return;
    }

    printf("(%d) -> ", head -> input);
    display(head -> next);
}

void free_rec(Node *head)
{
    if ( !head )
        return;

    free_rec(head -> next);
    // prendo head e non head -> next perché se si stoppa significa che
    // head -> next era null e quindi non dovevi freeare niente
    free(head);
}

void free_ite(Node *head)
{
    //creo una variabile temporanea
    Node *temp;
    while( !head )
    {
        // che prende il valore di head cosi non si va a perdere
        temp = head;
        // head poi mi diventa il successivo, perdiamo riferimento, ma abbiamo temp
        head = head -> next;
        // cosi possiamo liberare temp perche abbiamo dato il continuo della lista a head
        free(temp);
    }
}