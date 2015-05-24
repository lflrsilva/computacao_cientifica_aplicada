/*
  File:   acesso_memoria.c
  Author: lflrsilva

  Topicos abordados:
  - Conceitos de endereco e ponteiros
  - Aplicacao dos ponteiros
  - Manipulacao de dados com ponteiros
  - Ponteiros nulos

  Ponteiro e Referencia: manipulacao de memoria
 
  Ponteiros sao um tipo de variavel que nao aloca valores em si,
  mas enderecos de memoria. Portanto, armazena o local de memoria
  para onde dado ponteiro aponta.
 
  Um ponteiro aponta para dado local (endereco) na memoria.
  Se int* T, T aponta para o endereco de uma variavel inteira.
 
  int* p; // eh o ponteiro de um inteiro
 
  __|__|__|__|__|__|__|__|__|__|
              ^*p
  A referencia eh o endereco na memoria onde dada variavel esta
  alocada. Se existe a declaracao de int i, &i eh o endereco
  onde i esta alocado.

  Pode-se apontar o ponteiro para o local de memoria onde i esta
  alocado.

  int i;
  int* p;
  p = &i;

              &i
  __|__|__|__|__|__|__|__|__|__|
              ^*p

  Diferente de ponteiros, nao se declara enderecos de memoria.

  Ponteiros podem ser localizados no espaço nulo de memoria.
 
  int *p = NULL;

  sendo que *p aponta para o primeiro espaco de memoria (0)
  do computador (nao eh usado pelo sistema). Pode-se usar testes
  condicionais para checar se o ponteiro eh nulo ou nao.

  if(p)    // true se p nao for nulo

  if(!p)   // true se p for nulo

  Muitas vezes inicializa-se o ponteiro como NULL para nao afetar o
  sistema.

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    // declaracao das variaveis
    int  i  = 5;        // i eh int, valor do objeto i é 5.
    int* pi = &i;       // pi eh um ponteiro de um inteiro
                        // e atribui o endereco de i a pi
    int  j  = *pi;      // valor da variavel apontada por pi
                        // e atribuido a j, j = 5

	int *ptr = NULL;    // espaco null

//    double* ii = &j;       // ILEGAL!!

    double d1 = 2.7, d2 = 3.1;

    double* p = &d1;    // p aponta para d1, *p = 2.7
    double a = *p;      // a = 2.7
    p = &d2;            // p aponta para d2, *p = 3.1
                        // Aqui p muda para onde aponta na memoria

    double b = *p;      // b = 3.1
    *p = 5.5;           // o valor para qual p aponta eh 5.5
                        // Aqui o valor para o qual p aponta muda

    double c = *p;      // c = 5.5
    double d = d2;      // d = 5.5, ja que *p = 5.5
	
	// Apresentando em tela o endereco na memoria
	// formato %p : endereco de ponteiro
	printf("Endereco de d2: %p\n", &d2);
	printf("Endereco de p: %p\n", p);

    printf("Alterando o endereco de p...\n");
    p = &d;
	printf("Endereco de p: %p\n", p);
	
    return (EXIT_SUCCESS);
}
