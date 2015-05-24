/*
  File:   tipos_uniao.c
  Author: lflrsilva

  Topicos abordados:
  - fundamentos de uniao
  - sintaxe de uniao
 
  Union - estrutura de variaveis com tipos diferentes e
  compartilham o mesmo espaco de memoria.
 
  union nome_union {
      tipo1 var1;
      tipo2 var2;
  };
 
  Ao declarar um union, o compilador aloca um espaco grande
  o bastante para armazenar o maior tipo. As variaveis sao alocadas
  no mesmo espaco de memoria. Utilizado para evitar fragmentacao de
  dados e conversoes nao usuais entre tipos. Por exemplo, uma conversao
  nao usual do arredondamento de um double.
 
  Acesso as variaveis da mesma forma da estrutura (struct).
 
  Comentario LF:
  SINCERAMENTE, NUNCA USEI!!!!

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.
 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    union pw {
        char ch[2];
        int  i;
    };

    // declaracao de variaveis
    union pw word;

    return (EXIT_SUCCESS);
}

