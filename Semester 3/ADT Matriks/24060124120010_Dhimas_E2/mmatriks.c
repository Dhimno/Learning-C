/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : Dhimas Reza Nafi Wahyudi/24060124120010 */
/* Tanggal   : 18 September 2025 */
/***********************************/

#include <stdio.h>
#include "matriks.h"

int main() {
	/*kamus*/
    Matriks M1;
    Matriks M2;
    Matriks M3;
    Matriks M4;
    Matriks M5;
	
	/*algoritma*/
    printf("===========================================\n");
    printf("    Test initMatriks dan printMatriks \n");
    printf("===========================================\n");
    initMatriks(&M1);
    printMatriks(M1);
    printf("===========================================\n");
    printf("    Test getNBaris dan getNKolom \n");
    printf("===========================================\n");
    printf("Jumlah baris dalam M1 adalah %d\n", getNBaris(M1));
    printf("Jumlah kolom dalam M1 adalah %d\n", getNKolom(M1));
	
    printf("===========================================\n");
    printf("                 Test addX \n");
    printf("===========================================\n");
    addX(&M1, 7, 1, 1);
    addX(&M1, 9, 1, 2);
    addX(&M1, 4, 2, 1);
    addX(&M1, 1, 2, 2);
    viewMatriks(M1);
    printf("Jumlah baris dalam M1 adalah %d\n", getNBaris(M1));
    printf("Jumlah kolom dalam M1 adalah %d\n", getNKolom(M1));

    printf("===========================================\n");
    printf("         Test isEmptyMatriks M1\n");
    printf("===========================================\n");
    printf("Matriks M1 adalah matriks %d\n", isEmptyMatriks(M1));

    printf("===========================================\n");
    printf("         Test isFullMatriks M1\n");
    printf("===========================================\n");
    printf("Matriks M1 adalah matriks %d\n", isFullMatriks(M1));

    printf("===========================================\n");
    printf("           Test populateMatriks \n");
    printf("===========================================\n");
    initMatriks(&M2);
    populateMatriks(&M2, 2, 2);
    viewMatriks(M2);

    printf("===========================================\n");
    printf("           Test isiMatriksIdentitas \n");
    printf("===========================================\n");
	isiMatriksIdentitas(&M4, 2);
    viewMatriks(M4);

    printf("===========================================\n");
    printf("         Test getTransposeMatriks\n");
    printf("===========================================\n");
    viewMatriks(getTransposeMatriks(M1));

    printf("===========================================\n");
    printf("           Test transposeMatriks M1 \n");
    printf("===========================================\n");
    transposeMatriks(&M1);
    viewMatriks(M1);

    printf("===========================================\n");
    printf("           Test isiMatriksRandom \n");
    printf("===========================================\n");
	isiMatriksRandom(&M5,3,3);
	viewMatriks(M5);

    printf("===========================================\n");
    printf("           Test addMatriks M1 dan M2 \n");
    printf("===========================================\n");
    viewMatriks(addMatriks(M1,M2));

    printf("===========================================\n");
    printf("         Test subMatriks M1 dan M2 \n");
    printf("===========================================\n");
    viewMatriks(subMatriks(M1,M2));

    printf("===========================================\n");
    printf("        Test kaliMatriks M1 dan M2 \n");
    printf("===========================================\n");
    viewMatriks(kaliMatriks(M1,M2));

    printf("===========================================\n");
    printf("    Test kaliSkalarrMatriks M1 dengan 2 \n");
    printf("===========================================\n");
    viewMatriks(kaliSkalarMatriks(M1,2));

    printf("===========================================\n");
    printf("            Test addPadding \n");
    printf("===========================================\n");
    viewMatriks(addPadding(M1,1));

    printf("===========================================\n");
    printf("            Test maxPooling \n");
    printf("===========================================\n");
    viewMatriks(maxPooling(M1,2));

    printf("===========================================\n");
    printf("            Test avgPooling \n");
    printf("===========================================\n");
    viewMatriks(avgPooling(M1,2));

    printf("===========================================\n");
    printf("            Test conv \n");
    printf("===========================================\n");
    viewMatriks(conv(M1,M4));

    printf("===========================================\n");
    printf("            Test countX \n");
    printf("===========================================\n");
    printf("Jumlah angka '2' di M2 adalah %d\n", countX(M2, 2));

    printf("===========================================\n");
    printf("            Test searchX \n");
    printf("===========================================\n");
    int row, col;
    searchX(M2, 2, &row, &col);
    if (row != -999 && col != -999) {
        printf("Angka 2 ditemukan di baris %d kolom %d\n", row, col);
    } else {
        printf("Angka 2 tidak ditemukan di M2\n");
    }


	return 0;
}