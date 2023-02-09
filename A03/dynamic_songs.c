/*----------------------------------------------
 * Author: Hilary Lutz
 * Date: 2/8/23
 * Description: A program that reads in songs from a csv file. 
 ---------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct Song{
  char title[128];
  char artist[128];
  int durSec;
  int durMin;
  float dance;
  float energy;
  float tempo;
  float valence;
};
int main() {
    FILE *fp;
   char str[128];

   /* opening file for reading */
   fp = fopen("songlist.csv" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL ) {
      /* writing content to stdout */
      puts(str);
   }
   fclose(fp);
  return 0;
}
