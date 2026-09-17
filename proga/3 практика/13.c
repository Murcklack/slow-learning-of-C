#include <stdio.h>

int main(void) {
  int n = 10, s, i;
  for (s = 1, i = 0; i <= n; i++) {
    s = s * 2;
    printf("%d\n", s);
  }
  return 0;
}
