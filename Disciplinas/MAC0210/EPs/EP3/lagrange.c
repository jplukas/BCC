#include <stdlib.h>
#include "lagrange.h"

// Estrutura para representar um polinomio interpolante na forma de Lagrange
struct s_lagrange_interp{
    unsigned int n_points;
    Point* points;
    double w_is[];
}s_lagrange_interp;


Lagrange_interp make_lagrange_interp(unsigned int n, Point points[]){
    Lagrange_interp interp = malloc(sizeof(s_lagrange_interp) + n * sizeof(double));
    interp->n_points = n;
    interp->points = points;

    for(int j = 0; j < n; j++){
        interp->w_is[j] = 1.0;
        for(int i = 0; i < n; i++){
            if(i != j)
                interp->w_is[j] *= (get_x(points[j]) - get_x(points[i]));
        }
        interp->w_is[j] = 1.0 / interp->w_is[j];
        // printf("w[%d]=%f\n", j, interp->w_is[j]);
    }
    return interp;
}

void destroy_lagrange_interp(Lagrange_interp interp){
    free(interp);
}

double calc_lagrange(Lagrange_interp interp, double x){
    for(unsigned int i = 0; i < interp->n_points; i++)
        if(get_x(interp->points[i]) == x) return get_y(interp->points[i]);

    double acc1 = 0, acc2 = 0;
    for(unsigned int i = 0; i < interp->n_points; i++){
        double it = interp->w_is[i] / (x -  get_x(interp->points[i]));
        acc2 += it;
        acc1 += it  * get_y(interp->points[i]);
    }
    return acc1/acc2;
}