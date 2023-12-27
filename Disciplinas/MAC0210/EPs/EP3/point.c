#include <stdlib.h>
#include "point.h"
#include "llist.h"

typedef struct s_point{
    double x;
    double y;
}s_point;

Point make_point(double x, double y){
    Point p = malloc(sizeof(s_point));
    p->x = x;
    p->y = y;
    return p;
}

void destroy_point(Point p){
    free(p);
}

double get_x(Point p){
    return p->x;
}

double get_y(Point p){
    return p->y;
}

Point* read_points(unsigned int n){
    Point* points = calloc(n, sizeof(Point));
    for(unsigned int i = 0; i < n; i++){
        double x;
        double y;

        if(scanf("%lf,%lf", &x, &y) != 2) {
            fprintf(stderr,"Could not read point from stdin\n");
            exit(EXIT_FAILURE);
        }

        points[i] = make_point(x, y);
    }
    return points;
}

Point* read_points_from_file(unsigned int* n, FILE* f){
    Llist points_l = make_list(destroy_point);
    unsigned int count = 0;
    while(!feof(f)){
        char a = fgetc(f);
        char b = fgetc(f);
        // printf("chars: \"%c\" \"%c\"\n", a, b);
        if(a == '\n' && feof(f)) break;
        ungetc(b, f);
        ungetc(a, f);

        double x;
        double y;

        if(fscanf(f, "%lf,%lf", &x, &y) != 2) {
            fprintf(stderr,"Could not read point from file\n");
            exit(EXIT_FAILURE);
        }
        // printf("%f %f\n", x, y);
        append(points_l, make_point(x, y));
        ++count;
    }

    (*n) = count;

    Point* points = calloc(count, sizeof(Point));

    while(count > 0)
        points[--count] = (Point) pop(points_l);
    
    destroy_Llist(points_l);
    return points;
}

void print_point(Point p){
    printf("%.14f, %.14f\n", p->x, p->y);
}

void destroy_points(Point* pts, unsigned int n){
    for(unsigned int i = 0; i < n; i++)
        destroy_point(pts[i]);
    free(pts);
}

