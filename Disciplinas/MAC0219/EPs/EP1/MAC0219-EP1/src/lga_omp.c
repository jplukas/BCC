#include "lga_base.h"
#include "lga_omp.h"
#include <stdio.h>
#include <omp.h>

static byte get_next_cell(int i, int j, byte *grid_in, int grid_size) {
    byte next_cell = EMPTY;

    for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
        int rev_dir = (dir + NUM_DIRECTIONS/2) % NUM_DIRECTIONS;
        byte rev_dir_mask = 0x01 << rev_dir;

        int di = directions[i%2][dir][0];
        int dj = directions[i%2][dir][1];
        int n_i = i + di;
        int n_j = j + dj;

        if (inbounds(n_i, n_j, grid_size)) {
            if (grid_in[ind2d(n_i,n_j)] == WALL) {
                next_cell |= from_wall_collision(i, j, grid_in, grid_size, dir);
            }
            else if (grid_in[ind2d(n_i, n_j)] & rev_dir_mask) {
                next_cell |= rev_dir_mask;
            }
        }
    }

    return check_particles_collision(next_cell);
}

static void update(
    byte *grid_in,
    byte *grid_out,
    int grid_size,
    int n_threads) {

    int i;

    #pragma omp parallel for \
        shared(grid_in, grid_out, grid_size, n_threads) \
        private(i) num_threads(n_threads) \
        schedule(static)
        for (i = 0; i < grid_size * grid_size; i++) {
            if (grid_in[i] == WALL)
                grid_out[i] = WALL;
            else
                grid_out[i] = get_next_cell(
                    i / grid_size,
                    i % grid_size,
                    grid_in, grid_size);
        }
}

void simulate_omp(byte *grid_1, byte *grid_2, int grid_size, int num_threads) {
    // printf("Nthreads: %d\n", num_threads);

    #ifdef DEBUG
        const char s[100];
        int j = 0;
    #endif
    for (int i = 0; i < ITERATIONS/2; i++) {
        #ifdef DEBUG
            sprintf(s, "%03d.ppm\0", j++);
            create_pbm_grid(grid_1, grid_size, s);
        #endif
        update(grid_1, grid_2, grid_size, num_threads);
        #ifdef DEBUG
            sprintf(s, "%03d.ppm\0", j++);
            create_pbm_grid(grid_2, grid_size, s);
        #endif
        update(grid_2, grid_1, grid_size, num_threads);
    }
}
