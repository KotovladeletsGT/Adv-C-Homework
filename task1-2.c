#include <stdio.h>

int main(void) {
    int N;
    char letter, output;
    scanf("%d", &N);
    while(1) {
        scanf("%c", &letter);
        output = letter;
        if (letter == '.') {
            break;
        } else if (letter >= 'a' && letter <= 'z') {
            letter = letter - 'a';
            output = (letter + N) % 26;
            output = output + 'a';
        } else if (letter >= 'A' && letter <= 'Z') {
            letter = letter - 'A';
            output = (letter + N) % 26;
            output = output + 'A';
        } 
        printf("%c", output);
    }
}