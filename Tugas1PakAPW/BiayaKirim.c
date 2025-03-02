// Nama File 	: BiayaKirim.c
// Deskripsi 	: Menghitung dan menampilkan biaya pengiriman barang berdasarkan berat dan jarak
// Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi>
// Tgl Pembuatan	: <02-03-2025 dan 21:05>

#include <stdio.h> // Header file utama

// Program Utama
int main(){

// Kamus
    int m,s,bp;

// Algoritma
    printf("========================================\n");
    printf("Penghitung Biaya Kirim berdasarkan data\n");
    printf("========================================\n");
    printf("Masukkan massa bena yang akan dikirim (m): ");
    scanf("%d", &m);
    printf("Masukkan jarak pengantaran dari pengirim ke penerima yang diinginkan (s): ");
    scanf("%d", &s);
    bp = 10000 + 5000 * m + 2000 * s;
    printf("Jadi biaya pengiriman yang harus dibayar adalah %d", bp);
    return 0;
}