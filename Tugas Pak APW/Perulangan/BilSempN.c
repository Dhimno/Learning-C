/* Nama File 	: BilSempN.c */
/* Deskripsi 	: Menampilkan semua bilangan sempurna sampai bilangan ke N*/
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <04-03-2025 dan 08:39> */

#include <stdio.h> /* Header file utama */

/* Program Utama */
int main() {
    /* Kamus */
    int N, i, j, sum;
    
    /* Algoritma */
    printf("========================================\n");
    printf("Mencetak Bilangan Sempurna hingga N\n");
    printf("========================================\n");
    printf("Masukkan nilai N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Masukan harus lebih dari 0\n");
    } else {
        i = 2;
        printf("Bilangan Sempurna hingga %d adalah: ", N);
        while (i <= N) {
            sum = 0;
            j = 1;
            while (j < i) {
                if (i % j == 0) {
                    sum += j;
                }
                j++;
            }
            if (sum == i) {
                printf("%d ", i);
            }
            i++;
        }
        printf("\n");
    }
    
    return 0;
}
