/* 
  File:   aula1_1.c
  Author: lfernando
 
  Comentários de código em C entre os simbolos
 ou com uso de //

 Declaração e saída de variáveis em tela.
 */

// Área de declaração de bibliotecas e funções
#include <stdio.h>
#include <stdlib.h>
// #include <math.h>

/* Descomentar 3
 // Declaração de função
double f(int i) {
  return (i*i + (i-1)*(i-1) + (i-2)*(i-2) - 5)/3.14;
}
*/

// Início do programa principal
int main(int argc, char** argv) {

    // REGIÃO DE EXECUÇÃO
    // 1 - DECLARAÇÃO DAS VARIÁVEIS USADAS
    // 2 - ESTRUTURA DO CÓDIGO
    // 3 - FINALIZAÇÃO
    
//  DECLARAÇÃO DE VARIÁVEIS
/* Descomentar 1
    int x;          // x is declared to be of integer type
    float y = 3.14; // y is a floating point number and initialized with 3.14
    double z;       // z is a floating point number

    double f(int);  // f is a function taking an integer as
                    // its argument and returning a double

 */

//  ESTRUTURA DO CÓDIGO
/* Descomentar 2
    z = y + f(x);

    printf("O valor de x eh: %d\n", x);
    printf("O valor de y eh: %g\n", y);
    printf("O valor de z eh: %f\n", z);
    printf("\n");

    // Formatando a saida de dados em tela
    printf("O valor de x eh: %5d\n",   x);
    printf("O valor de y eh: %5.5f\n", y);
    printf("O valor de f eh: %5.5E\n", f(x));
    printf("O valor de z eh: %5.7g\n", z);

//  Exemplos de formatação
//   Exibe valor com um mínimo de 5 caracteres
//   e com 3 dígitos a direita do ponto decimal
//    printf("  %5.3f ", valor);

     printf("Esta string é muito grande e por isso foi\
   quebrada em mais de uma linha. Para fazer isso você\
   deve usar o sinal de barra invertida.");


/*
  Caracteres de escape
CARACTERE	SIGNIFICADO
\a	aviso sonoro
\b	retrocesso
\f	avanço de formulário
\n	nova linha
\r	retorno do carro (sem alimentação de linha)
\t	tabulação  horizontal
\v	tabulação vertical
\\	caractere de barra invertida
\'	apóstrofe
\"	aspas
\?	interrogação
\nnn	valor ASCII em octal
\xnnn	valor ASCII em hexadecimal
*/

// */

//  FINALIZAÇÃO
    return (EXIT_SUCCESS);
}
