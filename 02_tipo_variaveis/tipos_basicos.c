/*
  File:   tipos_basicos.c
  Author: lflrsilva

  Tipos de variaveis:
  - Inteira: sem casas decimais
  - Ponto flutuante: com casas decimais
    - Precisão simples
    - Precisão dupla
  - Caracteres: conjunto básico de caracteres da tabela ASCII
  - Tipo void: sem representação com propósito específico

  Regras obrigatorias para nome de variaveis:
  - Devem necessariamente comecar com uma letra ou
    caractere "_" (underscore)
  - Apenas os primeiros 31 caracteres do nome da variavel
    sao relevantes

  Boas praticas para nome de variaveis:
  - Use caixa baixa para variaveis locais
  - Use CAIXA ALTA para variaveis globais
  - Use um nome que represente o seu interesse
    para a variavel

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>    // define EXIT_SUCCESS

int main(int argc, char** argv) {

    // declaracao de variavel caractere
	char name;            // (1 byte)

    // declaracao de variavel inteira
    int i;                // (2 ou 4 bytes)

    // declaracao de variavel em ponto flutuante
    // precisao simples (4 bytes)
    float fpi;            // ~ 6  casas decimais

    // precisao dupla   (8 bytes)
    double dpi;           // ~ 15 casas decimais
    
	// forma de declaracao e inicializacao
	double dpi1 = 25.4;
    double dpi2 = 2e1;
    double dpi3 = 3.5e-2;
	
	// operacao de atribuicao
	// atribuindo valores a variaveis
	fpi  = 10.0;
	i    = 2;
	name = 'c';

    // saida de dados em tela
	printf("Valor de i    = %d\n", i);
	printf("Valor de fpi  = %f\n", fpi);
	printf("Valor de name = %c\n", name);

    return (EXIT_SUCCESS);
}
