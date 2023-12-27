#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define EULER = 2.71828182845904523536;

double x_0 = -1.0;
int abst_e;
int ftol_e;
double abstol;
double ftol;

double g_1(double x){
    return - sqrt(exp(x) / 2.0);
}

double g_2(double x){
    return sqrt(exp(x) / 2.0);
}

double g_3(double x){
    return log(2) + (2 * log(x));
}

double f(double x){
    return exp(x) - (2.0 * pow(x, 2.0));
}

double (*g) (double) = g_1;

double e_3(double x, int k){
    return fabs(x);
}

double e_2(double x, int k){
    return fabs(2 * (sqrt(2 * exp(x)) - x))/(4 - (exp(1) * sqrt(2)));
}

double e_1(double x, int k){
    return fabs(2 * (sqrt(2 * exp(x)) - x))/(4 - (exp(1) * sqrt(2)));
}

void usage(){
}

int main(int argc, char** argv){
    if(argc < 4) exit(0);
    sscanf(argv[1], "%lf", &x_0);
    sscanf(argv[2], "%d", &abst_e);
    sscanf(argv[3], "%d", &ftol_e);

    abstol = pow(.1, (double)abst_e);
    ftol = pow(.1, (double)ftol_e);

    // printf("x_0 = %e\n", x_0);
    // printf("abstol = %e\n", abstol);
    // printf("ftol = %e\n", ftol);

    double x = x_0;

    if(x_0 > 0) g = g_2;
    if(x_0 > 2) g = g_3;

    int i = 0;
    double value = 0.0;
    double px;
    do{
        px = x;
        // printf("x_%d = %e\n", i, x);
        value = f(x);
        // printf("e^x - 2x^2 = %e\n", value);
        x = g(x);
        // if(i>0)printf("distancia x_%d - x_%d: %e\n", i, i - 1, (x - px));
        i++;
    }while((fabs(value) >= ftol) && (fabs(px - x) >= abstol));
    printf("x = %e\n", x);
    printf("Iterações = %d\n", i);
    return 0;
}