/*
  File:   operadores_incremento.c
  Author: lflrsilva

  Topicos abordados:
  - Treinamento de depuracao
  - Operadores de incremento:
  - Avaliacao de operacoes de incremento

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    // declaracao de variaveis
    int  i = 4, j = 4;
    int valor;

    // Incremento e decremento
    i++;                 //  i = i + 1. Assim i = 5
    ++j;                 //  j = j + 1. Assim j = 5

    // Avaliando incremento
    int  m = i++;        //  m = i
	                     //  i = i + 1
	                     // Assim, m = 5, i = 6

    int  n = ++j;        // j = j + 1
	                     // n = j
	                     // Assim n = 6, j = 6

    // Avaliando decremento
    m =  --i;            // m = ?, i = ?
    n =  j--;            // n = ?, j = ?

    j = (i--) + (++i);   // resultado imprevisivel

    // imprimindo em tela
    valor = 1;
    printf("Usando depois da variavel : %d\n", valor++);
    printf("Valor apos incremento: %d\n", valor);

    valor = 1;
    printf("Usando depois da variavel : %d\n", ++valor);
    printf("Valor apos incremento: %d\n", valor);

    // atribuições compostas
    m += 2;              // m = m + 2 = 5 + 2 = 7
    m -= 2;              // m = m - 2 = 7 - 2 = 5
    m *= 2;              // m = 10

/*  Recomendacoes de uso
    my_very_long_variable = my_very_long_variable - 5 // messy
    my_very_long_variable -= 5                        // better
*/

    return (EXIT_SUCCESS);
}
