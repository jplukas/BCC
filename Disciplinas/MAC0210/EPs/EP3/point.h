#ifndef POINT_H
#define POINT_H
#include <stdio.h>

// Representacao de um ponto no R2 (opaco)
typedef struct s_point* Point;

// Construtor de ponto
Point make_point(double x, double y);

// Destroi um ponto
void destroy_point(Point p);

// Destroi um array de pontos
void destroy_points(Point* pts, unsigned int n);

// Devolve o valor x do ponto
double get_x(Point p);

// Devolve o valor y do ponto
double get_y(Point p);

// Le pontos do arquivo f e devolve um array de pontos
Point* read_points_from_file(unsigned int* n, FILE* f);

// Lê n pontos da entrada padrao e devolve um array de pontos
Point* read_points(unsigned int n);

// Printa um ponto na saida padrao
void print_point(Point p);

#endif /* POINT_H */