#include <stdio.h>

int main(void){
  printf("Введите год: ");
  int god;
  scanf("%d",&god);
  if (god % 400 == 0){
    printf("YES\n");
  }
  else if(god % 100 == 0){
    printf("NO\n");
  }
  else if(god % 4 == 0){
    printf("YES\n");
  }
  else {
    printf("NO\n");
  }
  return 0;
}
