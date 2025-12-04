/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060124120010/Dhimas Reza Nafi Wahyudi */
/* Tanggal   : 4/September/2025 */
/***********************************/
#include <stdio.h>

#include "titik.h"

#include <stdlib.h>


int main() {
  Titik T1;
  Titik T2;
  makeTitik( & T1, 4, 5);
  printf("T1 berupa titik dengan x yaitu %d dan titik y yaitu %d\n", getAbsis(T1), getOrdinat(T1));
  makeTitik0( & T2);
  printf("T2 berupa titik Dengan nilai x yaitu %d dan titik y yaitu %d\n", getAbsis(T2), getOrdinat(T2));
  setAbsis( & T1, 2);
  printf("Mengganti x dari T1 menjadi 2 -> (%d,%d)\n", getAbsis(T1), getOrdinat(T1));
  setOrdinat( & T1, 3);
  printf("Mengganti y dari T1 menjadi 3 -> (%d,%d)\n", getAbsis(T1), getOrdinat(T1));
  if (isOrigin(T1)) {
    printf("Titik T1 adalah titik (0,0))\n");
  } else {
    printf("Titik T1 bukan titik (0,0)\n");
  }
  if (isOnSumbuX(T1)) {
    printf("Titik T1 terletak pada sumbu X\n");
  } else {
    printf("Titik T1 tidak terletak pada sumbu X\n");
  }

  if (isOnSumbuY(T1)) {
    printf("Titik T1 terletak pada sumbu Y\n");
  } else {
    printf("Titik T1 tidak terletak pada sumbu Y\n");
  }
  if (isEqual(T1, T2)) {
    printf("T1 dan T2 adalah titik yang sama\n");
  } else {
    printf("T1 dan T2 adalah titik yang tidak sama\n");
  }
  Geser( & T1, 5, 5);
  printf("Menggeser titik T1 sebesar (5,5) menjadi (%d,%d)\n", getAbsis(T1), getOrdinat(T1));
  RefleksiX( & T1);
  printf("Merefleksi titik T1 terhadap sumbu X menjadi (%d,%d)\n", getAbsis(T1), getOrdinat(T1));

  RefleksiY( & T1);
  printf("Merefleksi titik T1 terhadap sumbu Y menjadi (%d,%d)\n", getAbsis(T1), getOrdinat(T1));
  Dilatasi( & T1, 3);
  printf("Mendilatasi titik T1 sebesar 3 menjadi (%d,%d)\n", getAbsis(T1), getOrdinat(T1));
  DilatasiX( & T1, T2, 2);
  printf("Titik T1 didilatasi terhadap titik (%d,%d) sebesar 2 dan menjadi (%d,%d)\n", getAbsis(T2), getOrdinat(T2), getAbsis(T1), getOrdinat(T1));
  return 0;
}