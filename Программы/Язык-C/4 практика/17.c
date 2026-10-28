#include <stdio.h>
void bin(int dec) {
    // в обратном порядке for (int i = 0; i < sizeof(dec)*8 ; i++)
    for (int i = 2; i >= 0 ; i--) {
        printf("%d", (dec >> i) & 1);
    }
    printf("\n");
}

void print_bin(unsigned long long a) {
  int octal_digits[sizeof(a)];
  int count = 0;

  unsigned long long temp = a;

  while (temp > 0) {
    octal_digits[count] = temp & 0b111; // берём 3 бита
    temp >>= 3;                   // сдвигаем на 3 бита
    printf("Бит(%d): ", count+1);
    bin(octal_digits[count]);
    count++;
  }

  printf("Результат: 0");

  for (int i = count - 1; i >= 0; i--) {
    printf("%d", octal_digits[i]);
  }
}

int main(void) {
  unsigned long long a = 0b0100010010010;
  printf("Исходное в восьмиричной 0%llo\n", a);

  print_bin(a);
  return 0;
}