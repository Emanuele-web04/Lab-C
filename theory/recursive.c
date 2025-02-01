// la funzione recosriva é una funzione che chiama se stessa
// agisce in modo weird nello stack e praticamente é come se venisse chiamata il doppio
// 
// ex:
//
//  n - 1 come parametro nella recursive
//  n == 1 caso base
//  func(3) 
//  return n * func(2) -> n * (n * 1)
//  return n * func(1) -> n * 1
//  return n ovvero return 1 -> passi 1 alla funzione precedente
//

#include <stdio.h>

int sum(int n, int m);

int main() 
{
    int n;
    printf("∑ starting from: ");
    scanf("%d", &n);

    int m;
    printf("∑ finishing at: ");
    scanf("%d", &m);
    
    int result = 0;
    result = sum(n, m);

    printf("\n∑(%d -> %d) [k - 2] = %d\n", n, m, result);

    return 0;
}

// ∑(n -> m) [n - 2]

int sum(int n, int m) 
{
    if (n == m)
        return (n - 2);
    return (n - 2) + sum(n + 1, m);    
}