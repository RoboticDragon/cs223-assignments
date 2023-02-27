/*----------------------------------------------
 * Author: Hilary Lutz
 * Date: 2/22/23
 * Description: A program that tests reads in binary. 
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main() {
  int w;
  int h;
  struct ppm_pixel* pixels = read_ppm("feep-raw.ppm", &w, &h);
  for(int i = 0; i < (w * h); i++){
    
      printf("(%d, %d, %d)\n", pixels[i].red, pixels[i].green, pixels[i].blue);
   
  }
  // todo: print out the grid of pixels
  printf("\n");
  free(pixels);
  
  return 0;
}

