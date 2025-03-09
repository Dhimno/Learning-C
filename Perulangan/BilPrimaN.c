/* Nama File 	: BilPrimaN.c */
/* Deskripsi 	: Menampilkan semua bilangan prima sampai bilangan ke N tanpa fungsi terpisah */
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <04-03-2025 dan 08:39> */

#include <stdio.h> /* Header file utama */

/* Program Utama */
int main() {
    /* Kamus */
    int N, i, j, counter;

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
        i = 2;
        while (i <= N) {
            counter = 0;
            j = 1;
            while (j <= i) {
                if (i % j == 0) {
                    counter++;
                }
                j++;
            }
            if (counter == 2) {
                printf("%d ", i);
            }
            i++;
        }
        printf("\n");
    }

    return 0;
}
