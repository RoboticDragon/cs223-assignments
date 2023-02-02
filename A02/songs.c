#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/***************************************************
 * songs.c
 * Author: Hilary Lutz
 * Implements a song holder/folder thing
 */
struct Song{
  char title[32];
  char author[32];
  int durSec;
  int durMin;
  float dance;
};
int main() {
  struct Song song1;
  struct Song song2;
  struct Song song3;
  strcpy(song1.title, "Viva la Vida");
  strcpy(song1.author, "Coldplay");
  song1.durMin = 4;
  song1.durSec = 35;
  song1.dance = 0.5;
  strcpy(song2.title, "Livin la Vida Loca");
  strcpy(song2.author, "Ricky Martin");
  song2.durMin = 3;
  song2.durSec = 26;
  song2.dance = 0.8;
  strcpy(song3.title, "Stormbreaker");
  strcpy(song3.author, "Cami-Cat");
  song3.durMin = 3;
  song3.durSec = 56;
  song3.dance = 0.6;
  struct Song songs[3] = {song1, song2, song3};
  printf("Welcome to Hilary's Song List.\n");
  for(int i = 0; i < 3; i ++){
    printf("%d) %s artist: %s duration: %d:%d danceability: %f \n", i, songs[i].title, songs[i].author, songs[i].durMin, songs[i].durSec, songs[i].dance);
  }
  int songID;
  printf("Enter a song ID to edit [0,1,2]: ");
  scanf("%d", &songID);
  if(songID > 2 || songID < 0){
    printf("Chose a valid number!\n");
  } else {
    printf("Which attribute do you wish to edit? [artist, title, duration, danceability]: ");
    char attr[14];
    scanf("%s", attr);
    if(strcmp(attr, "artist") == 0){
      char art[32];
      printf("Enter artist here: ");
      scanf(" %[^\n]%*c", art);
      strcpy(songs[songID].author, art);
    } else if(strcmp(attr, "title") == 0){
      char titl[32];
      printf("Enter title here: ");
      scanf(" %[^\n]%*c", titl);
      strcpy(songs[songID].title, titl);
    } else if(strcmp(attr, "duration") == 0){
      printf("Enter duration (minutes) here: ");
      scanf(" %d%*c", &songs[songID].durMin);
      printf("Enter duration (seconds) here: ");
      scanf(" %d%*c", &songs[songID].durSec);
    } else {
      printf("Enter danceability here: ");
      scanf(" %f%*c", &songs[songID].dance);
    }
    printf("\n");
    for(int i = 0; i < 3; i ++){
      printf("%d) %s artist: %s duration: %d:%d danceability: %f \n", i, songs[i].title, songs[i].author, songs[i].durMin, songs[i].durSec, songs[i].dance);
    }
  }
  
  return 0;
}
