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
struct node* find_previous(struct Song x, struct node* list) { 
 
/*1*/ struct node* p = list; 
/*2*/ while( (p->next != NULL) && (p->next->song.artist == x.artist) ){
      p = p->next; 
} 
/*3*/ 
/*4*/ return p; 
} 
void delete(struct node* node){
   struct node* prev = find_previous(node->song, node);
   prev->next = node->next;
   free(node);
}

void print(struct node* list) {
   if(!list){
      printf("List empty!\n");
      return;
   }
  printf("%s     %s   (%d:%d) D: %f E: %f T: %f V: %f\n", list->song.title, list->song.artist, (list->song.dur / 600),(list->song.dur % 600), 
  list->song.dance, list->song.energy, list->song.tempo, list->song.valence);
}

void printSongs(struct node* s){
   while(s != NULL){
      printf("%s     %s    (%d:%ds) D: %f E: %f T: %f V: %f\n", s->song.title, s->song.artist, (s->song.dur / 600),(s->song.dur % 600), 
  s->song.dance, s->song.energy, s->song.tempo, s->song.valence);
  s = s->next;
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
  //struct node* songNode;
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
      
        list = insert_front(song1, NULL);
        
      } else {
         
         list = insert_front(song1, list);
         
         
      }
      j++;
      //fclose(infile);
      outfile = fopen("output.txt", "w");
   if (outfile == NULL) {
    printf("Error: unable to open outfile\n");
    exit(1);
  }

  
  
  
      
      
    }
   free(listOfWords);
  }
  
  //free(songNode);
//   free(buffer);
//   free(header);
  int len = 5;
  printSongs(list);
  printf("Dataset contains %d songs\n", len);
  char cont;
  printf("Press 'd' to show the most danceable song (any other key to quit): ");
   scanf(" %c", &cont);
   printf("\n");
  while(cont == 'd' && len > 0){
   
   struct node* most = list;
   struct node* n = list;
   while(n != NULL){
      if(n->song.dance > most->song.dance){
         most = n;
         
      }
      n = n->next;
   }
   free(n);
      print(most);
      printf("-----------------------\n");
      delete(most);
      len -= 1;
      printSongs(list);
      printf("Dataset contains %d songs\n", len);
      
      printf("-------------------------------------------------------\n");
      printf("Press 'd' to show the most danceable song (any other key to quit): ");
      scanf(" %c",&cont);
   

  }
  //printf(outfile, "This is output! %d", 100);
  fclose(outfile);
  fclose(infile);
  //print(list);
  clearList(list);
  
  return 0;
}
