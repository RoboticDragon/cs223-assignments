#include <stdio.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
  int val = 5003;
  char* firstVal = malloc(sizeof(char) * 8);
  int* list;
  int len = 0;
  FILE* fp = fopen("data.bin", "rb");
  fread(&len, sizeof(int), 1, fp);
  printf("Test: %d\n", len);
  
  list = malloc(len * sizeof(int));
  fread(list, sizeof(int), len, fp);
  //printf("Test %d hello\n", list[1]);
  //printf("\n");
  pid_t child;
  child = fork();
  int isFound = 0;
  int i;
  if(child == 0){
    for(i = len / 2; i < len; i++){
      if(list[i] == val){
        isFound = 1;
        break;
      }
    }
    if(isFound == 1){
      printf("Child found value %d at index %d\n", val, i);
    } else {
      printf("Child not found\n");
    }
  } else {
    for(i = 0; i < len / 2; i++){
      if(list[i] == val){
        isFound = 1;
        break;
      }
    }
    if(isFound == 1){
      printf("Parent found value %d at index %d\n", val, i);
    } else {
      printf("Parent not found\n");
    }
  }
  //printf("%d\n", list[0]);
  fclose(fp);
  free(list);
  free(firstVal);
  return 0;
}
