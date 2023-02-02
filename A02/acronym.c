#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/***************************************************
 * acronym.c
 * Author: Hilary Lutz
 * Implements an acronym maker
 */
int main() {
  char word[1025];
  printf("Enter a phrase: ");
  scanf("%[^\n]%*c", word);
  int i;
  int a = 0;
  char acro[100];
  for(i = 0; i < 1025; i ++){
    int low = islower(word[i]);
    if(low == 0 && word[i] != ' '){
      acro[a] = word[i];
      a ++;
    }
  }
  printf("Your acronym is %s\n", acro);
  return 0;
}
