/*
  File:   aritmetica_ponteiros.c
  Author: lflrsilva

  Topicos abordados:
  - Conceitos sobre aritmetica de ponteiros
  - Aplicacoes com ponteiros
  - Teoria sobre operacoes relacionais com ponteiros

  Aritmetica de ponteiros
 
  Ponteiros alocam a informacao de posicao (endereco) na memoria.
  O endereco na memoria eh um valor, que referencia a sua posicao.
  Sendo assim, eh possivel realizar operacoes simples com ponteiros:
  ++, --, + e -
  
  int *m;     // 4 bytes para inteiros

  Assumindo que m aponta para o local de memoria 1000:

  m++;

  O local de memoria sera atualizado de onde m aponta
  para 1004: 1000 + 4 bytes.

  Comparacao de ponteiros

  Pode-se comparar ponteiros com operadores relacionais ==, < e >
  
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

#define NMAX 3

int main(int argc, char** argv) {

    int var[] = {10, 100, 300};
	int i, *ptr;
	
	ptr = var;
	for(i = 0; i < NMAX; i++)
	{
        // mudar %p para %d
		printf("Endereco de var[%d] = %p\n", i, ptr );
		printf("Valor de var[%d]    = %d\n", i, *ptr );
		
		// movendo a posicao de ptr na memoria
		ptr++;
	}

    return (EXIT_SUCCESS);
}
