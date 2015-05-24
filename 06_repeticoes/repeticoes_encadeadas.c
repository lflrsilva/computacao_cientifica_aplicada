/*
  File:   repeticoes_encadeadas.c
  Author: lflrsilva

  Topicos abordados:
  - Uso de repeticoes encadeadas
  - Aplicacao de comandos encadeados

  Sintaxe basica:
 
  for (i=0; i<=5; i++)
  {
      statement1;
      ...
      for(j=0;j<=3; j++)
      {
          statement2;
          ...
      }
      statement3;
      ...
  }

  Cuidados:
  - Contadores nos lacos interno e externo
  - Uso de break e continue

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.
 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int i, j, k, levels, space;
    int nmax = 100;

    // obtendo nos. primos inteiros
    // no. primo soh divisivel por ele mesmo
    for(i = 2; i<nmax; i++)
    {
        for(j = 2; j <= (i/j); j++)
        {
            if( !(i%j) )
            {
                // caso encontre resto na divisao, nao eh no. primo
                break;
            }
        }
       if(j > (i/j))
       {
           printf("%d eh primo\n", i);
       }
    }

    // construindo uma piramide
    printf("Entre com o numero de niveis na piramide:");
    scanf("%d",&levels);
 
    space = levels;
 
    for ( i = 1 ; i <= levels ; i++ )
    {
        for ( k = 1 ; k < space ; k++ )
        {
            // escrevendo espacos em tela ate coluna = nivel -1
            printf(" ");
        }
        
        space--;
 
        for ( k = 1 ; k <= 2*i - 1 ; k++ )
        {
            // construindo a piramide
            printf("*");
        }
        printf("\n");
    }

    return (EXIT_SUCCESS);
}
