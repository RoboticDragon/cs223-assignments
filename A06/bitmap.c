/*----------------------------------------------
 * Author: Hilary Lutz
 * Date: 3/1/23
 * Description: Reads in hex and translates it into image
 ---------------------------------------------*/
#include <stdio.h>

int main() {
  unsigned long img;
  scanf(" %lx", &img);
  printf("Image (unsigned long): %lx\n", img);
  unsigned long mask = 0x1ul << 63;
  unsigned long storage;
  
  for(int i = 63; i >= 0; i--){
    storage = img & mask;
    if(storage == 0){
      printf(" ");
    } else{
      printf("@");
    }
    if(i % 8 == 0){
      printf("\n");
    }
    mask = mask >> 1;
  }
  // todo: your code here
  return 0;
}
