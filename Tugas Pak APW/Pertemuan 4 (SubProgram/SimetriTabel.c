/*Nama File 	: SimetriTabel.c*/
/*Deskripsi 	: Menentukan apakah sebuah tabel simetris atau tidak*/
/*Pembuat   	: <24060124120010-Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <08-04-2025 dan 08:13>*/

# include <stdio.h> /*header file*/

/*Program Utama*/
int main() 
{

    /*Kamus*/
    int i;
    int T1[100];
    int T2[100];
    int N1;
    int N2;
    int j;
    int sum;

    /*Algoritma*/
    printf("Masukkan Banyak elemen tabel T1: ");
    scanf("%d", &N1);

    printf("Masukkan Banyak elemen tabel T2: ");
    scanf("%d", &N2);

    T1[N1];
    T2[N2];

    if (N1 < 1 || N2 < 1)
    {
        printf("Masukkan banyak anggota tabel T1 dan T2 lebih dari 0");
    }
    else
    {
        printf("Masukkan nilai elemen tabel T1\n");
        for (i = 0; i < N1; i++)
        {
            scanf("%d", &T1[i]);
            if (T1[i] <= 0)
            {
                printf("Masukkan nilai elemen tabel T1 lebih dari 0");
                i--;
            }
        }

        printf("Masukkan nilai elemen tabel T2\n");
        for (i = 0; i < N2; i++)
        {
            scanf("%d", &T2[i]);
            if (T2[i] <= 0)
            {
                printf("Masukkan nilai elemen tabel T2 lebih dari 0");
                i--;
            }
        }

        for (i = 0; i < N1; i++)
        {
            if (T1[i] > 0)
            {
                j = i;
                if (N1 == N2)
                {
                    if (T1[i] == T2[j])
                    {
                        sum = sum + 1;
                    }
                }
            }
        }
    }

    if (sum == N1)
    {
        printf("T1 dan T2 Simetris");
    }
    else
    {
        printf("T1 dan T2 Tidak Simetris");
    }

    return 0;
}
