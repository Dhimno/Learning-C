/*Nama File 		: CekSegitiga.c*/
/*Deskripsi 		: Mengecek apakah sebuah segitiga termasuk sama sisi, sama kaki, atau sembarang atau bahkan tidak segitiga*/
/*Pembuat   		: <24060124120010 - Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <01-03-2025 dan 22:25>*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ /*Kamus*/
  int x;
  int y;
  int z;
  
  /*Algoritma*/
  printf("========================================\n");
  printf("Pengecek segitiga\n");
  printf("========================================\n");
  printf("Masukkan sisi pertama yang anda inginkan: ");
  scanf("%d", &x);
  printf("Masukkan sisi kedua yang anda inginkan: ");
  scanf("%d", &y);
  printf("Masukkan sisi ketiga yang anda inginkan: ");
  scanf("%d", &z);

if (x <= 0 || y <= 0 || z <= 0){
      printf("Terdapat nilai yang bukan sisi segitiga");
  } else if (x == y == z) {
      printf("Nilai yang anda masukkan membentuk segitiga sama sisi");
  } else if (x == y || y == z || x == z) {
      printf("Nilai yang anda masukkan membentuk segitiga sama kaki");
  } else {
    printf("Nilai yang anda masukkan membentuk segitiga sembarang");
  }

  return 0;
}