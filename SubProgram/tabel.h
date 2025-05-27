#ifndef TABEL_H
#define TABEL_H

#include "boolean.h"

typedef int ElmtType;
typedef int IdxType;

#define IdxMax 100
#define IdxMin 1

typedef struct {
    ElmtType TI[IdxMax - IdxMin + 1];  /* Tabel */
    int NEff;                          /* Indeks efektif tabel */
} TabInt;

// Function Prototypes
void CreateEmpty(TabInt* T);
boolean IsIdxValid(TabInt T, IdxType i); // Pass TabInt to check bounds
boolean IsIdxEff(TabInt T, IdxType i);
boolean IsEmpty(TabInt T);
boolean IsFull(TabInt T);
void PrintTabel(TabInt T);
void IsiTabel(TabInt* T, ElmtType N);
ElmtType ValMax(TabInt T);
ElmtType ValMin(TabInt T);
IdxType IdxValMax(TabInt T);
IdxType IdxValMin(TabInt T);

#endif // TABEL_H
