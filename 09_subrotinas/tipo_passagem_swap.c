/*
  File:   tipo_passagem_swap.c
  Author: lflrsilva

  Topicos abordados:
  - Passagem de dados por valor ou referencia

  * Passagem de argumentos

  1) por valor      : o valor da variavel de entrada e' passado para dentro
                      da sub-rotina. Se existir manipulacao do valor na
                      sub-rotina, este nao e' alterado no programa principal.
 
  2) por referencia : o endereco de memoria da variavel e' passado para a
                      sub-rotina. Ao alterar o valor na sub-rotina, este
                      tambem o sera' no programa principal.
                      PASSAGEM POR PONTEIRO !!

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

// passagem por valor
int pass_val_value(int x)
{
    x = x*x;
    return(x + 5);
}

// passagem por referencia
int pass_val_refer(int* x)
{
    int temp;
    temp = *x;
    *x = temp*temp;
    return(temp);
}

// declaracao de prototype
void swap(int* p, int* q);
void swap_val(int , int );
void swap_ref(int* , int* );

int main(int argc, char** argv) {

    int i, j;

    i = 5;
    j = pass_val_value(i);
    printf("por valor: i = %2d e j = %2d\n", i, j);

    i = 5;
    j = pass_val_refer(&i);
    printf("por refer: i = %2d e j = %2d\n", i, j);

    i = 10;
    j = 20;
    printf("Valores no programa principal: i = %2d e j = %2d\n", i, j);

    swap_val(i, j);
    printf("Troca de valores por valor: i = %2d e j = %2d\n", i, j);

    swap_ref(&i, &j);
    printf("Troca de valores por refer: i = %2d e j = %2d\n", i, j);

    //Finalização
    return (EXIT_SUCCESS);
}
/*
void swap(int* p, int* q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
*/