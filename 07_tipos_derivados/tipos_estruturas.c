/*
  File:   tipos_estruturas.c
  Author: lflrsilva

  Topicos abordados:
  - fundamentos de estruturas
  - sintaxe de estruturas

  Definicao de outros tipos de dados:
 
  Uso de estruturas - eh uma colecao de variaveis referenciadas por
  um unico nome. Desta forma, as informacoes podem ser agrupadas em
  forma estruturada.
 
  // definicao
  struct nome_estrutura {     // nome_estrutura eh o identificador
      double variavel1;       // as variaveis sao os campos da
      tipo variavel2;         // estrutura
  };
 
  // declaracao
  nome_estrutura e1;     --> declaracao no programa principal
  
  // acesso as variaveis
  e1.variavel1 = 3.0;    --> acesso a variavel dentro da estrutura

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.
  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    //declaracao da forma da estrutura
    struct tanque {
        char nome[30];  // nome na planta
        int   id ;      // id na planta
        double V;       // volume (m^3)
        double F[2];    // vazao vol. in-out (m^3/s)
    };

    struct ponto3d {
        double x;
        double y;
        double z;
    };

    int i;
    double t, dt;
    struct tanque t1;     // declaracao da estrutura do tipo tanque
    struct tanque t2[2];  // declaracao de array de tanque

    // declaracao com inicializacao
    struct ponto3d pto = {1.0,2.0,3.0};
    printf("Inicializamos: %5.5e %5.5e %5.5e\n", pto.x, pto.y, pto.z);
    
    // iniciar variaveis
    // funcao strcpy(a, b) <string.h>
    // copia a string b e cola na string a
    strcpy(t1.nome, "tambor_alimentacao");

    t1.id   = 1;
    t1.V    = 10.0; // volume inicial do tanque
    t1.F[0] = 0.0;  // sem vazao de entrada
    t1.F[1] = 0.1;  // vazao de saida
    
    t2[0]   = t1;   // Inicializa todas as variaveis
                    // de t2[0] como t1
    t2[0].id = 2;   // Id tem que ser outro...

    strcpy(t2[1].nome, "reator_mistura");
    t2[1].id   = 3;
    t2[1].V    = 0.0;   // volume inicial
    // vazao de saida dos outros tanques
    t2[1].F[0] = t1.F[1] + t2[0].F[1];
    t2[1].F[1] = 0.0;  // vazao de saida

    // Enchimento do reator mistura
    t  = 0.0;
    dt = 0.1;  // passo de tempo
    printf("   t \t\t V\n");
    printf("%3.1le \t %3.1le\n", t, t2[1].V);

    for(i = 0; i < 10; i++)
    {
        t2[1].V += t2[1].F[0] - t2[1].F[1];
        t       += dt;
        printf("%3.1le \t %3.1le\n", t, t2[1].V);
    }
    
    return (EXIT_SUCCESS);
}
