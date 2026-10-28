#include <stdio.h>

int main(void) {
  int a = 11, s, n;
  for (s = 0, n = 2; n < a; n++) {
    if (a % n == 0)
      s++;
  }
  if (s == 0) {
    puts("Good");
  }
}
