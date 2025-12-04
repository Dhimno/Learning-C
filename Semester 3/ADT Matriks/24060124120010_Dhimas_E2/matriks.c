
/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : Dhimas Reza Nafi Wahyudi/24060124120010 */
/* Tanggal   : 18 September 2025 */
/***********************************/

#include <stdio.h>
#include "matriks.h"
#include "boolean.h"
#include "stdlib.h"

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M) {
    int i, j;
    for (i = 1; i <= 11; i++) {
        for (j = 1; j <= 11; j++) {
            (*M).cell[i][j] = -999;
        }
    }

    (*M).nbaris = 0;
    (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M) {
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M) {
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M) {
    return M.nbaris == 0 && M.nkolom == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    return M.nbaris == 10 && M.nkolom == 10;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX(Matriks *M, int X, int row, int col) {
    if (!isFullMatriks(*M) && row > 0 && col > 0) {
        if ((*M).cell[row][col] == -999) {
            (*M).cell[row][col] = X;

            (*M).nbaris = row;
            (*M).nkolom = col;
        }
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X) {
    int i, j;
    boolean found;
    found = false;
    i = 1;
    while ((i <= getNBaris(*M)) && !found) {
        j = 1;
        while ((j <= getNKolom(*M)) && !found) {
            if ((*M).cell[i][j] == X) {
                (*M).cell[i][j] = -999;
                found = 1;
            } else {
                j++;
            }
        }
        if (!found) {
            i++;
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y) {
    int i,j;
    (*M).nbaris = x;
    (*M).nkolom = y;
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            (*M).cell[i][j] = rand() % 100;
        }
    }
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                (*M).cell[i][j] = 1;
            } else {
                (*M).cell[i][j] = 0;
            }
        }
    }

    (*M).nbaris = n;
    (*M).nkolom = n;
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y) {
    (*M).nbaris = x;
    (*M).nkolom = y;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            printf("Masukkan elemen [%d][%d]: ", i, j);
            scanf("%d", &(*M).cell[i][j]);
        }
    }
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M) {
    int i, j;
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M) {
    int i, j;
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2) {
    Matriks NMatriks;
    int i,j;
    initMatriks(&NMatriks);

    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        NMatriks.nbaris = getNBaris(M1);
        NMatriks.nkolom = getNKolom(M1);
        for (i = 1; i <= NMatriks.nbaris; i++) {
            for (j = 1; j <= NMatriks.nkolom; j++) {
                NMatriks.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
            }
        }
    }
    return NMatriks;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2){
	Matriks M3;
    int i,j;
    initMatriks(&M3);
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)){
        for(i = 1; i <= getNBaris(M1); i++){
            for(j = 1; j <= getNKolom(M1); j++){
                M3.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
            }
        }
        M3.nbaris = getNBaris(M1);
        M3.nkolom = getNKolom(M1);
    }else{
        printf("Ukuran matriks tidak sama\n");
    }

    return M3;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2){
    Matriks M3;
    int i,j,k;
    initMatriks(&M3);

    if(getNKolom(M1) == getNBaris(M2)){
		M3.nbaris = getNBaris(M1);
    	M3.nkolom = getNKolom(M2);

		for(i = 1; i <= getNBaris(M1); i++){
        	for(j = 1; j <= getNKolom(M2); j++){
            	M3.cell[i][j] = 0; 
            	for(k = 1; k <= getNKolom(M1); k++){
                	M3.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
            	}
        	}
   		}
		return M3;

	} else {
		printf("Error");
	}  
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x) {
    Matriks M;
    int i,j;
    initMatriks(&M);
    M.nbaris = getNBaris(M1);
    M.nkolom = getNKolom(M1);
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            M.cell[i][j] = M1.cell[i][j] * x;
        }
    }
    return M;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
    // kamus lokal
    int i, j;
    int temp;

    // algoritma
    if (getNBaris(*M) == getNKolom(*M)) {
        for (i = 1; i <= getNBaris(*M); i++) {
            for (j = i + 1; j <= getNKolom(*M); j++) {
                temp = (*M).cell[i][j];
                (*M).cell[i][j] = (*M).cell[j][i];
                (*M).cell[j][i] = temp;
            }
        }
    }
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M){
	Matriks M1;
    int i,j;
	initMatriks(&M1);

	for(i = 1;i <= getNBaris(M);i++){
		for(j = 1;j <= getNKolom(M);j++){
			M1.cell[j][i] = M.cell[i][j];
		}
	}
	M1.nbaris = M.nkolom;
	M1.nkolom = M.nbaris;

	return M1;
}

/* function addPadding(M: Matriks, input n:integer)
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n){
    Matriks M2;
    int i,j;
    initMatriks(&M2);
    M2.nbaris = getNBaris(M) + 2*n;
    M2.nkolom = getNKolom(M) + 2*n;

    for(i = 1; i <= M2.nbaris; i++){
        for(j = 1; j <= M2.nkolom; j++){
            M2.cell[i][j] = 0;
        }
    }

    for(i = 1; i <= getNBaris(M); i++){
        for(j = 1; j <= getNKolom(M); j++){
            M2.cell[i+n][j+n] = M.cell[i][j];
        }
    }

    return M2;
}

/* function maxPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size){
    Matriks M2;
    initMatriks(&M2);

    int Baris = getNBaris(M) / size;
    int Kolom = getNKolom(M) / size;

    if (getNBaris(M) % size != 0 || getNKolom(M) % size != 0){
        printf("ERROR\n");
        return M2;
    }

    for (int i = 1; i <= Baris; i++){
        for (int j = 1; j <= Kolom; j++){
            int max = -999; 
            for (int bi = 1; bi <= size; bi++){
                for (int bj = 1; bj <= size; bj++){
                    int row = (i-1)*size + bi;
                    int col = (j-1)*size + bj;
                    if (M.cell[row][col] > max){
                        max = M.cell[row][col];
                    }
                }
            }
            M2.cell[i][j] = max;
        }
    }
	M2.nbaris = Baris;
    M2.nkolom = Kolom;

    return M2;
}


/* function avgPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size){
	Matriks M2;
	initMatriks(&M2);

	int baris = getNBaris(M) /size;
	int kolom = getNKolom(M) / size;

	if(getNBaris(M) % size != 0 || getNKolom(M) % size != 0){
		printf("ERROR");
		return M2;
	}

	for(int i = 1;i <= baris;i++){
		for(int j = 1;j <= kolom;j++){
			int avg = 0;
			for(int bi = 1;bi <= size;bi++){
				for(int bj = 1;bj <= size;bj++){
					int row = (i-1)*size + bi;
					int col = (j-1)*size + bj;
					avg = M.cell[row][col] + avg;
				}
			}
			M2.cell[i][j] = avg / (size*size);
		}
	}
	M2.nbaris = baris;
    M2.nkolom = kolom;

    return M2;

}

/* function conv(M: Matriks, K:Matriks)
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K) {
    Matriks M2;
	initMatriks(&M2);
    M2.nbaris = getNBaris(M) - getNBaris(K) + 1;
    M2.nkolom = getNKolom(M) - getNKolom(K) + 1;

    for (int i = 1; i <= getNBaris(M2); i++) {
        for (int j = 1; j <= getNKolom(M2); j++) {
            int sum = 0;
            for (int ki = 1; ki <= getNBaris(K); ki++) {
                for (int kj = 1; kj <= getNKolom(K); kj++) {
                    sum += M.cell[i + ki - 1][j + kj - 1] * K.cell[ki][kj];
                }
            }
            M2.cell[i][j] = sum;
        }
    }
    return M2;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col){
    *row = -999;
    *col = -999;
    boolean found = false;
    for(int i = 1; i <= getNBaris(M) && !found; i++){
        for(int j = 1; j <= getNKolom(M) && !found; j++){
            if(M.cell[i][j] == X){
                *row = i;
                *col = j;
                found = true;
            }
        }
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X){
	int count = 0;
    for(int i = 1; i <= getNBaris(M); i++){
        for(int j = 1; j <= getNKolom(M); j++){
            if(M.cell[i][j] == X){
				count++;
            }
        }
    }
	return count;
}
