#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void czar_right(char text[100], int sdvig)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 32){
            printf(" ");
            continue;
        }
        else if (text[i] >= 65 && text[i] <= 90)
        {
            text[i] = text[i] + sdvig;
            if (text[i] > 90)
            {
                text[i] = text[i] % 90 + 64;
            }
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            text[i] = text[i] + sdvig;
            if (text[i] > 122)
            {
                text[i] = text[i] % 122 + 96;
            }
        }
        printf("%c", text[i]);
    }
}

void czar_left(char text[100], int sdvig)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 32){
            printf(" ");
            continue;
        }
        else if (text[i] >= 65 && text[i] <= 90)
        {
            text[i] = text[i] - sdvig;
            if (text[i] < 65)
            {
                text[i] = 91 - sdvig;
            }
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            text[i] = text[i] - sdvig;
            if (text[i] < 97)
            {
                text[i] = 123 - sdvig;
            }
        }
        else
        {
            printf("Фигню написал");
            return;
        }
        printf("%c", text[i]);
    }
}

int main()
{
    char text[100];
    int sdvig;
    int direction = 0; // 0 сдвиг вправо, 1 влево

    printf("Введи текст: ");
    scanf("%99[^\n]", text);

    printf("Введи сдвиг: ");
    scanf("%d", &sdvig);

    if (sdvig < 0)
    {
        direction = 1;
        sdvig = abs(sdvig);
    }
    if (sdvig > 26)
    {
        sdvig = ((sdvig % 26) + 26) % 26;
    }

    if (direction == 0)
    {
        czar_right(text, sdvig);
    }
    else
    {
        czar_left(text, sdvig);
    }

    printf("\n");
    return 0;
}