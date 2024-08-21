#include <stdio.h>

int main(void) {
    unsigned int N, onemass, tmp;
    onemass = 1;
    int counter;
    counter  = 0;
    scanf("%u", &N);
    for(int i = 0; i < N; i++) {
        tmp = N;
        tmp = tmp & onemass;
        if (tmp > 0) {
            counter++;
        }
        //printf("tmp = %u ", tmp);
        //printf("onemass = %u\n", onemass);
        onemass = onemass * 2;   
        }
    printf("%d\n", counter);
    return 0;
}