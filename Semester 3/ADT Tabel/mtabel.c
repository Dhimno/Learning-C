/************************************/
/* Program   : mtabel.c */
/* Deskripsi : aplikasi driver modul tabel */
/* NIM/Nama  : 24060124120010/Dhimas Reza Nafi Wahyudi */
/* Tanggal   : 11/September/2025 */
/***********************************/
#include <stdio.h>
#include "tabel.h"

int main() {
    Tabel T1;
    Tabel T2;
    Tabel T3;
    int pos;
    char x;
    printf("================================\n");
    printf("Uji create, add, dan view tabel\n");
    printf("================================\n");
    /* Tabel 1 */
    createTable(&T1);
    addXTable(&T1, 'A');
    addXTable(&T1, 'B');
    addXTable(&T1, 'C');
    addXTable(&T1, 'D');
    addXTable(&T1, 'E');
    viewTable(T1);
	printf("\n");

	/* Tabel 2 */
    createTable(&T2);
    addXTable(&T2, 'A');
    addXTable(&T2, 'B');
    addXTable(&T2, 'C');
    addXTable(&T2, 'D');
    addXTable(&T2, 'E');

    printf("==================\n");
    printf("Uji isEmptyTable\n");
    printf("==================\n");
    printf("Tabel 1 adalah tabel %d (1=Kosong, 0=Tidak Kosong)\n", isEmptyTable(T1));
	printf("\n");

    printf("================\n");
    printf("Uji isFullTable\n");
    printf("================\n");
    printf("Tabel 1 adalah tabel %d (1=Penuh, 0=Tidak penuh)\n", isFullTable(T1));
	printf("\n");

    printf("====================\n");
    printf("Uji addUniqueXTable\n");
    printf("====================\n");
    addUniqueXTable(&T1, 'A');
    addUniqueXTable(&T1, 'Z');
    viewTable(T1);
	printf("\n");

    printf("==============\n");
    printf("Uji isEqual\n");
    printf("==============\n");
    printf("Tabel 1 dan 2 adalah tabel yang %d (1=sama, 0=beda)\n", isEqualTable(T1, T2));
	printf("\n");

    printf("===============\n");
    printf("Uji countVokal\n");
    printf("===============\n");
    printf("Jumlah huruf vokal dalam tabel 1 adalah %d\n", countVocal(T1));
	printf("\n");

    printf("============\n");
    printf("Uji countX\n");
    printf("============\n");
    x = 'A';
    printf("Jumlah '%c' di T1 adalah %d\n", x, countX(T1, x));
	printf("\n");    

    printf("=============\n");
    printf("Uji SearchX\n");
    printf("=============\n");
    searchX(T2, x, &pos);
    printf("Posisi '%c' pertama di T2 adalah %d\n", x, pos);

    delXTable(&T1, 'A');
    printf("\nT1 sesudah hapus A menggunakan delXTable:\n");
    viewTable(T1);

    delAllXTable(&T2, 'A');
    printf("T2 sesudah hapus A menggunakan delAllXTable:\n");
    viewTable(T2);
	printf("\n");

    printf("=============\n");
    printf("Uji delTable\n");
    printf("=============\n");
    printf("Sebelum hapus indeks ke-3:\n");
    viewTable(T1);
    delTable(&T1, 3);
    printf("Sesudah hapus indeks ke-3:\n");
    viewTable(T1);
	printf("\n");

    /* Tabel 3 */
    printf("==================\n");
    printf("Uji populateTable\n");
    printf("==================\n");
    populateTable(&T3, 5);
    viewTable(T3);
    printf("\n");

    printf("===========\n");
    printf("Uji Modus\n");
    printf("===========\n");
    printf("Modus dalam T3 adalah %c\n", Modus(T3));
    printf("\n");

    printf("=================\n");
    printf("Uji InverseTabel\n");
    printf("=================\n");
    inverseTable(&T3);
    viewTable(T3);
	printf("\n");

    printf("============\n");
    printf("Uji sortAsc\n");
    printf("============\n");
    sortAsc(&T3);
    viewTable(T3);
	printf("\n");

    printf("=============\n");
    printf("Uji sortDesc\n");
    printf("=============\n");
    sortDesc(&T3);
    viewTable(T3);
	printf("\n");


    return 0;
}