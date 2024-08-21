#include <stdio.h>
#include <stdint.h>

uint32_t my_func(uint32_t number){
    uint32_t ret;
    ret = number + 1;
    return ret;
 
}

int main(void){
    uint32_t N;
    scanf("%u", &N);
    printf("%u", my_func(N));
    return 0;
}