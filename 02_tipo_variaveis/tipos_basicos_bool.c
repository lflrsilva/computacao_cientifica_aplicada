/*
  File:   tipos_basicos_bool.c
  Author: lflrsilva

  Topicos abordados:
  - Historico, novas implementacoes
  - 0 (falso) ou qualquer valor (verdadeiro)
  - Variaveis booleanas (VERDADEIRO
    OU FALSO)

  Referencias:
  [1] http://en.wikibooks.org/wiki/C_Programming/Variables#Data_type_modifiers

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Uma alternativa eh criar macros
#define false 0
#define true  1
*/

int main(int argc, char** argv) {

    // declarando variavel booleana
	bool teste_true  = true;
	bool teste_false = false;
	
	// ver resultado das variaveis
	printf("Resultado de true  = %d\n", teste_true);
	printf("Resultado de false = %d\n", teste_false);
	
    return (EXIT_SUCCESS);
}

