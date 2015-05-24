/*
  File:   operadores_aritmeticos.c
  Author: lflrsilva

  Topicos abordados:
  - Treinamento de depuracao
  - Operacoes basicas (+ - * / %)
  - Operacoes com inteiros
  - Operacoes de ponto flutuante
  - Precedencia de operacao
  - Uso de parenteses

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    // declaracao de variaveis
    double d = 3.14;
    int n = 2;

    // operacoes entre tipos de variaveis
    int m = d + n;      // m = ?, conversao implicita entre tipos
    double c = d + n;   // c = ?, conversao implicita entre tipos

    // operacoes entre inteiros
    double a = 13/4;    // a = ?
    double x = 3/4;     // x = ?
	
	// conversao de tipos de variaveis
    double y = 3.0/4;   // y = 0.75
    double z = 3/4.0;   // z = 0.75
	
	// uso de remainder (%)
    int t = 13%4;       // t = 1, resto de 13/4 eh 1
                        // 12/4 = 3, resta 1
	
	// operacoes compostas
	// execucao da expressao da esquerda para direita
	// precedencia: * ou / e + ou -
	n = 2 + 3*4 - 4/2;
	n = (2 + 3)*4 - 4/2;
	n = 2 + 3*(4 - 4)/2;
	n = 2 + (3*(4 -4)/2);

    return (EXIT_SUCCESS);
}
