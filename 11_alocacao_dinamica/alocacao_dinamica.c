/* 
  File:   alocacao_dinamica.c
  Author: lflrsilva

  Topicos abordados:
  - Tipos de alocacao de espaco em memoria
  - Sintaxe de uso das funcoes

 * Alocacao Estatica em C
  Representa a alocacao de memoria em tempo de compilacao do codigo. Dados
  se mantem na memoria ate o fim da execucao do programa.
  
  int i;
  double arr[10];
 
 * Alocacao Dinamica em C
  Representa a alocacao de memoria em tempo de execucao do codigo. Deve ser
  usada especificamente para dado tipo de variavel. Deve ser desalocada
  manualmente pelo usuario antes do fim da execucao do programa para evitar
  vazamento de memoria no SO (memoria fica "presa" ate o programa terminar).
 
 * Uso das funcoes em stdlib.h :
 
  void* malloc(size_t<numero_de_bytes>);   --> aloca os bytes na memoria
  void* free(void *p);                     --> desocupa a memoria
 
  tipo size_t definido em stdlib.h como valor de inteiro representando o
  numero de bytes a ser alocado.
 
  A funcao malloc() retorna um ponteiro aplicado a qualquer tipo de variavel.
  O ponteiro retornado se aplica ao primeiro byte de memoria alocada.
  Portanto, aponta para o primeiro elemento de um array, por exemplo.
 
  int* p1;
  p1 = (int*) malloc( 50*sizeof(int) );
 
  sizeof(tipo) eh uma funcao que retorna o numero de bytes necessario para
  alocar o tipo de variavel.
 
  Para desalocar a memoria, usa-se
 
  free(p1);
 
  CUIDADO!! Vazamento de memoria pode travar o seu SO.
 
 * OUTRAS FUNCOES :
 
  void *calloc(size_t nelements, size_t elementSize);
 
  A funcao calloc() tem o mesmo objetivo de malloc, alocando a memoria e
  inicializando-a para zero.
  
  char *word = calloc(200, sizeof(char));
 
  Faltou espaco para as variaveis? Realoque a memoria usando o realloc()
 
  void *realloc(void *pointer, size_t size);
 
  Eh possivel aumentar ou diminuir o espaco de memoria alocado para a regiao
  aplicada para o pointer.
 
  Se a funcao nao for capaz de alterar o bloco de memoria ja alocado em modo
  sequencial, esta aloca um novo bloco com o novo tamanho, copia os dados
  existentes no bloco antigo e limpa o ponteiro como NULL.
 
  void *p = malloc(orig_size);
 
  // e depois no codigo...
  p = realloc(p, big_size);
 
  Falha com realloc() pode causar fuga de memoria. Sempre faca testes quando
  usar este recurso!!! Quando ocorre problema, realloc() coloca o ponteiro como
  NULL.
 
  void *p = malloc(orig_size);
 
  void *tmp = realloc(p, big_size);
  if (tmp != NULL) {
      p = tmp; // OK, atribui um novo e maior bloco para p
  } else {
     // Deu problema! Tratamento do problema para evitar estrago maior...
  }
 
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved. 
 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int  i, n = 10;
    int *p;

    p = (int*) malloc(n*sizeof(int));
//    p = (int*) malloc(10*sizeof(int));  // Com definicao do retorno int*
//    p = malloc(10*sizeof(int));         // Sem definicao do retorno int*

    for(i = 0; i<10; i++)
    {
        p[i] = i*i;
        printf("p[%d] = %2d\n", i, p[i]);
    }


    for(i = 0; i<10; i++)
    {
        p = (int*) realloc(p, (100*n*i)*sizeof(int));
    }
    
    free(p);

    /* Depois de liberar a memoria, o ponteiro fica perdido. O SO pode tentar
     * usar o espaco de memoria que o seu programa liberou e, caso o seu
     * programa tente usar o ponteiro perdido novamente, pode corromper os
     * dados do SO. Para seguranca, apos liberar a memoria, tire o ponteiro
     * dali!!!!
     */
    p = NULL;  // Joguei o ponteiro para um local nulo definido (o SO nao usa!)
    
    return (EXIT_SUCCESS);
}

