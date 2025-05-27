#include <stdio.h>
#include "boolean.h"
#include "tabel.h"

/***************************************************************/
/*                         KONSTRUKTOR                         */
/***************************************************************/
void CreateEmpty(TabInt* T) {
    T->NEff = 0;
}

/***************************************************************/
/*             OPERASI TERHADAP INDEKS TABEL                   */
/***************************************************************/
boolean IsIdxValid(TabInt T, IdxType i) {
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff(TabInt T, IdxType i) {
    return (i >= IdxMin && i <= T.NEff);
}

/***************************************************************/
/*                     PREDIKAT TABEL                          */
/***************************************************************/
boolean IsEmpty(TabInt T) {
    return (T.NEff == 0);
}

boolean IsFull(TabInt T) {
    return (T.NEff == (IdxMax - IdxMin + 1));
}

/***************************************************************/
/*          ISI TULIS, HUBUNGAN DENGAN I/O DEVICE              */
/***************************************************************/
void PrintTabel(TabInt T) {
    if (IsEmpty(T)) {
        printf("Tabel kosong.\n");
    }
}

void IsiTabel(TabInt* T, ElmtType N) {
    if (N > (IdxMax - IdxMin + 1)) {
        printf("Jumlah elemen melebihi kapasitas tabel.\n");
        return;
    }

    T->NEff = N;
    for (int i = 0; i < N; i++) {
        printf("Masukkan elemen ke-%d: ", i + 1);
        scanf("%d", &(T->TI[i]));
    }
}

/***************************************************************/
/*                      NILAI EKSTRIM                          */
/***************************************************************/
ElmtType ValMax(TabInt T) {
    if (IsEmpty(T)) return -1;

    ElmtType max = T.TI[0];
    for (int i = 1; i < T.NEff; i++) {
        if (T.TI[i] > max) {
            max = T.TI[i];
        }
    }
    return max;
}

ElmtType ValMin(TabInt T) {
    if (IsEmpty(T)) return -1;

    ElmtType min = T.TI[0];
    for (int i = 1; i < T.NEff; i++) {
        if (T.TI[i] < min) {
            min = T.TI[i];
        }
    }
    return min;
}

/***************************************************************/
/*                  INDEX NILAI EKSTRIM                        */
/***************************************************************/
IdxType IdxValMax(TabInt T) {
    if (IsEmpty(T)) return -1;

    IdxType idxMax = 0;
    for (int i = 1; i < T.NEff; i++) {
        if (T.TI[i] > T.TI[idxMax]) {
            idxMax = i;
        }
    }
    return idxMax + IdxMin; 
}

IdxType IdxValMin(TabInt T) {
    if (IsEmpty(T)) return -1;

    IdxType idxMin = 0;
    for (int i = 1; i < T.NEff; i++) {
        if (T.TI[i] < T.TI[idxMin]) {
            idxMin = i;
        }
    }
    return idxMin + IdxMin; 
}