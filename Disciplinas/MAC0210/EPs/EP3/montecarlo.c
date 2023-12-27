#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int alldigits(const char* str){
    size_t length = strlen(str);
    for(size_t i = 0; i < length; i++)
        if(! isdigit(str[i])) return 0;
    return 1;
}

double f_2(double x){
    return 4 * pow((4 * x + 3), 3);
}

double f_3(double x){
    return 1;
}

double drand(){
    return rand() / (double) RAND_MAX;
}

int main(int argc, char const *argv[]){
    if(argc != 3){
        fprintf(stderr, "Usage: %s <opt> <n> \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    unsigned long int n_samples;
    if(! alldigits(argv[2]) ||
    sscanf(argv[2], "%lu", &n_samples) == EOF ||
    n_samples == 0){
        fprintf(stderr, "Error: arg <n> should be a positive integer\n");
        exit(EXIT_FAILURE);
    }
    unsigned char opt;
    if(! alldigits(argv[1]) ||
    sscanf(argv[1], "%hhu", &opt) == EOF ||
    opt == 0){
        fprintf(stderr, "Error: arg <opt> should be 1, 2, 3 or 4\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    double (*g)(double);
    long double I = 0.0;
    switch (opt){
    case 1:
        g = sin;
        break;
    case 2:
        g = f_2;
        break;
    case 3:
        g = f_3;
        break;
    case 4:
        for(unsigned long int i = 0; i < n_samples; i++){
            double x = drand();
            double y = drand();
            x *= x;
            y *= y;
            I += x + y <= 1.0 ? 1 : 0;
        }
        I = I/(double) n_samples;
        printf("%.14Lf", 4.0 * I);
        return 0;
        break;
    default:
        fprintf(stderr, "Error: arg <opt> should be 1, 2, 3 or 4\n");
        exit(EXIT_FAILURE);
        break;
    }

    for(unsigned long int i = 0; i < n_samples; i++)
        I += g(drand());

    I = I/(double) n_samples;
    printf("%.14Lf", I);
    return 0;
}
