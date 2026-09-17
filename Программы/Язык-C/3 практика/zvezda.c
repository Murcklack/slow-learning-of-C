#include <stdio.h>

int main(void) {
  long double public_key;
  long double module;
  long double messege;
  long double q;
  long double p;

  printf("public_key: ");
  scanf("%LF", &public_key);
  printf("module: ");
  scanf("%LF", &module);
  printf("messege: ");
  scanf("%LF", &messege);

  printf("%LF %LF", p, q);
  return 0;
}
