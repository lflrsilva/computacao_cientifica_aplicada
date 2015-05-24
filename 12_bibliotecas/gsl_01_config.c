/* 
  File:   gsl_config.c
  Author: lflrsilva

  Topicos abordados:
  - Instalacao GNU Scientific Library (GSL)
  - Configuracao para uso de bibliotecas externas (GSL)
  - Configuracao de IDEs
    * Netbeans
    * Xcode

 * Instalacao GSL

  Ubuntu: sudo apt-get install nome_pacotes

  sendo que nome dos pacotes inclui :
  biblioteca      : libgsl0ldbl
  desenvolvimento : gsl-bin libgsl0-dev
  documentacao    : gsl-doc-info gsl-doc-pdf gsl-ref-html

  Mac OS (usando Macports): sudo port install nome_pacotes

  sendo que nome dos pacotes inclui :
  biblioteca completa : gsl

 * Comandos de linha para comilacao e construcao do executavel
  
  Compilacao do codigo:
   gcc -c arquivo_fonte.c -I/path/include/gsl/

  Construcao do executavel:
   gcc arquivo_objeto.o -o gsl_exe -L/path/lib -lgsl -lgslcblas

  Note que path eh o caminho onde a biblioteca esta instalada em seu
  computador.

  Preparo da IDE para uso das bibliotecas GSL
 
  1) Localizar no terminal onde estao os arquivos (*.h e libs)
 
   locate gsl
 
  2) Incluir no projeto/compilador C os diretorios onde estao os arquivos
     de cabecalho (header .h)  :  /usr/include/gsl
 
     Necessario para o reconhecimento das funcoes no momento da compilacao.
 
  3) Incluir no projeto/vinculador os diretorios onde estao as bilbiotecas
     estaticas (arquivo .a)  : /usr/lib
 
  4) Especificar no vinculador quais sao as bibliotecas de interesse:
 
     libgsl.a  (do GSL)  e    libgslcblas.a  (do CBLAS)
 
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved. 

 */

#include <stdio.h>
#include <stdlib.h>
#include <gsl_sf_bessel.h>   // header especificado no manual
                             // para uso das funcoes de bessel

int main(int argc, char** argv) {

    double x = 5.0;
    double y = gsl_sf_bessel_J0(x);
    printf("J0(%5.5le) = %.18le\n", x, y);
    
    return (EXIT_SUCCESS);
}

