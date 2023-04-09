#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include "read_ppm.h"
#include "write_ppm.h"
#include <assert.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(int argc, char* argv[]) {
  struct timeval stop, start;
  double timer = time(0);
  gettimeofday(&start, NULL);
  int size = 100;
  float xmin = -2.0;
  float xmax = 0.47;
  float ymin = -1.12;
  float ymax = 1.12;
  int maxIterations = 1000;

  int opt;
  while ((opt = getopt(argc, argv, ":s:l:r:t:b:")) != -1) {
    switch (opt) {
      case 's': size = atoi(optarg); break;
      case 'l': xmin = atof(optarg); break;
      case 'r': xmax = atof(optarg); break;
      case 't': ymax = atof(optarg); break;
      case 'b': ymin = atof(optarg); break;
      case '?': printf("usage: %s -s <size> -l <xmin> -r <xmax> -b <ymin> -t <ymax>\n", argv[0]); break;
    }
  }
  
  printf("Generating mandelbrot with size %dx%d\n", size, size);
  printf("  X range = [%.4f,%.4f]\n", xmin, xmax);
  printf("  Y range = [%.4f,%.4f]\n", ymin, ymax);
  struct ppm_pixel* palette  = malloc(sizeof(struct ppm_pixel) * maxIterations);
  struct ppm_pixel* pixels  = malloc(sizeof(struct ppm_pixel) * size * size);
  for(int x = 0; x <  maxIterations; x++){
    int basered = rand() % 255;
    int basegreen = rand() % 255;
    int baseblue = rand() % 255;
    palette[x].red = basered + rand() % 100 - 50;
    palette[x].green = basegreen + rand() % 100 - 50;
    palette[x].blue = baseblue + rand() % 100 - 50;
  }
 

  int shmid;
  shmid = shmget(IPC_PRIVATE, sizeof(char) * size, 0644 | IPC_CREAT);
  if (shmid == -1) {
    perror("Error: cannot initialize shared memory\n");
    exit(1);
  }

  char* buffer = shmat(shmid, NULL, 0);
  if (buffer == (void*) -1) {
    perror("Error: cannot access shared memory\n");
    exit(1);
  } 

  buffer[40] = '\0';
  for (int i = 0; i < 4; i++) {
    int pid = fork();
    if (pid == 0) {
      for(int i = 0; i < size / 2; i++){
    for(int j = 0; j < size / 2; j++){
      float xfrac = i / (float)size;
      float yfrac = j / (float)size;
      float x0 = xmin + xfrac * (xmax - xmin);
      float y0 = ymin + yfrac * (ymax - ymin);
      float x = 0;
      float y = 0;
      int iter = 0;
      while (iter < maxIterations && x*x + y*y < 2*2){
        float xtmp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtmp;
        iter++;
      }
      if (iter < maxIterations){
        pixels[j * size + i].red = palette[iter].red;
        pixels[j * size + i].green = palette[iter].green;
        pixels[j * size + i].blue = palette[iter].blue;
      } // escaped
      else{
        pixels[j * size + i].red = 0;
        pixels[j * size + i].green = 0;
        pixels[j * size + i].blue = 0;
      }
        
    }
  }
      exit(0);
    } else {
      printf("Launched child process: %d\n", pid);
    }
  }

  for (int i = 0; i < 4; i++) {
    int status;
    int pid = wait(&status);
    if(i == 0){
      for(int i = size / 2; i < size; i++){
    for(int j = size / 2; j < size; j++){
      float xfrac = i / (float)size;
      float yfrac = j / (float)size;
      float x0 = xmin + xfrac * (xmax - xmin);
      float y0 = ymin + yfrac * (ymax - ymin);
      float x = 0;
      float y = 0;
      int iter = 0;
      while (iter < maxIterations && x*x + y*y < 2*2){
        float xtmp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtmp;
        iter++;
      }
      if (iter < maxIterations){
        pixels[j * size + i].red = palette[iter].red;
        pixels[j * size + i].green = palette[iter].green;
        pixels[j * size + i].blue = palette[iter].blue;
      } // escaped
      else{
        pixels[j * size + i].red = 0;
        pixels[j * size + i].green = 0;
        pixels[j * size + i].blue = 0;
      }
        
    }
  }
    } else if (i == 1){
      for(int i = 0; i < size / 2; i++){
    for(int j = size / 2; j < size; j++){
      float xfrac = i / (float)size;
      float yfrac = j / (float)size;
      float x0 = xmin + xfrac * (xmax - xmin);
      float y0 = ymin + yfrac * (ymax - ymin);
      float x = 0;
      float y = 0;
      int iter = 0;
      while (iter < maxIterations && x*x + y*y < 2*2){
        float xtmp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtmp;
        iter++;
      }
      if (iter < maxIterations){
        pixels[j * size + i].red = palette[iter].red;
        pixels[j * size + i].green = palette[iter].green;
        pixels[j * size + i].blue = palette[iter].blue;
      } // escaped
      else{
        pixels[j * size + i].red = 0;
        pixels[j * size + i].green = 0;
        pixels[j * size + i].blue = 0;
      }
        
    }
  }
    } else if(i == 2){
      for(int i = size / 2; i < size; i++){
    for(int j = 0; j < size / 2; j++){
      float xfrac = i / (float)size;
      float yfrac = j / (float)size;
      float x0 = xmin + xfrac * (xmax - xmin);
      float y0 = ymin + yfrac * (ymax - ymin);
      float x = 0;
      float y = 0;
      int iter = 0;
      while (iter < maxIterations && x*x + y*y < 2*2){
        float xtmp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtmp;
        iter++;
      }
      if (iter < maxIterations){
        pixels[j * size + i].red = palette[iter].red;
        pixels[j * size + i].green = palette[iter].green;
        pixels[j * size + i].blue = palette[iter].blue;
      } // escaped
      else{
        pixels[j * size + i].red = 0;
        pixels[j * size + i].green = 0;
        pixels[j * size + i].blue = 0;
      }
        
    }
  }
    } else {
      for(int i = 0; i < size / 2; i++){
    for(int j = 0; j < size / 2; j++){
      float xfrac = i / (float)size;
      float yfrac = j / (float)size;
      float x0 = xmin + xfrac * (xmax - xmin);
      float y0 = ymin + yfrac * (ymax - ymin);
      float x = 0;
      float y = 0;
      int iter = 0;
      while (iter < maxIterations && x*x + y*y < 2*2){
        float xtmp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtmp;
        iter++;
      }
      if (iter < maxIterations){
        pixels[j * size + i].red = palette[iter].red;
        pixels[j * size + i].green = palette[iter].green;
        pixels[j * size + i].blue = palette[iter].blue;
      } // escaped
      else{
        pixels[j * size + i].red = 0;
        pixels[j * size + i].green = 0;
        pixels[j * size + i].blue = 0;
      }
        
    }
  }
    }
    printf("Child process complete: %d\n", pid);
  }
  gettimeofday(&stop, NULL);
  timer = stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec)/1.e6;
  printf("time is %f\n",timer);

  if (shmdt(buffer) == -1) {
    perror("Error: cannot detatch from shared memory\n");
    exit(1);
  }

  if (shmctl(shmid, IPC_RMID, 0) == -1) {
    perror("Error: cannot remove shared memory\n");
    exit(1);
  }   
  write_ppm("multi-mandelbrot-100.ppm", pixels,size, size);
  // compute image
  free(pixels);
  free(palette);
  return 0;
}
