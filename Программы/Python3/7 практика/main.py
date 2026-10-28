from random import randint, shuffle

def method(N):
    def func(x):
        return x ** 2 / 10 + 1

    # Отрезок и число разбиений
    a, b = -2, 5
    # Шаг сетки
    h = (b - a) / N

    # Вычисляем значения функции в точках сетки
    values = []
    for i in range(N):
        x_i = a + i * h
        values.append(func(x_i))

    # Суммируем площади прямоугольников
    S = 0
    for v in values:
        S += v * h

    print(f"S = {S:.2f}")

#for i in [10, 100,1000,10000, 100000]: method(i)

def method_trap(N):
    def func(x):
        return x ** 2 / 10 + 1

    a, b = -2, 5
    h = (b - a) / N
    S = (func(a) + func(b)) / 2

    for i in range(1, N-1):
        x_i = a + i * h
        S += func(x_i)
        
    S *= h

    print(f"S = {S:.2f}")

# for i in [10, 100,1000,10000, 100000]: method_trap(i)

def magichial_square(n):
    if n % 2 == 0:
        print("Братан введи нечётное")
        return 0
    numbers = []
    matrix_r = []
    matrix_c = []
    
magichial_square(3)