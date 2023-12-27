#include "lga_base.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
    Vetor que indica as coordenadas do vizinho de cada posicao i,j no grid hexagonal
    Vizinho de i,j == i + directions[i%2][dir][0], j + directions[i%2][dir][1]
    dir = 0, 1, 2, 3, 4 ou 5 de acordo com o esquema:

     2   1
      \ /
    3 - - 0
      / \
     4   5
*/
int directions[2][6][2] = {
    {{0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, 0}, {1, 1}},
    {{0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}}
};

// Aloca grid na memoria
byte *allocate_grid(int grid_size) {
    byte *grid = (byte*) calloc(grid_size*grid_size, sizeof(byte));

    if (!grid) {
        fprintf(stderr, "Error allocating grid\n");
        exit(EXIT_FAILURE);
    }

    return grid;
}

// Le o estado inicial do grid de um arquivo x.in, onde x == grid_size
void read_grid_from_file(byte *grid, int grid_size) {
    FILE *file_ptr;
    char filename[8];

    snprintf(filename, sizeof(filename), "%d.in", grid_size);

    file_ptr = fopen(filename, "rb");
    if (!file_ptr) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int total_bytes = grid_size * grid_size;
    size_t total_read = fread(grid, sizeof(byte), total_bytes, file_ptr);
    if (total_read != (size_t) total_bytes) {
        fprintf(stderr, "Error reading file, read %lu bytes out of %d\n", total_read, total_bytes);
        exit(EXIT_FAILURE);
    }

    fclose(file_ptr);
}

// Determina o valor inicial dos grids, lendo o grid_1 do arquivo
// e copiando inicialmente apenas as paredes pra o grid_2
void initialize_grids(byte *grid_1, byte *grid_2, int grid_size) {
    read_grid_from_file(grid_1, grid_size);

    // Como as paredes sao fixas durante a simulacao,
    // basta inseri-las no grid auxiliar
    // uma vez durante a inicializacao
    for (int idx = 0; idx < grid_size*grid_size; idx++) {
        if (grid_1[idx] == WALL)
            grid_2[idx] = WALL;
        else
            grid_2[idx] = EMPTY;
    }
}

// Verifica se a particula esta indo para um dos cantos entre duas paredes
bool is_corner(int i, int j, byte *grid_in, int grid_size, int dir) {
    if (dir == 0 || dir == 3)
        return false;
    if (dir == 1) {
        return (!inbounds(i-2, j, grid_size) || grid_in[ind2d(i-2,j)] == WALL) &&
            (!inbounds(i, j+1, grid_size) || grid_in[ind2d(i,j+1)] == WALL);
    }
    if (dir == 2) {
        return (!inbounds(i-2, j, grid_size) || grid_in[ind2d(i-2,j)] == WALL) &&
            (!inbounds(i, j-1, grid_size) || grid_in[ind2d(i,j-1)] == WALL);
    }
    if (dir == 4) {
        return (!inbounds(i+2, j, grid_size) || grid_in[ind2d(i+2,j)] == WALL) &&
            (!inbounds(i, j-1, grid_size) || grid_in[ind2d(i,j-1)] == WALL);
    }
    if (dir == 5) {
        return (!inbounds(i+2, j, grid_size) || grid_in[ind2d(i+2,j)] == WALL) &&
            (!inbounds(i, j+1, grid_size) || grid_in[ind2d(i,j+1)] == WALL);
    }

    return false;
}

// Tentativa de implementar uma colisao um pouco mais realista com
// as paredes, buscando conservar o momento na direcao paralela a parede.
// Verifica se houve colisao com a parede que possa levar uma nova particula
// ateh a celula (i,j). Nesse caso, retorna a direcao dessa nova particula em (i,j).
// Assume paredes no grid na vertical ou na horizontal, nao na diagonal ou celulas isoladas.
byte from_wall_collision(int i, int j, byte *grid_in, int grid_size, int dir) {
    // rev_dir: direcao oposta a dir
    int rev_dir = (dir + NUM_DIRECTIONS/2) % NUM_DIRECTIONS;
    byte rev_dir_mask = 0x01 << rev_dir;

    if (dir == 0) {
        if (grid_in[ind2d(i,j)] & 0x01)
            return rev_dir_mask;
    }
    else if (dir == 1) {
        if (inbounds(i-2, j, grid_size) && (grid_in[ind2d(i-2,j)] & 0x20))
            return rev_dir_mask;
        if (inbounds(i, j+1, grid_size) && (grid_in[ind2d(i,j+1)] & 0x04))
            return rev_dir_mask;

    } else if (dir == 2) {
        if (inbounds(i-2, j, grid_size) && (grid_in[ind2d(i-2,j)] & 0x10))
            return rev_dir_mask;
        if (inbounds(i, j-1, grid_size) && (grid_in[ind2d(i,j-1)] & 0x02))
            return rev_dir_mask;

    } else if (dir == 3) {
        if (grid_in[ind2d(i,j)] & 0x08)
            return rev_dir_mask;

    } else if (dir == 4) {
        if (inbounds(i+2, j, grid_size) && (grid_in[ind2d(i+2,j)] & 0x04))
            return rev_dir_mask;
        if (inbounds(i, j-1, grid_size) && (grid_in[ind2d(i,j-1)] & 0x20))
            return rev_dir_mask;

    } if (dir == 5) {
        if (inbounds(i+2, j, grid_size) && (grid_in[ind2d(i+2,j)] & 0x02))
            return rev_dir_mask;
        if (inbounds(i, j+1, grid_size) && (grid_in[ind2d(i,j+1)] & 0x10))
            return rev_dir_mask;
    }

    // Literalmente um "corner case": evita que uma particula desapareca
    // quando ela colide na quina entre duas paredes
    byte dir_mask = 0x01 << dir;
    if ((grid_in[ind2d(i,j)] & dir_mask) && is_corner(i, j, grid_in, grid_size, dir))
        return rev_dir_mask;

    return EMPTY;
}

// Logica de colisao entre particulas de acordo com o modelo
byte check_particles_collision(byte cell) {
    switch (cell) {
        // Colisao entre duas particulas
        case 0x09:
            return 0x12;
        case 0x12:
            return 0x28;
        case 0x28:
            return 0x09;

        // Colisao entre tres particulas
        case 0x15:
            return 0x2A;
        case 0x2A:
            return 0x15;

        // Colisao entre quatro particulas
        case 0x36:
            return 0x2D;
        case 0x2D:
            return 0x1B;
        case 0x1B:
            return 0x36;

        default:
            return cell;
    }
}

// Imprime o estado atual da simulacao para debug,
// mostrando particulas (*) e paredes (#)
void print_grid(byte *grid, int grid_size) {
    for (int i = 0; i < grid_size; i++) {

        // Para ter aparencia hexagonal
        if (i % 2 == 0)
            printf(" ");

        for (int j = 0; j < grid_size; j++) {
            byte c = grid[ind2d(i,j)];

            if (c == EMPTY)
                printf("  ");
            else if (c == WALL)
                printf("# ");
            else
                printf("* ");
        }
        printf("\n");
    }
}

// Imprime o estado atual da simulacao para gerar uma
// animacao ASCII da simulacao
void print_grid_animation(byte *grid, int grid_size) {
    for (int i = 0; i < grid_size; i++) {
        printf("\"");
        if (i % 2 == 0)
            printf(" ");
        for (int j = 0; j < grid_size; j++) {
            byte c = grid[ind2d(i,j)];

            if (c == EMPTY)
                printf("  ");
            else if (c == WALL)
                printf("# ");
            else
                printf("* ");
        }
        // TODO: remover ultima virgula no arquivo
        // Do jeito que esta, isso deve ser feito manualmente
        if (i == grid_size - 1)
            printf("\"+a,\n");
        else
            printf("\"+a+\n");
    }
}

// Imprime o estado atual da simulacao para debug,
// mostrando o valor numerico de cada celula
void print_grid_numbers(byte *grid, int grid_size) {
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            printf("%-3d", grid[ind2d(i,j)]);
        }
        printf("\n");
    }
}

int hexagon[5][5] = {
    {000, 150, 255, 150, 000}, 
    {220, 249, 255, 249, 220}, 
    {255, 255, 255, 255, 255}, 
    {220, 249, 255, 249, 220}, 
    {000, 150, 255, 150, 000}
};



void color(int* p, byte aux){
    if(aux == WALL){
        p[0] = p[1] = p[2] = 0;    
        return;
    }
    if(aux == EMPTY){
        p[0] = p[1] = p[2] = 255;    
        return;
    }

    p[0] = 30;
    p[1] = 30;
    p[2] = 255;
    int step = (255 - 30) / 6;
    for(int i = 0; i < 6; i++){
        if(aux % 2){
            p[0] += step;
            p[2] -= step;
        }
        aux /= 2;
    }
}

void create_pbm_grid(byte *grid, int grid_size, const char* fname){
    FILE* f = fopen(fname, "wb");
    fwrite("P6\n", sizeof(char), 3, f);
    const char buff[100];
    int hex_grid_height = grid_size * 5;
    int hex_grid_width = grid_size * 6 + 2;
    sprintf(buff, "%d %d 255\n\0", hex_grid_width, hex_grid_height);
    fwrite(buff, sizeof(char), strlen(buff), f);

    int*** strip = (int***)malloc(5 * sizeof(int**));

    for(int a = 0; a < 5; a++){
        strip[a] = (int**)malloc(hex_grid_width * sizeof(int*));

        for(int b = 0; b < hex_grid_width; b++)
            strip[a][b] = malloc(3 * sizeof(int));
    }
    for(int i = 0; i < grid_size; i++){
        for(int j = 0; j < grid_size; j++){
            int c[3] = {-1, -1, -1};
            byte aux = grid[ind2d(i,j)];
            color(c, aux);
            if(j > 0){
                put_vertical_separator_strip(strip, i % 2 ? (j * 6 - 1) : (j * 6 + 2));
                put_hex_strip(c, strip, i % 2 ? (j * 6) : (j * 6 + 3));
            }
            else
                put_hex_strip(c, strip, i % 2 ? 0 : 3);
        }
        pad_with_zeros(strip, i % 2 ? hex_grid_width - 3 : 0);
        print_strip(strip, hex_grid_width, f);
    }
    for(int a = 0; a < 5; a++){
        for(int b = 0; b < hex_grid_width; b++)
            free(strip[a][b]);
        free(strip[a]);
    }
    free(strip);
    fclose(f);
}

void put_vertical_separator_strip(int*** strip, int offset){
    for(int i = 0; i < 5; i++){
        strip[i][offset][0] = 0;
        strip[i][offset][1] = 0;
        strip[i][offset][2] = 0;
    }
}


void print_strip(int ***strip, int hex_grid_width, FILE* f){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < hex_grid_width; j++){
            char buffer[100];
            sprintf(buffer, "%c%c%c", strip[i][j][0],strip[i][j][1], strip[i][j][2]);
            fwrite(buffer, sizeof(char), 3, f);
        }   
    }
}

void put_hex_strip(int color[3], int ***strip, int offset){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            strip[i][j + offset][0] = (hexagon[i][j] * color[0]) / 255;
            strip[i][j + offset][1] = (hexagon[i][j] * color[1]) / 255;
            strip[i][j + offset][2] = (hexagon[i][j] * color[2]) / 255;
        }
    }
}

void pad_with_zeros(int ***strip, int offset){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            // printf("%d %d\n",i, j);
            strip[i][j + offset][0] = 0;
            strip[i][j + offset][1] = 0;
            strip[i][j + offset][2] = 0;
        }
    }
}
