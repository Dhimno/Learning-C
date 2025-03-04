/* Nama File 	: JumDeret.c */
/* Deskripsi 	: Menghitung dan menampilkan jumlah total deret bilangan ke-N */
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <04-03-2025 dan 08:39> */

#include <stdio.h> /* Header file utama */

/* Program Utama */
int main() {
    /* Kamus */
    int n; 
    int i = 1; 
    int sum = 0; 

/* Algoritma */
    printf("========================================\n");
    printf("Penghitung jumlah total deret ke-N\n");
    printf("========================================\n");
    printf("Masukkan nilai N: ");
    scanf("%d", &n);

    if (n <= 0){0
        printf("Masukan harus diatas 0");
    } else {
        while (i <= n) { 
            sum += i;    
            i++;
        }
    }

    printf("Jumlah total deret ke-%d adalah: %d\n", n, sum);

    return 0;
}

