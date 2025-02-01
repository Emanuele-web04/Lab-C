//
//  lab_4_1.c
//
//
//  Created by Emanuele Di Pietro on 24/01/25.
//

/*
    Si scriva un programma che, dati in input N numeri reali da tastiera, salvi in una struttura dati sequenziale, separatamente, la parte intera e quella decimale. Il programa restituisca, quindi, la posizione del massimo elemento intero e quella del massimo elemento decimale
 
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 0;
    printf("How many numbers? ");
    scanf("%d", &n);
    
    double value = 0;
    
    int int_part = 0;
    double double_part = 0;
    
    int* int_arr = malloc(sizeof(int) * n);
    double* double_arr = malloc(sizeof(double) * n);
                                                
    for(int i = 0; i < n; i++) {
        printf("Insert number: ");
        scanf("%lf", &value);
        int_part = floor(value);
        double_part = value - int_part;
        printf("%d, %.2f \n", int_part, double_part);
        if (floor(value) == value) {
            int_arr[i] = int_part;
        } else {
            double_arr[i] = double_part;
        }
    }
                         
                             int biggest = 0;
                             double biggest_double = 0;
                             
                             
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (int_arr[i] > int_arr[j])
                biggest = int_arr[i];
        }
    }
                             
                             printf("\n%d", biggest);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (double_arr[i] > double_arr[j])
                biggest_double = double_arr[i];
        }
    }
                             
                             printf("\n%.2lf", biggest_double);
    
    return 0;
}


