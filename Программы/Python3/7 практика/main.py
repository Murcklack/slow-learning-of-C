from random import randint, shuffle


def method(N):
    def func(x):
        return x**2 / 10 + 1

    a, b = -2, 5
    h = (b - a) / N

    values = []
    for i in range(N):
        x_i = a + i * h
        values.append(func(x_i))

    S = 0
    for v in values:
        S += v * h

    print(f"S = {S:.2f}")


# for i in [10, 100,1000,10000, 100000]: method(i)


def method_trap(N):
    def func(x):
        return x**2 / 10 + 1

    a, b = -2, 5
    h = (b - a) / N
    S = (func(a) + func(b)) / 2

    for i in range(1, N - 1):
        x_i = a + i * h
        S += func(x_i)

    S *= h

    print(f"S = {S:.2f}")


# for i in [10, 100,1000,10000, 100000]: method_trap(i)


def magichial_square(n):
    matrix = [[0] * n for _ in range(n)]
    r = 0  # строка
    c = n // 2  # колонка

    for i in range(1, n * n + 1):
        matrix[r][c] = i
        next_r = (r - 1) % n
        next_c = (c + 1) % n
        if matrix[next_r][next_c] == 0:
            r = next_r
            c = next_c
        else:
            r = (r + 1) % n
    for x in matrix:
        print(x)

    random_mirror = randint(0, 1)
    random_invert = randint(0, 1)

    if random_mirror == 1:
        for i in range(n):
            matrix[i] = matrix[i][::-1]
        print("Применил отражение")
        for x in matrix:
            print(x)

    if random_invert == 1:
        for a in range(n):
            for b in range(n):
                x = matrix[a][b]
                matrix[a][b] = (n * n + 1) - x
        print("Применил инверт")
        for x in matrix:
            print(x)

    magic_const = n * (n * n + 1) / 2
    print(f"magic const = {magic_const}")
    for b in range(n):
        if sum(matrix[b]) != magic_const:
            print("Проверка проваленна в строках")
            return 1
        suma = 0
        for a in range(n):
            suma += matrix[a][b]
        if suma != magic_const:
            print("Проверка провалена в столбцах")
            return 1

    glava = 0
    pobochka = 0
    for i in range(n):
        glava += matrix[i][i]
        pobochka += matrix[i][n - 1 - i]

    if glava != magic_const or pobochka != magic_const:
        print("Проверка провалена: ошибка в диагоналях")
        return 1

    print("ДЖАЙРО СМОТРИ!! ЭТО МАГИЧЕСКИЙ")
    return 0


# magichial_square(7)


def ya_karta(n, coord, alex):
    best = 1000
    best_coords = []
    for i in coord:
        distance = ((i[0] - alex[0]) ** 2 + (i[1] - alex[1]) ** 2) ** 0.5
        if best > distance:
            best = round(distance, 2)
            best_coords = i
    print(best, best_coords)


# ya_karta(4, [[1,2], [3,5], [5,6], [7,8]], [2,3])


def filterok(nums):
    chet = list(filter(lambda x: x % 2 == 0, nums))
    polog = list(filter(lambda x: x > 0, nums))
    special = list(filter(lambda x: x % 2 == 0 and x > 5, nums))

    print(f"Chet: {chet}")
    print(f">0: {polog}")
    print(f"spec: {special}")


nums = [12, -5, 0, 7, 18, -3, 9, 24, 6, 15]
# filterok(nums)


def vishi_sort(words, students, nums):
    dlina = sorted(words, key=lambda x: len(x))
    vozrast = sorted(students, key=lambda x: x[1], reverse=True)
    chisla = sorted(nums, key=lambda x: x % 10)

    print(dlina)
    print(vozrast)
    print(chisla)


words = ["яблоко", "кот", "программирование", "дом", "молоко"]
students = [("Аня", 20), ("Борис", 18), ("Вера", 22), ("Глеб", 19)]
nums = [33, 12, 45, 21, 8, 99]
# vishi_sort(words, students, nums)


def filtered_and_sorted(students):
    students = sorted(
        (sorted(filter(lambda x: x[1] > 3, students), key=lambda x: x[0])),
        key=lambda x: x[1],
        reverse=True,
    )
    print(students)


students = [
    ("Аня", 5),
    ("Борис", 3),
    ("Вера", 4),
    ("Глеб", 5),
    ("Дина", 2),
    ("Егор", 4),
    ("Жанна", 5),
    ("Зоя", 3),
]

# filtered_and_sorted(students)


def absolute_cinema(rassadka, k):
    for x in range(len(rassadka)):
        S_V_O = 0
        for i in rassadka[x]:
            if i == 0:
                S_V_O += 1
            else:
                S_V_O = 0
        if S_V_O >= k:
            print(x + 1)
            return 0
    print(0)


rassadka = [
    [0, 1, 0, 1, 0],
    [1, 0, 0, 0, 0],
    [0, 0, 0, 0, 1],
    [1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0],
]
# absolute_cinema(rassadka, 3)


def pravilo(n, m):
    A = [[0] * m for _ in range(n)]
    for r in range(n):
        for c in range(m):
            if r == 0 or c == 0:
                A[r][c] = 1
            else:
                A[r][c] = A[r - 1][c] + A[r][c - 1]

    for r in A:
        print(r)


# pravilo(4,6)


def tokenize(text):
    razdel = [
        " ",
        "\t",
        "\n",
        ",",
        ";",
        ":",
        "!",
        "?",
        "(",
        ")",
        "[",
        "]",
        "{",
        "}",
        '"',
        "«",
        "»",
        "…",
        "—",
        "–",
    ]
    cifry = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]

    tokens = []
    slovo = ""

    for i in range(len(text)):
        char = text[i]
        if char == "." or char == "-" or char == "'":
            if i > 0 and i < len(text) - 1:
                sleva = text[i - 1]
                sprava = text[i + 1]

                if char == ".":
                    if sleva in cifry and sprava in cifry:
                        slovo += char
                    else:
                        if slovo != "":
                            tokens.append(slovo)
                            slovo = ""
                else:
                    if sleva not in razdel and sprava not in razdel:
                        slovo += char
                    else:
                        if slovo != "":
                            tokens.append(slovo)
                            slovo = ""
            else:
                if slovo != "":
                    tokens.append(slovo)
                    slovo = ""

        elif char in razdel:
            if slovo != "":
                tokens.append(slovo)
                slovo = ""

        else:
            slovo += char

    if slovo != "":
        tokens.append(slovo)

    return tokens


# print(tokenize('Кто-то сказал: "I don\'t know!". Pi = 3.14, а 1.5 - это дробь.'))


def okno(massa, n):
    winda = []
    for i in range(len(massa) - n + 1):
        kopilka = []
        for b in range(n):
            kopilka.append(massa[i + b])
        winda.append(kopilka)
    print(winda)


massa = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
# okno(massa, 3)


def Mark_with_down_syndrome(md):
    if md == "":
        return ""

    lines = md.split("\n")
    html_lines = []

    for i in range(len(lines)):
        line = lines[i]

        if line == "":
            html_lines.append("")
            continue

        level = 0
        if line[0] == "#":
            for char in line:
                if char == "#":
                    level += 1
                else:
                    break

        is_header = False
        if 1 <= level <= 6 and len(line) > level and line[level] == " ":
            is_header = True

        while "**" in line:
            pos1 = line.find("**")
            if pos1 != -1:
                line = line[:pos1] + "<b>" + line[pos1 + 2 :]

            pos2 = line.find("**")
            if pos2 != -1:
                line = line[:pos2] + "</b>" + line[pos2 + 2 :]

        while "`" in line:
            pos1 = line.find("`")
            if pos1 != -1:
                line = line[:pos1] + "<code>" + line[pos1 + 1 :]
            pos2 = line.find("`")
            if pos2 != -1:
                line = line[:pos2] + "</code>" + line[pos2 + 1 :]

        if is_header == 1:
            text = line[level + 1 :]
            html_lines.append(f"<h{level}>{text}</h{level}>")
        else:
            html_lines.append(f"<p>{line}</p>")

    result = ""
    for i in range(len(html_lines)):
        result += html_lines[i]
        if i < len(html_lines) - 1:
            result += "\n"

    print(result)


Mark_with_down_syndrome("# Привет")
Mark_with_down_syndrome("### Тема")
Mark_with_down_syndrome("###### Мелкий")
Mark_with_down_syndrome("Это **важно**")
Mark_with_down_syndrome("Код `x`")
Mark_with_down_syndrome("")
