/*----------------------------------------------
 * Author: Hilary Lutz
 * Date: 2/22/23
 * Description: A function that reads in ppm binary files
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"

// Choose *one* to implement (do not remove the other one!)

struct ppm_pixel** read_ppm_2d(const char* filename, int* w, int* h) {
  return NULL;
}

struct ppm_pixel* read_ppm(const char* filename, int* w, int* h) {
 
  
  FILE* infile = NULL;
infile = fopen(filename, "rb");
if (infile == NULL) {
    printf("Error: unable to open file %s\n", "input.txt");
    exit(1);
  }

  char header[1024]; 
  for(int x = 0; x < 4; x++){
   fgets(header, 1024, infile);
   
   if(x == 2){
      sscanf(header, "%d", w);
      sscanf(header, "%d", h);
   }
  }
  
  

 
   

    // tokenize the line
    struct ppm_pixel* listOfPixs;
    listOfPixs = malloc(sizeof(struct ppm_pixel) * *w * *h);
    if(listOfPixs == NULL){
      printf("Error allocating memory\n");
      return NULL;
    }
   
    fread(listOfPixs, sizeof(struct ppm_pixel), (*h * *w), infile);
  
      
      
    
    fclose(infile);
    
    return listOfPixs;
}
