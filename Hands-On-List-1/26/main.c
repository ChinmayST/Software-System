#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("%s One argument only\n", argv[0]);
        return 1;
    }

    printf("Hello, %s!\n", argv[1]);
    return 0;
}

