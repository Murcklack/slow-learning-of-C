#include <stdio.h>

void print_bin(unsigned long long a) {
  int octal_digits[sizeof(a)];
  int count = 0;

  unsigned long long temp = a;

  while (temp > 0) {
    octal_digits[count] = temp & 0b111; // берём 3 бита
    temp >>= 3;                         // сдвигаем на 3 бита
    count++;
  }

  printf("Результат: 0");

  for (int i = count - 1; i >= 0; i--) {
    printf("%d", octal_digits[i]);
  }
}

int main(void) {
  unsigned long long a = 0b0100010010010;
  printf("Исходное в восьмиричной %llo\n", a);

  print_bin(a);
  return 0;
}