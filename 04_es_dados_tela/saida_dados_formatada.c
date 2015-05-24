/*
  File:   saida_dados_formatada.c
  Author: lflrsilva

  Topicos abordados:
  - Formatacao de inteiros
  - Formatacao de ponto flutuante
  - Formatacao de strings (cadeia de caracteres) 
  - Caracteres de escape

 Referencias
   [1] http://www.codingunit.com/printf-format-specifiers-format-conversions-and-formatted-output
   [2] http://www.cdf.toronto.edu/~ajr/209/notes/printf.html
   [3] http://www.cprogramming.com/tutorial/printf-format-strings.html 

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    // declaracao de variaveis
    int i = 2;
    long int imax = 2147483644;
    float f = 3.7182;
    double d = 3.1415926535;

    // Saida formatada de inteiro (%d)
    // Impressao em tela da variavel
    printf("Imprimindo o valor de i\n");
    printf("Valor formatado = %d \n", i);
    printf("Valor formatado = %5d \n", i);
    printf("Valor formatado = %5d \n", 100000*i);
    printf("Valor formatado = %20d\n", 100000*i);
    printf("**************************************\n");
    
    printf("Imprimindo o valor de imax\n");
    printf("Valor formatado = %20d\n", imax);
//    printf("Valor formatado = %20ld\n", imax);
    printf("**************************************\n");
    
    // Saida formatada de ponto flutuante (%f, %g)
    // Impressao em tela da variavel
    printf("Imprimindo o valor de f (float)\n");
    printf("Valor formatado = %d \n", f);
    printf("Valor formatado = %f \n", f);
    printf("Valor formatado = %10f \n", f);
    printf("Valor formatado = %10.2f \n", f);
    printf("Valor formatado = %10.7g \n", f);
    printf("Valor formatado = %10.7g \n", d);
    printf("**************************************\n");
    // Variantes para saida formatada em ponto flutuante
    // Impressao em formato exponencial
    printf("Valor formatado = %.4e \n", d);
    printf("Valor formatado = %.3E \n", d);    // arredondamento
    printf("Valor formatado = %10.4le \n", d); // Impressao em formato longo
    printf("**************************************\n");

    // Saida formatada de string (%s)
    // Impressao em tela da variavel
    // Ola, mundo (11 caracteres)
    
    // Impressao da string (nada demais)
	printf(":%s:\n", "Ola, mundo!");
    // Impressao da string com 13 espacos disponiveis
	printf(":%13s:\n", "Ola, mundo!");
    // Impressao da string usando soh 8 caracteres
	printf(":%.8s:\n", "Ola, mundo!");
    // Impressao da string usando soh 8 caracteres
    // e 13 espacos disponiveis
	printf(":%13.8s:\n", "Ola, mundo!");
    printf("**************************************\n");

/*
  Caracteres de escape
CARACTERE	SIGNIFICADO
\a	aviso sonoro (caso a placa mae permita)
\b	retrocesso (backspace)
\f	avanço de formulário (nova pagina)
\n	nova linha
\r	retorno do carro (sem alimentação de linha)
\t	tabulação  horizontal
\\	caractere de barra invertida
\'	apóstrofe
\"	aspas
\?	interrogação
\nnn	valor ASCII em octal
\xnnn	valor ASCII em hexadecimal
*/
    printf("Ola \t mundo \n");
    printf("Ola \t mundo \r Cansei da aula\n");
    
    return (EXIT_SUCCESS);
}
