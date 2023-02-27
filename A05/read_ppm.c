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
  
   //char buffer[1024];

 
 //printf("got here 1\n");
 
   int j = 0;

    
     // printf("Got here 2 \n");
    
     // printf("Got here 3 \n");
   

    // tokenize the line
    struct ppm_pixel* listOfPixs;
    listOfPixs = malloc(sizeof(struct ppm_pixel) * *w * *h);
    if(listOfPixs == NULL){
      printf("Error allocating memory\n");
      return NULL;
    }
    //printf("Got here 4 \n");
    //struct ppm_pixel* listOfPixs;
    fread(listOfPixs, sizeof(struct ppm_pixel), (*h * *w), infile);
    //printf("Got here 5 \n");
   // printf("%c",listOfPixs[0].red);
   // //printf("Got here 6 \n"); 
     
   //  while (listOfPixs) {
      //printf("%c\n", listOfPixs[0].blue);
      //printf("Got here 7 \n");
      //struct ppm_pixel pixel;
      //printf("Got here 8 \n");
      
      int i = 0;
      while(i < 3){
       
         if(i == 0){
            //pixel.red = listOfPixs[i].red;
            // printf("%d\n", pixel.red);
            // printf("Got here 9 \n");
         } else if (i == 1){
            //pixel.green = listOfPixs[i].green;
            // printf("%d\n", pixel.green);
            // printf("Got here 10 \n");
         } else {
            //pixel.blue = listOfPixs[i].blue;
            // printf("%d\n", pixel.blue);
            // printf("Got here 11 \n");
            
         }
      
        //listOfPixs = strtok(NULL, ",");
        i++;
        //printf("red: %c, green: %c, blue: %c\n", pixel.red, pixel.green, pixel.blue);
      }
      //printf("Got here 12 \n");
  
      //listOfPixs = strtok(NULL, ",");
      //printf("Red: %d, Green: %d, Blue: %d\n", pixel.red, pixel.green, pixel.blue);
    
      //printf("Got here 13 \n");
      j++;
  

  


    

    //}
    
    
    fclose(infile);
    
    return listOfPixs;
}
