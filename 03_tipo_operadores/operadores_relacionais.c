/*
  File:   operadores_relacionais.c
  Author: lflrsilva

  Topicos abordados:
  - Treinamento de depuracao
  - Operadores relacionais:
    - Igual a          : ==
    - Maior que        : >
    - Menor que        : <
    - Maior ou igual a : >=
    - Menor ou igual a : <=
    - Nao igual a      : !=
  - Avaliacao de operacoes relacionais

  - Operadores logicos:
    - E   : &&  (o pessimista)
    - OU  : ||  (o otimista)
    - NAO : !
  - Avaliacao de operacoes logicas

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   // inclusao de variaveis booleanas

int main(int argc, char** argv) {

    // declaracao de variaveis
    int  a = 10, b = 20;
	bool t1 = true, f1 = false;
	bool t2 = true, f2 = false;
	
    // operacoes relacionais
	// resultado: verdadeiro (1) ou falso (0)
	int res1 = ( a == b );   // res1 = ?
	int res2 = ( a > b  );   // res2 = ?
	int res3 = ( a < b  );   // res3 = ?
	int res4 = ( a >= b );   // res4 = ?
	int res5 = ( a <= b );   // res5 = ?
	int res6 = ( a != b );   // res6 = ?
	
    // operacoes logicas
	// resultado: verdadeiro (1) ou falso (0)
	int loc1 = (t1 && t2);   // loc1 = ?
	int loc2 = (t1 && f1);   // loc2 = ?
	int loc3 = (f1 && f2);   // loc3 = ?

	int loc4 = (t1 || t2);   // loc4 = ?
	int loc5 = (t1 || f1);   // loc5 = ?
	int loc6 = (f1 || f2);   // loc6 = ?

	int loc7 = !(t1 || t2);  // loc7 = ?	

    return (EXIT_SUCCESS);
}
