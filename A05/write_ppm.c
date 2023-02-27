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
FILE* infile = NULL;
infile = fopen("feep-raw.ppm", "r");
FILE* outfile = NULL;
outfile = fopen(filename, "wb");
if (infile == NULL) {
    printf("Error: unable to open file %s\n", "input.txt");
    exit(1);
  }
  char header[1024]; 
  for(int x = 0; x < 4; x++){
   fgets(header, 1024, infile);
   fprintf(outfile, "%s", header);
   printf("%s", header);
   if(x == 2){
      sscanf(header, "%d", &w);
      sscanf(header, "%d", &h);
   }
  }
  
  
  fwrite(pixels, sizeof(struct ppm_pixel), (w * h), outfile);
  
  fclose(infile);
  fclose(outfile);
    // write the header to the file:
    //    1. the header needs P6 on the first line
    //    2. the header needs a comment on the second line
    //    3. the header needs the width and height on the third line (use passed in values)
    //    4. the header needs 255 on the fouth line
    // write the pixels with fwrite
    // close the file
}

void write_ppm_2d(const char* filename, struct ppm_pixel** pixels, int w, int h) {

}
