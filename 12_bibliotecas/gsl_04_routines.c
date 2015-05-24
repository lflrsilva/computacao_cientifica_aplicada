struct my_f_params {
    double a;
    double b;
    double c;
};

double my_f (double x, void * p) {
    struct my_f_params * params
      = (struct my_f_params *)p;
    double a = (params->a);
    double b = (params->b);
    double c = (params->c);

    return  (a * x + b) * x + c;
}

