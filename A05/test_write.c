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
  //int c;
  struct ppm_pixel* pixels = read_ppm("feep-raw.ppm", &w, &h);
  struct ppm_pixel* des = malloc(w * h * sizeof(struct ppm_pixel));
  write_ppm("test.ppm", pixels, w, h);
 //FILE* fp = fopen("test.ppm", "r");
  // test writing the file to test.ppm, reload it, and print the contents
  FILE* output = NULL;
  output = fopen("test.ppm", "wb");
 
  fread(des, sizeof(struct ppm_pixel), h * w, output);
  // todo: print out the grid of pixels
  for(int i = 0; i < (w * h); i++){
    
      printf("(%d, %d, %d)\n", des[i].red, des[i].green, des[i].blue);
   
  }
  
  printf("\n");
  free(pixels);
  free(des);
  fclose(output);
  
  return 0;
}
