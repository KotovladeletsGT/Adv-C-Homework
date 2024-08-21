#include <stdio.h>

int zero_counter(int number) { //Функция умножает число на маску и проверяет ноль ли в конце
    int zero_count = 0;
    while (number > 0) {
        if ((number & 1) == 0) { 
            zero_count++;
        }
        number = number >> 1;
    }
    return zero_count;
}

int main(void) {
    int N, K, i, answ;
    i = 1;
    answ = 0;
    scanf("%d%d", &N, &K);
    while (i <= N) { //Если расчётное число нулей соотвествует требуемому - увеличиваем счётчик
        if (zero_counter(i) == K) {
            answ++;
        }
        i++;
    }
    printf("%d", answ);
    printf("\n");
    return 0;
}