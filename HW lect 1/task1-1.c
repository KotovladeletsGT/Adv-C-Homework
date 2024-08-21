#include <stdio.h>

int main(void) {
    int a, b, num, max, count;
    b = 1;
    max = -1000;
    count = 0;
    scanf("%d", &a);
    
    while (b <= a) {
        scanf("%d", &num);
        if (num > max) {
            max = num;
            count = 1;
        } else if (num == max) {
            count++;
        }
        b++;
    }
    printf("%d \n", count);
    return 0;
}
