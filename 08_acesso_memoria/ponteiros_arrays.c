/*
  File:   ponteiros_arrays.c
  Author: lflrsilva

  Topicos abordados:
  - Ponteiros para arrays
  - Array de ponteiros

  Ponteiros para arrays: manipulacao de memoria
 
  Arrays sao ponteiros constantes que apontam para o
  primeiro elemento da lista. Portanto, ao atribuir um
  array a um ponteiro, este ira apontar para o primeiro
  elemento do array.
  
  double m[25];
  double *ptr;
  
  ptr = m;

  m     [0] [1] [2] [3] ... [23] [24]
  ___|___|___|___|___|___|___|___|___|___|
         ^*ptr
 
  Diferente do array, o ponteiro pode ser movido nos enderecos
  de memoria e, assim, acessar outros dados. 

  for(i = 0; i < 25; i++)
  {
      printf("*(ptr + %d) : %f\n", i, *(ptr + i) );
  }
 
  Eh possivel criar um array de ponteiros e usa-los de forma
  independente:
 
  double *ptr[25];

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

#define NMAX 5

int main(int argc, char** argv) {

    double m[NMAX] = {10.0, 20.0, 30.0, 35.0, 60.0};
	double *ptr, *pta[NMAX];
	int i;
	
    // atribuindo o endereco de m[0] a ptr
	ptr = m;
	
	printf("Acesso aos dados pelo ponteiro ptr: \n");
	for(i = 0; i < NMAX; i++)
	{
		printf("*(ptr + %d) : %f\n", i, *(ptr + i) );
	}

	printf("\n");

	printf("Acesso aos dados pelo endereco de m: \n");
	for(i = 0; i < NMAX; i++)
	{
		printf("*(m + %d) : %f\n", i, *(m + i) );
	}
	
    //atribuindo cada elemento do array de ponteiros para cada
    //elemento do array do tipo double
	for(i = 0; i < NMAX; i++)
	{
        // atribuindo o endereco de cada elemento a um ponteiro
		pta[i] = &m[i];
	}
	
    return (EXIT_SUCCESS);
}
