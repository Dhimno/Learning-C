/*Nama File 		: bilInteger.c*/
/*Deskripsi 		: Mengecek apakah sebuah bilangan integer merupakan bulat positif atau nol atau bulat negatif*/
/*Pembuat   		: <24060124120010 - Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <01-03-2025 dan 22:16>*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ /*Kamus*/
  int i;

  /*Algoritma*/
  printf("========================================\n");
  printf("Pengecek bilangan integer\n");
  printf("========================================\n");
  printf("Masukkan bilangan integer yang anda inginkan: ");
  scanf("%d", &i);

  if (i > 0){
      printf("Bilangan yang anda masukkan merupakan bilangan bulat positif");
  } else if (i == 0){
      printf("Bilangan yang anda masukkan merupakan bilangan nol");
  } else {
      printf("Bilangan yang anda masukkan merupakan bilangan bulat negatif");
  }

  return 0;
}