#include <stdio.h>
int main(void)
{    
    int dollars;
    double rubles, kurs;
    scanf("%d %lf", &dollars, &kurs);
    rubles = rubles * kurs;
    printf("%.13lf\n", rubles);

    return 0;
}
