/*
  File:   passagem_arrays.c
  Author: lflrsilva

  Passagem de arrays (vetores e matrizes)
 
  Para arrays como argumentos da sub-rotina, apenas o endereco e'
  passado como parametro. No caso, sempre para o primeiro elemento
  do array. Neste caso, a passagem eh sempre por referencia e o usuario
  pode alterar o conteudo do argumento passado para a sub-rotina. Pode-se
  evitar isso passando o argumento como uma variavel constante.

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

// Diferentes formas de declaracao do prototype
// void display(int num[10]);
// void display(int num[]);
void display(int* num);

// Prototype para somatorio
double h(double* const d, int n);           // ponteiro constante
// double h(const double* const d, int n);  // variavel e ponteiro const

int main(int argc, char** argv) {

    int t[10], i;

    double a[] = {1, 2, 8, 20, -10, 30};
    double sum, d5;

    for (i=0; i < 10; i++) {
        t[i] = i;       
    }

    display(t);

    sum = h(a,6);   // Soma dos elementos de a
    d5 = a[5];      // d5 = 1000

    return (EXIT_SUCCESS);
}
