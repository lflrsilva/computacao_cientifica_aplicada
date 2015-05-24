/* 
  File:   gsl_arrays.c
  Author: lflrsilva
   Topicos abordados:
  - Uso de vetores e matrizes com GSL (ver manual)

 Definicao de gsl_vector: estrutura de dados
 
    typedef struct
    {
       size_t size;        // no. de elementos
       size_t stride;      // tamanho do tipo alocado
       double * data;      // local na memoria do primeiro elemento
       gsl_block * block;  // dados do vetor
       int owner;          // flag para desalocar memoria
    } gsl_vector; 
 
  Alocacao de espaco na memoria:
  gsl_vector * gsl_vector_alloc (size_t n)

  Liberando o espaco na memoria:
  void gsl_vector_free (gsl_vector * v)

  Acessando  os valores dos elementos do vetor:
  double gsl_vector_get (const gsl_vector * v, size_t i)

  Atribuindo valor x ao elemento i do vetor:
  void gsl_vector_set (gsl_vector * v, size_t i, double x)

  Escrevendo em arquivo  
  int gsl_vector_fprintf (FILE * stream, const gsl_vector * v, const char * format)
  
  Lendo de arquivo
  int gsl_vector_fscanf (FILE * stream, gsl_vector * v)
  
  Obs.: Operacoes de algebra linear estao descritos na secao BLAS
 
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved. 

 */

#include <stdio.h>
#include <stdlib.h>
#include <gsl_vector.h>

int main(int argc, char** argv) {
    
    int n = 10, i;
    gsl_vector* v = gsl_vector_calloc(n);
    gsl_vector* u = gsl_vector_calloc(n);
    
    for(i=0; i < n; i++)
    {
        // atribuindo valores por elemento
        gsl_vector_set(v, i, i*i + i);
        gsl_vector_set(u, i, i*i - i);

        // acessando valores por elemento
        printf("v_%2d = %g\t u_%2d = %g\n", i,
                gsl_vector_get(v,i), gsl_vector_get(u,i));
    }
    
    // soma, elemento a elemento, de dois vetores
    // Resultado no primeiro argumento da funcao
    gsl_vector_add(v, u);
    
    printf("Result of the addition of v and u\n");
    for(i=0; i < n; i++)
    {
        printf("v_%2d + u_%2d = %g\n", i, i, gsl_vector_get(v,i));
    }
    
    gsl_vector_free(v);

    return (EXIT_SUCCESS);
}

