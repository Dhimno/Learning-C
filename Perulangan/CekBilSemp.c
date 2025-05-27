/* Nama File 	: CekBilSemp.c */
/* Deskripsi 	: Mengecek apakah suatu bilangan merupakan bilangan sempurna*/
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <04-03-2025 dan 08:39> */

#include <stdio.h> /* Header file utama */

/* Program Utama */
int main() {
    /* Kamus */
    int n;
    int i;
    int sum; 

    /* Algoritma */
    i = 1;
    sum = 0;
    printf("========================================\n");
    printf("Pengecek Bilangan Sempurna\n");
    printf("========================================\n");
    printf("Masukkan nilai N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Masukan harus lebih dari 0\n");
    } else {
        while (i < n) {
            if (n % i == 0) {
                sum += i;
            }
            i++;
        }
        printf("\n");

        if (sum == n) {
            printf("%d adalah Bilangan Sempurna\n", n);
        } else {
            printf("%d Bukan Bilangan Sempurna\n", n);
        }
    }

    return 0;
}
