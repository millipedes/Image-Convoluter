#include "../canvas/include/canvas.h"
#include "../convolution/include/convolution.h"

int main(void) {
  canvas read_canvas = read_canvas_png("test_in.png");
  canvas write_canvas = init_canvas(read_canvas.height, read_canvas.width,
      MAX_COL, MAX_COL, MAX_COL);
  matrix the_matrix = gaussian_two_d(DEFAULT_SIGMA, 7, 7);
  for(int i = 0; i < 15; i++) {
    if(i % 2 == 0)
      write_canvas = convolute_canvas(read_canvas, write_canvas, the_matrix);
    else
      read_canvas = convolute_canvas(write_canvas, read_canvas, the_matrix);
  }
  write_canvas_ppm(write_canvas, "test_out.png");
  free_canvas(read_canvas);
  free_canvas(write_canvas);
  free_gauss_two_d(the_matrix);
  return 0;
}
