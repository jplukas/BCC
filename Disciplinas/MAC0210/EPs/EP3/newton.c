#include <stdlib.h>
#include <stdio.h>
#include "newton.h"

// Estrutura para representar um polinomio interpolante na forma de Newton
struct s_newton_interp{
    unsigned int n_points;
    Point* points;
    double c_is[];
}s_newton_interp;

double calc_newton(Newton_interp n, double x){

    if(!n) return -1; // Ponteiro para o interpolante eh NULL
    double acc_soma = 0.0;
    for(int i = 0; i < n->n_points; i++){
        double acc_mult = n->c_is[i];
        for (int j = 0; j < i; j++){
            acc_mult *= (x - get_x(n->points[j]));
        }
        acc_soma += acc_mult;
    }
    return acc_soma;
}


Newton_interp make_newton_interp(unsigned int n, Point points[]){
    Newton_interp newton = malloc(sizeof(s_newton_interp) + n * sizeof(double));
    newton->n_points = n;
    newton->points = points;

    double div_diff[n][n];

    for(int i = 0; i < n; i++){
        div_diff[i][0] = get_y(points[i]);
    }
    newton->c_is[0] = div_diff[0][0];

    for(int j = 1; j < n; j++){
        for(int i = j; i < n; i++){
            div_diff[i][j] = (div_diff[i][j - 1] - div_diff[i - 1][j - 1])/
            (get_x(points[i]) - get_x(points[i - j]));
        }
        newton->c_is[j] = div_diff[j][j];
    }

    return newton;
}


void destroy_newton_interp(Newton_interp newton){
    free(newton);
}
