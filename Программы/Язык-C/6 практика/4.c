#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // 1
    int re[10];
    int im[10];

    srand(time(NULL));
    // 2
    for (int i = 0; i < 10; i++)
    {
        re[i] = (rand() % 65536) - 32768;
        im[i] = (rand() % 65536) - 32768;
        // 3
        printf("s[%d] = %.1f + j*(%.1f)\n", i, (float)re[i], (float)im[i]);
    }
    // 4

    long long E = 0;
    for (int k = 0; k < 10; k++)
    {
        E = E + ((long long)re[k] * re[k] + (long long)im[k] * im[k]);
    }
    printf("\nЭнергия сигнала E=%lld\n", E);
    // 5
    int max_re = 0;
    int max_re_i = 0;
    for (int i = 0; i < 10; i++)
    {
        if (max_re < re[i])
        {
            max_re = re[i];
            max_re_i = i;
        }
    }

    printf("Максимальный элемент: %d, его индекс: %d", max_re, max_re_i);

    return 0;
}