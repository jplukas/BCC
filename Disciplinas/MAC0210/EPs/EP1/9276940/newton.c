#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>

double abstol;
double ftol;
unsigned int max_iteractions = 10000;

//Flag para indicar se o metodo de newton divergiu para um determinado x_0;
char diverges = 0;
int MAX_ROOTS = 20;

double* coefficients = NULL;
int n_coefficients = 0;

// x^3 - 1
double complex f_x(double complex x){
    double complex acc = 0 + 0*I;
    for(int i = 0; i < n_coefficients; i++)
        acc += coefficients[i] * cpow(x, (double)i);
    return acc;
}

// 3x^2
double complex df_x(double complex x){
    double complex acc = 0 + 0*I;
    for(int i = 1; i < n_coefficients; i++)
        acc += coefficients[i] * ((double)(i)) * cpow(x, (double)i - 1);
    return acc;
}

double complex newton(double complex x_0){
    diverges = 0;
    double complex x = x_0;
    double complex px;
    double complex value;
    double complex dvalue;
    double dist = 0;
    // double lastdist;
    unsigned int iteraction = 0;
    do{
        // lastdist = dist;
        px = x;
        value = f_x(x);
        dvalue = df_x(x);

        if(dvalue == 0 || ((++iteraction) > max_iteractions)){
            diverges = 1;
            return 0;
        }

        x -= (value / dvalue);
        dist = cabs(x - px);

        // if(dist >= lastdist ){
        //     diverges = 1;
        //     return 0;
        // }
    }while((dist >= abstol) && (cabs(value) >= ftol));
    return x;
}

int get_red(double phi){
    if(phi < 0){
        fprintf(stderr, "ERRO\n");
        exit(1);
    }
    phi = phi + (M_PI / 4.0);
    if(phi >= 2.0 * M_PI) phi -= 2.0 * M_PI;
    if(phi < M_PI / 2.0) return 255;
    if(phi < M_PI) return floor(255.0 * sin(phi));
    if(phi < 3.0 * M_PI / 2.0) return 0;
    return floor(255.0 * cos(phi));
}

int get_green(double phi){
    return get_red(phi + M_PI * (4.0/3.0));
}

int get_blue(double phi){
    return get_red(phi + M_PI * (2.0/3.0));
}

int main(int argc, char** argv){
    int height, width;
    double start_x, start_y, end_x, end_y;

    double complex roots[MAX_ROOTS];
    for(int i = 0; i < MAX_ROOTS; i++)
        roots[i] = 0;

    int num_roots = 0;

    if(argc < 13){
        printf("%d argumentos!\n", argc);
        exit(1);
    }

    sscanf(argv[1], "%d", &height);
    sscanf(argv[2], "%d", &width);
    sscanf(argv[3], "%lg", &start_x);
    sscanf(argv[4], "%lg", &start_y);
    sscanf(argv[5], "%lg", &end_x);
    sscanf(argv[6], "%lg", &end_y);

    sscanf(argv[7], "%lg", &abstol);
    sscanf(argv[8], "%lg", &ftol);

    sscanf(argv[9], "%u", &max_iteractions);

    n_coefficients = argc - 10;
    coefficients = malloc(n_coefficients * sizeof(double));

    for(int i = 0; i < n_coefficients; i++)
        sscanf(argv[i + 10], "%lg", &coefficients[i]);

    if(coefficients[n_coefficients - 1] == 0){
        fprintf(stderr, "O último coeficiente não pode ser 0!\n");
        exit(1);
    }


    unsigned int** image = malloc(height * sizeof(unsigned int*));
    for(int i = 0; i < height; i++){
        image[i] = malloc(width * sizeof(unsigned int));
        // for(int j = 0; j < width; j++)
        //     image[i][j] = 0;
    }

    double step_x = (end_x - start_x) / width;
    double step_y = (end_y - start_y) / height;
    
    //Preenche a matriz image com as cores
    for(int i = 0; i < height; i++){
        double curr_y = start_y + (double)i * step_y; 
        for(int j = 0; j < width; j++){
            diverges = 0;
            double curr_x = start_x + (double)j * step_x;
            double complex x_ij = curr_x + curr_y * I;
            double complex r = newton(x_ij);

            if(diverges)
                image[i][j] = 0;
            else{
                //Percorre a lista de raizes para encontrar a cor com a qual colorir o pixel
                int k = 0;
                for(k = 0; k < num_roots; k++){
                    if(cabs(roots[k] - r) < abstol){
                        break;
                    }
                }
                image[i][j] = k + 1;
                if(k == num_roots){
                    //Raiz nao esta na lista
                    if(k == MAX_ROOTS){
                        //Nao ha mais espaco na lista
                        image[i][j] = -1;
                    }
                    else{
                        roots[k] = r;
                        num_roots++;
                    }
                }
            }
        }
    }

    int colors[num_roots + 1][3];
    double phi_step = (2 * M_PI) / (double)num_roots;
    for(int i = 1; i <= num_roots; i++){
        double phi = ((double)i) * phi_step;
        colors[i][0] = get_red(phi);
        colors[i][1] = get_green(phi);
        colors[i][2] = get_blue(phi);
    }

    colors[0][0] = 0;
    colors[0][1] = 0;
    colors[0][2] = 0;


    //Printa a matriz imagem no formato ppm
    printf("P3 %d %d 255\n", width, height);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int c = image[i][j];
            if(c == -1){
                printf("255 255 255 ");
            }
            else{
                int r = colors[c][0];
                int g = colors[c][1];
                int b = colors[c][2];
                printf("%d %d %d ", r, g ,b);
            }
        }
        printf("\n");
    }


    //cleanup
    for(int i = 0; i < height; i++){
        free(image[i]);
    }
    free(image);
    free(coefficients);
    return 0;
}