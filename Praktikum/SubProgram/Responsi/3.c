#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Kamus */
    int A, B, C, D, bulanCounter;

    /* Algoritma */
    scanf("%d %d %d %d", &A, &B, &C, &D);
    bulanCounter = 0;

    while (A > 0 || B > 0 || C > 0 || D > 0) {
        if (A > 0) {
            A -= 3;
            if (A < 0) {
                if (B == 0 && C > 0) {
                    C -= abs(A);
                    if (C < 0) {
                        C = 0;
                    }
                } else if (B == 0 && D > 0) {
                    D -= abs(A);
                    if (D < 0) {
                        D = 0;
                    }
                }
                A = 0;
            }
        } else if (B > 0) {
            B -= 3;
            if (B < 0) {
                if (C > 0) {
                    C -= abs(B);
                    if (C < 0) {
                        C = 0;
                    }
                } else if (D > 0) {
                    D -= abs(B);
                    if (D < 0) {
                        D = 0;
                    }
                }
                B = 0;
            }
        } else if (C > 0) {
            C -= 3;
            if (C < 0) {
                C = 0;
            }
        } else if (D > 0) {
            D -= 3;
            if (D < 0) {
                D = 0;
            }
        }
        bulanCounter++;
    }
    printf("%d", bulanCounter);

    return 0;
}
