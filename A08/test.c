#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char* argv[]) {
  int size = 480;
  float xmin = -2.0;
  float xmax = 0.47;
  float ymin = -1.12;
  float ymax = 1.12;
  int maxIterations = 1000;

  int opt;
  while ((opt = getopt(argc, argv, ":s:l:r:t:b:")) != -1) {
    switch (opt) {
      case 's': size = atoi(optarg); break;
      case 'l': xmin = atof(optarg); break;
      case 'r': xmax = atof(optarg); break;
      case 't': ymax = atof(optarg); break;
      case 'b': ymin = atof(optarg); break;
      case '?': printf("usage: %s -s <size> -l <xmin> -r <xmax> -b <ymin> -t <ymax>\n", argv[0]); break;
    }
  }
  
  printf("Generating mandelbrot with size %dx%d\n", size, size);
  printf("  X range = [%.4f,%.4f]\n", xmin, xmax);
  printf("  Y range = [%.4f,%.4f]\n", ymin, ymax);
  struct ppm_pixel* palette  = malloc(sizeof(struct ppm_pixel) * maxIterations);
  struct ppm_pixel* pixels  = malloc(sizeof(struct ppm_pixel) * size * size);
  for(int x = 0; x <  maxIterations; x++){
    palette[x].red = rand() % 255;
    palette[x].green = rand() % 255;
    palette[x].blue = rand() % 255;
  }
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      float xfrac = i / (float)size;
      float yfrac = j / (float)size;
      float x0 = xmin + xfrac * (xmax/2 - xmin);
      float y0 = ymin + yfrac * (ymax - ymin);
      float x = 0;
      float y = 0;
      int iter = 0;
      while (iter < maxIterations && x*x + y*y < 2*2){
        float xtmp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtmp;
        iter++;
      }
      if (iter < maxIterations){
        pixels[j * size + i].red = palette[iter].red;
        pixels[j * size + i].green = palette[iter].green;
        pixels[j * size + i].blue = palette[iter].blue;
      } // escaped
      else{
        pixels[j * size + i].red = 0;
        pixels[j * size + i].green = 0;
        pixels[j * size + i].blue = 0;
      }
        
    }
  }
  srand(time(0));
  write_ppm("mandelbrot-480-1649001071.ppm", pixels,size, size);
  // compute image
  free(pixels);
  free(palette);
  return 0;
}