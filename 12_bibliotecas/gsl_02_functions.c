/*
  File:   gsl_functions.c
  Author: lflrsilva

  Topicos abordados:
  - Uso de GSL (ver manual)
  - Uso de funcoes inline
    * M_PI
    * gsl_pow
    * gsl_poly_eval
    * gsl_sf_gamma

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved. 

 */

#include <stdio.h>
#include <stdlib.h>
#include <gsl_math.h>
#include <gsl_poly.h>
#include <gsl_sf_gamma.h>

int main(int argc, char** argv) {

    double x = 3.3, y;
    int i, j, k;

    // variaveis para polyeval
    double c[] = {1., -8., 28., -56., 70., -56., 28., -8., 1.};
    int len = 9;
    
    // funcao gamma e integracao numerica
    double mua[8], mu[8];

    // funcoes e constantes dentro de gsl_math.h
    printf("PI = %5.5le \n", M_PI );
    printf("x*x = %5.5le\n", gsl_pow_2(x) );     // pg. 18

    //  funcoes e constantes dentro de gsl_poly.h
    x = 1.0;
    y = gsl_poly_eval(c, len, x);  // pg. 28
    printf("Polynomial eval : %5.5le\n", y);

    /* gamma
     * 
     * muk analitico = GAMMA(2+k)/(2^k)
     *
     * muk numerico: usa-se subrotina!
     *
     * muk = int_{0}^{infinity} v^k * f(v,t) dv     pg. 186
     *
     * sendo f(v,t) = exp(-v)
     *
     */
    for(k=0; k<8;k++)
    {
        // Calculo analitico
        mua[k] = gsl_sf_gamma(2. + k) /( gsl_pow_int(2.,k) ); // pg. 56
        printf("muka[%2d] = %5.5le\n", k, mua[k]);

        // Calculo numerico
        // mu[k] ?? - Uso de subrotina
        // E' para voces fazerem!!!

    }

    return (EXIT_SUCCESS);
}

