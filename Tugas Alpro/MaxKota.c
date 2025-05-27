/* Nama File     : MaxKota.c */
/* Deskripsi     : Menentukan kota dengan rata-rata penjualan tertinggi */
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

    int total, /* Total penjualan tiap kota */ 
    rata, /* Rata rata penjualan tiap kota */
    kotaTertinggi, /* index dari kota dengan jumlah rata-rata penjualan terbesar */
    k, /* iterasi */
    b, /* iterasi */
    maxRata; /* Rata rata penjualan terbesar dari tabel data */

    /* Algoritma */
    kotaTertinggi = 0; /* Inisialisasi kotaTertinggi*/
    maxRata = 0; /* Inisialisasi maxRata */
    for (int k = 0; k < 3; k++) {
        total = 0; /* Inisialisasi total */
        for (int b = 0; b < 4; b++) {
            total += data[k][b]; /* Mengganti total dengan nilai dari index k b dari tabel data */
        }
        rata = total / 4; /* Mencari rata - rata */
        if (rata > maxRata) { /* Jika rata-rata lebih besar dari nilai max rata */
            maxRata = rata; /* Ubah nilai max rata dengan rata rata */
            kotaTertinggi = k; /* Ubah index kota tertinggi dengan index k */
        }
    }

    if (kotaTertinggi == 0) { /* Jika kota tertinggi 0 */
        printf("Kota dengan rata-rata tertinggi adalah Jakarta\n");
    } else if (kotaTertinggi == 1) { /* Jika kota tertinggi 1 */
        printf("Kota dengan rata-rata tertinggi adalah Semarang\n");
    } else if (kotaTertinggi == 2) { /* Jika kota tertinggi 2 */
        printf("Kota dengan rata-rata tertinggi adalah Pati\n");
    }

    return 0;
}
