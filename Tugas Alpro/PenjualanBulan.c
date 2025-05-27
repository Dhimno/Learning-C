/* Nama File     : PenjualanBulan.c */
/* Deskripsi     : Menampilkan penjualan dari semua kota pada bulan tertentu */
/* Dibuat oleh   : Dhimas Reza Nafi Wahyudi - 24060124120010*/
/* Tgl Pembuatan : 14 April 2025 */

#include <stdio.h> /* header file */

/* Program Utama */
int main() {
    /* Kamus */
    int data[3][4] = { /* Membuat tabel 3x4 dengan data yang ditentukan */
        {10, 20, 15, 15},
        {7, 10, 8, 3},
        {10, 10, 12, 8},
    };

    int bulanInput, /* Inputan bulan (1-4) */
    i; /* Iterasi */

    /* Algoritma */
    printf("Masukkan nomor bulan (1-4): ");
    scanf("%d", &bulanInput); /* Menerima input */

    if (bulanInput >= 1 && bulanInput <= 4) { /* Jika bulanInput lebih dari sama dengan 1 dan bulanInput kurang dari sama dengan 4 */
        for (int i = 0; i < 3; i++) {
            if (i == 0) { /* Jika i = 0 */
                printf("Jakarta: %d\n", data[i][bulanInput - 1]);
            } else if (i == 1) { /* Jika i = 1 */
                printf("Semarang: %d\n", data[i][bulanInput - 1]);
            } else if (i == 2) { /* Jika i = 2 */
                printf("Pati: %d\n", data[i][bulanInput - 1]);
            }
        }
    } else { /* Jika input salah */
        printf("Input bulan tidak valid\n");
    }

    return 0;
}
