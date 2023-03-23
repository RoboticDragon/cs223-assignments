#include <stdio.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    pid_t child_a, child_b;
    int base = getpid();
    printf("%d] A0\n", getpid() % base);
    child_a = fork();
    
    if (child_a == 0) {
      printf("%d] B1\n", getpid() % base);
    } else {
      child_b = fork();

    if (child_b == 0) {
      sleep(5);
        printf("%d] C1\n", getpid() % base);
    } else {
        printf("%d] B0\n", getpid() % base);
        sleep(5);
        printf("%d] C0\n", getpid() % base);
    }
}
  printf("%d] Bye!\n", getpid() % base);
  return 0;
}
