from random import randint


def only_letters(s):
    result = ""
    for char in s:
        if char.isalpha():
            result += char
    print(result)


# only_letters('Hello, World! 2026')  # Output: HelloWorld


def elka(N):
    for x in range(N):
        print(" " * (N - x - 1) + "#" * (2 * x + 1))
    print(" " * (N - 1) + "#")


# elka(20)


def Amstrong(N):
    cunt = 0
    for y in range(1, N):
        chisla = []
        for x in range(len(str(y))):
            chisla.append(int(str(y)[x]))
        if y == sum(x ** len(chisla) for x in chisla):
            cunt += 1
    print(cunt)


def Sostavlenie_slova(text, word):
    text = [i for i in text]
    word = [i for i in word]
    print(text, word)

    for x in text.copy():
        if x not in word:
            text.remove(x)
    print(text)

    for a in text.copy():
        if text.count(a) > 1:
            text.remove(a)

    if word == text:
        print("True")
    else:
        print("False")


def guess_number():
    chislo = str(randint(1, 100))
    user = 0
    while user != chislo:
        user = input("Введи число: ")
        if user < chislo:
            print("Больше")
        elif user > chislo:
            print("Меньше")
        else:
            print("Угадал")


def menu():
    def palindom(message):
        True

    while True:
        print("""1  Проверка на палиндром (без учёта регистра и пробелов).
2  Подсчёт гласных (a, e, i, o, u).
3  Проверка «только цифры» (.isdiagit()).
4  Проверка «только буквы» (.isalpha()).
5  Переворот строки ([::-1]).
6  Верхний регистр (.upper()).
7  Нижний регистр (.lower()).
8  Замена пробелов на _.
9  Проверка на email (есть @, после него — .).
10 Извлечение домена (часть после @).
11 Выход""")
    message = input("Сообщение: ")
    choise = input("Выбери действие: ")
