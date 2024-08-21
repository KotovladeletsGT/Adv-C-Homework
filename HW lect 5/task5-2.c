#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 104

void prefix(char *line, char *prefix)
{ // В цикле бегаем по строке, записываем префикс
    int count = 0;
    char tmp;
    while (1)
    { // Концом префикса является 0 или _
        tmp = line[count];
        if (tmp == 0 || tmp == '_')
        {
            break;
        }
        count++;
    }
    if (count == 0)
    {
        while (1)
        {
            tmp = line[count];
            if (tmp == 0)
            {
                break;
            }
            prefix[count] = line[count];
            count++;
        }
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            prefix[i] = line[i];
        }
    }
}

void suffix(char *line, char *suffix)
{ // В цикле бегаем по строке, записываем суффикс
    int index = 0;
    int count = 0;
    char tmp;
    while (1)
    {
        tmp = line[count];
        if (tmp == '_')
        {
            index = count;
        }
        if (tmp == 0)
        {
            break;
        }
        count++;
    }
    if (index == 0)
    {
        count = 0;
        while (1)
        {
            tmp = line[count];
            if (tmp == 0)
            {
                break;
            }
            suffix[count] = line[count];
            count++;
        }
    }
    else
    {
        index++;
        count = 0;
        while (1)
        {
            tmp = line[index + count];
            if (tmp == 0)
            {
                break;
            }
            suffix[count] = tmp;
            count++;
        }
    }
}

int comparator(char *prefix, char *suffix)
{
    int ret = 0;
    int pre_len = strlen(prefix);
    int suf_len = strlen(suffix);
    char tmp1[MAX_STRING_SIZE] = {0};
    char tmp2[MAX_STRING_SIZE] = {0};
    int count_hight;

    if (pre_len > suf_len)
    {
        count_hight = suf_len;
    }
    else
    {
        count_hight = pre_len;
    }
    for (int i = 1; i <= count_hight; i++)
    {
        memset(tmp1, 0, MAX_STRING_SIZE);
        memset(tmp2, 0, MAX_STRING_SIZE);

        for (int j = 0; j < i; j++)
        {
            tmp1[j] = prefix[j];
            tmp2[j] = suffix[suf_len - i + j];
        }

        if (strcmp(tmp1, tmp2) == 0)
        {
            ret = i;
        }
    }
    return ret;
}

int main(void)
{

    char line_1[MAX_STRING_SIZE] = {0}; // Инициализируем
    char line_2[MAX_STRING_SIZE] = {0};
    char prefix_1[MAX_STRING_SIZE] = {0};
    char prefix_2[MAX_STRING_SIZE] = {0};
    char suffix_1[MAX_STRING_SIZE] = {0};
    char suffix_2[MAX_STRING_SIZE] = {0};
    int ret_1, ret_2;
    char tmp;
    int count = 0;

    int first_done = 0;
    while (1)
    { // Читаем строки
        scanf("%c", &tmp);
        if (tmp == '\n')
        {
            if (first_done == 1)
            {
                break;
            }
            first_done = 1;
            count = 0;
            continue;
        }
        if (first_done == 0)
        {
            line_1[count] = tmp;
        }
        else
        {
            line_2[count] = tmp;
        }
        count++;
    }

    prefix(line_1, prefix_1);
    prefix(line_2, prefix_2);

    suffix(line_1, suffix_1);
    suffix(line_2, suffix_2);

    // Сравниваем префиксы и суффиксы

    ret_1 = comparator(prefix_1, suffix_2);

    ret_2 = comparator(prefix_2, suffix_1);

    printf("%d %d", ret_1, ret_2);
    return 0;
}

/*
don't_panic
nick_is_a_mastodon
*/
// monty_python
// python_has_list_comprehensions
