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
        m = message.replace(",", "").replace(".", "").replace(" ", "").lower()
        obratka = m[::-1]
        if m == obratka:
            print("Сообщение является палиндромом!")
        else:
            print("Сообщение НЕ является палиндромом!")

    def glas(message):
        glas = ["a", "e", "i", "o", "u"]
        cunt = 0
        for i in glas:
            cunt += message.count(i)
        print(f"В сообщении: {cunt} гласных")

    def proverka(message):
        text = [i for i in message]
        word = ["@", "."]

        for i in text.copy():
            if i == "@":
                break
            else:
                text.remove(i)

        for x in text.copy():
            if x not in word:
                text.remove(x)

        for a in text.copy():
            if text.count(a) > 1:
                text.remove(a)

        if text == word:
            print("email")
        else:
            print("Не email")

    def dmain(message):
        m = [i for i in message]
        for i in m.copy():
            if i == "@":
                m.remove(i)
                break
            else:
                m.remove(i)
        print("".join(m))

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

        match choise:
            case "1":
                palindom(message)
            case "2":
                glas(message)
            case "3":
                if message.isdigit() == 1:
                    print("Да, только из цифр")
                else:
                    print("Неа, встречаются буквы")
            case "4":
                if message.isalpha() == 1:
                    print("Да, только из букв")
                else:
                    print("Неа, цифры есть")
            case "5":
                print(message[::-1])
            case "6":
                print(message.upper)
            case "7":
                print(message.lower)
            case "8":
                print(message.replace(" ", "_"))
            case "9":
                proverka(message)
            case "10":
                dmain(message)
            case "11":
                print("Пака")
                break
            case _:
                print("Неверная цифра")

        vihod = input("Хотите выйти? (Y/N)\n")
        yes = ["yes", "Yes", "y", "Y"]
        if vihod in yes:
            print("Пака")
            break

    return 0


# menu()


def validator():
    def proverka(message):
        text = [i for i in message]
        word = ["@", "."]

        for i in text.copy():
            if i == "@":
                break
            else:
                text.remove(i)

        for x in text.copy():
            if x not in word:
                text.remove(x)

        for a in text.copy():
            if text.count(a) > 1:
                text.remove(a)

        if text != word:
            email_check.append("Не содержит . после @")

    email = input("Введи email: ")
    passwd = input("Введи пароль: ")

    email_check = []
    passwd_check = []
    zapret = ["@", "."]
    spec = ["!", "@", "#", "$", "%", "^", "&", "*"]

    # Email
    if email.count("@") > 1 or email.count("@") == 0:
        email_check.append("В вашем email @ больше 1 или его вообще нет")

    proverka(email)

    if email[0] in zapret or email[-1] in zapret:
        email_check.append("Брух... @ или . в начале или конце")

    if len(email) > 30 or len(email) < 6:
        email_check.append("Меньше 6 или больше 30 символов")

    # passwd
    has_digit = any(i.isdigit() for i in passwd)
    has_capital = any(i.isupper() for i in passwd)
    has_lower = any(i.islower() for i in passwd)

    if len(passwd) < 8:
        passwd_check.append("Короткий")

    if has_digit == False:
        passwd_check.append("Нет цифр")

    if has_capital == False:
        passwd_check.append("Нет заглавных")

    if has_lower == False:
        passwd_check.append("Нет строчных")

    for i in passwd:
        if i in spec:
            spec = 1
            break
    if spec != 1:
        passwd_check.append("Нет спецсимволов")

    # Вывод
    if email_check == []:
        print(f"\n\nEmail: {email} -> OK")
    else:
        print(f"\n\nEmail: {email} ->")
        for x in email_check:
            print(f"x {x}")

    if passwd_check == []:
        print(f"Пароль: {passwd} -> OK")
    else:
        print(f"Пароль: {passwd} ->")
        for x in passwd_check:
            print(f"x {x}")


#validator()


def Haiku():
    line1 = input("Первая строка: ").lower()
    line2 = input("Вторая строка: ").lower()  
    line3 = input("Третья строка: ").lower()
    glas = ["а", "е", "ё", "и", "у", "о", "у", "ы", "э", "ю", "я"]
    lines = [line1, line2, line3]
    cunt1 = 0
    cunt2 = 0
    cunt3 = 0
    
    
    for i in range(len(lines)):
        if lines[i] == "":
            print(f"Не хайку. Должно быть 3 строки. Добавь текст в строку {i+1}")
            return 0
    
    for x in line1:
        if x in glas:
            cunt1+=1
    for x in line2:
        if x in glas:
            cunt2+=1
    for x in line3:
        if x in glas:
            cunt3+=1
    print(cunt1,cunt2,cunt3)
    if cunt1 == 5 and cunt2 == 7 and cunt3 == 5:
        print("Хайку!")
    else:
        print("Не хайку :(")
    
def sandwitch(x):
    ## Шифровка
    def shifr(a):
        index = []
        slovo = ""
        for i in range(len(a)):
            if i % 2 != 0:
                index.append(i)
        if len(a) % 2 != 0:
                index.append(len(a)) 
        for i in range(len(a),0,-1):
            if i % 2 == 0:
                index.append(i)
        for b in index:
            slovo += x[b-1]
        print(slovo)
        
    x = [i for i in x]
    if x[-1] != "#":
        print("Где #?")
    else:
        x.pop(-1)
        shifr(x)


def variables(name):
    if name.count("_") > 0:
        name = name.split("_")
        result = f'{name[0]}'
        for x in range(1,len(name)):
            result += name[x].capitalize()
        print(result)
        return 0
    if any(i.isupper() for i in name) == True:
        for i in range(len(name)):
            if name[i].isupper() == True:
                name = name[:i] + f"_{name[i].lower()}" + name[i+1:]
                i += 1
        print(name)
        return 0
    else:
        print(name)
print("Беееее")