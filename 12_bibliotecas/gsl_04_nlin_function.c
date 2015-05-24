/*
  File:   gsl_nlin_function.c
  Author: lflrsilva

  Topicos abordados:
  - Uso de GSL (ver manual)
  - Uso de metodos para solucao de funcoes nao lineares

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <gsl_errno.h>
#include <gsl_math.h>
#include <gsl_roots.h>

// Prototype e definicao dos parametros a serem usados na funcao
struct my_f_params {
    double a;
    double b;
    double c;
};

// Prototype e definicao da funcao a ser usada
double my_f (double x, void * p);

int main(int argc, char** argv) {
    
    // Variaveis auxiliares
    int i, status, maxIter = 100;
    double x_lo = 0.0, x_hi = 5.0;
    double root, answer = sqrt(5.0);
    double abstol = 1.e-8;
    double reltol = 1.e-5;

    // Escolhendo o tipo de solver a ser aplicado
    // Info: gsl_root_fsolver  - para metodos com limites iniciais
    //       possiveis opcoes: gsl_root_fsolver_bisection
    //                         gsl_root_fsolver_falsepos
    //                         gsl_root_fsolver_brent
    //
    //       gsl_root_fdfsolver - para metodos baseados em derivadas
    //       possiveis opcoes: gsl_root_fdfsolver_newton
    //                         gsl_root_fdfsolver_secant
    //                         gsl_root_fdfsolver_steffenson
    const gsl_root_fsolver_type* T = gsl_root_fsolver_bisection;

    // Alocando espaco para executar o solver
    // Info: gsl_root_fsolver   - para metodos com limites iniciais
    //       gsl_root_fdfsolver - para metodos baseados em Newton
    gsl_root_fsolver* s = gsl_root_fsolver_alloc(T);

    // Declarando a funcao e parametros a serem usados
    gsl_function F;
//    struct my_f_params parametros = {3.0, 2.0, 1.0};
    struct my_f_params parametros = {1.0, 0.0, -5.0};

    F.function = &my_f;
    F.params   = &parametros;

    // Inicializando as funcoes para usar o metodo
    // gsl_root_fsolver_set
    // (
    //     gsl_root_fsolver * s,
    //     gsl_function * F,
    //     double x_lower,
    //     double x_upper
    //  )    
    gsl_root_fsolver_set(s, &F, x_lo, x_hi);

    // Passando para tela o nome do solver usado
    printf ("s is a '%s' solver\n", gsl_root_fsolver_name(s));

    // Aplicando o metodo!!
    i = 0;         // primeira iteracao
    root   = 0.0;  // inicializando...
    status = 0;    // inicializando...
    
    printf("%5d %5d [%.7f, %.7f] %.7f %+.7f %.7f\n",
               i, status, x_lo, x_hi, root, root-answer, x_hi-x_lo);

    do
    {
        i++;

        // Aplicacao de uma unica iteracao
        status = gsl_root_fsolver_iterate(s);

        // Verifica o valor da raiz
        root   = gsl_root_fsolver_root(s);

        // Retorna os valores dos novos limites
        x_lo   = gsl_root_fsolver_x_lower(s);
        x_hi   = gsl_root_fsolver_x_upper(s);

        // Retorna valor para checar se a convergencia foi atinginda
        // Teste avaliando limites x_lo e x_hi contra erro misto
        // absoluto (1.e-8 no exemplo abaixo) e relativo (1.e-5 no exemplo
        // abaixo).
        // Macros dentro de <gsl_errno.h>
        // GSL_SUCCESS
        // GSL_CONTINUE
        status = gsl_root_test_interval(x_lo, x_hi, abstol, reltol);
        
        if (status == GSL_SUCCESS)
        {
             printf("Convergiu!\n");
        }

        printf("%5d %5d [%.7f, %.7f] %.7f %+.7f %.7f\n",
                   i, status, x_lo, x_hi, root, root-answer, x_hi-x_lo);
    }
    while (status == GSL_CONTINUE && i < maxIter);

    //- Liberando memoria alocada para a solucao
    gsl_root_fsolver_free(s);

    return (EXIT_SUCCESS);
}
