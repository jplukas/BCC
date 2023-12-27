#include "lga_base.h"
#include "lga_pth.h"
#include <pthread.h>

typedef struct thread_arg{
    int start;
    int end;
    byte* grid_in;
    byte* grid_out;
    int grid_size;
}thread_arg;

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

static void update(thread_arg* arg) {
    for (int i = arg->start; i < arg->end; i++){
        if (arg->grid_in[i] == WALL)
            arg->grid_out[i] = WALL;
        else
            arg->grid_out[i] = get_next_cell(
                i / arg->grid_size,
                i % arg->grid_size,
                arg->grid_in, arg->grid_size);
    }
}

void simulate_pth(byte *grid_1, byte *grid_2, int grid_size, int num_threads) {

    #ifdef DEBUG
        const char s[100];
        int j = 0;
    #endif

    for (int i = 0; i < ITERATIONS/2; i++) {
        int chunk_size = (grid_size * grid_size) / num_threads;
        int extra_work = (grid_size * grid_size) % num_threads;
        thread_arg args[num_threads];
        pthread_t tids[num_threads];
        int last_end = 0;
        for(int j = 0; j < num_threads; j++){
            args[j].grid_in = grid_1;
            args[j].grid_out = grid_2;
            args[j].grid_size = grid_size;
            args[j].start = last_end;
            last_end += chunk_size;
            if(extra_work){
                last_end++;
                extra_work--;
            }
            args[j].end = last_end;
            pthread_create(&tids[j], NULL, update, &args[j]);
        }
        for(int j = 0; j < num_threads; j++) pthread_join(tids[j], NULL);

        #ifdef DEBUG
            sprintf(s, "%03d.ppm\0", j++);
            create_pbm_grid(grid_1, grid_size, s);
        #endif        

        for(int j = 0; j < num_threads; j++){
            args[j].grid_in = grid_2;
            args[j].grid_out = grid_1;
            
            pthread_create(&tids[j], NULL, update, &args[j]);
        }
        
        for(int j = 0; j < num_threads; j++) pthread_join(tids[j], NULL);

        #ifdef DEBUG
            sprintf(s, "%03d.ppm\0", j++);
            create_pbm_grid(grid_2, grid_size, s);
        #endif
    }
}
