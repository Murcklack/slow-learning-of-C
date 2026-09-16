#include <stdio.h>
// Отделяем последнюю цифру и складываем её в S
int main(void) {
  int a = 514999, k, s;
  for (int n = a, s = 0; n != 0; n = n / 10) {
    k = n % 10;
    s = s + k;
    printf("%d-%d\n", k, s);
  }
  return 0;
}
