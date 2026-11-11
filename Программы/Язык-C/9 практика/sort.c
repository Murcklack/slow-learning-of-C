// Сортировка пузырьком (по возрастанию)
// arr - массив, size - количество элементов
void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        // если за проход не было обменов, массив уже отсортирован
        if (!swapped)
        {
            break;
        }
    }
}
//Не убегай, это я твой коментарий, всё хрошо
//Да ладно тебе, никто ещё не умирал
