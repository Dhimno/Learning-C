/* File       : main.c */
/* Deskripsi  : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM/Nama   : 24060124120010/Dhimas Reza Nafi Wahyudi */
/* Tanggal    : 9 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
#include "list1.c"

int main() {
    List1 L, L2, L3;
    address P, A;
    infotype V;

    printf("==================================================\n");
    printf("                  MAIN PROGRAM        \n");
    printf("==================================================\n");

    // Membuat list kosong
    printf("\nMembuat list baru:\n");
    CreateList(&L);
    PrintList(L);
    printf("Apakah list kosong? %d\n", IsEmptyList(L));
    printf("==================================================\n");

    // Menambahkan elemen pada list kosong
    printf("Menambahkan elemen di awal dan akhir:\n");
    InsertVFirst(&L, 'A');
    InsertVLast(&L, 'B');
    InsertVLast(&L, 'C');
    InsertVLast(&L, 'D');
    printf("Isi list: ");
    PrintList(L);
    printf("==================================================\n");

    printf("Menambahkan elemen di awal lagi:\n");
    InsertVFirst(&L, 'Z');
    PrintList(L);
    printf("==================================================\n");

    printf("Jumlah elemen dalam list: %d\n", NbElm(L));
    printf("==================================================\n");

    // Menghapus elemen pertama dan terakhir
    printf("Menghapus elemen pertama:\n");
    DeleteVFirst(&L, &V);
    printf("Elemen yang dihapus: %c\n", V);
    printf("Isi list sekarang: ");
    PrintList(L);
    printf("==================================================\n");

    printf("Menghapus elemen terakhir:\n");
    DeleteVLast(&L, &V);
    printf("Elemen yang dihapus: %c\n", V);
    printf("Isi list sekarang: ");
    PrintList(L);
    printf("==================================================\n");

    // Test SearchX
    printf("Mencari elemen 'B':\n");
    SearchX(L, 'B', &A);
    if (A != NIL){
        printf("Elemen 'B' ditemukan\n");
    } else {
        printf("Elemen 'B' tidak ditemukan\n");
    };
    printf("==================================================\n"); 

    // Test UpdateX
    printf("Isi list sebelum UpdateX:\n");
    PrintList(L);
    printf("Mengganti elemen pertama 'B' menjadi 'X':\n");
    UpdateX(&L, 'B', 'A');
    printf("Isi list setelah UpdateX:\n");
    PrintList(L);
    printf("==================================================\n");

    // Test UpdateAllX
    printf("Mengganti semua 'A' menjadi 'Y':\n");
    UpdateAllX(&L, 'A', 'Y');
    PrintList(L);
    printf("==================================================\n");

    // Test Invers
    printf("Membalik urutan list:\n");
    Invers(&L);
    PrintList(L);
    printf("==================================================\n");

    // Test CountVocal dan CountX
    printf("Jumlah huruf vokal: %d\n", CountVocal(L));
    printf("Jumlah huruf 'Y': %d\n", CountX(L, 'Y'));
    printf("Frekuensi 'Y': %.2f\n", FrekuensiX(L, 'Y'));
    printf("==================================================\n");

    // Test SearchAllX
    SearchAllX(L, 'Y');
    printf("\n==================================================\n");

    // Test InsertVAfter
    printf("Insert 'Z' setelah 'C':\n");
    InsertVAfter(&L, 'C', 'Z');
    PrintList(L);
    printf("==================================================\n");

    // Test Modus dan NbModus
    printf("Huruf modus: %c\n", Modus(L));
    printf("NbModus: %d\n", NbModus(L));
    printf("==================================================\n");

    // Test CopyList
    printf("Menduplikasi list ke L2:\n");
    CopyList(L, &L2);
    PrintList(L2);
    printf("==================================================\n");

    // Test ConcatList
    printf("Menggabungkan L dan L2 menjadi L3:\n");
    ConcatList(L, L2, &L3);
    PrintList(L3);
    printf("==================================================\n");

    // Test SplitList
    printf("Membagi L3 menjadi dua list (L dan L2):\n");
    SplitList(L3, &L, &L2);
    printf("Bagian pertama:\n");
    PrintList(L);
    printf("Bagian kedua:\n");
    PrintList(L2);
    printf("==================================================\n");

    return 0;
}
