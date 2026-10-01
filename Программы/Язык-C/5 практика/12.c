#include <stdio.h>
#include <stdio.h>

int main(void) {
  unsigned int a = 0x00C0FFEE;
  
  // sizeof(a) вернет размер переменной a в байтах (обычно это 4 байта для int)
  int num_bytes = sizeof(a); 
  
  printf("Исходное число: 0x%08X\n\n", a);

  for (int i = 0; i < num_bytes; i++) {
    // Вычисляем, на сколько бит нужно сдвинуть число
    int shift = i * 8; 
    
    // Сдвигаем и накладываем маску 0xFF
    unsigned char byte = (a >> shift) & 0xFF;
    
    printf("Байт %d (сдвиг на %2d бит): %02X\n", i, shift, byte);
  }

  return 0;
}