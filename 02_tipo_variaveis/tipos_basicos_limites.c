/*
  File:   tipos_basicos_limites.c
  Author: lflrsilva

  Topicos abordados:
  - Quantidade de memoria alocada
  - Limites dos valores das variaveis
  - Introducao a precisao numerica

  Obs.: valores dos limites escritos no codigo sao de sistemas
  32 bits e podem variar entre diferentes SOs.

  Referencias:
  [1] http://www.tutorialspoint.com/c_standard_library/index.htm
  [2] http://en.wikibooks.org/wiki/C_Programming/C_Reference/limits.h

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>    // define EXIT_SUCCESS
#include <limits.h>    // valores limite de inteiros
#include <float.h>     // valores limite de ponto flutuante

int main(int argc, char** argv) {

    // Variaveis inteiras
	int i;                // -32768 a 32767 (2 bytes)
	                      // -2147483648 a 2147483647 (4 bytes)

    // restringe a variavel a valor positivo
    unsigned int j;       // 0 a 65535 (2 bytes)
	                      // 0 a 4294967295 (4 bytes)

    // define a quantidade de bytes alocados
    // 2 bytes
    short int k;           // -32768 a 32767
	unsigned short int l;  // 0 a 65535
	
    // 4 bytes
    long int m;           // -2147483648 a 2147483647
	unsigned long int n;  // 0 a 4294967295
	
    // declaracao de variavel em ponto flutuante
    // precisao simples (4 bytes - ~ 6  casas decimais)
    float fpi;            // 1.2E-38 a 3.4E+38

    // precisao dupla   (8 bytes - ~ 15 casas decimais)
    double dpi;           // 2.3E-308 a 1.7E+308

    // precisao dupla estendida  (10 bytes - ~ 19 casas decimais)
    long double ldpi;     // 3.4E-4932 a 1.1E+4932
	
	// saida em tela de bytes armazenados na memoria
	printf("Qtde de armazenada para int    : %d \n", sizeof(int));
	printf("Qtde de armazenada para float  : %d \n", sizeof(float));
	printf("Qtde de armazenada para double : %d \n", sizeof(long double));
	printf("Qtde de armazenada para char   : %d \n", sizeof(char));
    printf("\n");

	// saida em tela dos limites das variaveis inteiras
	// constantes macro definidas em limits.h
    printf("Valor minimo para SHORT INT = %d\n", SHRT_MIN);
    printf("Valor maximo para SHORT INT = %d\n", SHRT_MAX);
    printf("\n");

    printf("Valor minimo para INT = %d\n", INT_MIN);
    printf("Valor maximo para INT = %d\n", INT_MAX);
    printf("\n");

    printf("Valor maximo para UNSIGNED LONG INT = %lu\n", ULONG_MAX);
    printf("\n");

	// saida em tela dos limites das variaveis em ponto flutuante
	// constantes macro definidas em float.h
    printf("Valor minimo para FLOAT = %.10e\n", FLT_MIN);
    printf("Valor maximo para FLOAT = %.10e\n", FLT_MAX);
    printf("\n");

    printf("Valor minimo para DOUBLE = %.10e\n", DBL_MIN);
    printf("Valor maximo para LONG DOUBLE = %.10Le\n", LDBL_MAX);
	
    return (EXIT_SUCCESS);
}

