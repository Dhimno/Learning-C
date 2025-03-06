/* Nama File 	: BilSempN.c */
/* Deskripsi 	: Menampilkan semua bilangan sempurna sampai bilangan ke N*/
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <04-03-2025 dan 08:39> */

#include <stdio.h> /* Header file utama */

int isSempurna(int num) { /* Fungsi pembantu */
    int i = 1; 
    int sum = 0;

    while (i < num) {
        if (num % i == 0) {
            sum += i;
        }
        i++;
    }

    return (sum == num);
}

/* Program Utama */
int main() {
    /* Kamus */
    int N, i = 2;

    /* Algoritma */
    printf("========================================\n");
    printf("Mencetak Bilangan Sempurna hingga N\n");
    printf("========================================\n");
    printf("Masukkan nilai N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Masukan harus lebih dari 0\n");
    } else {
        printf("Bilangan Sempurna hingga %d adalah: ", N);
        while (i <= N) {
            if (isSempurna(i)) {
                printf("%d ", i);
            }
            i++;
        }
        printf("\n");
    }

    return 0;
}
