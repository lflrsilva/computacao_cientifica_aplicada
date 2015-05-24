#include <stdio.h>
#include <stdlib.h>
#include <gsl_errno.h>
#include <gsl_math.h>
#include <gsl_roots.h>

# define Nmax 10   // Max number of series terms

struct func_params {
    double Bi;
};

double func (double zetan, void * p)
{
    struct func_params * params = (struct func_params *)p;
    double Bi = (params->Bi);
    return (zetan*tan(zetan) - Bi);
}

int main(int argc, char** argv) {

    // Physical parameters
    double Bi, Fo;
    double C[Nmax], zeta[Nmax];

    // Spatial variables
    double x, dx;

    //- GSL routines declarations
    const gsl_root_fsolver_type* T;
    gsl_root_fsolver* s;
    gsl_function F;
    struct func_params params;

    //- Support variables for the GSL chosen method
    int status, maxIter = 200;
    double x_lo, x_hi;
    double tolabs, tolrel;

    // Additional variables
    double sum, sumi;
    double erro =1.e-5;
    int i, j;

    FILE* fp;

    // Initializing variables
    Fo = 0.02;         // Fourier number
    Bi = 0.1;          // Biot number
    dx = 0.05;         // increase delta x

    // GSL definitions and initialization
    T = gsl_root_fsolver_brent;
    s = gsl_root_fsolver_alloc(T);

    params.Bi  = Bi;
    F.function = &func;
    F.params   = &params;

    tolrel  = 1.0e-5;       // Relative tolerance
    tolabs  = 1.0e-8;       // Absolute tolerance
    maxIter = 300;          // Max iterations
   
    for(i=0; i<Nmax; i++)
    {
        // For each i serie term, I have a root...
        x_lo = -1.e-1  + i*M_PI;
        x_hi = M_PI_4  + i*M_PI;
        gsl_root_fsolver_set (s, &F, x_lo, x_hi);
        printf("Term %d of the serie\n", i);
        
        j = 0;
        do
        {
            j++;

            status  = gsl_root_fsolver_iterate(s);
            status  = gsl_root_test_interval(x_lo, x_hi, tolabs, tolrel);

            // Checking stuff - Comment after it is ok!!
            x_lo   = gsl_root_fsolver_x_lower(s);
            x_hi   = gsl_root_fsolver_x_upper(s);
            printf("%5d %5d [%.7f, %.7f] %.7f %.7f\n",
                   j, status, x_lo, x_hi, gsl_root_fsolver_root(s), x_hi-x_lo);
            
        }
        while (status == GSL_CONTINUE && j < maxIter);

        // Checking convergence
        if(j > maxIter)
        {
            printf("Error: maximum number of iterations achieved.\n");
            printf("Aborting...\n");
            exit(EXIT_FAILURE);
        }

        //- Storing the solution
        zeta[i] = gsl_root_fsolver_root(s);

        // Calculating the series coeficient
        C[i] = 4.0*sin(zeta[i])/( 2.0*zeta[i] + sin(2.0*zeta[i]) );
    }

    //- Ok, I don't need to use it anymore
    gsl_root_fsolver_free(s);

    // File acess
    if( (fp = fopen("parede.dat","w") ) == NULL)
    {
        printf("File acess error!\n");
        printf("Aborting...\n");
        exit(EXIT_FAILURE);
    }

    // Initializing x
    x = 0.0;   // dim. less
    while(x < (1.0+dx) )
    {
        // Cleaning variables
        sum = 0.0;
        for(i=0; i<Nmax; i++)
        {
            sumi = sum;
            sum += C[i]*exp(-zeta[i]*zeta[i]*Fo)*cos(zeta[i]*x);

            // Check if number of terms of the serie is sufficient
            if(fabs(sum-sumi) < erro)
            {
                break;
            }
        }

        fprintf(fp, "%5.3le %5.3le\n", x, sum);

        // Increase dx
        x += dx;
    }

    fclose(fp);
    return (EXIT_SUCCESS);
}
