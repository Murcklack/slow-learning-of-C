# Task 1
```C
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
```
# Task 2
```C
#include <stdio.h>

int main(){
  int max = 2147483647;
  printf("%d\n", max + 1);

  unsigned int un = 0;
  printf("%u\n", un - 1);

  char min_ch = -128;
  printf("%hhd\n", min_ch - 1);
}

```
# Task 3
```C
#include <stdio.h>

int main() {
  char ch = 63;
  unsigned char uch = 'r';
  short j = 'b', k = 98;

  printf("%c == %d\n", ch, ch);
  printf("%c == %d\n", uch, uch);
  printf("%c == %c\n", j, k);

  return 0;
}

```
# Task 4
```C
#include <stdio.h>
#include <math.h>

int main(){
  double x = 0.5;
  double result = sqrt(x);
  printf("The sqare root of %lf is %lf\n", x, result);
  return 0;
}

```

# Автор конспекта: Murcklack 🧪

**TG**: [@murcklack](https://t.me/murcklack)
**Сайт**: [murcklack.sos.al](https://murcklack.sos.al)