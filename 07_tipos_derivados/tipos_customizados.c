/*
  File:   tipos_customizados.c
  Author: lflrsilva

  Topicos abordados:
  - fundamentos de tipos customizados
  - sintaxe de typedef

  Definicao de outros tipos de dados:
 
  Novas definicoes de variaveis com typedef
 
  Definicao de um novo tipo com base nos tipos ja'
  existentes.
 
  typedef tipo novo_nome;
  
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

typedef double real;        // uma vez definido real
typedef real dprecision;    // pode-se usa-lo para definir
                            // outra variavel.
typedef struct {
    int x;
    float f;
} mystruct;

int main(int argc, char** argv) {

    real dp;
    dprecision dp2;
    mystruct s = {1, 2.71};

    dp  = 3.14;
    dp2 = dp;
    printf("Estrutura: %d\t%e\n", s.x, s.f);
    
    return (EXIT_SUCCESS);
}
