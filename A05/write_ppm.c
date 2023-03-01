/*----------------------------------------------
 * Author: Hilary Lutz
 * Date: 2/22/23
 * Description: A program that writes binary data
 ---------------------------------------------*/
#include "write_ppm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// implement *one* (but do not remove the other one)!

void write_ppm(const char* filename, struct ppm_pixel* pixels, int w, int h) {
// open a file for writing that has the given filename
FILE* fp = NULL;
fp = fopen(filename, "wb");

if (fp == NULL) {
    printf("Error: unable to open file %s\n", "input.txt");
    exit(1);
  }

  fprintf(fp, "P6\n# Created by GIMP version 2.10.24 PNM plug-in\n %d %d\n255\n", w, h);
  fwrite(pixels, sizeof(struct ppm_pixel), (w * h), fp);
  
  fclose(fp);
  
}

void write_ppm_2d(const char* filename, struct ppm_pixel** pixels, int w, int h) {

}
