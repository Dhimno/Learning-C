/* File         : main.c */
/* Deskripsi    : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM/Nama   	: 24060124120010/Dhimas Reza Nafi Wahyudi */
/* Tanggal    	: 20 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list3.c"

int main() {
    List3 L, L1, L2, L3, L4;
    infotype X;
    address P;
    char V;

    CreateList(&L);
    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L3);
    CreateList(&L4);
    printf("========== Uji List Berkait Ganda ===========\n");
    printf("=============================================\n");

    printf("Uji InsertVFirst dan InsertVLast:\n");
    InsertVFirst(&L, 'B');
    InsertVLast(&L, 'C');
    InsertVFirst(&L, 'A');
    InsertVLast(&L, 'D');
    PrintList(L);
    printf("========================================\n");

    printf("Uji CountX:\n");
    printf("Count huruf A: %d\n", CountX(L, 'A'));
    printf("========================================\n");

    printf("Uji SearchX:\n");
    printf("Search huruf A: ");
    SearchX(L, 'A', &P);
    if (P != NIL) {
        printf("Huruf A ditemukan\n");
    } else {
        printf("Tidak ditemukan\n");
    }
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
    InsertVAfterX(&L, 'B', 'A');
    PrintList(L);
    printf("========================================\n");

    printf("Uji InsertVBeforeX:\n");
    InsertVBeforeX(&L, 'C', 'B');
    PrintList(L);
    printf("========================================\n");

    printf("Uji SearchAllX:\n");
    printf("Posisi huruf B:\n");
    SearchAllX(L, 'B');
    printf("========================================\n");

    printf("Uji Modus:\n");
    printf("Huruf dengan kemunculan terbanyak: %c\n", Modus(L));
    printf("========================================\n");

    printf("Uji MaxMember:\n");
    printf("Huruf dengan kemunculan terbanyak muncul %d kali.\n", MaxMember(L));
    printf("========================================\n");

    printf("Uji Copy:\n");
    CopyList(L, &L1);
    printf("List hasil salinan:\n");
    PrintList(L1);
    printf("========================================\n");

    printf("Uji Concat:\n");
    InsertVLast(&L2, 'W');
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

    InsertVLast(&L4, 'N');
    InsertVLast(&L4, 'G');
    InsertVLast(&L4, 'A');
    InsertVLast(&L4, 'N');
    InsertVLast(&L4, 'T');
    InsertVLast(&L4, 'U');
    InsertVLast(&L4, 'K');
    printf("Uji CountNG:\n");
    PrintList(L4);
    printf("CountNG = %d\n", CountNG(L4));
    printf("========================================\n");


    DeleteAllX(&L4, 'N');
    printf("Uji DeleteAllX:\n");
    PrintList(L4);
    printf("========================================\n");

    DeleteX(&L4, 'G');
    printf("Uji DeleteX:\n");
    PrintList(L4);
    printf("========================================\n");
    
    printf("\nUji DeleteVAfterX:\n");
    DeleteVAfterX(&L4, 'A', &V);
    if (V != '#') {
        printf("Terhapus: %c\n", V);
    } else {
        printf("Tidak ada yang dihapus\n");
    }
    PrintList(L4);
    printf("========================================\n");

    printf("\nUji DeleteVBeforeX:\n");
    DeleteVBeforeX(&L4, 'U', &V);
    if (V != '#') {
        printf("Terhapus: %c\n", V);
    } else {
        printf("Tidak ada yang dihapus\n");
    }
    PrintList(L4);
    printf("========================================\n");

    UpdateX(&L4, 'K', 'S');
    printf("Uji UpdateX:\n");
    PrintList(L4);
    printf("========================================\n");

    return 0;
}
