#include <stdio.h>

int main(void) {
    unsigned int N, K, tmp, output;

    scanf("%u%u", &N, &K);
    for(int i = 0; i < K; i++) {
        tmp = N & 1;
        tmp <<= 31;
        N >>= 1;
        N = N | tmp;
        output = N;
    }
    
    printf("%u \n", output);
    return 0;
}
