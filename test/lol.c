#include <stdio.h>

int add_sub(int a, int b, int c)
{
    int result;
    __asm__(
        "movl %2, %%eax;"        // a -> eax
        "addl %1, %%eax;"        // eax += b
        "subl %3, %%eax;"        // eax -= c
        : "=a"(result)           // выход: результат в eax
        : "b"(b), "c"(a), "d"(c) // входные в регистры
        : "cc"                   // изменяем флаги
    );
    return result;
}

int main(void)
{
    /* a, b, c, ожидаемый результат */
    int tests[][4] = {
        {1, 2, 3, 0},
        {10, 20, 5, 25},
        {0, 0, 0, 0},
        {-5, 3, 2, -4},
        {100, -50, -25, 75},
        {2147483647, 1, 1, 2147483647},
    };
    int n = (int)(sizeof(tests) / sizeof(tests[0]));
    int i;

    for (i = 0; i < n; i++)
    {
        int got = add_sub(tests[i][0], tests[i][1], tests[i][2]);
        int expected = tests[i][3];

        printf("add_sub(%d, %d, %d) = %d\t[ожидалось %d] %s\n",
               tests[i][0], tests[i][1], tests[i][2], got, expected,
               got == expected ? "OK" : "FAIL");
    }

    return 0;
}
