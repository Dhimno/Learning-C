/* Nama File 	: FaktorBil.c */
/* Deskripsi 	: Menghitug dan menampilkan faktor dari suatu bilangan*/
/* Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi> */
/* Tgl Pembuatan	: <04-03-2025 dan 08:39> */

#include <stdio.h> /* Header file utama */

/* Program Utama */
int main() {
    /* Kamus */
    int n; 
    int i = 1;

/* Algoritma */
    printf("========================================\n");
    printf("Penghitung faktor dari bilangan N\n");
    printf("========================================\n");
    printf("Masukkan nilai N: ");
    scanf("%d", &n);

    printf("Jadi faktor dari %d adalah: ", n);
    if (i <= 0){
        printf("Masukan harus diatas 0");
    } else {
        while (i <= n)
        {
            if (n%i==0){
                printf("%d, ", i);
                i++;
            } else {
                i++;
            }
        }
    }

    return 0;
}

