#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void len_decrescente(int *v, int N, int i, int *count);

int main()
{
    int N = 0;
    printf("Quante stringe vuoi? ");
    scanf("%d", &N);

    char strings[N][50];
    char input[50];
    int str_lenghts[N];
    for(int i = 0; i < N; i++)
    {
        printf("Stringa %d\n", i + 1);
        scanf("%s", input);

        int len = strlen(input);
        str_lenghts[i] = len;
    }

    int i = 0, count = 0;
    len_decrescente(str_lenghts, N, i, &count);

    count == N ? printf("Decrescente\n") : printf("Nop\n");

    return 0;
}

void len_decrescente(int *v, int N, int i, int *count)
{
    if (i > N) return;
    printf("%d\n", v[i]);
    if (v[i] > v[i + 1]) *count += 1;
    len_decrescente(v, N, ++i, count);
}