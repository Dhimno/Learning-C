/*Nama File 	: JumFrekNilTabel.c*/
/*Deskripsi 	: mengoutputkan nilai-nilai dalam tabel yang frekuensinya lebih dari satu*/
/*Pembuat   	: <24060124120010-Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <08-04-2025 dan 08:03>*/

# include <stdio.h> /*header file*/

int main() /*Program Utama*/
{

    /*Kamus*/
    int i;
    int N;
    int j;
    int T[10];
    int Frek;
    int Sum;

    /*Algoritma*/
    printf("Masukkan banyak elemen yang diinginkan: ");
    scanf("%d", &N);

    if (N < 2)
    {
        printf("Banyak elemen harus lebih dari 1");
    }
    else
    {
        T[N];
        printf("Masukkan nilai elemen:\n");
        for (i = 0; i < N; i++)
        {
            scanf("%d", &T[i]);
            if (T[i] <= 0)
            {
                printf("Masukkan nilai harus lebih dari 0\n");
                i--;
            }
        }

        Sum = 0;
        printf("Jumlah nilai frekuensi yang muncul lebih dari sekali:");
        for (i = 0; i < N; i++)
        {
            if (T[i] > 0)
            {
                Frek = 0;
                for (j = 0; j < N; j++)
                {
                    if (T[i] == T[j])
                    {
                        Frek = Frek + 1;
                    }
                }

                if (Frek > 1)
                {
                    printf(" + %d", T[i]);
                    Sum = Sum + T[i];
                }
            }
        }
    }

    printf(" = %d", Sum);

    return 0;
}