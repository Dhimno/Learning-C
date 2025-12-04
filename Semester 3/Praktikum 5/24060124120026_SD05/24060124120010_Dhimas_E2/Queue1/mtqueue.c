/* Program   : mtqueue.c */
/* Deskripsi : driver ADT Queue kontigu */
/* NIM/Nama  : 24060124120010/Dhimas Reza Nafi Wahyudi */
/* Tanggal   : 2 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue.c"

int main() {
    /* kamus */
    tqueue Q1, Q2;
    char e;

    /* algoritma */
    printf("===========================================\n");
    printf("        PROGRAM UJI COBA ADT QUEUE \n");
    printf("===========================================\n");

    printf("===========================================\n");
    printf("           Test createQueue \n");
    printf("===========================================\n");
    createQueue(&Q1);
    createQueue(&Q2);
    printQueue(Q1);
    printf("isEmptyQueue(Q1) = %d\n", isEmptyQueue(Q1));
    printf("isFullQueue(Q1)  = %d\n", isFullQueue(Q1));
    printf("sizeQueue(Q1)    = %d\n", sizeQueue(Q1));

    printf("===========================================\n");
    printf("              Test enqueue \n");
    printf("===========================================\n");
    enqueue(&Q1, 'A');
    enqueue(&Q1, 'B');
    enqueue(&Q1, 'C');
    enqueue(&Q1, 'D');
    enqueue(&Q1, 'E');
    printQueue(Q1);
    printf("ViewQueue(Q1): ");
    viewQueue(Q1);
    printf("Head = %d, Tail = %d\n", head(Q1), tail(Q1));
    printf("infoHead = %c, infoTail = %c\n", infoHead(Q1), infoTail(Q1));

    printf("===========================================\n");
    printf("              Test dequeue \n");
    printf("===========================================\n");
    dequeue(&Q1, &e);
    printf("Elemen yang diambil = %c\n", e);
    printQueue(Q1);
    printf("ViewQueue(Q1): ");
    viewQueue(Q1);
    printf("sizeQueue(Q1) = %d\n", sizeQueue(Q1));

    printf("===========================================\n");
    printf("         Test dequeue hingga kosong \n");
    printf("===========================================\n");
    while (!isEmptyQueue(Q1)) {
        dequeue(&Q1, &e);
        printf("Keluar: %c | Sisa Queue: ", e);
        viewQueue(Q1);
    }
    printf("Q1 sekarang kosong\n");

    printf("===========================================\n");
    printf("           Test isOneElement \n");
    printf("===========================================\n");
    enqueue(&Q1, 'X');
    if (isOneElement(Q1)) {
        printf("Q1 berisi satu elemen: %c\n", infoHead(Q1));
    }

    printf("===========================================\n");
    printf("       Test enqueue2 dan dequeue2 \n");
    printf("===========================================\n");
    enqueue2(&Q1, &Q2, 'P');
    enqueue2(&Q1, &Q2, 'Q');
    enqueue2(&Q1, &Q2, 'R');
    enqueue2(&Q1, &Q2, 'S');
    enqueue2(&Q1, &Q2, 'T');

    printf("Isi Q1: "); viewQueue(Q1);
    printf("Isi Q2: "); viewQueue(Q2);

    printf("Dequeue2 beberapa kali...\n");
    dequeue2(&Q1, &Q2, &e);
    printf("Keluar: %c\n", e);
    dequeue2(&Q1, &Q2, &e);
    printf("Keluar: %c\n", e);
    dequeue2(&Q1, &Q2, &e);
    printf("Keluar: %c\n", e);

    printf("Isi Q1 sekarang: "); viewQueue(Q1);
    printf("Isi Q2 sekarang: "); viewQueue(Q2);

    return 0;
}
