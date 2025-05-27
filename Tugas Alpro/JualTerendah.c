/* Nama File     : JualTerendah.c */
/* Deskripsi     : Menampilkan lokasi penjualan terendah (kota & bulan) */
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

    int baris, /* Baris dari kota yang penjualannya terendah */
    kolom, /* Kolom dari kota yang penjualannya terendah */
    i, /* iterasi */
    j, /* iterasi */
    nilaiMin; /* penjualan dengan nilai terendah */
    
    /* Algoritma */
    baris = 0; /* Inisialisasi nilai baris */
    kolom = 0; /* Inisialisasi nilai kolom */
    nilaiMin = 100; /* Inisialisasi nilaiMin */

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (data[i][j] < nilaiMin) {
                nilaiMin = data[i][j]; /* Ubah nilai min menjadi nilai dari data dari baris i dan j*/
                baris = i; /* Ubah baris menjadi baris ke iterasi ke i*/
                kolom = j; /* Ubah kolom menjadi kolom ke iterasi ke j*/
            }
        }
    }

    if (baris == 0) { /* Jika baris 0 */
        printf("Penjualan terendah terjadi di Jakarta ");
    } else if (baris == 1) { /* Jika baris 1 */
        printf("Penjualan terendah terjadi di Semarang ");
    } else if (baris == 2) { /* Jika baris 2 */
        printf("Penjualan terendah terjadi di Pati ");
    }

    if (kolom == 0) { /* Jika kolom 0 */
        printf("bulan Januari\n");
    } else if (kolom == 1) { /* Jika kolom 1 */
        printf("bulan Februari\n");
    } else if (kolom == 2) { /* Jika kolom 2 */
        printf("bulan Maret\n");
    } else if (kolom == 3) { /* Jika kolom 3 */
        printf("bulan April\n");
    }

    return 0;
}
