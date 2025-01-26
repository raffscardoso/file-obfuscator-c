#include <stdio.h>

int obfuscate(int ch) {
    return ~ch;
}

int main() {
    int ch;
    while( (ch = getchar()) != EOF) {
        putchar(obfuscate(ch));
    }
    return 0;
}