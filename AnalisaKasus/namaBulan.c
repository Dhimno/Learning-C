/*Nama File 	: namaBulan.c*/
/*Deskripsi 	: Mengecek dan menampilkan nama bulan apabila benar dan mengecek apabila salah juga*/
/*Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <01-03-2025 dan 22:23>*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ /*Kamus*/
  int Bulan;

  /*Algoritma*/
  printf("========================================\n");
  printf("Pengecek Nama Bulan\n");
  printf("========================================\n");
  printf("Masukkan angka Bulan ke berapa yang anda inginkan: ");
  scanf("%d", &Bulan);

  switch (Bulan)
  {
  case 1:
    printf("Januari");
    break;
  case 2:
    printf("Februari");
    break;
  case 3:
    printf("Maret");
    break;
  case 4:
    printf("April");
    break;
  case 5:
    printf("May");
    break;
  case 6:
    printf("Juni");
    break;
  case 7:
    printf("Juli");
    break;
  case 8:
    printf("Agustus");
    break;
  case 9:
    printf("September");
    break;
  case 10:
    printf("Oktober");
    break;
  case 11:
    printf("November");
    break;
  case 12:
    printf("Desember");
    break;
  default:
    printf("Masukan nomor bulan tidak tepat");
    break;
  }

  return 0;
}