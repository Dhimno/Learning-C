/* Nama File 	: CekBilPrima.c */
/* Deskripsi 	: Mengecek apakah suatu bilangan adalah bilangan prima*/
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <04-03-2025 dan 08:39> */

#include <stdio.h> /* Header file utama */

/* Program Utama */
int main() {
    /* Kamus */
    int n;
    int i;
    int counter;

    /* Algoritma */
    i = 1;
    counter = 0;
    printf("========================================\n");
    printf("Pengecek bilangan prima\n");
    printf("========================================\n");
    printf("Masukkan nilai N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Masukan harus di atas 0\n");
    } else {
        while (i <= n) {
            if (n % i == 0) {
                counter++;
            }
            i++;
        }

        if (counter == 2) {
            printf("%d adalah bilangan prima\n", n);
        } else {
            printf("%d bukan merupakan bilangan prima\n", n);
        }
    }

    return 0;
}
