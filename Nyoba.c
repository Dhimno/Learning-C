#include <stdio.h>

int main() {
    for (size_t i = 1; i <= 5; i += 2) { // i = 1, 3, 5
        for (size_t j = 0; j < i; j++) { // print i stars
            printf("*");
        }
        printf("\n"); // move to next line
    }
    return 0;
}