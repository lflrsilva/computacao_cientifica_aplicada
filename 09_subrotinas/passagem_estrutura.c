/*
   File:  passagem_estrutura.c
  Author: lflrsilva

  Topicos abordados:
  - Passagem de estruturas para subrotinas

  Uso de estruturas
 
  - Passagem dos dados da estrutura para funcoes:
  Visto como passagem usual de variaveis, como
  valor ou ponteiro.

  func1(t1.id);   // passagem por valor da variavel
  func1(&t1.id);  // passagem por referencia da variavel

  - Passagem da estrutura para funcoes (valor ou referencia):

  Para passagem por valor, alta perda de eficiencia computacional
  para alocacao dos campos da estrutura dentro da funcao. NAO USEM!!!!

  Apenas pasagem do ponteiro ao passar estrutura por referencia.
  Custo computacional reduzido! Nesta passagem, os campos sao
  acessados dentro da funcao usando o operador -> .
 
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct my_time {
    int horas;
    int minutos;
    int segundos;
};

// declaraco de prototypes
void display(struct my_time *t);
void update (struct my_time *t);

int main(int argc, char** argv) {

    int i;
    struct my_time systime;

    // inicializando variaveis
    systime.horas    = 0;
    systime.minutos  = 0;
    systime.segundos = 0;

    for(i=0;i<70;i++)
    {
        update (&systime);
        display(&systime);
    }

    return (EXIT_SUCCESS);
}

void update(struct my_time *t) {

    t->segundos++;

    // checando se 60 seg conta 1 min
    if(t->segundos == 60) {
        t->segundos = 0;
        t->minutos++;
    }

    // checando se 60 min conta 1 hora
    if(t->minutos == 60) {
        t->minutos = 0;
        t->horas++;
    }

    // checando se 24 horas conta 1 dia completo
    if(t->horas == 24) {
        t->horas = 0;
    }
    // funcao para "dormir" (esperar) um segundo
    sleep(1);
}

void display(struct my_time *t) {
    printf("%02d:",  t->horas);
    printf("%02d:",  t->minutos);
    printf("%02d\n", t->segundos);
}
