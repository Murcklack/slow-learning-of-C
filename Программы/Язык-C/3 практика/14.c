#include <stdio.h>

// Определяем простое число
int main(void) {
  int n, a = 7;
  for (n = 2; n < a; n++) {
    if (a % n == 0) {
      break;
    }
  }
  if (n == a) {
    puts("Good");
  }
  return 0;
}
