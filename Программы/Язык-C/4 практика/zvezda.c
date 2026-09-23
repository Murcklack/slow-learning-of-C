#include <math.h>
int main(void) {
  int t = 0, C = 20, A = 10, F = 10;
  float speed = 0.1;

  while (1) {
    for (int y = 0; y < 50; y++) {
      int x1 = C + A * sin(F * y + t);
      int x2 = C - A * sin(F * y + t);
    }
  }
}
