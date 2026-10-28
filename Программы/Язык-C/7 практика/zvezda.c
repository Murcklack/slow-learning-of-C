#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* czar_right(char text[100], int sdvig)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            int shift = text[i] + sdvig;
            if (shift > 90)
            {
                shift = shift % 90 + 64;
            }
            text[i] = shift;
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            int shift = text[i] + sdvig;
            if (shift > 122)
            {
                shift = shift % 122 + 96;
            }
            text[i] = shift;
        }
    }
    return text;
}

char* czar_left(char text[100], int sdvig)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            int shift = text[i] - sdvig;
            if (shift < 65)
            {
                shift = 91 - (65 - shift);
            }
            text[i] = shift;
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            int shift = text[i] - sdvig;
            if (shift < 97)
            {
                shift = 123 - (97 - shift);
            }
            text[i] = shift;
        }
    }
    return text;
}
int vzlom_jopi(char text[100])
{
    int best_shift = 0;
    int max_e_t_count = -1;
    char best_text[100];

    for (int s = 0; s < 26; s++)
    {
        char temp[100];
        strcpy(temp, text);
        
        czar_left(temp, s);

        int e_t_count = 0;
        for (int i = 0; temp[i] != '\0'; i++)
        {
            if (temp[i] == 'e' || temp[i] == 'E' || temp[i] == 't' || temp[i] == 'T')
            {
                e_t_count++;
            }
        }

        if (e_t_count >= max_e_t_count)
        {
            max_e_t_count = e_t_count;
            best_shift = s;
            strcpy(best_text, temp);
        }
    }

    strcpy(text, best_text); 
    return best_shift;
}

int main()
{
    char text[100];
    int sdvig;
    int direction = 0; // 0 сдвиг вправо, 1 влево

    printf("Шифровка/расшифровка? (0/1): ");
    scanf("%d", &direction);
    getchar();

    printf("Введи текст: ");
    scanf("%99[^\n]", text);

    printf("Введи сдвиг: ");
    scanf("%d", &sdvig);


    if (sdvig < 0){
        direction = !direction;
        sdvig = abs(sdvig);
    }

    sdvig = sdvig % 26;

    if (direction == 2){
        int found_shift = vzlom_jopi(text);
        printf("Найденный сдвиг: %d\n", found_shift);
        printf("Результат: %s\n", text);
    }
    else if (direction == 0)
    {
        printf("Result: %s\n", czar_right(text, sdvig));
    }
    else
    {
        printf("Result: %s\n", czar_left(text, sdvig));
    }

    printf("\n");
    return 0;
}