#include "stdio.h"

int main(void){

  long code, operator, tri, dva, dva2;
  scanf("+ %1ld %1ld %1ld %1ld %1ld", &code, &operator, &tri, &dva, &dva2);
  printf("+%ld (%ld) %ld-%ld-%ld",code,operator,tri,dva,dva2);
  return 0;
}
