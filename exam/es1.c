/*
    Si scriva un programma che, dati in input N numeri reali da tastiera, 
    stabilisca quali, tra i numeri inseriti, 
    sono divisori di qualche altro numero inserito.
*/

#include <stdio.h>
#include <stdlib.h>

float *populate_array(int N);
void check_dividend(float *v, int N);

int main()
{       
    int N = 0;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &N);

    float *v = NULL;
    v = populate_array(N);

    check_dividend(v, N);

    free(v);
    return 0;
}

// funzione per allocare dinamicamente l array
float *populate_array(int N)
{   
    float *arr = malloc(sizeof(float) * N);
    if ( !arr ) exit(0);

    for ( int i = 0; i < N; i++ )
    {
        printf("> ");
        scanf("%f", &arr[i]);
    }

    return arr;
}

void check_dividend(float *v, int N)
{
    // double for loop per controllare ogni elemento con tutta l'array
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // devo fare il check con l indice diverso
            // perche cosi non vado a prendere lo stesso
            // possiamo farlo o cosi
            if (i != j)
            {
                // dato che il modulo per i float non worka
                // checkiamo se la divisione in intero * v[j] == v[i]
                // ex 7 / 2 = 3.5 -> int = 3 * 2 = 6 != 7
                // 6 / 2 = 3.0 -> int = 3 * 2 = 6 -> é un divisore
                float division = v[i] / v[j];
                if ((int)division * v[j] == v[i])
                    printf("%.2f é divisore di %.2f\n", v[j], v[i]);
            }

            // o cosi
            // if ( i == j )
            //     continue;
            // e sotto la logica
        }
    }
}


