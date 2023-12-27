#ifndef NEWTON_H
#define NEWTON_H
#include "point.h"

// Representacao de um polinomio interpolante na forma de Newton (opaco)
typedef struct s_newton_interp* Newton_interp;

// Constroi um interpolante polinomial de grau no maximo n+1 na forma de Newton 
Newton_interp make_newton_interp(unsigned int n, Point points[]);

// Destroi um polinomio interpolante de Newton
void destroy_newton_interp(Newton_interp newton);

// Função que calcula o valor do interpolante em x.
double calc_newton(Newton_interp n, double x);

#endif /* NEWTON_H */