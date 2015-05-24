/*
 * Entrada e saída de dados
 *
 * Saída em tela   : printf("Ola mundo");
 *
 * Entrada em tela : int scanf("%formato", &varivel);
 *
 *(c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    char eu[20];
    int  i;
    double x;

    printf("Qual o seu nome? ");
    scanf("%s", &eu);
    printf("Muito prazer em conhece-lo, %s!\n",eu);
    printf("\n");

    i = 1;
    while(i>0)
    {
        printf("Entre com um inteiro, cara: ");
        scanf("%d",&i);
    }

    // 16le é a forma mais geral com 16 casas
    // para a entrada do double.
    printf("Entre com um double, cara: ");
    scanf("%16le", &x);

    printf("O valor eh %g\n", x);

    //Finalização
    return (EXIT_SUCCESS);
}
