/*Nama File 	: kallSS.c*/
/*Deskripsi 	: Mengoperasikan kedua input integer berdasarkan pilihan opsi yang disajikan*/
/*Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <01-03-2025 dan 22:40>*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ /*Kamus*/
  int iA;
  int iB;
  char program;

  /*Algoritma*/
  printf("========================================\n");
  printf("Kall-SS\n");
  printf("========================================\n");
  printf("Masukkan angka pertama yang anda inginkan: ");
  scanf("%d", &iA);
  printf("Masukkan angka Kedua yang anda inginkan: ");
  scanf("%d", &iB);
  printf("a. Penambahan\nb. Pengurangan\nc. Perkalian\nd. Pembagian\ne. Div\nf. Mod\n");
  printf("Masukkan Kode Program yang anda inginkan: ");
  scanf(" %c", &program);  
  switch (program)
  {
  case 'a':
    printf("Hasil penambahan adalah %d", iA + iB);
    break;
  case 'b':
    printf("Hasil pengurangan adalah %d", iA - iB);
    break;
  case 'c':
    printf("Hasil perkalian adalah %d", iA * iB);
    break;
  case 'd':
    printf("Hasil pembagian adalah %.3f", (float)iA / iB);
    break;
  case 'e':
    printf("Hasil div adalah %d", iA / iB);
    break;
  case 'f':
    printf("Hasil mod adalah %d", iA % iB);
    break;
  default:
    printf("Bukan pilihan menu yang benar");
    break;
  }

  return 0;
}