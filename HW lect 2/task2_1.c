#include <stdio.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

void * findMaxBlock(list *head) { //Бегаем в цикле, ищем макс значение памяти
    list *addr = NULL;
    size_t max_size = 0;
    while (1) {
        if (head != NULL) {
            if (head->size > max_size) {
                max_size = head->size;
                addr = head->address;
            }
            head = head->next;
        }

        else {
            break;
        }
    }
    if (max_size == 0) {
        return NULL;
    } else {
        return addr;
    }
}

// int main(void) {
//     list list1 = {.address = &list1,
//                     .size = 1};
//     list list2 = {.address = &list2,
//                     .size = 6};
//     list list3 = {.address = &list3,
//                     .size = 3};
//     list1.next = &list2;
//     list2.next = &list3;
//     list3.next = NULL;
//     printf("list 1 %p\n", &list1);
//     printf("list 2 %p\n", &list2);
//     printf("list 3 %p\n", &list3);
//     list * point;
//     point = findMaxBlock(&list1);
//     printf("list 4 %p\n", point);
//     return 0;

// }