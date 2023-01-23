/***************************************************
 * mathgame.c
 * Author: 
 * Implements a math game
 */

#include <stdio.h>
#include <stdlib.h>
int main() {
  int numTimes = 0;
  int numWon = 0;
  int result = 0;
  printf("Welcome to this math game! \n");
  printf("How many times do you want to play? \n");
  scanf("%d", &numTimes);
  for(int i = 0; i < numTimes; i ++){
    int one = rand() % 10;
    int two = rand() % 10;
    printf("What is %d", one, " + %d", two, "? ");
    scanf("%d", &result);
    if(result == (one + two)){
      numWon ++;
      printf("Correct!\n");
    } else {
     printf("Incorrect!\n"); 
    }
  }
  printf("You got %d out of %d correct. Good game!", numWon, numTimes);
  return 0;
}
