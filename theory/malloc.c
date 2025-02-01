// the stack is a block of contiguos addresses together
// it goes from top to bottom
// everything you create, e.g.
// int x = 5; int y = 10; is going to be stored next to each other like address x: 16; addrss y: 17;
//
// in the meanwhile the heap is not a contigous block of memory
// it goes bottom to up

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    // creiamo un puntatore ad un indirizzo di memoria, senza inizializzarlo
    // oppure inizializzarlo a NULL
    int *a = NULL;

    // poi grazie alla funzione malloc, creiamo in memoria (MemoryALLocation) un tot di spazio per quel puntatore
    // qui creo in memoria uno spazio contiguo di 4 byte(int) per 5 volte, quindi creo uno spazio in memoria complessivo di 5*4 nell'heap
    a = malloc( sizeof(int) * 5 );
    // la malloc ti ritorna il memory address del primo elemento inserito -> tipo puntatore

    // é probabile che quando si va a malloccare ci possano essere "garbage values" nell'indirizzo di memoria
    // la malloc non fa niente per liberarti il posto, ed é per questo che si usa "calloc"
    int *b = NULL;
    //si scrive diversamente
    b = calloc( 5, size(int) );
    // calloc quindi ti svuota il valore nell'address cosi puoi fa quello che vuoi 
    // dato che calloc deve freeare, o meglio, checkare se i valori sono vuoti e poi magari svuotarli
    // sará piú time consuming

    // dato che malloc e calloc occupano spazio nell'heap e non nello stack, non si auto eliminano
    // ergo le devi freeare ed eliminare tu con 
    free(a);
    free(b);
    // quello che fa free, é prendersi il blocco di memoria (indirizzo) e renderlo di nuovo disponibile
    // ergo se passi a, passi l'indirizzo del primo, e dato che é contiguo, tutto l'array in memoria si freea
    // se non dovessimo freeare, "memory leak" potrebbe accadere

    retrun 0;
}