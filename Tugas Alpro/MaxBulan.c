/* Nama File     : MaxBulan.c */
/* Deskripsi     : Menampilkan rata-rata penjualan terbesar dan menentukan terjadi di bulan apa */
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

    int total, /* Total penjualan tiap bulan */ 
    rata, /* Rata rata penjualan tiap bulan */
    bulanTertinggi, /* index bulan tertinggi */
    i, /* iterasi */
    j, /* iterasi */
    rataTertinggi; /* Rata rata penjualan terbesar dari tabel penjualan*/

    /* Algoritma */
    bulanTertinggi = 0; /* Inisialisasi bulan tertinggi */
    rataTertinggi = 0; /* Inisialisasi rata rata tertinggi */
    for (int b = 0; b < 4; b++) {
        total = 0; /* Inisialisasi total */
        for (int k = 0; k < 3; k++) {
            total += penjualan[k][b]; /* Mengganti total dengan nilai nilai elemen k b dari tabel penjualan*/
        }
        rata = total / 3; /* Hitung nilai rata rata */
        if (rata > rataTertinggi) { /* Jika rata lebih besar dari rata tertinggi */
            rataTertinggi = rata; /* Ubah nilai rataTertinggi menjadi rata */
            bulanTertinggi = b; /* Ubah bulan tertinggi ke index b */
        }
    }

    if (bulanTertinggi == 0) { /* Jika bulan tertinggi 0 */
        printf("Rata-rata penjualan tertinggi terjadi di bulan Januari\n");
    } else if (bulanTertinggi == 1) { /* Jika bulan tertinggi 1 */
        printf("Rata-rata penjualan tertinggi terjadi di bulan Februari\n");
    } else if (bulanTertinggi == 2) { /* Jika bulan tertinggi 2 */
        printf("Rata-rata penjualan tertinggi terjadi di bulan Maret\n");
    } else if (bulanTertinggi == 3) { /* Jika bulan tertinggi 3 */
        printf("Rata-rata penjualan tertinggi terjadi di bulan April\n");
    }

    return 0;
}
