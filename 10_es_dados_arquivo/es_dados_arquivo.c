/*
  File:   es_dados_arquivo.c
  Author: lflrsilva

  Topicos abordados:
  - Conceitos sobre entrada e saida de dados
    em arquivos
  - Tipo ponteiro FILE* (estrutura de E/S)
  - Sintaxe de E/S em arquivo

  Entrada e saida de dados
  
  Quando um programa eh finalizado, os dados armazenados na memoria
  sao apagados. Em diversos casos, existe o interesse em armazenar
  os dados para uso futuro (outro programa, por exemplo). Existem 
  funcoes em C <stdio.h>para ler e gravar dados em arquivos de texto
  ou binarios.

  Para tal, deve-se declarar um ponteiro do tipo FILE para manipular
  as operacoes de E/S em arquivo (chamado de "corrente" de dados).

  FILE* nome_stream;

  Este ponteiro deve ser usado em todas as operacoes de E/S em arquivo.
  A funcao fopen eh utilizada para abrir um arquivo e E/S de dados em
  diferentes modos de acesso.

  FILE *fopen(const char *filename, const char *mode);
  
  Modos de acesso de arquivo
     * r  - aberto para leitura
     * w  - aberto para escrita (arquivo nao precisa existir)
     * a  - aberto para adicionar ao fim (arquivo nao precisa existir)
     * r+ - aberto para leitura e escrita, comecando do incio do
	        arquivo
     * w+ - aberto para leitura e escrita (sobrescreve arquivo existente)
     * a+ - aberto para leitura e escrita (adiciona se arquivo existe)
 
  Para entrada e saida formatada de dados:

  Saida em arquivo   : fprintf(nome_stream, "Ola mundo");
 
  Entrada em arquivo : fscanf(nome_stream, "%formato", &varivel);
 
  Ao fim do uso do arquivo, convem fecha-lo.
  
  fclose(nome_stream)
 
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    double x, y;

    // Definicao dos atributos de arquivo
    FILE* stream;

/*
    stream = fopen("arquivo.dat","w");
    if (stream != NULL) // check se o arquivo abriu corretamente
    {
        fprintf(stream, "Dentro do arquivo!!\n");
    }

*/

    // Outra forma de checar abertura de arquivo...
    if( (stream = fopen("arquivo.dat","r") ) == NULL)
    {
        printf("Erro na leitura do arquivo!!\n");
        printf("Abortando...\n");
        exit(EXIT_FAILURE);
    }

    // lendo dados dentro do arquivo
    fscanf(stream,"%16le %16le", &x, &y);

    // escrevendo em tela os valores para conferir
    printf("Os valores lidos no arquivo foram: %16le %16le\n",x, y);

    // fechando o arquivo
    fclose(stream);
	
    // Reabrindo arquivo para adicionar dados
    if( (stream = fopen("arquivo.dat","a+") ) == NULL)
    {
        printf("Erro na leitura do arquivo!!\n");
        printf("Abortando...\n");
        exit(EXIT_FAILURE);
    }
	
	fprintf(stream, "%5.3e %5.3e\n", 1.0, 2.0);
    
    // fechando o arquivo
    fclose(stream);
	
    return (EXIT_SUCCESS);
}
