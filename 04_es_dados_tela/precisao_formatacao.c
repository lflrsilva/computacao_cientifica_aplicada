/*
  File:   precisao_formatacao.c
  Author: lflrsilva

  Precisao de ponto flutuante

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {

    float fpi = atan(1)*4;         // precisão simples    ~ 7  digitos
    double dpi = atan(1)*4;        // precisão dupla      ~ 14 digitos
    long double ldpi = atan(1)*4;  // precisão estendida  ~ 17 digitos

    // Formatando a saida de dados em tela
    printf("O valor de fpi eh:  %.30g\n",  fpi);
    printf("O valor de dpi eh:  %.30g\n",  dpi);
    printf("O valor de ldpi eh: %.30Lg\n", ldpi);

    return (EXIT_SUCCESS);
}

