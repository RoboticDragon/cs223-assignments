/*----------------------------------------------
 * Author: Hilary Lutz
 * Date: 2/8/23
 * Description: A program which adds dots between the letters of a phrase. 
 ---------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
  int pause;
  char word1[32];
  char *word2; 
  printf("Pause length: ");
  scanf(" %d%*c", &pause);
  printf("Text: ");
  scanf("%[^\n]%*c", word1);
  long len = strlen(word1);
  word2 = malloc(sizeof(char) * (pause + 1) * strlen(word1) + 1);
  word2[sizeof(char) * (pause + 1) * strlen(word1)] = '\0';
  printf("sizeof word1: %lu\n", len);
  printf("sizeof word2: %lu\n", sizeof(word2));
  printf("sizeof pause: %lu\n", sizeof(pause));
  printf("word1 * pause: %lu\n", (len * (pause + 1)));
  for(int i = 0; i < ((pause + 1) * strlen(word1)); i++){
    if(i % (pause + 1) == 0){
      word2[i] = word1[i / (pause + 1)];
    } else{
      word2[i] = '.';
    }
  }
  
  printf("%s \n", word2);
  free(word2);
  return 0;
}
