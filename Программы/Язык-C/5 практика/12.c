#include <stdio.h>

int perevod(unsigned int a, int num_bytes) {
  int bytes[num_bytes];
  for (int i = 0; i < num_bytes; i++) {
    int shift = i * 8;
    unsigned char byte = (a >> shift) & 0xFF;
    bytes[i] = byte;
    printf("Байт %d (сдвиг на %2d бит): %x\n", i, shift, byte);
  }
  printf("0x");
  for (int i = num_bytes - 1; i >= 2; i--) {
    printf("%x", bytes[i]);
  }
  printf("%x%x", bytes[0], bytes[1]);
}

int main(void) {
  unsigned int a = 0x1092;
  int num_bytes = sizeof(a);

  printf("Исходное число: 0x%x\n", a);
  perevod(a, num_bytes);

  return 0; 
}