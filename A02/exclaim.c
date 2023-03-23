#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/***************************************************
 * exclaim.c
 * Author: Hilary Lutz
 * Implements a symbol word swap thing
 */
int main() {
  char word[32];
  printf("Enter a word: ");
  scanf("%s", word);
  char characters[4] = {'@', '!', '#', '*'};
  for(int i = 0; i < strlen(word); i++){
    if(word[i] == ' '){
      break;
    }
    int letter = islower(word[i]);
    if(letter > 0){
      char c = characters[rand() % 5];
      word[i] = c;
    }
  }
  printf("OMG! %s\n", word);
  return 0;
}
