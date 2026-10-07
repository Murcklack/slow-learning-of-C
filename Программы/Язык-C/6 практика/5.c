#include <stdio.h>

int max_min(int price[], int n) {
  int max = price[0];
  int min = price[0];
  int max_day = 1;
  int min_day = 1;
  for (int i = 1; i < n; i++) {
    if (price[i] > max) {
      max = price[i];
      max_day = i + 1;
    }
  }
  for (int i = 1; i < n; i++) {
    if (price[i] < min) {
      min = price[i];
      min_day = i + 1;
    }
  }
  printf("Минимальная прибыль: %dр - %d день\n", min, min_day);
  printf("Максимальная прибыль: %dр - %d день\n", max, max_day);
  return 0;
}

int max_prosad(int price[], int n) {

  int max_cen = 0, cena = 0, max_prosad = 0, max_day = 0, start = 0, end = 0;
  for (int i = 0; i < n; i++) {
    cena = price[i];
    if (cena > max_cen) {
      max_cen = cena;
      max_day = i + 1;
    }
    int prosadka = max_cen - cena;
    if (prosadka > max_prosad) {
      max_prosad = prosadka;
      start = max_day;
      end = i + 1;
    }
  }
  printf("Максимальная просадка: %dр, начало - %d, конец - %d\n", max_prosad,
         start, end);
  return 0;
}

int max_period(int price[], int n) {
  int period = 0, start = 1, end = 0, max_period = 0, max_start = 0,
      max_end = 0;
  for (int i = 0; i < n; i++) {
    if ((price[i] <= price[i + 1]) & (i < n - 1)) {
      period++;
    } else {
      end = i + 1;
      if (period > max_period) {
        max_period = period;
        max_start = start;
        max_end = end;
      }
      period = 0;
      start = i + 1;
    }
  }
  printf("Период роста дни:");
  for (int i = max_start; i <= max_end; i++) {
    printf(" %d", i);
  }
  printf(" => период из %d дней\n", max_period);
  return 0;
}

int main() {
  int price[15] = {100, 102, 105, 103, 98,  96,  99, 104,
                   110, 108, 112, 118, 115, 111, 117};
  int n = sizeof(price) / sizeof(price[0]);
  max_min(price, n);
  max_prosad(price, n);
  max_period(price, n);

  return 0;
}