/*
  File:   condicional_switch.c
  Author: lflrsilva

  Condicionais e compostos
  Uso do Switch

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int i, j, k;

    // atribuicao de 0 a variavel i
    i = 0;

	// avaliacao de i frente a alguns casos
    switch(i) {

        // caso i = 0, executa os comandos abaixo
        case 0:
            j = 6;
            k = 36;
            break;         // saida do comando switch

        // caso i = 5, executa os comandos abaixo
        case 5:
            j = 7;
            k = 7;
            break;         // saida do comando switch

       // caso padrao
       default:           // use default if i != 0 && i !=5
            j = 8;          // default statement
    }

    return (EXIT_SUCCESS);
}
