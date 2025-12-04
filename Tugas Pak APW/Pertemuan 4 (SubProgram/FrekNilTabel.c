/*Nama File 	: FrekNilTabel.c*/
/*Deskripsi 	: Mengoutput integer yang frekuensi munculnya lebih dari 1*/
/*Pembuat   	: <24060124120010-Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <08-04-2025 dan 07:51>*/

# include <stdio.h> /*header file*/

/*Program Utama*/

int main() 
{

    /*Kamus*/
    int i; // iterasi
    int j; // iterasi
    int k; // iterasi
    int N; // jumlah inputan
    int Frek; // penyimpan frekuensi
    int isFrek; // pengecek apabila tidak ada frekuensi

    /*Algoritma*/
    printf("Masukkan banyak elemen yang diinginkan: ");
    scanf("%d", &N);

    int T[N];
    isFrek = 1;

    if (N < 2){
        printf("Banyak tabel harus lebih dari 2");
    }else {
        printf("Masukkan nilai elemen tabel:\n");
        for (i = 0; i < N; i++){
            scanf("%d", &T[i]);
            if (T[i] <= 0){
                printf("Masukkan nilai anggota tabel lebih dari 0\n");
                i--;
            }
        }

        printf("Nilai yang memiliki frekuensi lebih dari 1 yaitu");
        for (i = 0; i < N; i++){
            if (T[i] > 0){
                Frek = 0;
                for (j = 0; j < N; j++){
                    if (T[i] == T[j]){
                        Frek = Frek + 1;
                    }
                }

                if (Frek > 1){
                    isFrek = 0;
                    printf(" %d", T[i]);

                    for (k = i + 1; k < N; k++){
                        if (T[i] == T[k]){
                            T[k] = 0;
                        }
                    }
                }
            }
        }
    }

    if (isFrek == 1){
        printf(" tidak ada");
    }

    return 0;
}