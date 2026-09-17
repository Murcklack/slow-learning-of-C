from string import printable

def task1():
    name = "М" 
    fam = "К"
    otch = "Д"
    print(name,"-", ord(name), fam, "-", ord(fam), otch, "-", ord(otch))

def task2():
    slovo = "Информатика"
    utf8 = slovo.encode("utf-8")
    cp = slovo.encode("cp1251")
    print(utf8, "- информатика utf")
    print(cp, "- информатика cp")
    print("Из-за того, что русские буквы кодируются 2 битами в utf")

def task3():
    user = input("Введи строку: ")
    print(f"Число символов: {len(user)}")
    print(f"Число битов для хранения строки UTF-8: {len(user.encode("utf-8"))}")
    print(f"Число битов для хранения строки CP1251: {len(user.encode("cp1251"))}")

def task4():
    a = b'\xd0\x9a\xd0\xbe\xd0\xb4\xd0\xb8\xd1\x80\xd0\xbe\xd0\xb2\xd0\xba\xd0\xb8'
    b = b'\xd1\x88\xd0\xbf\xd0\xb0\xd1\x80\xd0\xb3\xd0\xb0\xd0\xbb\xd0\xba\xd0\xb0'
    c = b'\xca\xee\xe4\xe8\xf0\xee\xe2\xea\xe8'
    print(a.decode("utf-8"), b.decode("utf-8"), "- UTF-8","\n" + c.decode("cp1251"), "- CP1251")

def task5():
    japan = "ル"
    arab = "م"
    germany = "ü" 
    emoji = "🍨" 
    print(japan,ord(japan),len(japan.encode("utf-8")))
    print(arab,ord(arab),len(arab.encode("utf-8")))
    print(germany,ord(germany),len(germany.encode("utf-8")))
    print(emoji,ord(emoji),len(emoji.encode("utf-8")))

def task6():
    sms = 'Я чувствую притяжение тьмы. Во мне всегда жило что-то тёмное.'.encode("utf8")
    broken_txt = sms.decode("cp1251")
    restored = broken_txt.encode("cp1251").decode("UTF-8")
    
    print(restored)

def task7():
    size = int(input("Введи размер(GB): "))
    speed = int(input("Введи скорость интернета(Мбит/с): "))
    time = int(input("Введи время (Минуты): "))

    down_time = size*1024*8//speed
    print("\nТвои данные:")
    print(f"Время скачивания: {down_time//60}:{down_time%60}")
    print(f"Общее время: {time+down_time//60}:{down_time%60}")

def task8():
    tovari = int(input("Общее кол-во товаров: "))
    storage = int(input("Вместимость 1 контейнера: "))
    efficency = round(100 - (tovari%storage * 100 / tovari),2)

    print("\nРезультат")
    print(f"Полных: {tovari//storage}")
    print(f"Остаток: {tovari%storage}")
    print(f"Эффективность: {efficency}%")

def task9():
    user_num = input("Введи номер машины: ")
    if len(user_num) == 7 and user_num[0:4].isdigit and user_num[4:7].isalpha:
        print("У вас новый формат!")
    elif len(user_num) == 6 and user_num[0:3].isalpha and user_num[3:6].isdigit:
        print("У вас старый формат!")
    else:
        print("Ты фигню написал, перепроверь :/")

task9()