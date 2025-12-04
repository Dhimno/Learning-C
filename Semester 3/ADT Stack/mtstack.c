/* Program   : mtstack.c */
/* Deskripsi : driver ADT stack karakter */
/* NIM/Nama  : Dhimas Reza Nafi Wahyudi/24060124120010 */
/* Tanggal   : Kamis, 25 September 2025 */
/***********************************/

#include <stdio.h>
#include "tstack.c"

int main() {
    /* kamus */
    Tstack A;
    char X;
    int N;
    char kata[20];

    /* algoritma */
    printf("===========================================\n");
    printf("           Test createStack \n");
    printf("===========================================\n");
    createStack(&A);
    printStack(A);
    printf("Top = %d\n", top(A));

    printf("===========================================\n");
    printf("      Test isEmptyStack dan isFullStack \n");
    printf("===========================================\n");
    if(isEmptyStack(A)) {
        printf("Stack masih kosong.\n");
    }
    if(!isFullStack(A)) {
        printf("Stack belum penuh.\n");
    }

    printf("===========================================\n");
    printf("               Test push \n");
    printf("===========================================\n");
    push(&A, 'A');
    push(&A, 'B');
    push(&A, 'C');
    viewStack(A);
    printf("Top sekarang: %d\n", top(A));
    printf("Infotop: %c\n", infotop(A));

    printf("===========================================\n");
    printf("               Test pop \n");
    printf("===========================================\n");
    pop(&A, &X);
    printf("Elemen yang di-pop: %c\n", X);
    viewStack(A);
    printf("Top sekarang: %d\n", top(A));

    printf("===========================================\n");
    printf("               Test pushN \n");
    printf("===========================================\n");
    printf("Masukkan berapa banyak data yang ingin dimasukkan: ");
    scanf("%d", &N);
    pushN(&A, N);
    viewStack(A);
    printf("Top sekarang: %d\n", top(A));

    printf("===========================================\n");
    printf("             Test printStack \n");
    printf("===========================================\n");
    printStack(A);

    printf("===========================================\n");
    printf("             Test isPalindrom \n");
    printf("===========================================\n");
    printf("Masukkan sebuah kata (max 30): ");
    scanf("%s", kata);
    if(isPalindrom(kata)) {
        printf("'%s' adalah palindrom.\n", kata);
    } else {
        printf("'%s' bukan palindrom.\n", kata);
    }

    return 0;
}
