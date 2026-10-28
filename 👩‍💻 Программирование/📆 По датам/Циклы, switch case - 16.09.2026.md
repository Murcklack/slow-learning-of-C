# switch .. case
```C
switch (a){
case 'a':
	// ...
	break;
case 'b':
	// ...
	break;
case 'c':
	// ...
	break;
case 'd':
	// ...
	break;
default:
	// ...
}
```
Если не поставить `break`, то после выполнения команды вы провалитесь в нижестоящий case
# Branch prediction
Предсказатель переходов
- **Статическое предсказание**
		Выбираем одну из веток и только она откладывается в кэш
- **Динамическое предсказание**
		Набираем статистику тех кто чаще выполняется и кладём их в кэш

>[!warning]
>Больше 3-4 условий не используем иначе код будет нечитабельным и вообще неэффективным

---
# Шаги компиляции
1. Обработка прерроцессором
		`gcc -E hello.c -o hello.i`
2. Трансляция программы из языка **C** в **Assembler**
		`gcc -S hello.i -o hello.s`
3. Трансляция из **Assembler** в объектный модуль
		`gcc -c hello.s -o hello.o`
4. Объектный модуль в исполняемую программу
		`gcc hello.o -o hello`

---
# Циклы
## While

```c
#include <stdio.h>
int main(void){
int i = 0;
while (i < 3) {
    printf("meow\n");
    i++;
}
return 0;
}
```
`Ctrl + C` - Если ты попал в бесконечный цикл (Стопает программу)

## For
```c
for (s1;s2;s3) {
}
```
- **s1** - блок инициализации
- **s2** - логическое выражение
- **s3** - шаг цикла
### Пример вывести числа от 0 до 4
```c
#include <stdio.h>
int main(void){
for (int i = 0; i < 5; i ++) {
    printf("%d\n",i);
}
return 0;
}
```
## Break
`break` - позволяет досрочно выйти из цикла
**Пример:**
```c
#include <stdio.h>
int main(void){
int i = 0;
while (i < 10)
{
    i++;
    if (i == 6){
        break;
    }
}
printf("%d\n",i);
return 0;
}
```
В выводе увидим 6
## Continue
`continue` - позволяет перейти на следующую итерацию цикла
```C
#include <stdio.h>
int main(void){
int i = 0;
while (i < 10)
{
    i++;
    if (i == 4){
        continue;
    }
    printf("%d\n",i);
}
return 0;
}
```
В выводе мы не увидим 4
## Вложенные циклы
```c
#include <stdio.h>
int main(void){
for(int i = 1;i <= 3; i++){
    for (int j = 1; j<=3; j++){
        printf("%d", i * j);
    }
    printf("\n");
}
return 0;
}
```
**Вывод:**
```
123
246
369
```
---
# Автор конспекта: Murcklack 🧪

**TG**: [@murcklack](https://t.me/murcklack)
**Сайт**: [murcklack.sos.al](https://murcklack.sos.al)