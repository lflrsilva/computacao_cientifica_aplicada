/*
  File:   tipos_basicos_modifiers.c
  Author: lflrsilva

  Topicos abordados:
  - Criacao de macro usando define
  - Variaveis constantes
  - Alocacao no registro de memoria
  - Detalhes de static, extern, volatile, auto

  Referencias:
  [1] http://en.wikibooks.org/wiki/C_Programming/Variables#Data_type_modifiers

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>    // define EXIT_SUCCESS

// definindo macros (sem ;)
#define PRECO_DO_OLEO 100

int main(int argc, char** argv) {

    // declarando uma variavel constante
	const int i = 10;
	// alocacao da variavel no registro
	register double j = 1.75;
	
	// nao eh possivel alterar o valor da variavel
	// i = 11;
	
    return (EXIT_SUCCESS);
}

