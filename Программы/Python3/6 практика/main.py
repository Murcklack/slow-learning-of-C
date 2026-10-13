from random import randint


def lottery():
    nums = []
    for i in range(6):
        nums += [str(randint(1, 49))]
    print(" ".join(nums))


def dynamic(nums):
    numbers = nums.split(" ")
    maxes = []
    for i in range(len(numbers)):
        if numbers[i - 1] < numbers[i] and i != 0:
            maxes += [numbers[i]]
    print(" ".join(maxes))


# dynamic("1 5 2 4 3")


def Andrey(x, heights):
    if len(heights) > 100:
        print("Беее <=100")
        return 0
    Andrey = x
    heights = heights.split(" ")
    stroi = 0
    for i in range(len(heights)):
        if Andrey > int(heights[i]):
            stroi = i
            print(i + 1)
            return 0
    print(len(heights) + 1)


# Andrey(176, "215 210 207")


def coin():
    orel = 0
    reshka = 0
    count = 0
    userfriendly = []
    while orel < 3 and reshka < 3:
        res = randint(1, 2)
        if res == 1:
            orel += 1
            userfriendly += ["O"]
        else:
            reshka += 1
            userfriendly += ["P"]
        count += 1
        print(" ".join(userfriendly) + f" (Попыток : {count})")


def masterklad(map):
    zoloto = []
    for i in range(len(map)):
        if (i != len(map) and i != len(map) - 1) and (
            map[i] > map[i + 1] and map[i] > map[i - 1]
        ):
            zoloto += [map[i]]
    print(zoloto)
    if zoloto != []:
        map.remove(max(zoloto))
    print(map)


# depths = [1,3,2,5,4,6,1]
# masterklad(depths)


def luna(card):
    sum_chet = 0
    sum_nechet = 0
    digits = [int(d) for d in card]
    for i in range(len(digits)):
        if i + 1 % 2 == 0:
            sum_chet += digits[i]
        else:
            proiz = digits[i] * 2
            if proiz > 9:
                proiz -= 9
            sum_nechet += proiz
    if (sum_chet + sum_nechet) % 10 == 0:
        print("Корректный номер")
    else:
        print("Некорректный номер")


# luna("4276440013361511")


def abbr(n, words):
    word = words.split(" ")
    if n > 100 or n < 1 or len(word) != n:
        print("n > 100 or n < 1 or len(word) != n")
        return 0
    if len(words) > 100 or len(words) < 1:
        print("words > 100 or < 1")
        return 0
    for w in word:
        if len(w) > 10:
            print(f"{w[0]}{len(w) - 2}{w[len(w) - 1]}")
        else:
            print(w)


# abbr(3, "word localization internationalization")


def obshaga(n, doors):
    svo = 0
    if len(doors) != n:
        print("Задано неверное кол-во комнат")
        return 0
    for i in doors:
        komnata = i.split(" ")
        if int(komnata[1]) - int(komnata[0]) >= 2:
            svo += 1
    print(f"Ответ: {svo}")


# obshaga(3, ["1 10", "0 10", "10 10"])


def cycle_sdvg(n, k, a):
    symb = []
    if (n < 1 or n > 1000) or (k < 0 or k > 10**9) or n != len(a):
        print("Братан, ограничения")
        return 0
    if k > n:
        k %= n
    for cun, i in enumerate(range(-1, -(k + 1), -1)):
        symb += a[i + cun]
        a.pop(i + cun)

    print(" ".join(symb[::-1]) + " " + " ".join(a))


# cycle_sdvg(5,12,["1","2","3","4","5"])


def circle_vibe(n, k):
    ludi = list(range(1, n + 1))
    vibe = []

    idx = 0

    while len(ludi) > 1:
        idx = (idx + k - 1) % len(ludi)

        vibe.append(str(ludi[idx]))
        ludi.pop(idx)

    print(f"Выбывание: {" ".join(vibe)} Победитель: {ludi[0]}")
    return vibe, ludi[0]


# circle_vibe(7, 3)

def dirty_data(grades):
    bukvi = ["отл", "хор", "уд", "неуд"]
    chisla = ["5", "4", "3", "2"]
    cleaned = []
    for i in grades:
        if str(i) in chisla:
            cleaned.append(int(i))
        elif str(i) in bukvi:
            match i:
                case "отл": cleaned.append(5)
                case "хор": cleaned.append(4)
                case "уд": cleaned.append(3)
                case "неуд": cleaned.append(2)
    print(cleaned)

# dirty_data(["5", "неявка", "4", "хор", "", "148", "неуд"])

def robot(n,commands):
    commands = commands.lower().split(" ")
    if len(commands) != n or n<1 or n > 1000:
        print("Проверь n!")
        return 0
    y = 0
    x = 0
    for i in commands:
        match i:
            case "u": y+=1
            case "d": y-=1
            case "l": x-=1
            case "r": x+=1
            case _:
                print("Чет какой то кринж в множестве, исправляй!")
                return 0
    print(f"{x} {y} / {abs(x)+abs(y)}")
          
# robot(8,"U D L R U D L R")
print("\n\n Я 200")