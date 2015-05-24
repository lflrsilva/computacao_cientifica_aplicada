/*
  File:   gsl_integration.c
  Author: lflrsilva

  Topicos abordados:
  - Uso de GSL (ver manual)
  - Uso de rotinas GSL para integracao numerica

  int_{0}^{1} ln(alpha*x)/sqrt(x) dx = - 4.0

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl_integration.h>

// funcao para integracao
double f(double x, void* params) {
    double alpha = *(double *) params;
    double f = log(alpha*x)/sqrt(x);
    return f;
}

int main(int argc, char** argv) {

    // alocando espaco para as variaveis
	// da rotina de integracao
    gsl_integration_workspace* w =
            gsl_integration_workspace_alloc(1000);

    double result, error;
	double x0 = 0.0, xL = 1.0; // limites de integracao
	double abstol = 0.0;       // tolerancia absoluta
	double reltol = 1.e-7;     // tolerancia relativa
	
    double analytical = -4.0;  // resultado analitico
    double alpha      = 1.0;

    gsl_function F;            // declaracao da estrutura de funcao
    F.function = &f;           // endereco da funcao
    F.params   = &alpha;       // endereco dos parametros

    // funcao integracao (ver manual)
    gsl_integration_qags(&F, x0, xL, abstol, reltol, 1000, w, &result, &error);

    printf("result          = %5.18le\n", result);
    printf("analytical      = %5.18le\n", analytical);
    printf("estimated error = %5.18le\n", error);
    printf("actual error    = %5.18le\n", fabs(analytical - result));

    // liberando o espaco alocado
    gsl_integration_workspace_free(w);

    return (EXIT_SUCCESS);
}
