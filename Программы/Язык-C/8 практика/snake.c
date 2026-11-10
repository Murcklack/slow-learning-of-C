#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// -------------------------- шаблон для ввода без пауз (Неблокирующий режим)
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

struct termios orig_termios;

void enable_raw_mode()
{
    tcgetattr(STDIN_FILENO, &orig_termios);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);

    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

void disable_raw_mode()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);

    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags & ~O_NONBLOCK);
}
// --------------------------

int spawn_food(int rows, int cols, int length, int *snake)
{
    int new_food_index;
    while (1)
    {
        int rand_x = 1 + rand() % (cols - 2);
        int rand_y = 1 + rand() % (rows - 2);

        new_food_index = rand_y * cols + rand_x;

        bool valid = true;
        for (int i = 0; i < length; i++)
        {
            if (snake[i] == new_food_index)
            {
                valid = false;
                break;
            }
        }
        if (valid == true)
        {
            break;
        }
    }
    return new_food_index;
}

int main()
{
    srand(time(NULL));
    // Pole
    int cols = 0;
    int rows = 0;

    // Snake
    int length = 3;
    int capacity = 10; // текущая вместимость
    int *snake = malloc(capacity * sizeof(int));
    if (snake == NULL)
    {
        printf("Criticall Error");
        return 1;
    }

    // Direction
    int dx = 1, dy = 0; // вектор движения

    // Food
    int food_index;

    // State
    int score = 0;
    bool is_running = true;
    int current_delay = 150000; // Задержка у тебя в МС!!
    int delay_step = 5000;

    // Game Init
    printf("Введи ширину поля (M): ");
    scanf("%d", &cols);
    printf("Введи высоту поля (N): ");
    scanf("%d", &rows);

    snake[0] = (rows / 2) * cols + (cols / 2);
    snake[1] = (rows / 2) * cols + (cols / 2 - 1);
    snake[2] = (rows / 2) * cols + (cols / 2 - 2);

    food_index = spawn_food(rows, cols, length, snake);

    enable_raw_mode();
    // Game looooopa
    while (is_running == true)
    {
        // 1. Вводик
        int ch;
        int last_key = EOF;

        // Крутим цикл, пока в буфере есть хоть какие-то символы
        while ((ch = getchar()) != EOF)
        {
            last_key = ch; // Запоминаем только самое последнее нажатие
        }

        // Если была нажата хоть одна кнопка
        if (last_key != EOF)
        {
            if ((last_key == 'w' || last_key == 'W') && dy != 1)
            {
                dx = 0;
                dy = -1;
            }
            else if ((last_key == 's' || last_key == 'S') && dy != -1)
            {
                dx = 0;
                dy = 1;
            }
            else if ((last_key == 'a' || last_key == 'A') && dx != 1)
            {
                dx = -1;
                dy = 0;
            }
            else if ((last_key == 'd' || last_key == 'D') && dx != -1)
            {
                dx = 1;
                dy = 0;
            }
        }

        // 2. ФИИИИИИИИИИИЗИКА
        int head = snake[0];

        int head_x = head % cols;
        int head_y = head / cols;

        int new_head_x = head_x + dx;
        int new_head_y = head_y + dy;

        if (new_head_x <= 0 || new_head_x >= cols || new_head_y <= 0 || new_head_y >= rows)
        {
            is_running = false;
            break;
        }

        int new_head = new_head_y * cols + new_head_x;

        for (int i = 0; i < length; i++)
        {
            if (new_head == snake[i])
            {
                is_running = false;
                break;
            }
        }

        int old_tail = snake[length - 1];

        for (int i = length - 1; i > 0; i--)
        {
            snake[i] = snake[i - 1];
        }

        if (new_head == food_index)
        {
            score++;
            if (current_delay >= 40000) // 40000 - минимальная задержка
            current_delay -= delay_step;
            length += 1;
            if (length > capacity)
            {
                int *temp = realloc(snake, (capacity + 10) * sizeof(int));
                if (temp == NULL)
                {
                    printf("ААаа, я маслину поймал...");
                    return 1;
                }
                else
                {
                    snake = temp;
                    capacity += 10;
                }
            }
            food_index = spawn_food(rows, cols, length, snake);
            snake[length - 1] = old_tail;
        }
        snake[0] = new_head;

        // 3. Render
        printf("\033[H\033[J");
        for (int b = 0; b < rows; b++)
        {
            for (int a = 0; a < cols; a++)
            {
                if (b == 0 || b == rows - 1)
                {
                    if (a == 0 || a == cols - 1)
                        printf("+");
                    else
                        printf("-");
                }
                else if (a == 0 || a == cols - 1)
                    printf("|");
                else if (b * cols + a == food_index)
                {
                    printf("*");
                }
                else if (b * cols + a == snake[0])
                {
                    printf("#");
                }
                else
                {
                    bool is_snake = false;
                    for (int x = 1; x < length; x++)
                    {
                        if (b * cols + a == snake[x])
                        {
                            is_snake = true;
                        }
                    }
                    if (is_snake)
                    {
                        printf("o");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
        fflush(stdout);

        // 4. ZaVershenie
        usleep(current_delay);
    }
    disable_raw_mode();
    printf("Счёт: %d", score);
    free(snake);
    return 0;
}