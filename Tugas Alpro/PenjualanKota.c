/* Nama File     : PenjualanKota.c */
/* Deskripsi     : Menampilkan penjualan dari sebuah kota selama 4 bulan */
/* Dibuat oleh   : Dhimas Reza Nafi Wahyudi - 24060124120010*/
/* Tgl Pembuatan : 14 April 2025 */

#include <stdio.h> /* header file */

/* Program Utama */
int main() {
    /* Kamus */
    int penjualan[3][4] = { /* Membuat tabel 3x4 dengan data yang ditentukan */
        {10, 20, 15, 15},
        {7, 10, 8, 3},
        {10, 10, 12, 8},
    };

    int kotaInput, /* Inputan Kota (1-4) */
    i; /* Iterasi */

    /* Algoritma */
    printf("Masukkan nomor kota (1-3): ");
    scanf("%d", &kotaInput); /* Menerima input */

    if (kotaInput >= 1 && kotaInput <= 3) { /* Jika kotaInput lebih dari sama dengan 1 dan kotaInput kurang dari sama dengan 4 */
        for (int j = 0; j < 4; j++) {
            if (j == 0) printf("Januari: "); /* Jika j = 0 */
            else if (j == 1) printf("Februari: "); /* Jika j = 1 */
            else if (j == 2) printf("Maret: "); /* Jika j = 2 */
            else if (j == 3) printf("April: "); /* Jika j = 3 */
            printf("%d\n", penjualan[kotaInput - 1][j]);
        }
    } else { /* Jika input salah */
        printf("Input kota tidak valid\n");
    }

    return 0;
}
