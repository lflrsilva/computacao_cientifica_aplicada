/*
  File:   gsl_ode_solve.c
  Author: lflrsilva

  Topicos abordados:
  - Uso de GSL (ver manual)
  - Uso de metodos para solucao de sistema de EDO's

 * Montagem do sistema de EDO's:
  
  dy1/dt = f(t, y1, y2, y3, ... )
  dy2/dt = f(t, y1, y2, y3, ... )
  dy3/dt = f(t, y1, y2, y3, ... )
  ...
  
  dyi/dt = f(t, yi )
  
  sendo yi = [y1, y2, y3, ...]

  Organiza-se tudo em um sistema de equacoes matricial.

 * Metodologias disponiveis no GSL:
	Metodos explicitos:
	- gsl_odeiv2_step_rk2  : Runge-Kutta (2,3)
	- gsl_odeiv2_step_rk4  : Runge-Kutta (4)
	- gsl_odeiv2_step_rkf45: Runge-Kutta-Fehlberg (4,5)
	- gsl_odeiv2_step_rkck : Runge-Kutta Cash-Karp (4,5)
	- gsl_odeiv2_step_rk8pd: Runge-Kutta Prince-Dormand (8,9)
	Metodos implicitos (podem precisar do jacobiano ou da
	alocacao do gsl_odeiv2_step_set_driver):
	- gsl_odeiv2_step_rk1imp : Runge-Kutta (1)
	- gsl_odeiv2_step_rk2imp : Runge-Kutta (2)
	- gsl_odeiv2_step_rk4imp : Runge-Kutta (4)
	- gsl_odeiv2_step_bsimp  : Bulirsch-Stoer
	- gsl_odeiv2_step_msadams: Adams (1 a 12)
	- gsl_odeiv2_step_msbdf  : BDF (1 a 12)

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <gsl_errno.h>
#include <gsl_matrix.h>
#include <gsl_odeiv.h>


 // funcao com as equacoes diferenciais
 int func(double t, const double y[], double f[], void *params)
 {
   double mu = *(double *)params;

   f[0] = y[1];
   f[1] = -y[0] - mu*y[1]*(y[0]*y[0] - 1);

   return GSL_SUCCESS;
 }

 // jacobiano das equacoes diferenciais
 // Efetivamente usado em metodos baseados em calculo
 // de derivadas
 int jac(double t, const double y[], double *dfdy, double dfdt[], void *params)
 {
   double mu = *(double *)params;

   gsl_matrix_view dfdy_mat = gsl_matrix_view_array (dfdy, 2, 2);
   gsl_matrix* m           = &dfdy_mat.matrix;

   gsl_matrix_set (m, 0, 0, 0.0);
   gsl_matrix_set (m, 0, 1, 1.0);
   gsl_matrix_set (m, 1, 0, -2.0*mu*y[0]*y[1] - 1.0);
   gsl_matrix_set (m, 1, 1, -mu*(y[0]*y[0] - 1.0));

   dfdt[0] = 0.0;
   dfdt[1] = 0.0;
   return GSL_SUCCESS;
 }

int main(int argc, char** argv) {

    // Tamanho do sistema a ser resolvido
    size_t dim = 2;
	
	// Definicao dos erros por passo de tempo
	double abstol = 1.e-6;
	double reltol = 1.e-10;

    // Definindo o metodo a ser usado
    const gsl_odeiv_step_type* T = gsl_odeiv_step_rk8pd;

    // Alocando espaco para utilizar o metodo T e a dimensao do 
    //  numero de equacoes a serem resolvidas.
    gsl_odeiv_step* s = gsl_odeiv_step_alloc(T, dim);
    
    // Verifica e obtem o melhor passo na evolucao da variavel, de
    //  acordo com os erros absoluto e relativo alimentados.
    gsl_odeiv_control* c = gsl_odeiv_control_y_new(abstol, reltol);

    // Alocando espaco para aplicar as operacoes de solucao numerica
    gsl_odeiv_evolve* e = gsl_odeiv_evolve_alloc(dim);

    // Definicao dos parametros usados e do sistema a ser resolvido
    //  (funcao e seu jacobiano).
    double mu = 10;
    gsl_odeiv_system sys = {func, jac, 2, &mu};

    // Definicao das variaveis e suas condicoes iniciais
    double t = 0.0, tf = 100.0;
    double h = 1e-2;
    double y[2] = { 1.0, 0.0 }; // C.I. das variaveis 

    // Variaveis auxiliares
    int status;

    printf ("%.5e %.5e %.5e\n", t, y[0], y[1]);
    while (t < tf)
    {
        // Evolucao da funcao.
        // Importante!! t e h sao passados por referencia e seus valores
        // mudam a cada iteracao. Dessa maneira, o passo de tempo NAO eh
        // fixo!!!
        status = gsl_odeiv_evolve_apply(e, c, s, &sys, &t, tf, &h, y);

        if(status != GSL_SUCCESS)
        {
            printf ("error, return value=%d\n", status);
            break;
        }

        printf ("%.5e %.5e %.5e\n", t, y[0], y[1]);
    }

    // Desalocando a memoria...
    gsl_odeiv_evolve_free (e);
    gsl_odeiv_control_free (c);

    return (EXIT_SUCCESS);
}
