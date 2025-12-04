/* File : mtqueue3.c */
/* Deskripsi : Program utama untuk mengetes ADT Queue3 */
/* NIM/Nama  : 24060124120010/Dhimas Reza Nafi Wahyudi */
/* Tanggal   : 9 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue3.c"

int main() {
    // kamus
    tqueue3 Q;
    char E;

    // algoritma
    createQueue3(&Q);
    printf("==================================================\n");
    printf("           PROGRAM TESTING ADT QUEUE III          \n");
    printf("==================================================\n");

    printf("\nMembuat Queue baru...\n");
    printQueue3(Q);
    printf("\n==================================================\n");

    printf("Apakah Queue kosong? %s\n", isEmptyQueue3(Q) ? "Ya" : "Tidak");
    printf("==================================================\n");

    printf("Menambahkan elemen: A, B, C\n");
    enqueue3(&Q, 'A');
    enqueue3(&Q, 'B');
    enqueue3(&Q, 'C');

    printf("Isi Queue (wadah): ");
    printQueue3(Q);
    printf("\nIsi Queue (elemen aktif): ");
    viewQueue3(Q);
    printf("\n==================================================\n");

    printf("Head: %d | Tail: %d\n", head3(Q), tail3(Q));
    printf("InfoHead: %c | InfoTail: %c\n", infoHead3(Q), infoTail3(Q));
    printf("==================================================\n");

    printf("Ukuran Queue: %d\n", sizeQueue3(Q));
    printf("Apakah satu elemen? %s\n", isOneElement3(Q) ? "Ya" : "Tidak");
    printf("Apakah penuh? %s\n", isFullQueue3(Q) ? "Ya" : "Tidak");
    printf("==================================================\n");

    printf("Menghapus 1 elemen (dequeue)...\n");
    dequeue3(&Q, &E);
    printf("Elemen yang dihapus: %c\n", E);
    printf("Isi Queue: ");
    viewQueue3(Q);
    printf("\n==================================================\n");

    printf("Menambah elemen lagi: D, E, F\n");
    enqueue3(&Q, 'D');
    enqueue3(&Q, 'E');
    enqueue3(&Q, 'F');
    viewQueue3(Q);
    printf("\n==================================================\n");

    printf("Apakah tail di depan head? %s\n", isTailOverHead(Q) ? "Ya" : "Tidak");
    printf("==================================================\n");

    printf("Mengosongkan Queue...\n");
    while (!isEmptyQueue3(Q)) {
        dequeue3(&Q, &E);
        printf("Menghapus: %c\n", E);
    }

    printf("==================================================\n");
    printf("Queue akhir:\n");
    printQueue3(Q);
    printf("\nApakah Queue kosong? %s\n", isEmptyQueue3(Q) ? "Ya" : "Tidak");
    printf("==================================================\n");

    return 0;
}
