/*
  File:   codigo_principal.c
  Author: lflrsilva

  Topicos abordados:
  - Conceitos sobre funcoes e subrotinas
  - Sintaxe e passagem de dados
  - Formas de passagem de dados

 * Sub-rotinas:
  Estrutura modular no desenvolvimento do codigo, usando codigos auxiliares
  chamados funcoes ou sub-rotinas. As instrucoes sera executadas em uma
  estrutura independente do codigo principal ( main() ). Portanto, o
  codigo principal deve enviar informacoes para a sub-rotina. Por sua vez,
  ao finalizar suas operacoes a sub-rotina deve retornar o resultado para
  o codigo principal.

  A definicao geral de subrotinas segue abaixo:
  
  tipo_retorno nome_funcao ( lista_parametros )
  {
      comandos dentro da sub-rotina
  }
  
  - tipo_retorno: a sub-rotina deve retornar um valor ao codigo principal.
    Define-se o tipo da variavel a ser retornada. Caso nao se deseje retornar
    nenhuma informacao, utiliza-se void.

  - nome_funcao: auto-explicativo

  - lista_parametros: Valores no codigo principal nao sao conhecidos pela
    sub-rotina. Assim, deve-se passar as variaveis necessarias para executar
    os comandos dentro da sub-rotina.

  - comandos: auto-explicativo

  Ex.: www.tutorialspoint.com

	// function returning the max between two numbers
	int max(int num1, int num2)
	{
	   // local variable declaration
	   int result;

	   if (num1 > num2)
	      result = num1;
	   else
	      result = num2;

	   return result;
	}

 * Declaracao de subrotinas : prototypes

  As rotinas podem ser escritas diretamente no arquivo fonte do
  codigo principal ou em um arquivo em separado. Quando escritas
  em arquivo separado ou apos o main(), deve-se declara-las
  (prototype). A declaracao de sub-rotinas deve conter:

  tipo_retorno nome_funcao ( lista_parametros );
 
  Ex.: www.tutorialspoint.com

  Pode-se declarar a funcao acima como:

  int max(int num1, int num2);

  Nao e necessario explicitar o nome das variaveis, apenas o
  tipo das variaveis que seram passadas para a subrotina.

  int max(int, int );
 
  Mais exemplos de prototype:

  int square(int);             // recebe int, retorna int
  double sum(double,double);   // recebe 2 double, retorna 1 double
  int f();                     // nao recebe nada, retorna int
  void g(double,double);       // recebe dois double, nao retorna nada
 
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

// declaracao de prototype
int max(int num1, int num2);

int main(int argc, char** argv) {

	// declaracao das variaveis em main()
	int a = 100;
	int b = 200;
	int ret;
 
	// chamando a funcao para obter o valor maximo
	ret = max(a, b);

	printf( "Valor maximo eh : %d\n", ret );

    return (EXIT_SUCCESS);
}

// implementacao da funcao
int max(int num1, int num2) 
{
   //declaracao das variaveis locais da funcao
   int result;
 
    if (num1 > num2) {
        result = num1;
    }
    else {
        result = num2;
	}
 
   return result; 
}