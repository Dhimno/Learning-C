/*Nama File 		: hitungTahanan.c*/
/*Deskripsi 		: Menghitung dan menjumlahkan tahanan apabila tidak ada yang bernilai negatif*/
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
  printf("Pengecek Tahanan\n");
  printf("========================================\n");
  printf("Masukkan tahanan pertama yang anda inginkan: ");
  scanf("%d", &x);
  printf("Masukkan tahanan kedua yang anda inginkan: ");
  scanf("%d", &y);
  printf("Masukkan tahanan ketiga yang anda inginkan: ");
  scanf("%d", &z);

if (x >= 0 && y >= 0 && z >= 0){
      printf("Jadi total tahanan adalaha %d", x+y+z);
  } else {
    printf("Masukan tahanan tidak boleh negatif");
  }

  return 0;
}