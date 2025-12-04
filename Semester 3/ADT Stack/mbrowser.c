/* Program   : mbrowser.c */
/* Deskripsi : simulasi tombol Backward & Forward browser menggunakan ADT Stack */
/* NIM/Nama  : Dhimas Reza Nafi Wahyudi/24060124120010 */
/* Tanggal   : Kamis, 25 September 2025 */
/***********************************/

#include <stdio.h>
#include "tstack.c"

int main() {
    /* kamus */
    Tstack history, forward;
    int kode;
    char url, X;

    /* algoritma */
    createStack(&history);
    createStack(&forward);

    printf("===========================================\n");
    printf("      SIMULASI BROWSER DENGAN STACK \n");
    printf("===========================================\n");
    printf("Kode:\n");
    printf("1: Kunjungi halaman baru\n");
    printf("2: Backward\n");
    printf("3: Forward\n");
    printf("4: Exit\n");

    do {
        printf("===========================================\n");
        printf("           Input kode aksi \n");
        printf("===========================================\n");
        printf("Masukkan kode: ");
        scanf("%d", &kode);

        if(kode == 1) {
            printf("Masukkan halaman (1 karakter): ");
            scanf(" %c", &url);
            push(&history, url);
            createStack(&forward);
            printf(">> Halaman baru dikunjungi: %c\n", url);

        } else if(kode == 2) {
            printf("===========================================\n");
            printf("             Test Backward \n");
            printf("===========================================\n");
            if(!isEmptyStack(history)) {
                pop(&history, &X);
                push(&forward, X);

                if(!isEmptyStack(history)) {
                    printf(">> Backward ke halaman: %c\n", infotop(history));
                } else {
                    printf(">> Tidak ada halaman sebelumnya!\n");
                }
            } else {
                printf(">> History kosong, tidak bisa backward!\n");
            }

        } else if(kode == 3) {
            printf("===========================================\n");
            printf("             Test Forward \n");
            printf("===========================================\n");
            if(!isEmptyStack(forward)) {
                pop(&forward, &X);
                push(&history, X);

                printf(">> Forward ke halaman: %c\n", X);
            } else {
                printf(">> Tidak ada halaman untuk forward!\n");
            }

        } else if(kode == 4) {
            printf("===========================================\n");
            printf("        Keluar dari program \n");
            printf("===========================================\n");
            break;

        } else {
            printf("Kode tidak valid!\n");
        }

        if(kode >= 1 && kode <= 3) {
            printf("-------------------------------------------\n");
            printf("Current page: ");
            if(!isEmptyStack(history)) {
                printf("%c\n", infotop(history));
            } else {
                printf("Kosong\n");
            }

            printf("Stack History : ");
            viewStack(history);

            printf("Stack Forward : ");
            viewStack(forward);
            printf("-------------------------------------------\n");
        }

    } while(kode != 4);

    printf("=== SELESAI SIMULASI BROWSER ===\n");
    return 0;
}
