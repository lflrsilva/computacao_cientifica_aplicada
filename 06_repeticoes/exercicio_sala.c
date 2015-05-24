/*
  File:   exercicio_sala.c
  Author: lflrsilva

 Laços e repetições

 * EXERCICIO EM AULA
 *
 * SUM_i=0,99 SUM_j=200,500 (i-j)
 *
 * 5*PROD_i=1,4 PROD_j=-3,27 (i+j^2)
 
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int i, j;
    int sum;
    long double prod;

    // Calculo do somatorio
    sum = 0;
    for(i=0; i< 100; i++)
    {
        for(j=200; j<=500; j++)
        {
            sum += i - j;
        }
    }
    printf("Resultado da soma eh : %d\n\n", sum);

    // Calculo do produtorio
    prod = 5.;
    for(i=1; i< 5; i++)
    {
        for(j=27; j>= -3; j--)
        {
            prod *= i + j*j;
        }
    }
    printf("Resultado do produtorio eh : %Lg\n\n", prod);

    return (EXIT_SUCCESS);
}
