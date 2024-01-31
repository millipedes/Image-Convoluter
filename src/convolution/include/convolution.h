#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "../../canvas/include/canvas.h"

#define DEFAULT_SIGMA 0.84089642

typedef struct MATRIX_T {
  double ** values;
  int height;
  int width;
} matrix;

canvas convolute_canvas(canvas canvas_old, canvas canvas_new,
    matrix the_matrix);
pixel convolute_pixel(canvas canvas_old, matrix the_matrix,
    int pixel_i, int pixel_j);
matrix gaussian_two_d(double sigma, int width, int height);
double gauss_matrix_element(double sigma, double i, double j);
void free_gauss_two_d(matrix gauss);

#endif
