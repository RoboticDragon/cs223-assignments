/*----------------------------------------------
 * Author: Hilary Lutz
 * Date: 2/15/23 (due date)
 * Description: A program that uploads songs in a linked list.
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
struct node {
  struct Song song;
  struct node* next;
};

struct node* insert_front(struct Song val, struct node* head) {
  struct node* n = malloc(sizeof(struct node));
  if (n == NULL) {
    printf("ERROR: Out of space!\n");
    exit(1);
  }
  n->song = val;
  n->next = head;
  return n;
}

void print(struct node* list) {
   if(!list){
      printf("List empty!\n");
      return;
   }
  for (struct node* n = list; n->next != NULL; n = n->next) {
    printf("Song: %s\n", n->song.title);
  }
}

void printSongs(struct Song *s, int len){
   for(int i = 0; i < len; i ++){
      printf("%d) %s\n\t artist: %s\n\t duration (in milliseconds): %d\n\t danceability: %f\n\t energy: %f\n\t tempo: %f\n\t valence: %f\n", i + 1, s[i].title, s[i].artist, s[i].dur, s[i].dance, s[i].energy, s[i].tempo, s[i].valence);
   }
}

void clearList(struct node* list){
   struct node* n = list;
   while(n!= NULL){
      struct node* n2 = n->next;
      free(n);
      n = n2;
   }
}
int main() {
  



//int length;
FILE* infile = NULL;
infile = fopen("songlist.csv", "r");
if (infile == NULL) {
    printf("Error: unable to open file %s\n", "input.txt");
    exit(1);
  }
  FILE* outfile = NULL;
  char buffer[1024];
  //fgets(buffer, 1024, infile);
  
  char header[1024]; 
  fgets(header, 1024, infile);
int times = 0;
  struct node* songNode;
    struct node* list;

    struct Song song1;
    int j = 0;
    while (fgets(buffer, 1024, infile)) {
   if(times > 50){
      break;
   }

    // tokenize the line

    char* listOfWords = strtok(buffer, ",");
    //struct Song song;
    
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
            strcpy(song1.title, listOfWords);
         } else if (i == 1){
            strcpy(song1.artist,listOfWords);
         } else if(i == 2){
            int d = atoi(listOfWords);
            song1.dur = d;
         } else if (i == 3){
            float d = atof(listOfWords);
            song1.dance = d;
         } else if(i == 4){
            float e = atof(listOfWords);
            song1.energy = e;
         } else if(i == 5){
            float t = atof(listOfWords);
            song1.tempo = t;
         } else {
            float v = atof(listOfWords);
            song1.valence = v;
         }
        times ++;
        listOfWords = strtok(NULL, ",");
        i++;
      }
      times = 0;
      listOfWords = strtok(NULL, ",");
      
      if(j == 0){
      printf("%s\n", song1.artist);
        list = insert_front(song1, songNode);
        
      } else {
         
         struct node* songNode2 = insert_front(song1, list);
         printf("%s\n", songNode2->next->song.artist);
         songNode = songNode2;
         printf("%s\n", songNode2->song.artist);
         
      }
      j++;
      //fclose(infile);
      outfile = fopen("output.txt", "w");
   if (outfile == NULL) {
    printf("Error: unable to open outfile\n");
    exit(1);
  }

  
  
  //free(listOfWords);
  //free(songNode);
      
      
    }

  }
  fprintf(outfile, "This is output! %d", 100);
  fclose(outfile);
  fclose(infile);
  print(list);
  return 0;
}
