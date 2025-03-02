/* Nama File 	: volBolaKerct.c */
/* Deskripsi 	: Menghitung dan menampilkan volume bola dan volume kerucut */
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <02-03-2025 dan 21:14> */

#include <stdio.h> /*Header file utama*/

/*Program Utama*/
int main()
{

/*Kamus*/
    int r;
    float Vb;
    float Vk;   

/*Algoritma*/
    printf("====================================\n");
    printf("Penghitung volume bola dan kerucut\n");
    printf("====================================\n");
    printf("Masukkan jari-jari lingkaran yang diinginkan (r): ");
    scanf("%d", &r);
    Vb = 1,333 * (3.1415 * (r * r * r));
    Vk = 0.5 * Vb;
    printf("Jadi volume bola adalah %f sedangkan volume kerucut adalah %f", Vb, Vk);
    return 0;
}