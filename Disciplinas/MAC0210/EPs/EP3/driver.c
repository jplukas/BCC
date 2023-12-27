#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "point.h"
#include "newton.h"
#include "lagrange.h"

// Retorna o menor valor de x para um array de pontos (x,y)
double min_x(Point* points, unsigned int n){
    double min = get_x(points[0]);
    for(unsigned int i = 0; i < n; i++){
        double curr = get_x(points[i]);
        if (curr < min) min = curr;
    }
    return min;
}

// Retorna o maior valor de x para um array de pontos (x,y)
double max_x(Point* points, unsigned int n){
    double max = get_x(points[0]);
    for(unsigned int i = 0; i < n; i++){
        double curr = get_x(points[i]);
        if (curr > max) max = curr;
    }
    return max;
}

int alldigits(const char* str){
    size_t length = strlen(str);
    for(size_t i = 0; i < length; i++)
        if(! isdigit(str[i])) return 0;
    return 1;
}

int main(int argc, char const *argv[]){
    if(argc != 4){
        fprintf(stderr, "Usage: %s <filename> <method> <n> \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    unsigned int n_samples;
    if(! alldigits(argv[3]) ||
    sscanf(argv[3], "%u", &n_samples) == EOF ||
    n_samples == 0){
        fprintf(stderr, "Error: arg <n> should be a positive integer\n");
        exit(EXIT_FAILURE);
    }

    const char* fname = argv[1];
    const char* method = argv[2];
    unsigned int n_pontos;
    FILE* f = fopen(fname, "r");
    if(!f){
        fprintf(stderr, "Error: could not open file \"%s\"\n", fname);
        exit(EXIT_FAILURE);
    }

    Point* pontos = read_points_from_file(&n_pontos, f);
    fclose(f);

    double xmin = min_x(pontos, n_pontos);
    double xmax = max_x(pontos, n_pontos);
    double stepsize = (xmax - xmin)/(double)(n_samples == 1 ? 1 : n_samples - 1);

    if(strcmp(method, "newton") == 0){
        Newton_interp newton = make_newton_interp(n_pontos, pontos);

        for(unsigned int i = 0; i < n_samples; i++){
            double x_i = xmin + (double)i * stepsize;
            double f_x_i = calc_newton(newton, x_i);
            printf("%.14f,%.14f\n", x_i, f_x_i);
        }

        destroy_points(pontos, n_pontos);
        destroy_newton_interp(newton);
    }
    else{
        Lagrange_interp interp = make_lagrange_interp(n_pontos, pontos);

        for(unsigned int i = 0; i < n_samples; i++){
            double x_i = xmin + (double)i * stepsize;
            double f_x_i = calc_lagrange(interp, x_i);
            printf("%.14f,%.14f\n", x_i, f_x_i);
        }

        destroy_points(pontos, n_pontos);
        destroy_newton_interp(interp);
    }
    return 0;
}