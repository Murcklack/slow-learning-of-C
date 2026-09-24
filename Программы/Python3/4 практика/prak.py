from string import printable 

def Zone(a,b,c,d):
    if c > b:
        print("Пересечения нет")
    else:
        if c == b:
            print(f"Точка {b}, длина 0")
        else:
            print(f"[{c},{b}], длина {b-c}")

def Schedule(start1,end1,start2,end2):
    if (start2 > end1) or (start2 == end1):
        print("NO")    
    else:
        print("YES")    
        
def Park(duration, hour):
    sum = 0
    night = False
    if hour in [22,23,0,1,2,3,4,5,6]:
        night = True
    if duration >= 30 and duration < 120:
        sum += 100
    elif duration >= 120 and duration < 300:
        sum += 250
    elif duration >= 300:
        sum += 500
    else:
        0
    if night == True:
        sum += sum*0.2
    print(int(sum))

def Error_code(code):
    match code:
        case 100: print("Ошибка конфигурации")
        case 101: print("Неизвестный параметр")
        case 102: print("Некорректное значение")
        case 200: print("Соединение установлено")
        case 201: print("Соединение разорвано")
        case 300: print("Ошибка авторизации")
        case 301: print("Доступ запрещён")
        case 400: print("Ошибка оборудования")
        case 500: print("Критическая ошибка")
        case _:   print("Unknown error")

def Tecnologia(distance, speed):
    if distance <= 0.1 and speed <= 100:
        print("WIFI") 
    elif distance <= 10 and speed <= 150:
        print("LTE")
    elif distance <= 2 and speed <= 1000:
        print("5G")
    elif distance <= 1000 and speed <= 200:
        print("SATELLITE")
    else:
        print("Чет какая то фигная")
        
def Ip(a,b,c,d):
    for i in [a,b,c,d]:
        if i <= 250 and i >= 0:
            0 
        else:
            print("INVALID")
            return 0
    ip = f"{a}.{b}.{c}.{d}"
    if ip == "127.0.0.1":
        print("LOOPBACK")
    elif ip == "0.0.0.0":
        print("UNSPECIFIED")
    elif a >= 224 and a <= 239:
        print("MULTICAST")
    elif (a == 10) or (a == 172 and (b >= 16 and b<=31)) or (a == 192 and b == 168):
        print("PRIVATE") 
    else:
        print("PUBLIC")

def Zamok(A,B,C,D):
    istina = f"{A}{B}{C}{D}"
    match istina:
        case "1000": print("OPEN")
        case "0111": print("OPEN")
        case "0011": print("OPEN")
        case "1011": print("CLOSED")
        case "1111": print("CLOSED")
        case "0000": print("CLOSED")
        case _: print("Че за бред бро? :/")

def Slon(letter1, num1, letter2, num2):
    nums = [1,2,3,4,5,6,7,8]
    letters = printable[10:18]
    if num1 in nums and num2 in nums and letter1 in letters and letter2 in letters:
        if abs(num1-ord(letter1)) == abs(num2-ord(letter2)):
            print("YES")
        else:
            print("NO")
    else:
        print("Фигню написал, числа и буквы проверь")

Ip(172,30,30,30)