from random import randint


def lottery():
    nums = []
    for i in range(6):
        nums += [str(randint(1,49))]
    print(" ".join(nums))

def dynamic(nums):
    numbers = nums.split(" ")
    maxes = []
    for i in range(len(numbers)):
        if numbers[i-1] < numbers[i] and i != 0:
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
            print(i+1)
            return 0   
    print(len(heights) + 1)

# Andrey(176, "215 210 207")

def coin():
    orel = 0
    reshka = 0
    count = 0
    userfriendly = []
    while orel < 3 and reshka < 3:
        res = randint(1,2)
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
        if (i != len(map) and i != len(map)-1) and (map[i] > map[i+1] and map[i] > map[i-1]):               
            zoloto += [map[i]]
    print(zoloto)
    if zoloto != []:
        map.remove(max(zoloto))  
    print(map)   

#depths = [1,3,2,5,4,6,1]
#masterklad(depths)

def luna(card):
    sum_chet = 0
    sum_nechet = 0
    digits = [int(d) for d in card]
    for i in range(len(digits)):
        if i+1 % 2 == 0:
            sum_chet += digits[i]
        else:
            proiz =  digits[i] * 2       
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
            print(f"{w[0]}{len(w)-2}{w[len(w)-1]}")
        else:
            print(w)

# abbr(3, "word localization internationalization")