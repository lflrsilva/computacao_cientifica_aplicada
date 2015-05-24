/*
  File:   operadores_relacionais_avancado.c
  Author: lflrsilva

  Topicos abordados:
  - Uso de operadores relacionais e logicos
  - Introducao aos condicionais
  - Avaliacao de operacoes avancadas

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    // declaracao de variaveis
    int x = 5;
    int i = 2, j = 2;

    // condicional SE
	// conteudo do condicional so eh
	// executado SE condicao for verdadeira
    if (x < 6)  // argumento true
    {
        // Executa codigo entre chaves
        printf("Entrei no condicional?\n");
        x = 7;
    }

    if (x == 0)  // argumento false
    {
        // Executa codigo entre chaves
        printf("Entrei no condicional?\n");
        x = 0;
    }

    if (0) x = 17;   // Inteiro 0 é interpretado como false

    if (1) x = 20;   // Qualquer valor diferente de 0 é true (padrão 1)

    x = 7;
    if(3 < x < 9)    // true ou false????
    {
        // executa codigo dentro do condicional???
        printf("Ola!\n");
    }

    x = 20;
    if(3 < x < 9)    // true ou false????
    {
        // executa codigo dentro do condicional???
        printf("Oi!\n");
    }

    if( (i = 0) && (j = 3) )    // true ou false????
    {
        // executa codigo dentro do condicional???
        printf("Eita!\n");
    }

    if( (i = 4) || (j = 5) )    // true ou false????
    {
        // executa codigo dentro do condicional???
        printf("Loucura!\n");
    }

    if( (i = 0) || (j = 6) )    // true ou false????
    {
        // executa codigo dentro do condicional???
        printf("Que viagem!\n");
    }

    return (EXIT_SUCCESS);
}
