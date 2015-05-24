/*
  File:   entrada_dados_formatada.c
  Author: lflrsilva

  Topicos abordados:
  - Entrada de inteiros
  - Entrada de ponto flutuante

 Referencias
   [1] http://www.cplusplus.com/reference/cstdio/
   [2] http://www.cplusplus.com/reference/cstdio/scanf/

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    // declaracao de variaveis
    int i, j;
    float f;
    double d;

    // Entrada de dados para variavel inteira (%d)
    printf("Entre com um valor inteiro: ");
    scanf("%d", &i);
    printf("O valor lido foi %d\n", i);
    printf("**************************************\n");

    // Entrada de dados para variavel ponto flutuante (%f, %g, %e)
    printf("Entre com um valor pt flutuante (float): ");
    scanf("%g", &f);
    printf("O valor lido foi %f\n", f);
    printf("**************************************\n");

    // Entrada de dados para variavel ponto flutuante (%lf, %lg, %le)
    printf("Entre com um valor pt flutuante (double): ");
    scanf("%lf", &d);
    printf("O valor lido foi %le\n", d);
    printf("**************************************\n");

    return (EXIT_SUCCESS);
}
