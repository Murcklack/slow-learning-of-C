#include <stdio.h>

int main(){
  int max = 2147483647;
  printf("%d\n", max + 1);

  unsigned int un = 0;
  printf("%u\n", un - 1);

  char min_ch = -128;
  printf("%hhd\n", min_ch - 1);
}
