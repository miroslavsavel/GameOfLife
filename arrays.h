#ifndef ARRAYS
#define ARRAYS

extern int *generate_array(int length);
extern int ** generate_2D_array(int row, int col);
extern int ** allocate_2D_array(int row, int col);
extern void print_2D_array(int ** pole, int row, int col);
extern void deallocate_2D_array(int ** pole, int row, int col);
extern void print_array(int *pole, size_t length);

#endif