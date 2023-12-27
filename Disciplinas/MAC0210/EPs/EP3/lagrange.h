#ifndef LAGRANGE_H
#define LAGRANGE_H
#include "point.h"

// Representacao de um polinomio interpolante na forma de Lagrange (opaco)
typedef struct s_lagrange_interp* Lagrange_interp;

// Constroi um interpolante polinomial de grau no maximo n+1 na forma de lagrange 
Lagrange_interp make_lagrange_interp(unsigned int n, Point points[]);

// Destroi um polinomio interpolante de lagrange
void destroy_lagrange_interp(Lagrange_interp interp);

// Função que calcula o valor do interpolante em x.
double calc_lagrange(Lagrange_interp interp, double x);

#endif /* LAGRANGE_H */