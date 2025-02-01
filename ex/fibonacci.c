/*
    Scrivi in maniera ricorsiva la serie di fibonacci.
    La funzione prende in input un valore intero,
    e stampa in cui sono inseriri i prmi n numeri di fibonacci.

    Input: 9
    Output: 1 1 2 3 5 8 13 21 34
*/

// la logica della serie é che preso un numero della serie ex: 8
// quel numero é dato dalla somma dei due suoi numeri precedenti 5 + 3
//
// si puo dire quindi che n = (n - 1) + (n - 2)
// in altra prospettiva -> n_ora per avere il n_succ -> n_succ = n_ora + n_ora - 1 -> 2n_ora -1
// quando n - 1 == 0 return 1

#include <stdio.h>

int fibonacci(int N);

int main()
{
    int N = 0;
    scanf("%d", &N);
    int n = 1;
    int i = 0;

    int fib = fibonacci(N);

    printf("%d", fib);

    return 0;
}

int fibonacci(int N) 
{
    if ( N == 0 || N == 1 ) return N;

    return fibonacci(N - 1) + fibonacci(N - 2);
}