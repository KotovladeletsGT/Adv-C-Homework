#include <stdio.h>

int scan(char *cup, char *is_number, char *is_dot) { // Читаем символы до точки или пробела, определяем что в cup[0]
    char tmp;
    int count = 0;
    while (1) {
        scanf("%c", &tmp);
        if (tmp == ' ') {
            break;
        }
        if (tmp == '.') {
            *is_dot = 1;
            break;
        }
        cup[count] = tmp;
        count++;
    }

    if (cup[0] >= '0' && cup[0] <= '9') {
        *is_number = 1;
    } else {
        *is_number = 0;
    }

    return count;
}

int is_symbol(char *cup) { // Проверяем что символ в cup[0] является операцией
    int flag = 0;
    const char operations[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; i++) {
        if (operations[i] == cup[0]) {
            flag = 1;
        }
        i++;
    }
}

int calc(int a, int b, char symbol) { // Зная символ, определяем требуемую математическую операцию 
    switch (symbol)
    {
    case '+':
     a = a + b;
        break;
    case '-':
     a = a - b;
    case '*':
     a = a * b;
        break;
    case '/':
     a = a / b;
        break;
    }
    return a;
}

int reverse_polish_writing(char *symbols, int sym_len, int *numbers) { // Считаем по обратной польской записи

    int ret;
    ret = calc(numbers[0], numbers[1], symbols[0]);
    int sym_count = 1;
    int num_count = 2;
    while (1) { // Условие выхода из цикла
        if (sym_len == 1) {
            break;
        }
        ret = calc(ret, numbers[num_count], symbols[sym_count]);
        num_count++;
        sym_count++;
        sym_len--;
    }
    return ret;
}



int digits_to_num(char *cup, int len) { // Преобразуем цифры из cup  в число и возвращаем его
    int ret = 0;
    int count = 0;
    int tmp;
    for (int i = len; i > 0; i--) {
        tmp = (int) (cup[count] - '0');
        for (int j = 1; j < i; j++) {
            tmp = tmp * 10;
        }
        ret = ret + tmp;
        count++;
    }
    return ret;
}


int main(void) {
    char symbols[1000] = {0}; // Массивы под операции и данные
    int sym_count = 0;
    int numbers[1000] = {0};
    int num_count = 0;
    char tmp[100] = {0};
    int tmp_count;
    char is_number; // Флаги
    char is_dot = 0;
    int ret;

    while (1) { // Чтение
        tmp_count = scan(tmp, &is_number, &is_dot);
        if (is_number) {
            numbers[num_count] = digits_to_num(tmp, tmp_count);
            num_count++;
        } else {
            if (is_symbol(tmp)) {
                symbols[sym_count] = tmp[0];
                sym_count++;
            }
        }
        if (is_dot) {
            break;
        }
    }

    ret = reverse_polish_writing(symbols, sym_count, numbers);
    printf("%d\n", ret);
    return 0;
}