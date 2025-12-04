/* File : main.c */
/* Deskripsi : aplikasi driver ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : Dhimas Reza Nafi Wahyudi / 24060124120026 */
/* Tanggal : Kamis, 4 Desember 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon2.c"
#include "pohon1.c"

int main() {
    bintree T, P;
    infotype X, Y;
    int n;

    printf("=============== Uji BinTree =================\n");
    printf("=============================================\n");

    T = Tree('A', AlokasiTree('B'), AlokasiTree('B'));

    if (left(T) != NULL) {
        left(left(T)) = AlokasiTree('D');
        right(left(T)) = AlokasiTree('E');
    }

    printf("Uji PrintTreeInden\n");
    PrintTreeInden(T, 0);
    printf("\n========================================\n");

    printf("Uji PrintLevel\n");
    PrintLevel(T, 3);
    PrintLevel(T, 2);
    printf("\n========================================\n");

    printf("Uji UpdateAllX\n");
    UpdateAllX(&T, 'B', 'X');
    PrintTreeInden(T, 0);
    printf("\n========================================\n");

    printf("Uji AddDaunTerkiri\n");
    AddDaunTerkiri(&T, 'Z');
    PrintTreeInden(T, 0);
    printf("\n========================================\n");

    printf("Uji AddDaun\n");
    AddDaun(&T, 'Z', 'Q', true);
    PrintTreeInden(T, 0);
    printf("\n========================================\n");

    printf("Uji InsertX\n");
    InsertX(&T, 'W');
    PrintTreeInden(T, 0);
    printf("\n========================================\n");

    printf("Uji DelDaunTerkiri\n");
    DelDaunTerkiri(&T, 'Q');
    PrintTreeInden(T, 0);
    printf("\n========================================\n");

    printf("Uji DelDaun\n");
    DelDaun(&T, 'W');
    PrintTreeInden(T, 0);
    printf("\n========================================\n");

    printf("Uji DeleteX\n");
    DeleteX(&T, 'D');
    PrintTreeInden(T, 0);
    printf("\n========================================\n");

    printf("Uji BuildBalanceTree\n");
    n = 3;
    P = BuildBalanceTree(n);
    PrintTreeInden(P, 0);
    printf("\n========================================\n");

    printf("Uji IsBalanceTree\n");
    printf("%d\n", IsBalanceTree(P));
    printf("%d\n", IsBalanceTree(T));
    printf("\n========================================\n");

    printf("Uji maxTree dan minTree\n");
    printf("%c\n", maxTree(P));
    printf("%c\n", minTree(P));
    printf("\n========================================\n");

    printf("Uji BSearch\n");
    printf("%d\n", BSearch(T, 'A'));
    printf("%d\n", BSearch(T, 'X'));
    printf("\n========================================\n");

    printf("Uji InsSearch\n");
    T = InsSearch(T, 'H');
    PrintTreeInden(T, 0);
    printf("\n========================================\n");

    printf("Uji DelBtree\n");
    DelBtree(&T, 'H');
    PrintTreeInden(T, 0);
    printf("\n========================================\n");

    return 0;
}
