#include "include/convolution.h"

canvas convolute_canvas(canvas canvas_old, canvas canvas_new,
    matrix the_matrix) {
  for(int i = 0; i < canvas_old.height; i++)
    for(int j = 0; j < canvas_old.width; j++)
      canvas_new.values[i][j] = convolute_pixel(canvas_old, the_matrix, i, j);
  return canvas_new;
}

pixel convolute_pixel(canvas canvas_old, matrix the_matrix,
    int pixel_i, int pixel_j) {
  double new_r = 0.0;
  double new_g = 0.0;
  double new_b = 0.0;
  for(int i = pixel_i - (the_matrix.height / 2);
      i < pixel_i + (the_matrix.height / 2); i++)
    for(int j = pixel_j - (the_matrix.width / 2);
        j < pixel_j + (the_matrix.width / 2); j++)
      if(i > 0 && j > 0 && i < canvas_old.height && j < canvas_old.width) {
        new_r += ((double)canvas_old.values[i][j].r
            * the_matrix.values[i - pixel_i + (the_matrix.height / 2)]
                               [j - pixel_j + (the_matrix.width / 2)]);
        new_g += ((double)canvas_old.values[i][j].g 
            * the_matrix.values[i - pixel_i + (the_matrix.height / 2)]
                               [j - pixel_j + (the_matrix.width / 2)]);
        new_b += ((double)canvas_old.values[i][j].b
            * the_matrix.values[i - pixel_i + (the_matrix.height / 2)]
                               [j - pixel_j + (the_matrix.width / 2)]);
      }

  return (pixel){(uint8_t)new_r, (uint8_t)new_g, (uint8_t)new_b};
}

matrix gaussian_two_d(double sigma, int width, int height) {
  matrix the_matrix = {0};

  the_matrix.values = calloc(height, sizeof(double *));
  for(int i = 0; i < width; i++)
    the_matrix.values[i] = calloc(width, sizeof(double));
  the_matrix.height = height;
  the_matrix.width = width;

  for(int i = -height / 2; i < height / 2 + 1; i++)
    for(int j = -width / 2; j < width / 2 + 1; j++)
      the_matrix.values[i + height / 2][j + width / 2]
        = gauss_matrix_element(sigma, i, j);

  return the_matrix;
}

double gauss_matrix_element(double sigma, double i, double j) {
  return (1.0 / (2.0 * M_PI * pow(sigma, 2))) *
    pow(M_E, -(pow(i, 2) + pow(j, 2)) / (2.0 * pow(sigma, 2)) );
}

void free_gauss_two_d(matrix gauss) {
  if(gauss.values) {
    for(int i = 0; i < gauss.height; i++)
      free(gauss.values[i]);
    free(gauss.values);
  }
}
