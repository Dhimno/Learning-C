/* Nama File 	: luasKellLayang.c */
/* Deskripsi 	: Menghitung dan menampilkan luas layang-layang dan kelilingnya */
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <02-03-2025 dan 21:05> */

#include <stdio.h> /*Header file utama*/

/* Program Utama */
int main()
{
/*Kamus*/
    int s1,s2,d1,d2,kell;
    float Luas;

/*Algoritma*/
    printf("===========================================\n");
    printf("Penghitung luas dan keliling layang-layang\n");
    printf("===========================================\n");
    printf("Masukkan sisi satu dari layang-layang yang diinginkan (s1): ");
    scanf("%d", &s1);
    printf("Masukkan sisi dua dari layang-layang yang diinginkan (s2): ");
    scanf("%d", &s2);
    printf("Masukkan diagonal satu dari layang-layang yang diinginkan (d1): ");
    scanf("%d", &d1);
    printf("Masukkan diagonal dua dari layang-layang yang diinginkan (d2): ");
    scanf("%d", &d2);
    kell =  2 * (s1 + s2);
    Luas = 0.5 * d1 * d2;
    printf("Jadi luas layang layang adalah %f sedangkan keliling dari layang-layang adalah %d", Luas, kell);
    return 0;
}