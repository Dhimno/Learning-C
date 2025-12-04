/*Nama File 	: NilMax2Tabel.c*/
/*Deskripsi 	: Menampilkan nilai maksimal yang ke-2 dari tabel array yang disediakan*/
/*Pembuat   	: <24060124120010-Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <08-04-2025 dan 07:41>*/

# include <stdio.h> /*header file*/

/*Program Utama*/

int main() 
{

    /*Kamus*/
    int i; // iterasi
    int N; // Banyak inputan
    int max; // nilai maksimal
    int max2; // nilai maksimal ke-2
    int isMax2; // pengecek apakah ada nilai maksimal ke-2

    /*Algoritma*/
    printf("Masukkan banyak elemen yang diinginkan: ");
    scanf("%d", &N);

    int T[N]; 

    max = 0;
    max2 = 0;
    isMax2 = 0;

    if (N < 2) {
        printf("Banyak elemen dalam tabel harus lebih dari 1\n");
    } else {
        printf("Masukkan elemen:\n");
        for (i = 0; i < N; i++){
            scanf("%d", &T[i]);
            if (T[i] <= 0) {
                printf("Masukkan nilai elemen tabel lebih dari 0\n");
                i--;
            }
        }

        for (i = 0; i < N; i++){
            if (T[i] > 0){
                if (T[i] > max){
                    max2 = max;
                    max = T[i];
                    if (i > 0) {
                        isMax2 = 1;
                    }
                }else if (T[i] > max2 && T[i] != max){
                    max2 = T[i];
                    isMax2 = 1;
                }
            }
        }

        if (isMax2 == 0){
            printf("Tidak ada nilai maksimum ke-2");
        }else {
            printf("Nilai maksimum ke-2 adalah %d", max2);
        }
    }

    return 0;
}