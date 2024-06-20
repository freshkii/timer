#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

void countdown(int seconds);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: timer <seconds>\n");
        return 1;
    }

    char* input = argv[1];
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            printf("error: argument must be a positive integer\n");
            return 1;
        }
    }

    int seconds = atoi(input);
    if (seconds <= 0) {
        printf("error: argument must be a positive integer greater than 0\n");
        return 1;
    }

    countdown(seconds);
    return 0;
}

void countdown(int seconds) {
    for (int i = 0; i < seconds; i++) {
        printf("\r%i", i);
        fflush(stdout); 
        sleep(1);
    }
    printf("%i\n", seconds);
}

