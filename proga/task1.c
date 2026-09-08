#include <stdio.h>

int main(){
  printf("|%d|\n",555);
  printf("|%10d|\n",555);
  printf("|%-10d|\n\n",555);
  
  printf("Words:%10d\n",59);
  printf("Letters:%10d\n",1004);
  printf("Digits:%8d\n\n",8);

  float a = 0.100000;
  float b = 0.200000;
  float sum = a + b;
  printf("a = %f; b = %f\n",a,b);
  printf("a + b = %.17f\n",sum);
}

