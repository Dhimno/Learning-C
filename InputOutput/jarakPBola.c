/* Nama File 	: jarakPBola.c */
/* Deskripsi 	: Menghitung dan menampilkan jarak yang ditempuh benda yang mengalami gerak parabola */
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <02-03-2025 dan 21:05> */

#include <stdio.h> /*Header file utama*/

/* Program Utama */
int main()
{
/*Kamus*/
    int V0;
    int t;
    int g;
    float y;

/*Algoritma*/
    printf("====================================\n");
    printf("Penghitung jarak dari benda parabola\n");
    printf("====================================\n");
    printf("Masukkan Kecepatan Awal yang diinginkan (V0): ");
    scanf("%d", &V0);
    printf("Masukkan waktu yang ditempuh oleh benda yang diinginkan (t): ");
    scanf("%d", &t);
    printf("Masukkan konstanta gratifikasi yang diinginkan (g): ");
    scanf("%d", &g);
    y = V0 * t - 0.5 * (g*t*t);
    printf("Jadi jarak yang ditempuh benda adalah (y): %f\n", y);
    return 0;
}