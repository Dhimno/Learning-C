/* File         : main.c */
/* Deskripsi    : aplikasi driver ADT list berkait SIRKULAR, representasi fisik pointer */
/* NIM/Nama   	: 24060124120010/Dhimas Reza Nafi Wahyudi */
/* Tanggal    	: 13 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"
#include "list2.c"

int main() {
    List2 L, L1, L2, L3;
    infotype X;

    CreateList(&L);
    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L3);
    printf("========== Uji List Sirkular ===========\n");
    printf("========================================\n");

    printf("Uji InsertVLast:\n");
    InsertVLast(&L, 'A');
    InsertVLast(&L, 'B');
    InsertVLast(&L, 'C');
    InsertVLast(&L, 'D');
    PrintList(L);
    printf("========================================\n");

    printf("Uji NbElm:\n");
    printf("Jumlah elemen: %d\n", NbElm(L));
    printf("========================================\n");

    printf("Uji DeleteVFirst:\n");
    DeleteVFirst(&L, &X);
    printf("Elemen dihapus: %c\n", X);
    PrintList(L);
    printf("========================================\n");

    printf("Uji DeleteVLast:\n");
    DeleteVLast(&L, &X);
    printf("Elemen dihapus: %c\n", X);
    PrintList(L);
    printf("========================================\n");

    printf("Uji Invers:\n");
    Invers(&L);
    PrintList(L);
    printf("========================================\n");

    printf("Uji CountVocal:\n");
    printf("Jumlah huruf vokal: %d\n", CountVocal(L));
    printf("========================================\n");

    printf("Uji FrekuensiX:\n");
    printf("Frekuensi huruf B: %.2f\n", FrekuensiX(L, 'B'));
    printf("========================================\n");

    printf("Uji InsertVAfterX:\n");
    InsertVAfterX(&L, 'C', 'E');
    PrintList(L);
    printf("========================================\n");

    printf("Uji InsertVBeforeX:\n");
    InsertVBeforeX(&L, 'B', 'C');
    PrintList(L);
    printf("========================================\n");

    printf("Uji SearchAllX:\n");
    printf("Posisi huruf B:\n");
    SearchAllX(L, 'B');
    printf("========================================\n");

    printf("Uji Modus:\n");
    printf("Huruf dengan kemunculan terbanyak: %c\n", Modus(L));
    printf("========================================\n");

    printf("Uji Copy:\n");
    CopyList(L, &L1);
    printf("List hasil salinan:\n");
    PrintList(L1);
    printf("========================================\n");

    printf("Uji Concat:\n");
    InsertVLast(&L2, 'X');
    InsertVLast(&L2, 'Y');
    InsertVLast(&L2, 'Z');
    printf("List L : ");
    PrintList(L);
    printf("List L2: ");
    PrintList(L2);
    ConcatList(L, L2, &L3);
    printf("Hasil Concat (L3): ");
    PrintList(L3);
    printf("========================================\n");

    printf("Uji Split:\n");
    SplitList(L3, &L1, &L2);
    printf("Hasil Split ke L1 dan L2:\n");
    printf("L1: ");
    PrintList(L1);
    printf("L2: ");
    PrintList(L2);
    printf("========================================\n");

    return 0;
}
