#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct list { // Создаём список для слов
    char word[20];
    struct list *next;
};


void add_word_to_list(struct list **head, const char *word) { // Функция записи в список новых слов
    struct list *new_node = (struct list *)malloc(sizeof(struct list));
    strncpy(new_node->word, word, 20);  // Копируем слово
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;  // Назначаем новый элемент головой если список пуст
    } else {
        struct list *current = *head;
        while (current->next != NULL) { // Определяем пункт назначения
            current = current->next;
        }
        current->next = new_node;  // Добавляем в конец списка
    }
}


void swap_elements(struct list *a, struct list *b) { // Функция перестановки
    char temp[20];
    strncpy(temp, a->word, 20);
    strncpy(a->word, b->word, 20);
    strncpy(b->word, temp, 20);
}

void sorting(struct list *head) { // Функция сортировки списка слов по алфавиту
    if (head == NULL) return;

    struct list *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (strcmp(j->word, j->next->word) > 0) {
                swap_elements(j, j->next);
            }
        }
    }
}


void print_list(struct list *head) { // Функция для печати результата 
    struct list *current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}


void delete_list(struct list **head) { // Функция очистки памяти
    struct list *current = *head;
    struct list *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}





int main() {
    char input[1000]; // Создаём массивчик
    struct list *word_list = NULL;

    fgets(input, sizeof(input), stdin); // Читаем строку из слов

    char *token = strtok(input, " ."); // Обрабатываем слова
    while (token != NULL) {
        add_word_to_list(&word_list, token);
        token = strtok(NULL, " .");
    }

    sorting(word_list); // Сортируем список

    print_list(word_list); // Печатаем список

    delete_list(&word_list); // Чистим память
    
    return 0;
}