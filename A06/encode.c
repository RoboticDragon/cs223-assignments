/*----------------------------------------------
 * Author: 
 * Date: 
 * Description
 ---------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"
#include <math.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: encode <file.ppm>\n");
    return 0;
  }
  int w;
  int h;
  struct ppm_pixel* pixels = read_ppm(argv[1], &w, &h);
  int* pixArr = malloc(sizeof(int) * w * h *3);
  char* message = "lol";
  int index = 0;
  int i2 = 0;
  double sum = 0;
 
  
  //unsigned char* chars = malloc((sizeof(unsigned char) * w * h * 3)/8);
  for(int i = 0; i < (w * h); i++){
    if(i2 >= sizeof(message)){
      break;
    }
    if(pixels[i].red % 2 != message[i2] % 2){
      if(message[i2] % 2 == 0){
        pixels[i].red = pixels[i].red & 0xfe;
        //pixels[i].red = pixels[i].red & ~1;
      } else {
        //pixels[i].red = pixels[i].red | 1;
        pixels[i].red = pixels[i].red | 0x01;
      }
    }
    if(pixels[i].green % 2 != message[i2 + 1] % 2){
       if(message[i2] % 2 == 0){
        pixels[i].green = pixels[i].green & 0xfe;
        //pixels[i].green = pixels[i].green & ~1;
      } else {
        //pixels[i].green = pixels[i].green | 1;
        pixels[i].green = pixels[i].green | 0x01;
      }
    }
    if(pixels[i].blue % 2 != message[i2 + 2] % 2){
       if(message[i2] % 2 == 0){
        //pixels[i].blue = pixels[i].blue & ~1;
        pixels[i].blue = pixels[i].blue & 0xfe;
      } else {
        //pixels[i].blue = pixels[i].blue | 1;
        pixels[i].blue = pixels[i].blue | 0x01;
      }
    }
    //pixArr[index] = pixels[i].red % 2;
    
    //pixArr[index + 1] = pixels[i].green % 2;

    //pixArr[index + 2] = pixels[i].blue % 2;
    printf("%d%d%d", pixels[i].red % 2, pixels[i].green % 2, pixels[i].blue % 2);
    //printf("%d%d%d", pixArr[index], pixArr[index + 1], pixArr[index + 2]);
    //index += 3;
    i2 += 3;
  }
  printf("\n");
  write_ppm("feep-raw-encoded.ppm", pixels, w, h);
  free(pixels);
  pixels = read_ppm("feep-raw-encoded.ppm", &w, &h);
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
      printf("%02X\n", s);
      //printf("%02X ", s);
      sum = 0;
     }
  }
  free(pixels);
  free(pixArr);
  return 0;
}

