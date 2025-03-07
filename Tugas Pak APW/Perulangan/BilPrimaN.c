/* Nama File 	: BilPrimaN.c */
/* Deskripsi 	: Menampilkan semua bilangan prima sampai bilangan ke N*/
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <04-03-2025 dan 08:39> */

#include <stdio.h> /* Header file utama */

int isPrima(int num) { /* Fungsi pembantu */
    int i;
    int counter = 0;

    if (num < 2) return 0;

    i = 1;
    while (i <= num) {
        if (num % i == 0) {
            counter++;
        }
        i++;
    }

    return (counter == 2);
}

/* Program Utama */
int main() {
    /* Kamus */
    int N, i = 2;

    /* Algoritma */
    printf("========================================\n");
    printf("Mencetak Bilangan Prima hingga N\n");
    printf("========================================\n");
    printf("Masukkan nilai N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Masukan harus lebih dari 0\n");
    } else {
        printf("Bilangan Primanya adalah: ");
        while (i <= N) {
            if (isPrima(i)) {
                printf("%d ", i);
            }
            i++;
        }
        printf("\n");
    }

    return 0;
}

