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
unsigned char* printbincharpad(char c)
{
  unsigned char* output = malloc(sizeof(c) * 7);
    for (int i = 7; i >= 0; --i)
    {
         output[i] = ((c & (1 << i)) ? '1' : '0') ;
         //printf("%c", output[i]);
    }
    //printf("\n");
    return output;
}
int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: encode <file.ppm>\n");
    return 0;
  }
  int w;
  int h;
  struct ppm_pixel* pixels = read_ppm(argv[1], &w, &h);
  //FILE* fp = ("feep-raw-encoded.ppm", "wb");
 
  int* pixArr = malloc(sizeof(int) * w * h *3);
   printf("Passed pixArr\n");
  char* message = "hello";
  //char* output = malloc(sizeof(char) * w * h *3);
  int index = 0;
  unsigned int* binMessage = malloc(sizeof(char) * strlen(message) * 8);
   printf("Passed binMessage\n");
  for(int j = 0; j < strlen(message); j += 1){
    //printf("%c\n", message[j]);
    unsigned char* charMessage = printbincharpad(message[j]);
    for(int x = 7; x >= 0; x--){
      printf("%c", charMessage[x]);
      binMessage[index] = charMessage[x];
      index ++;
    }
    
  }
  index = 0;
  // int i2 = 0;
  // double sum = 0;
 for(int i = 0; i < sizeof(pixels); i++){
    pixArr[index] = pixels[i].red % 2;
    pixArr[index + 1] = pixels[i].green % 2;
    pixArr[index + 2] = pixels[i].blue % 2;
    index += 3;
 }
  for(int y = 0; y < (sizeof(char) * strlen(message) * 8); y++){
    pixArr[y] = binMessage[y];
    // printf("%c", binMessage[y]);
    // printf("%c", pixArr[y]);
  }
  printf("\n");
 
  //write_ppm(fp, pixArr, w, h);
  free(pixArr);
  free(pixels);
  free(binMessage);
  return 0;
}

