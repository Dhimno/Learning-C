/* Program   : mtqueue2.c */
/* Deskripsi : driver ADT Queue versi 2 */
/* NIM/Nama  : Dhimas Reza Nafi Wahyudi/24060124120010 */
/* Tanggal   : 2 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue2.c"

int main() {
    /* kamus */
    tqueue2 Q1, Q2;
    char e;
    
    /* algoritma */
    printf("===========================================\n");
    printf("        PROGRAM UJI COBA ADT QUEUE2 \n");
    printf("===========================================\n");

    printf("===========================================\n");
    printf("           Test createQueue2 \n");
    printf("===========================================\n");
    createQueue2(&Q1);
    printQueue2(Q1);
    printf("isEmptyQueue2(Q1) = %d\n", isEmptyQueue2(Q1));
    printf("isFullQueue2(Q1)  = %d\n", isFullQueue2(Q1));
    printf("sizeQueue2(Q1)    = %d\n", sizeQueue2(Q1));

    printf("===========================================\n");
    printf("              Test enqueue2 \n");
    printf("===========================================\n");
    enqueue2(&Q1, 'A');
    enqueue2(&Q1, 'B');
    enqueue2(&Q1, 'C');
    enqueue2(&Q1, 'D');
    enqueue2(&Q1, 'E');
    viewQueue2(Q1);
    printf("Head = %d, Tail = %d\n", head2(Q1), tail2(Q1));
    printf("infoHead = %c, infoTail = %c\n", infoHead2(Q1), infoTail2(Q1));

    printf("===========================================\n");
    printf("              Test dequeue2 \n");
    printf("===========================================\n");
    dequeue2(&Q1, &e);
    printf("Elemen yang diambil = %c\n", e);
    viewQueue2(Q1);
    printf("Head = %d, Tail = %d\n", head2(Q1), tail2(Q1));
    printf("sizeQueue2(Q1) = %d\n", sizeQueue2(Q1));

    printf("===========================================\n");
    printf("         Test dequeue2 hingga kosong \n");
    printf("===========================================\n");
    while (!isEmptyQueue2(Q1)) {
        dequeue2(&Q1, &e);
        printf("Keluar: %c | Sisa Queue: ", e);
        viewQueue2(Q1);
    }
    printf("Q1 sekarang kosong\n");

    printf("===========================================\n");
    printf("           Test isOneElement2 \n");
    printf("===========================================\n");
    enqueue2(&Q1, 'X');
    if (isOneElement2(Q1)) {
        printf("Q1 berisi satu elemen: %c\n", infoHead2(Q1));
    }

    printf("===========================================\n");
    printf("           Test enqueue2N \n");
    printf("===========================================\n");
    enqueue2N(&Q1, 2); // input manual
    printf("Isi Q1 sekarang: ");
    viewQueue2(Q1);
    printf("Head = %d, Tail = %d\n", head2(Q1), tail2(Q1)); 
    printf("infoHead = %c, infoTail = %c\n", infoHead2(Q1), infoTail2(Q1));

    printf("===========================================\n");
    printf("    Test isTailStop dan resetHead \n");
    printf("===========================================\n");
    while (!isFullQueue2(Q1)) {
        enqueue2(&Q1, 'Z');
    }
    printf("Isi penuh: ");
    viewQueue2(Q1);
    printf("Tail stop? %d\n", isTailStop(Q1));
    resetHead(&Q1);
    printf("Setelah resetHead: ");
    viewQueue2(Q1);

    printf("===========================================\n");
    printf("       Test enqueue2 & dequeue2 Q2 \n");
    printf("===========================================\n");
    createQueue2(&Q2);
    enqueue2(&Q2, 'P');
    enqueue2(&Q2, 'R');
    enqueue2(&Q2, 'T');
    printf("Isi Q2: ");
    viewQueue2(Q2);

    printf("Dequeue2 beberapa kali...\n");
    dequeue2(&Q1, &e); printf("Keluar: %c\n", e);
    dequeue2(&Q2, &e); printf("Keluar: %c\n", e);
    dequeue2(&Q1, &e); printf("Keluar: %c\n", e);
    printf("Isi Q1 sekarang: "); viewQueue2(Q1); 
    printf("Isi Q2 sekarang: "); viewQueue2(Q2); 

    printf("===========================================\n");
    printf("          Test isEqualQueue2 \n");
    printf("===========================================\n");
    if (isEqualQueue2(Q1, Q2))
        printf("Q1 dan Q2 sama\n");
    else
        printf("Q1 dan Q2 berbeda\n");

    printf("===========================================\n");
    printf("   Test printQueue2 kondisi akhir \n");
    printf("===========================================\n");
    printQueue2(Q1);
    printQueue2(Q2);

    return 0;
}
