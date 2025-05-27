/*Nama File 	: tukar.c*/
/*Deskripsi 	: Menukar nilai antara bilangan a dan b*/
/*Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <26-03-2025 dan 22:23>*/

#include <stdio.h> /*header file*/

void tukar(int *a, int *b) {
    /*Kamus Lokal*/
    int temp = *a;

    /*Algoritma*/
    *a = *b;
    *b = temp;
}

/*Program Utama*/
int main() {
    /*Kamus*/
    int a, b;

    /*Algoritma*/
    printf("Masukkan nilai dua bilangan: ");
    scanf("%d %d", &a, &b);
    tukar(&a, &b);
    printf("Hasil setelah ditukar: %d %d\n", a, b);
}
