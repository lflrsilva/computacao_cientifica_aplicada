/*
  File:   tipos_listas_arrays.c
  Author: lflrsilva

  Topicos abordados:
  - fundamentos de alocacao de arrays
  - sintaxe no uso de arrays
  - arrays 1d
  - arrays 2d

  Arrays: vetores e matrizes
 
  Sendo T uma variável declarada, T[n] é um array ou lista 
  unidimensional (vetor) de n elementos com o mesmo tipo de T.
 
  Os elementos são indexados a partir de 0 ate n-1 e são armazenados
  em sequência na memória.

  int T[5];     alocacao 5 x ( 4 bytes ) = 20 bytes

  |___|___|___|___|___|
    0   1   2   3   4
  
  Para lista bidimensional, T[n][m] aloca uma matriz com n linhas e m
  colunas, com elementos do mesmo tipo de T.

  int T[3][2];  alocacao 3 x 2 x (4 bytes) = 24 bytes

  n  
   0 |___|___|
       0   1   m

   1 |___|___|
       0   1   m

   2 |___|___|
       0   1   m

  Contudo, um array bidimensional eh armazenado sequencialmente na memoria,
  na ordem de linhas e colunas
   
   n =   0       1       2
         |___|___|___|___|___|___|
   m =     0   1   0   1   0   1

  De modo geral, armazenamento sequencial na memoria
     
  Memória RAM
  int v[n];  // sequencial
  ____|____|____|____|____|______|
   v[0] v[1] v[2]    ...    v[n-1]
     
  int v[n][m];  // sequencial por linha
  _______|_______|_______|_________|_______|_______|_______|_________|
  v[0][0] v[0][1]   ...   v[0][m-1] v[1][0] v[1][1]   ...   v[1][m-1] ...
     
  Qual o uso eficiente do acesso a memoria em arrays 2D?? Lembre-se
  que a informacao passa para a memoria cache!
    
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Nmax 30

int main(int argc, char** argv) {

    int i,j;
    float vec[3];     // array 1D com 3 floats; vec[0], vec[1], vec[2]
    int st[Nmax];     // array 1D com 30 ints; st[0], ... st[29]

    double mt[2][5];  // array 2D c/ 2 linhas e 5 colunas

    // Declaracao com inicializacao
    int v[] = {1, 2, 3, 4};
    int a[3]= {2, 4, 5};
    int u[][3] = { {1, 2, 3} , {4, 5, 8} };
    char filename[30] = "output";   // array de caracteres

    /* Erro se declarado E inicializado assim:
     * int v[4];
     * v = {2, 4, 5, 9}; // Erro!! Não dá para ser assim.
     */

    vec[0] = 1.0;
    vec[2] = 2.0;

    for(i = 0; i < 30; i++) {
        st[i] = i*i + 7;
    }

    j = st[29];

    mt[0][0] = 5.0;
    mt[1][4] = 5.0;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 5; j++) {

            mt[i][j] = i + j;  // conversao implicita de tipos
        }
    }

    // As operacoes NAO podem ser realizadas diretamente com arrays
    // apenas com os COMPONENTES do array.

    j = st[0] * st[29];

    mt[0][0] = mt[1][1] + mt[0][4] * pow(mt[1][3], 2.5);

    return (EXIT_SUCCESS);
}
