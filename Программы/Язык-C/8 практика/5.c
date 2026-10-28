#include <stdio.h>
#include <string.h>

int vivod_raz(char nehvatka[], int n_i, char povtor[], int p_i, char lish[], int l_i)
{
    if (n_i != 0)
    {
        nehvatka[n_i] = '\0';
        printf("В b нехватает: ");
        printf("%s\n", nehvatka);
    }

    if (p_i != 0)
    {
        povtor[p_i] = '\0';
        printf("В b повторяется: ");
        printf("%s\n", povtor);
    }

    if (l_i != 0)
    {
        lish[l_i] = '\0';
        printf("В b лишние: ");
        printf("%s\n", lish);
    }
    if (l_i != 0 || p_i != 0 || n_i != 0){
        return 1;
    }
    return 0;
}

int sravn(char a[], char b[])
{
    char povtor[strlen(a) + 1];
    int p_i = 0;
    char nehvatka[strlen(a) + 1];
    int n_i = 0;
    char lish[strlen(a) + 1];
    int l_i = 0;

    for (unsigned int i = 0; i < strlen(a); i++)
    {
        int count = 0;
        for (unsigned int k = 0; k < strlen(b); k++)
        {
            if (b[k] == a[i])
            {
                count++;
            }
        }
        if (count == 0)
        {
            nehvatka[n_i] = a[i];
            n_i++;
        }
        else if (count > 1)
        {
            povtor[p_i] = a[i];
            p_i++;
        }
    }
    for (unsigned int i = 0; i < strlen(b); i++)
    {
        int count = 0;
        for (unsigned int k = 0; k < strlen(a); k++)
        {
            if (b[i] == a[k])
            {
                count++;
            }
        }
        if (count == 0)
        {
            lish[l_i] = b[i];
            l_i++;
        }
    }
    if (vivod_raz(nehvatka, n_i, povtor, p_i, lish, l_i) != 0){
        return 1;
    }
    return 0;
}

int main()
{
    char a[] = "listen";
    char b[] = "topten";

    if ((int)strlen(a) != (int)strlen(b))
    {
        printf("Братааан... Количество букв в a != b");
        return 0;
    }

    if (sravn(a,b) == 0){
        printf("Анаграммы");
    }
    else{
        printf("\nНе анаграммы\n");
    }

    return 0;
}