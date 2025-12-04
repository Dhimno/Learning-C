/* File         : list3.c */
/* Deskripsi    : realisasi body ADT list berkait dengan representasi fisik pointer */
/* NIM/Nama   	: 24060124120010/Dhimas Reza Nafi Wahyudi */
/* Tanggal    	: 20 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"
#include "boolean.h" 

/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) //representasi fisik fungsi
{	// Kamus Lokal
	address P;
	// Algoritma
	P = (address)malloc(sizeof(Elm));
	if (P != NIL) {
        info(P) = E;
		next(P) = NIL;
		prev(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	toggle: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    // Kamus Lokal

    // Algoritma
    free(*P);
    *P = NIL;
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {toggle: membuat list kosong}*/
void CreateList (List3 *L){
    // Kamus Lokal

    // Algoritma
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L){
    // Kamus Lokal

    // Algoritma
    return (First(L) == NIL);
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L){
    // Kamus Lokal
    address P;
    
    // Algoritma
    if (IsEmptyList(L)) // Jika list tidak empty
    {
        printf("List kosong\n");
    } else
    {
        P = First(L);
        while (P != NIL)
        {
            printf("%c ", info(P));
            P = next(P);
        } // end while ketika P = NIL
        printf("\n");
    }
    
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L){
    // Kamus Lokal
    int n;
    address P;

    // Algoritma
    n = 0;
    P = First(L);
    while (P != NIL)
    {
        n++;
        P = next(P);
    } // End While ketika P = NIL
    return n;
    
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ){
    // Kamus Lokal
    address P;
    // Algoritma
    P = Alokasi(V);
    if (P != NIL) // Jika alamat P tidak kosong
    {
        next(P) = First(*L);
        prev(P) = NIL;
        if (First(*L) != NIL) // Jika element pertama dalam list ada / tidak kosong
        {
            prev(First(*L)) = P;
        }
        First(*L) = P; // Jika kosong langsung diisi P
        
    }
    
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ){
    // Kamus Lokal
    address P, Last;
    // Algoritma
    P = Alokasi(V);
    if (P != NIL) // Jika P tidak sama dengan NIL
    {
        if (IsEmptyList(*L)) // Jika list empty
        {
            First(*L) = P;
            next(P) = NIL;
            prev(P) = NIL;
        } else
        {
            Last = First(*L);
            while (next(Last) != NIL)
            {
                Last = next(Last);
            } // end while ketika next(Last) = NIL
            next(Last) = P;
            prev(P) = Last;
            next(P) = NIL;
        }
        
    }
    
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V){
    // Kamus Lokal
    address P;
    // Algoritma
    *V = '#';
    if (IsEmptyList(*L)){

    } else {
        P = First(*L);
        *V = info(P);
        if (next(P) == NIL) { // Jika satu element
            First(*L) = NIL;
        } else { // Jika lebih dari satu element
            First(*L) = next(P);
            prev(First(*L)) = NIL;
        }
        Dealokasi(&P);
    }
    
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V){
    // Kamus Lokal
    address P, Last;
    // Algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        if (next(P) == NIL) {
            *V = info(P);
            First(*L) = NIL;
            Dealokasi(&P);
        } else {
            while (next(P) != NIL) {
                P = next(P);
            }
            *V = info(P);
            next(prev(P)) = NIL;
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ toggle: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X){
    // Kamus Lokal
    address P;
    infotype temp;
    boolean selesai;
    // Algoritma
    selesai = false;
    P = First(*L);
    if (!IsEmptyList(*L)) { // Jika list tidak kosong
        while (P != NIL && !selesai) {
            if (info(P) == X) { // Jika info(P) = X
                if (P == First(*L)) { // Jika P = First(*L)
                    DeleteVFirst(L, &temp);
                    selesai = true;
                } else if (next(P) == NIL) { // Jika next(P) = NIL
                    DeleteVLast(L, &temp);
                    selesai = true;
                } else { // Jika kondisi tidak memenuhi kedua atas
                    next(prev(P)) = next(P);
                    prev(next(P)) = prev(P);
                    Dealokasi(&P);
                    selesai = true;
                }
            } else { // Info(P) != X
                P = next(P);
            }
        } // end while ketika P = NIL or selesai = true/1
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ toggle : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A){
    // Kamus Lokal
    address P;
    boolean selesai;
    // Algoritma
    *A = NIL;
    selesai = false;
    P = First(L);
    while (P != NIL && !selesai) {
        if (info(P) == X) { // Jika info(P) = X
            *A = P;
            selesai = true;
        } else { // Jika info(P) != X
            P = next(P);
        }
    } // end while ketika P = NIL or selesai = true
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ toggle : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y){
    // Kamus Lokal
    address P;
    // Algoritma
    P = First(*L);
    while (P != NIL) {
        if (info(P) == X){ // Jika info(P) = X
            info(P) = Y;
        }
        P = next(P);
    } // end while ketika P = NIL
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L){
    // kamus lokal
    address P, temp;
    boolean toggle;
    // algoritma
    toggle = true;
    if (IsEmptyList(*L)) { // Jika list empty
        toggle = false;
    }
    if (toggle) { // Jika toggle = true
        if (next(First(*L)) == NIL) { // Jika next(First(*L)) == NIL
            toggle = false;
        }
    }
    if (toggle) { // Jika toggle = true
        P = First(*L);
        while (P != NIL) {
            temp = next(P);
            next(P) = prev(P);
            prev(P) = temp;
            P = temp;
        } // end while ketika P = NIL
        P = First(*L);
        while (prev(P) != NIL) {
            P = prev(P);
        } // end while ketika prev(P) = NIL
        First(*L) = P;
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V){
    // Kamus Lokal
    address P, Q;
    boolean selesai;
    // Algoritma
    selesai = false;
    if (!IsEmptyList(*L)) { // Jika list tidak empty
        P = First(*L);
        while (P != NIL && !selesai) {
            if (info(P) == X) { // Jika info(P) == X
                Q = Alokasi(V);
                if (Q != NIL) { // Jika Q != NIL
                    next(Q) = next(P);
                    prev(Q) = P;
                    if (next(P) != NIL) { // Jika next(P) != NIL
                        prev(next(P)) = Q;
                    }
                    next(P) = Q;
                }
                selesai = true;
            } else { // Jika Info(P) != X
                P = next(P);
            }
        } // end while ketika P = NIL or selesai = true
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V){
    // Kamus Lokal
    address P, Q;
    boolean toggle;
    // Algoritma
    toggle = true;
    if (IsEmptyList(*L)) { // Jika list empty
        toggle = false;
    }
    if (toggle) { // Jika toggle = true
        P = First(*L);
        while (P != NIL && toggle) {
            if (info(P) == X) { // Jika info(P) = X
                Q = Alokasi(V);
                if (Q != NIL) { // Jika Q != NIL
                    next(Q) = P;
                    prev(Q) = prev(P);
                    if (prev(P) != NIL) { // Jika prev(P) != NIL
                        next(prev(P)) = Q;
                    } else { // Jika prev(P) = NIL
                        First(*L) = Q;
                    }
                    prev(P) = Q;
                }
                toggle = false;
            } else { // Jika info(P) != X
                P = next(P);
            }
        } // end while ketika P = NIL or toggle = false
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V){
    // Kamus Lokal
    address P, Del;
    boolean toggle;
    // Algoritma
    *V = '#';
    toggle = true;
    if (IsEmptyList(*L)) { // Jika list emptry
        toggle = false;
    }
    if (toggle) { // Jika toggle = true
        P = First(*L);
        while (P != NIL && toggle) {
            if (info(P) == X && next(P) != NIL) { // Jika info(P) == X and next(P) != NIL
                Del = next(P);
                *V = info(Del);
                next(P) = next(Del);
                if (next(Del) != NIL) { // Jika next(Del) != NIL
                    prev(next(Del)) = P;
                }
                Dealokasi(&Del);
                toggle = false;
            } else {
                P = next(P);
            }
        } // end while ketika P = NIL or toggle = false
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V){
    // Kamus Lokal
    address P, Del;
    boolean toggle;
    // Algoritma
    *V = '#';
    toggle = true;
    if (IsEmptyList(*L)) { // Jika list empty
        toggle = false;
    }
    if (toggle) { // Jika toggle = true
        P = First(*L);
        while (P != NIL && toggle) {
            if (info(P) == X && prev(P) != NIL) { // Jika info(P) == X && prev(P) != NIL
                Del = prev(P);
                *V = info(Del);
                if (prev(Del) != NIL) { // Jika prev(Del) != NIL
                    next(prev(Del)) = P;
                    prev(P) = prev(Del);
                } else { // Jika prev(Del) = NIL
                    First(*L) = P;
                    prev(P) = NIL;
                }
                Dealokasi(&Del);
                toggle = false;
            } else { // Jika info(P) != X or prev(P) = NIL
                P = next(P);
            }
        } // end while ketika P = NIL or !toggle
    }
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X){
    // Kamus Lokal
    int count;
    address P;
    // Algoritma
    count = 0;
    P = First(L);
    while (P != NIL) {
        if (info(P) == X){ // Jika Info(P) = X
            count++;
        } 
        P = next(P);
    } // end while ketika P = NIL
    return count;
}


/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X){
    // Kamus Lokal
    int total;
    // Algoritma
    total = NbElm(L);
    if (total == 0){
        return 0.0f;
    } 
    return (float)CountX(L, X) / (float) total;
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L){
    // Kamus Lokal
    int max, c;
    address P;
    // Algoritma
    max = 0;
    P = First(L);
    while (P != NIL) {
        c = CountX(L, info(P));
        if (c > max){ // ketika C > Max
            max = c;
        } 
        P = next(P);
    } // end while ketika P = NIL
    return max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L){
    // Kamus Lokal
    char m;
    int max, c;
    address P;
    // Algoritma
    if (IsEmptyList(L)) // Jika list empty
        return '#';
    m = info(First(L));
    max = 0;
    P = First(L);
    while (P != NIL) {
        c = CountX(L, info(P));
        if (c > max) { // Jika c > max
            max = c;
            m = info(P);
        }
        P = next(P);
    } // end while ketika P = NIL
    return m;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L){
    // Kamus Lokal
    int count;
    address P;
    char c;
    // Algoritma
    count = 0;
    P = First(L);
    while (P != NIL) { 
        c = info(P);
        if (c=='A'||c=='I'||c=='U'||c=='E'||c=='O'|| c=='a'||c=='i'||c=='u'||c=='e'||c=='o') {
            count++; // Jika terindikasi ada huruf vokal
        } 
        P = next(P);
    } // end while ketika P = NIL
    return count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L){
    // Kamus Lokal
    int count;
    address P;
    // Algoritma
    count = 0;
    P = First(L);
    while (P != NIL && next(P) != NIL) {
        if (info(P) == 'N' && info(next(P)) == 'G'){ // Ketika huruf N diikuti huruf G
            count++;
        } 
        P = next(P);
    } // end while ketika P = NIL or next(P) = NIL
    return count;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ toggle: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X){
    // Kamus Lokal
    int idx;
    address P;
    boolean toggle, ketemu;
    // Algoritma
    idx = 1;
    ketemu = false;
    toggle = true;
    if (IsEmptyList(L)) { // Jika list emptry
        printf("0\n");
        toggle = false;
    }
    if (toggle) { // Jika
        P = First(L);
        while (P != NIL) {
            if (info(P) == X) {
                printf("%d ", idx);
                ketemu = true;
            }
            idx++;
            P = next(P);
        }
        if (!ketemu) {
            printf("0");
        }
        printf("\n");
    }
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ toggle: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X){
    // Kamus Lokal

    // Algoritma
    while (CountX(*L, X) > 0) {
        DeleteX(L, X);
    } // end while ketika jumlah X dalam list 0
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L){
    // Kamus Lokal
    address P;
    // Algoritma
    CreateList(L);
    P = First(L1);
    while (P != NIL) { 
        InsertVLast(L, info(P));
        P = next(P);
    } // end while ketika P = NIL
    P = First(L2);
    while (P != NIL) {
        InsertVLast(L, info(P));
        P = next(P);
    } // end while ketika P = NIL
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2){
    // Kamus Lokal
    int n, mid, i;
    address P;
    // Algoritma
    CreateList(L1);
    CreateList(L2);
    n = NbElm(L);
    mid = n / 2;
    P = First(L);
    if (n > 0) { // Jika n lebih dari 0
        for (i = 1; i <= mid && P != NIL; i++) {
            InsertVLast(L1, info(P));
            P = next(P);
        } 
        while (P != NIL) {
            InsertVLast(L2, info(P));
            P = next(P);
        } // end while ketika P = NIL
    }
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2){
    // Kamus Lokal
    address P;
    // Algoritma
    CreateList(L2);
    P = First(L1);
    while (P != NIL) {
        InsertVLast(L2, info(P));
        P = next(P);
    } // end while ketika. P = NIL
}