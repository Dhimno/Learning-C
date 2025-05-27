/*Nama File 	: namaHari.c*/
/*Deskripsi 	: Mengecek dan menampilkan nama hari apabila benar dan mengecek apabila salah juga*/
/*Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <01-03-2025 dan 22:20>*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ /*Kamus*/
  int Hari;

  /*Algoritma*/
  printf("========================================\n");
  printf("Pengecek Nama Hari\n");
  printf("========================================\n");
  printf("Masukkan angka hari ke berapa yang anda inginkan: ");
  scanf("%d", &Hari);

  switch (Hari)
  {
  case 1:
    printf("Senin");
    break;
  case 2:
    printf("Selasa");
    break;
  case 3:
    printf("Rabu");
    break;
  case 4:
    printf("Kamis");
    break;
  case 5:
    printf("Jum'at");
    break;
  case 6:
    printf("Sabtu");
    break;
  case 7:
    printf("Minggu");
    break;
  default:
    printf("Masukan nomor hari tidak tepat");
    break;
  }

  return 0;
}