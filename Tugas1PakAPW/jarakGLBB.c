// Nama File 	: jarakGLBB.c
// Deskripsi 	: Menghitung dan menampilkan jarak yang ditempuh oleh benda yang mengalami gerak lurus berubah beraturan
// Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi>
// Tgl Pembuatan	: <02-03-2025 dan 21:05>

#include <stdio.h> // Header file utama

// Program Utama
int main(){

// Kamus
    int V0;
    int t;
    int a;
    float s;

// Algoritma
    printf("=================================\n");
    printf("Penghitung jarak dari benda GLBB\n");
    printf("=================================\n");
    printf("Masukkan Kecepatan Awal yang diinginkan (V0): ");
    scanf("%d", &V0);
    printf("Masukkan waktu yang ditempuh oleh benda yang diinginkan (t): ");
    scanf("%d", &t);
    printf("Masukkan percepatan benda yang diinginkan (a): ");
    scanf("%d", &a);
    s = V0 * t + 0.5 * (a*t*t);
    printf("Jadi jarak yang ditempuh benda adalah (s): %f\n", s);
    return 0;
}