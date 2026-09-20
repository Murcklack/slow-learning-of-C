#include <stdio.h>
#include <math.h>

int main(void) {
  long long public_key;
  long long module;
  long long messege;
  long long q;
  long long p;
  long long fi;
  long long d;

  printf("Данные в формате (ключ модуль сообщение): ");
  scanf("%lld %lld %lld", &public_key, &module, &messege);

  for (long long i = 2; i < module; i++) {
            if (module % i == 0) {
                p = i;
                q = module / i;
                break;          
            }
        }

  
  fi = (p-1) * (q-1);
  for (long long i = 1;1; i++){
    if ((i * public_key) % fi == 1){
      d = i;
      break;
    }
  }

  long long symb = 1;

  for (long long i = 0; i < d; i++) {
    symb = (symb * messege) % module;
  }

  // Пример
  // (3^4)%5
  // 1 шаг = (1*3) % 5 == 3
  // 2 шаг = (3*3) % 5 == 4
  // 3 шаг = (4*3) % 5 == 2
  // 4 шаг = (2*3) % 5 == 1
  // Ответ: 1 == 3^4 % 5 == 81 %5
  // Тем самым мы не заставляем возводить число в степень и получать громадную штуку, которую не переварит наш ПК

  printf("Символ: %c", (char)symb);
  return 0;
}
