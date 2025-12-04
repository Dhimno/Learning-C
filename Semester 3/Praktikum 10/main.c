/* File : main.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : Dhimas Reza Nafi Wahyudi / 24060124120010 */
/* Tanggal : Kamis, 27 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.c"

int main() {
    bintree T, T2, T3, Left, Right;

    printf("=============== Uji BinTree =================\n");
    printf("=============================================\n");
    T = Tree('A', AlokasiTree('B'), AlokasiTree('C'));
    T2 = Tree('P', AlokasiTree('Q'), NIL);
    T3 = Tree('X', NIL, AlokasiTree('Y'));
    printf("Uji PrintPrefix\n");
    printf("Pohon T awal: ");
    PrintPrefix(T);
    printf("\n========================================\n");
    printf("\n");

    printf("Uji GetLeft dan GetRight\n");
    printf("Akar kiri adalah %c\n", info(GetLeft(T)));
    printf("Akar kanan adalah %c\n", info(GetRight(T)));
    printf("========================================\n");

    printf("Uji Predikat\n");    
    printf("IsEmptyTree : %d\n", IsEmptyTree(T));
    printf("IsDaun A : %d\n", IsDaun(T));
    printf("IsBiner A : %d\n", IsBiner(T));
    printf("IsUnerLeft : %d\n", IsUnerLeft(T2));
    printf("IsUnerRight : %d\n", IsUnerRight(T3));
    printf("========================================\n");

    printf("Uji NbElm dan NbDaun\n"); 
    printf("Jumlah elemen : %d\n", NbElm(T));
    printf("Jumlah daun : %d\n", NbDaun(T));
    printf("========================================\n");

    printf("Uji Tinggi\n"); 
    printf("Tinggi pohon : %d\n", Tinggi(T));
    printf("========================================\n");

    printf("Uji SearchX\n");     
    if (SearchX(T, 'B')){
        printf("Node B ditemukan!\n");
    } else {
        printf("Node B tidak ditemukan\n");
    }
    printf("========================================\n");

    printf("Uji UpdateX\n"); 
    printf("Ubah 'B' menjadi 'A'\n");
    UpdateX(&T, 'B', 'A');
    PrintPrefix(T);
    printf("\n========================================\n");

    printf("Uji CountX\n"); 
    printf("Jumlah node 'A' adalah %d\n", CountX(T, 'A'));
    printf("========================================\n");

    printf("Uji IsSkewLeft dan IsSkewRight\n"); 
    printf("Apakah T2 IsSkewLeft : %d\n", IsSkewLeft(T2));
    printf("Apakah T3 IsSkewRight : %d\n", IsSkewRight(T3));
    printf("========================================\n");

    printf("Uji PrintPrefixRingkas\n");
    PrintPrefixRingkas(T);
    printf("\n========================================\n");

    printf("Uji LevelX dan CountLevel\n");
    printf("Level node 'C' : %d\n", LevelX(T, 'C'));
    printf("Jumlah level 2 : %d\n", CountLevel(T, 2));
    printf("========================================\n");

    printf("Uji PrintLevel\n");
    printf("Node level 2 : ");
    PrintLevel(T, 2);
    printf("\n");
    printf("========================================\n");

    printf("Uji GetDaunTerkiri\n");
    printf("Daun terkiri : %c\n", GetDaunTerkiri(T));
    printf("========================================\n");

    printf("Uji FrekuensiX\n");
    printf("Frekuensi 'A' : %.2f\n", FrekuensiX(T, 'A'));
    printf("========================================\n");

    printf("Uji CountVocal dan PrintVocal\n");
    printf("Jumlah vokal : %d\n", CountVocal(T));
    printf("Huruf vokal : ");
    PrintVocal(T);
    printf("\n");
    printf("========================================\n");

    printf("Uji CountConsonant dan PrintConsonant\n");
    printf("Jumlah konsonan : %d\n", CountConsonant(T));
    printf("Huruf konsonan : ");
    PrintConsonant(T);
    printf("\n");
    printf("========================================\n");

    printf("Uji Modus\n");
    printf("Modus huruf : %c\n", Modus(T));
    printf("========================================\n");

    printf("Uji DealokasiTree\n");
    DealokasiTree(&T);
    printf("========================================\n");

    return 0;
}