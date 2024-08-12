#include <stdio.h>

int main(void) {
    unsigned int N, K, onemass, max_num, tmp;
    scanf("%u%u", &N, &K);
    for(int i = 0; i < K; i++) {
            onemass = onemass << 1;
            onemass = onemass | 1;
        }
        max_num = N & onemass;
        while (N > 0) {
            N = N >> 1;
            tmp = N & onemass;
            if (tmp > max_num) {
                max_num = tmp;
            }
        }
        
    printf("%u \n", max_num);
    return 0;
}



