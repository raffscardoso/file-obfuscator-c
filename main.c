#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int encrypt_decrypt_xor(int ch, int key) {
    return ch ^ key;

}

int key_treatment(const char *argv, int *key) {
    char *endptr;
    errno = 0;  
    long temp_key = strtol(argv, &endptr, 10);


    if (errno != 0 || *endptr != '\0' || temp_key < INT_MIN || temp_key > INT_MAX) {
        fprintf(stderr, "Error: Invalid key! Please enter a valid number.\n");
        return -1; 
    }

    *key = (int)temp_key; 
    return 0; 
}

int main(int argc, char *argv[]) {
     if (argc != 2) {
        printf("Use: %s <key> < file_input.txt > file_output.txt \n", argv[0]);
        return 1;
    }

    int ch,key;   

    if (key_treatment(argv[1], &key) != 0) {
        return 1;  
    }

    while( (ch = getchar()) != EOF) {
        putchar(encrypt_decrypt_xor(ch, key));
    }


    return 0;
}