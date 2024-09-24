

#include <stdio.h>
#include <stdlib.h>

typedef struct tree { // Создаём структуру дерева
    int key;
    struct tree *left, *right;
} tree;



void btUpView(tree *root) { // Функция, требуемая по заданию
    int left_mass[100] = {0};
    int left_count = 0;
    int root_key = root->key;
    int right_mass[100] = {0};
    int right_count = 0;
    tree *tmp = root->left;

    while (1) { // Читаем значения слева и записываем в массив left_mass
        if (tmp->left == NULL) { // Условие выхода: если левый указатель нулевой
            left_mass[left_count] = tmp->key; // Кладём в массив [счётчик] значение key
            left_count++;
            break;
        }
        left_mass[left_count] = tmp->key;
        left_count++;
        tmp = tmp->left;
    }

    tmp = root->right; // Теперь обрабатываем правую ветку, принцип тот же

    while (1) {
        if (tmp->right == NULL) {
            right_mass[right_count] = tmp->key;
            right_count++;
            break;
        }
        right_mass[right_count] = tmp->key;
        tmp = tmp->right;
        right_count++;
    }

    for (int i = left_count - 1; i >= 0; i--) { // Печаем левую ветку
        printf("%d ", left_mass[i]);
    }

    printf("%d ", root_key); // Печатаем макушку

    for (int i = 0; i < right_count; i++) { // Печатаем правую ветку
        printf("%d ", right_mass[i]);
    }
}