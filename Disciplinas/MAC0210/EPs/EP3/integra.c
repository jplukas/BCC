#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "point.h"

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
    if(argc != 3){
        fprintf(stderr, "Usage: %s <filename> <method> \n", argv[0]);
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

    double acc = 0.0;
    if(strcmp(method, "trap") == 0){
        for(unsigned int i = 0; i < n_pontos - 1; i++){
            double h = get_x(pontos[i + 1]) - get_x(pontos[i]);
            double y_0 = get_y(pontos[i]);
            double y_1 = get_y(pontos[i + 1]);
            acc += (y_0 + y_1) * (h/2.0);
        }
    }
    else if(strcmp(method, "simpson") == 0){
        unsigned int n = n_pontos % 2 == 1? n_pontos : n_pontos - 1;
        acc = 0.0;
        for(unsigned int i = 0; i < n - 1; i+=2){
            double y_0 = get_y(pontos[i]),
                   y_1 = get_y(pontos[i + 1]),
                   y_2 = get_y(pontos[i + 2]);

            double a = get_x(pontos[i]),
                   x_1 = get_x(pontos[i + 1]),
                   b = get_x(pontos[i + 2]);

            double apb = a + b,
                   ab = a * b,
                   apb2 = (apb * apb),
                   apb2mab = apb2 - ab;

            acc += (y_0 / (x_1 - a)) *
            (
                (apb2mab / 3) -
                (((b + x_1) / 2) * apb) +
                (b * x_1)
            );
            acc += (y_2 / (b - x_1)) *
            (
                (apb2mab / 3) -
                (((a + x_1) / 2) * apb) +
                (a * x_1)
            );
            acc += (
                (
                    (y_1 * (b - a)) / (
                        (x_1 - a) * 
                        (x_1 - b)
                    )
                )
            ) *
            (
                (apb2mab / 3) -
                (apb2 / 2) +
                ab
            );
        }
    }
    else{
        fprintf(stderr, "Error: método \"%s\" não reconhecido!\n", fname);
        exit(EXIT_FAILURE);
    }
    printf("%.14f\n", acc);
    destroy_points(pontos, n_pontos);
    return 0;
}