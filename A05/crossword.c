/*----------------------------------------------
 * Author: Hilary Lutz
 * Date: 2/22/23
 * Description: A program that makes a crossword puzzle
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char* word1 = argv[1]; 
  char* word2 = argv[2];
  char** arr;
  int len1 = strlen(word1);
  int len2 = strlen(word2);
  arr = malloc((strlen(word1) * sizeof(char*)));
  for(int i = 0; i <len1; i++){
    arr[i] =  malloc(strlen(word2) * sizeof(char));
  }
  
  //char sim;
  int boo = 0;
  int i;
  int j;
  int ix1 = 0;
  int ix2 = 0;
  for(i = 0; i < len1; i ++){
    for(j = 0; j < len2; j ++){
      if(word1[i] == word2[j]){
        //sim = word1[i];
        boo = 1;
        break;
      }
      if(boo == 1){
        break;
      }
     
    }
    
    if(boo == 1){
        break;
      } else {
        j = 0;
      }
  }
  if(boo == 0){
    printf("No shared letters!\n");
    free(arr);
    
    //free(word1);
    //free(word2);
    return 0;
  }
  for(int x = 0; x < len1; x++){
    for(int y = 0; y < len2; y ++){
      if(x == (len1 - j - 1)){
       
        arr[x][y] = word2[ix2];
        
        ix2 ++;
      } else {
        
        arr[x][y] = '.';
      }
       if(y == j){
        arr[x][y] = word1[ix1];
        ix1 ++;
      }
    }
  }
  for(int a = 0; a < len1; a++){
    for(int b = 0; b < len2; b++){
      printf("%c ", arr[a][b]);
    }
    printf("\n");
  }
  for(int i = 0; i <len1; i++){
    free(arr[i]);
  }
  free(arr);
  //free(word1);
  //free(word2);
 
  return 0;
}
