/*----------------------------------------------
 * Author: Hilary Lutz
 * Date: 3/1/23
 * Description
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"
#include <math.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: decode <file.ppm>\n");
    return 0;
  }
  int w;
  int h;
  struct ppm_pixel* pixels = read_ppm(argv[1], &w, &h);
  int* pixArr = malloc(sizeof(int) * w * h *3);
  
  int index = 0;
  double sum = 0;
  //unsigned char* chars = malloc((sizeof(unsigned char) * w * h * 3)/8);
  for(int i = 0; i < (w * h); i++){
    pixArr[index] = pixels[i].red % 2;
    
    pixArr[index + 1] = pixels[i].green % 2;

    pixArr[index + 2] = pixels[i].blue % 2;
    //printf("%d%d%d", pixels[i].red % 2, pixels[i].green % 2, pixels[i].blue % 2);
    //printf("%d%d%d", pixArr[index], pixArr[index + 1], pixArr[index + 2]);
    index += 3;
  }
  //printf("\n");
  for(int x = 0; x < (3 * w * h); x++){
    sum += pixArr[x] * (pow(2, 7 - (x % 8)));
    if(x % 8 == 0 && x > 0){
      unsigned char s = (unsigned int) sum;
      //printf("Sum: %f s: %d \n", sum, s);
      //printf("%d\n", s);
      //unsigned char in = s;
      //chars[(x / 8) - 1] = in;
      printf("%c", s);
      //printf("%02X ", s);
      sum = 0;
     }
  }
  printf("\n");
  //printf("%hhn\n", chars);
  free(pixels);
  free(pixArr);
  //free(chars);
  return 0;
}

