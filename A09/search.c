#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
struct thread_data {
  int start;
  int end;
  int* arr;
  int value;
  int valLoc;
};
void *find(void *userdata) {
  struct thread_data *data = (struct thread_data *) userdata;

  data->valLoc = -1;
  for (int i = data->start; i < data->end; i++) {
    if(data->arr[i] == data->value){
      data->valLoc = i;
    }
  }
  
  return (void*) NULL;
}
int main(int argc, char** argv) {
  srand(time(0));
  if (argc < 2) {
    printf("usage: %s <NumThreads>\n", argv[0]);
    exit(0);
  }
  int val = 5003;
  int* list;
  int len = 0;
  FILE* fp = fopen("data.bin", "rb");
  fread(&len, sizeof(int), 1, fp);
  printf("Test: %d\n", len);
  
  list = malloc(len * sizeof(int));
  fread(list, sizeof(int), len, fp);
   printf("Test with 4 threads\n");
  pthread_t threads[4];
  struct thread_data data[4];
  int subsize = len/4; // assume multiple of 4
  for (int i = 0; i < 4; i++) {
    data[i].arr = list;
    data[i].start = subsize * i;
    data[i].end = subsize * (i + 1);
    data[i].value = val;
    pthread_create(&threads[i], NULL, find, (void*) &data[i]);
  }
  int valLoc = -1;
  for (int i = 0; i < 4; i++) {
    pthread_join(threads[i], NULL);
    if (data[i].valLoc > -1){
      valLoc = data[i].valLoc;
    }
  }

  printf("The location of %d is %d\n", val, valLoc);
  free(list);
  fclose(fp);
  return 0;
}
