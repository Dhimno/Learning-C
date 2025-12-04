/************************************/
/* Program   : tabel.c */
/* Deskripsi : realisasi body modul tabel */
/* NIM/Nama  : 24060124120010/Dhimas Reza Nafi Wahyudi*/
/* Tanggal   : 11/September/2025 */
/***********************************/
#include <stdio.h>
#include "tabel.h"

/************************KONSTRUKTOR*************************/				 
/* procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah dengan 1 karakter spasi, spasi dianggap karakter kosong}
	{Proses: menginisialisasi T} */
void createTable(Tabel *T) {
    int i;
    for (i = 1; i <= 10; i++){
        (*T).wadah[i] = ' ';
    }
    (*T).size = 0;
}

/************************SELEKTOR*************************/
/* function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T) {
    return T.size;
}

/*************************PREDIKAT*************************/
/* function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable(Tabel T){
    return T.size == 0;
}

/* function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable(Tabel T){
    return T.size == 10;
}

/*************************OPERASI PENCARIAN*************************/
/*  procedure searchX (input T:Tabel, input X:character, output pos:integer )
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai x dalam T.wadah} */
void searchX(Tabel T, char x, int *pos){
    int i;
    *pos = -9999;
    i = 1;
    while (i <= getSize(T) && T.wadah[i] != x) {
        i += 1;
    }
    
    if (T.wadah[i] == x) {
        *pos = i;
    }
}

/* function countX (T:Tabel, x:character) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah} */
int countX(Tabel T, char x) {
    int i;
    int count;
    count = 0;
    for (i = 0; i <= getSize(T); i++) {
        if (T.wadah[i] == x) {
            count++;
        }
    }

    return count;
}

/* function countVocal(T: Tabel) -> integer
	{mengembalikan banyak elemen T yang berupa karakter huruf vocal } */
int countVocal(Tabel T) {
    int i;
    int count;
    count = 0;
    for (i = 1; i <= getSize(T); i++) {
        if (T.wadah[i] == 'A' || T.wadah[i] == 'I' || T.wadah[i] == 'U' || T.wadah[i] == 'E' || T.wadah[i] == 'O') {
            count++;
        }
    }

    return count;
}

/*************************MUTATOR*************************/
/* procedure addXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai x}*/
void addXTable(Tabel *T, char x) {
    if (!isFullTable(*T)) {
        (*T).size++;
        (*T).wadah[(*T).size] = x;
    }
}

/* procedure addUniqueXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika x unik dan tabel belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai unik x}*/
void addUniqueXTable(Tabel *T, char x) {
    if (!isFullTable(*T) && countX(*T, x) == 0) {
        addXTable(T, x);
    }
}

/* procedure delXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi, x terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai x, geser semua elemen sisa}*/
void delXTable(Tabel *T, char x) {
    int i, pos = -1;
    for (i = 1; i <= (*T).size; i++) {
        if ((*T).wadah[i] == x) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        delTable(T, pos);
    }
}

/* procedure delTable (input/output T:Tabel, input idx:integer)
	{I.S.: T terdefinisi, idx antara 1...getSize(T)}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen pada posisi idx, geser semua elemen sisa}*/
void delTable(Tabel *T, int idx) {
    int i;
    if (idx >= 1 && idx <= getSize(*T)) {
        for (i = idx; i < getSize(*T); i++) {
            (*T).wadah[i] = (*T).wadah[i+1];
        }
        (*T).wadah[getSize(*T)] = ' ';
        (*T).size--;
    }
}
/* procedure delAllXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable(Tabel *T, char x) {
    int i = 1;
    while (i <= (*T).size) {
        if ((*T).wadah[i] == x) {
            delTable(T, i);
        } else {
            i++;
        }
    }
}

/*************************OPERASI BACA/TULIS*************************/
/* procedure printTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T) {
    int i;
    for (i = 1; i <= 10; i++) {
        printf("[%c]", T.wadah[i]);
    }
    printf("\n");
}

/* procedure viewTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable(Tabel T) {
    int i;
    for (i = 1; i <= getSize(T); i++) {
        printf("[%c]", T.wadah[i]);
    }
    printf("\n");
}

/* procedure populateTable (input/output T:Tabel, input N: integer)
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTable(Tabel *T, int N) {
    int i;
    char c;
    createTable(T);
    for (i = 1; i <= N; i++) {
        printf("Masukkan elemen ke-%d: ", i);
        scanf(" %c", &c);
        addXTable(T, c);
    }
}

/*************************OPERASI STATISTIK*************************/
/*function Modus (T:Tabel ) -> char
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus(Tabel T) {
    int i, j, count, maxCount = 0;
    char modus = ' ';
    for (i = 1; i <= T.size; i++) {
        count = 0;
        for (j = 1; j <= T.size; j++) {
            if (T.wadah[i] == T.wadah[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            modus = T.wadah[i];
        }
    }
    return modus;
}

/*************************OPERASI RELASIONAL*************************/
/* function IsEqualTable (T1:Tabel, T2: Table ) -> boolean 
	{mengembalikan true jika T1 memiliki elemen dan urutan yang sama dengan T2 } */
boolean isEqualTable(Tabel T1, Tabel T2) {
    int i;
    if (getSize(T1) == getSize(T2)) {
        i = 1;
        while (T1.wadah[i] == T2.wadah[i] && i < getSize(T1)) {
            i++;
        }

        if (T1.wadah[i] == T2.wadah[i]) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

/*************************OPERASI LAINNYA*************************/
/* function getInverseTable(T:Tabel) -> Tabel 
	{mengembalikan tabel baru dengan isi elemen yang berkebalikan dengan tabel T } */
Tabel getInverseTable(Tabel T) {
    Tabel Tinv;
    int i;
    createTable(&Tinv);
    Tinv.size = T.size;
    for (i = 1; i <= T.size; i++) {
        Tinv.wadah[i] = T.wadah[T.size - i + 1];
    }
    return Tinv;
}

/* procedure inverseTable(input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah memiliki isi berkabalikan dengan isi tabel semula}
	{Proses: membalik isi elemen pada tabel T}*/
void inverseTable(Tabel *T) {
    int i;
    char temp;
    for (i = 1; i <= (*T).size/2; i++) {
        temp = (*T).wadah[i];
        (*T).wadah[i] = (*T).wadah[(*T).size - i + 1];
        (*T).wadah[(*T).size - i + 1] = temp;
    }
}

/*************************OPERASI PENGURUTAN*************************/
/* procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad awal ke akhir}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad awal ke akhir}*/
void sortAsc(Tabel *T) {
    int i, j;
    char temp;
    for (i = 1; i < (*T).size; i++) {
        for (j = 1; j <= (*T).size - i; j++) {
            if ((*T).wadah[j] > (*T).wadah[j+1]) {
                temp = (*T).wadah[j];
                (*T).wadah[j] = (*T).wadah[j+1];
                (*T).wadah[j+1] = temp;
            }
        }
    }
}

/* procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad akhir ke awal}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad akhir ke awal}*/
void sortDesc(Tabel *T) {
    int i, j;
    char temp;
    for (i = 1; i < (*T).size; i++) {
        for (j = 1; j <= (*T).size - i; j++) {
            if ((*T).wadah[j] < (*T).wadah[j+1]) {
                temp = (*T).wadah[j];
                (*T).wadah[j] = (*T).wadah[j+1];
                (*T).wadah[j+1] = temp;
            }
        }
    }
}