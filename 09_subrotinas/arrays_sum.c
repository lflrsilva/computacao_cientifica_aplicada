/*
  File:   arrays_sum.c
  Author: lflrsilva

  Declaracao com possibilidade de alterar d
  Ponteiro constante, não pode mudar local para onde aponta!

  (c) Copyright 2015 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.
*/

double h(double* const d, int n)
{
    int i;
    double sum = 0.;

    for(i = 0; i < n; i++)
        sum += d[i];

    d[n-1] = 1000.; // Mas pode alterar d!

    return(sum);
}

/* Declaracao com d constante
 *  Ponteiro e variável constantes!
 * TROCAR COM DECL. ACIMA
 */

/*
 double h(const double* const d, int n)
{
    int i;
    double sum = 0.;

    for(i = 0; i < n; i++)
        sum += d[i];

    d[n-1] = 1000.; // Mas pode alterar d!

    return(sum);
}
*/

