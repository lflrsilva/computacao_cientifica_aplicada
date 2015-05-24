/*
  File:   es_avancada.c
  Author: lflrsilva

  Topicos abordados:
  - Funcoes avancadas para manipulacao de arquivos

 * Renomear arquivos: modifica o nome do arquivo. Retorna 0 em caso
   de sucesso ou nao-zero caso falhe.

  int rename( const char *old_filename, const char *new_filename );
  
 * Remover arquivos: remove o arquivo fname. Retorna 0 em caso
   de sucesso ou nao-zero caso falhe.

  int remove( const char *fname );
  
 * Fim do arquivo: checar se a leiura chegou ao fim do arquivo.
  
  int feof( FILE *stream );

  sendo que retorna valor nao-nulo caso seja o fim do arquivo.
  Senao,retorna 0.
 
  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>

#define NMAX 5

int main(int argc, char** argv) {

    char filename[25] = "teste1.txt";
	double a[] = {1., 2., 3., 4., 5.};
	int i, ferror;

    FILE* fp;

    // Abrindo e criando arquivo filename...
    if( (fp = fopen(filename,"w") ) == NULL)
    {
        printf("Erro na leitura do arquivo %s!!\n", filename);
        printf("Abortando...\n");
        exit(EXIT_FAILURE);
    }
    // renomeando nome do arquivo
    ferror = rename(filename, "teste2.txt");
	if(ferror)
    {
        printf("Erro renomeando arquivo %s!!\n", filename);
        printf("Abortando...\n");
        exit(EXIT_FAILURE);
    }
    
    // Saida de dados formatada
    for(i=0; i<NMAX;i++)
    {
        fprintf(fp,"%5.5e\n", a[i]);
    }
    
    // fechando o arquivo
    fclose(fp);
    
    return (EXIT_SUCCESS);
}
