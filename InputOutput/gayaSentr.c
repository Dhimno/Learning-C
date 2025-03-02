/* Nama File 	: gayaSentr.c */
/* Deskripsi 	: Menghitung dan menampilkan hasil gaya yang terjadi */
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <01-03-2025 dan 21:11> */

#include <stdio.h> /*Header file utama*/

/* Program Utama */
int main()
{
/*Kamus*/
    int m;
    int v;
    int r;
    float f;

/*Algoritma*/
    printf("====================================\n");
    printf("Penghitung Gaya yang terjadi pada benda\n");
    printf("====================================\n");
    printf("Masukkan massa benda yang diinginkan (m): ");
    scanf("%d", &m);
    printf("Masukkan kecepatan benda yang diinginkan (v): ");
    scanf("%d", &v);
    printf("Masukkan jari-jari benda yang diinginkan (r): ");
    scanf("%d", &r);
    f = m*(v*v/r);
    printf("Jadi gaya yang dihasilkan benda adalah (F): %f\n", f);
    return 0;
}