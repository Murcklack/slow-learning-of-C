#include <stdio.h>

int main(void){
  printf("Input Temperature: ");
  float temp;
  char znak;
  scanf("%f %c",&temp,&znak);
  if (znak == 'c' || znak == 'C'){
    znak = 'f';
    temp = temp * 1.8 + 32;
    printf("Output Temperature: %.1f%c\n",temp,znak);
  }
  else if (znak == 'f' || znak == 'F'){
    znak = 'c';
    temp = (temp - 32) / 1.8;
    printf("Output Temperature: %.1f%c\n",temp,znak);
  }
  else {
    printf("Kernel Panic\n");
    return 1;
  }
  return 0;
}
