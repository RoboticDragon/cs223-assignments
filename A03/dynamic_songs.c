/*----------------------------------------------
 * Author: Hilary Lutz
 * Date: 2/8/23
 * Description: A program that reads in songs from a csv file. 
 ---------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Song{
  char title[128];
  char artist[128];
  int dur;
  float dance;
  float energy;
  float tempo;
  float valence;
};

void printSongs(struct Song *s, int len){
   for(int i = 0; i < len; i ++){
      printf("%d) %s\n\t artist: %s\n\t duration (in milliseconds): %d\n\t danceability: %f\n\t energy: %f\n\t tempo: %f\n\t valence: %f\n", i + 1, s[i].title, s[i].artist, s[i].dur, s[i].dance, s[i].energy, s[i].tempo, s[i].valence);
   }
}

int main() {
    FILE* infile = NULL;
    FILE* outfile = NULL;
   struct Song *songs;
   
   infile = fopen("songlist.csv", "r");
  if (infile == NULL) {
    printf("Error: unable to open file %s\n", "input.txt");
    exit(1);
  }

  // read in data line by line
  int length;
  char buffer[1024];
  fgets(buffer, 1024, infile);
  length = atof(strtok(buffer, ","));
  songs = malloc(sizeof(struct Song) * length);
  char header[1024]; 
  fgets(header, 1024, infile);
  //printf("%s\n", header);
  printf("Welcome to Hilary's Song List.\n");
  int times = 0;
  int j = 0;
  while (fgets(buffer, 1024, infile)) {
   if(times > 50){
      break;
   }

    // tokenize the line

    char* listOfWords = strtok(buffer, ",");
    struct Song song;
    
    while (listOfWords) {
      if(times > 50){
         break;
      }
      int i = 0;
      

      
      
      while(listOfWords){
         if(times > 20){
            break;
         }
         if(i == 0){
            strcpy(song.title, listOfWords);
         } else if (i == 1){
            strcpy(song.artist,listOfWords);
         } else if(i == 2){
            int d = atoi(listOfWords);
            song.dur = d;
         } else if (i == 3){
            float d = atof(listOfWords);
            song.dance = d;
         } else if(i == 4){
            float e = atof(listOfWords);
            song.energy = e;
         } else if(i == 5){
            float t = atof(listOfWords);
            song.tempo = t;
         } else {
            float v = atof(listOfWords);
            song.valence = v;
         }
        times ++;
        listOfWords = strtok(NULL, ",");
        i++;
      }
      times = 0;
      listOfWords = strtok(NULL, ",");
      songs[j] = song;
      
      j++;
      
    }

  }
  
  printSongs(songs, length);
   
  fclose(infile);

  outfile = fopen("output.txt", "w");
  if (outfile == NULL) {
    printf("Error: unable to open outfile\n");
    exit(1);
  }

  fprintf(outfile, "This is output! %d", 100);
  fclose(outfile);
  free(songs);

  return 0;
}
