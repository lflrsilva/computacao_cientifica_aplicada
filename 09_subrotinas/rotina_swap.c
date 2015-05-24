/*
  File:   rotina_swap.c
  Author: lflrsilva

  Rotinas para troca de valores entre as variaveis.
 
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

void swap_ref(int* p, int* q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void swap_val(int p, int q)
{
    int temp;
    temp = p;
    p = q;
    q = temp;
}
