/************************************/
/* Program   : titik.c */
/* Deskripsi : realisasi body modul Titik */
/* NIM/Nama  : 24060124120010/Dhimas Reza Nafi Wahyudi*/
/* Tanggal   : 4/September/2025 */
/***********************************/
#include <stdio.h>
#include "titik.h"


void makeTitik(Titik *T, int x, int y){
    T->absis = x;
    T->ordinat = y;
}

void makeTitik0(Titik *T){
    T->absis = 0;
    T->ordinat = 0;
}

int getAbsis(Titik T){
    return T.absis;
}

int getOrdinat(Titik T){
    return T.ordinat;
}

void setAbsis(Titik *T, int x){
    T->absis = x;
}

void setOrdinat(Titik *T, int y){
    T->ordinat = y;
}

boolean isOrigin(Titik T){
    return (T.absis == 0 && T.ordinat == 0);
}

boolean isOnSumbuX(Titik T){
    return (T.ordinat == 0);
}
boolean isOnSumbuY(Titik T){
    return (T.absis == 0);
}
boolean isEqual(Titik T1, Titik T2){
    return (T1.absis == T2.absis && T1.ordinat == T2.ordinat);
}
void Geser(Titik *T, int x, int y){
    T->absis += x;
    T->ordinat += y;
}

void RefleksiX(Titik *T){
    T->absis = -(T->absis);
}

void RefleksiY(Titik *T){
    T->ordinat = -(T->ordinat);
}

void Dilatasi(Titik *T, float k){
    T->absis = T->absis * k;
    T->ordinat = T->ordinat * k;
}

void DilatasiX(Titik *T, Titik X, float k){
    T->absis = X.absis + (T->absis - X.absis) * k;
    T->ordinat = X.ordinat + (T->ordinat - X.ordinat) * k;
}

int Kuadran(Titik T){
    if (T.absis > 0 && T.ordinat > 0) {
        return 1;
    } else if (T.absis < 0 && T.ordinat > 0) {
        return 2;
    } else if (T.absis < 0 && T.ordinat < 0) {
        return 3;
    } else if (T.absis > 0 && T.ordinat < 0) {
        return 4;
    } else {
        return 0; 
    }
}
