#include <stdio.h>

int main(void) {
  int a = 11, i;
  for (i = 2; i < a; i++) {
    if (a % i == 0) {
      break;
    }
  }
  if (i == a)
    puts("Good");
}
