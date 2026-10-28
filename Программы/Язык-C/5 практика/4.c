#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int vse[20];
    srand(time(NULL));
    // 2
    for (int i = 0; i < 20; i+=2)
    {
        vse[i] = (rand() % 65536) - 32768;
        vse[i+1] = (rand() % 65536) - 32768;
        // 3
        printf("s[%d] = %.1f + j*(%.1f)\n", (i+1)/2, (float)vse[i], (float)vse[i+1]);
    }
    // 4

    long long E = 0;
    for (int k = 0; k < 20; k+=2)
    {
        E = E + ((long long)vse[k] * vse[k] + (long long)vse[k+1] * vse[k+1]);
    }
    printf("\nЭнергия сигнала E=%lld\n", E);
    // 5
    int max_re = 0;
    int max_re_i = 0;
    for (int i = 0; i < 20; i+=2)
    {
        if (max_re < vse[i])
        {
            max_re = vse[i];
            max_re_i = i;
        }
    }

    printf("Максимальный элемент: %d, его индекс: %d", max_re, max_re_i);

    return 0;
}