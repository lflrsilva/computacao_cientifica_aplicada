/*
  File:   tipos_enumeracao.c
  Author: lflrsilva

  Topicos abordados:
  - fundamentos de enumeracao
  - sintaxe de enumeracao

  Enumeration - estrutura de variaveis do tipo constantes inteiras
  para tornar melhor a leitura do codigo. A estrutura inicia em 0,
  por padrao. Caso contrario, deve-se especificar o primeiro valor.
 
  // definicao
  enum nome_enumer {
      lista_de_enumeracao   // itens separados por virgula
  };

  // declaracao de var como enum
  enum nome_enumer var;

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    enum dia_semana {
        domingo = 1,    // valor de 1
        segunda,        // valor de 2
        terca,          // valor de 3
        quarta,         // valores subsequentes
        quinta,
        sexta,
        sabado
    };

    // declaracao de variaveis
    enum dia_semana feira, aniversario;

    feira = quarta;

    aniversario = sabado;

    printf("%d\n", feira);    // saida em tela como inteiro OK
//    printf("%s\n", feira);    // saida em tela como string PEEEE!!

    return (EXIT_SUCCESS);
}

