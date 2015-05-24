/*
  File:   repeticoes_for.c
  Author: lflrsilva

  Topicos abordados:
  - Uso de repeticoes (lacos)
  - Aplicacao do comando for
  - Interrupcao de laco com break 
  - Continuacao do laco com continue

  Laços e repetições
  Sintaxe basica:
 
  for (initialize; condition; expression)
  {
      statement1;
      statement2;
      ...
  }

  Etapas:
  - Inicializa o contador
  - Avalia a condicao de execucao do laco. Executa comandos se true
  - Ao fim da execucao de uma repeticao:
     - excuta expressao
     - avalia condicao
     - Caso condicao seja true, realiza uma repeticao
     - Caso false, executa comando logo apos o laco

  Cuidados:
  - Os 3 argumentos sao opcionais. Laco infinito!
 
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.
 */

// Área de declaração de bibliotecas e funções
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int i, nmax = 10;

    // Avaliação da repetição usando for
    printf("Inicializa variavel i = 0 dentro do laco\n");
    printf("Avalia se i < imax para execucao do laco\n");
    for(i=0; i < nmax; i++)
    {
        printf("Iteracao : %d\t", i);
        printf("Executa expressao i++ : %d\t", i+1);
        printf("Checa condicao i<nmax? : %d\n", (i+1) <nmax );
    }
    printf("\n");

    // Mais um teste
    for(i = 3; i < 50; i *= 2)
    {
        printf("i = %d\n", i);
    }
    printf("\n");

    // Isso eh executado?
    for (i = 3; i > 5; i *= 2)
    {
        printf("%d\n", i);
    }
    printf("\n");

    // uso de outras expressoes
    for(i = 10; i > 0; i--)
    {
        printf("%d\n", i);
    }
    printf("Feliz Ano Novo!\n");

    // Uso do continue e break
    for (i = 3; i < 50; i *= 2)
    {
        if (i == 6)
            continue;             // passa a proxima iteracao quando i == 6

        printf("i = %d\n", i);    // impressao em tela do valor de i

        if (i == 24)
            break;                // interrompe execucao do laco quando i == 24
    }

    return (EXIT_SUCCESS);
}

