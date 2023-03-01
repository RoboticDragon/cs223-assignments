/*----------------------------------------------
 * Author: Hilary Lutz
 * Date: 2/23/23
 * Description: A program that reads and writes a binary file
 ---------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char** argv) {
  int w, h;

  struct ppm_pixel* pixels = read_ppm("feep-raw.ppm", &w, &h);
  
  // test writing the file to test.ppm, reload it, and print the contents
  write_ppm("test.ppm", pixels, w, h);
  free(pixels);

  pixels = read_ppm("test.ppm", &w, &h);
 

  // todo: print out the grid of pixels
  for(int i = 0; i < (w * h); i++){
    
      printf("(%d, %d, %d)\n", pixels[i].red, pixels[i].green, pixels[i].blue);
   
  }
  
  printf("\n");
  free(pixels);
 
 
  
  return 0;
}
