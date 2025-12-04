/*Nama File     : JumBarKolMat.c*/
/*Deskripsi     : Menjumlahkan semua elemen pada baris dan kolom dari tabel*/
/*Pembuat   	: <24060124120010-Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <08-04-2025 dan 08:25>*/

# include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{
    /*Kamus*/
    int i;
    int j;
    int T[10][10];
    int baris;
    int kolom;
    int sumBaris;
    int sumKolom;
    
    /*Algoritma*/
    printf("Masukkan jumlah elemen baris matriks: ");
    scanf("%d", &baris);
    printf("Masukkan jumlah elemen kolom matriks: ");
    scanf("%d", &kolom);
    
    if (baris < 1 || kolom < 1)
    {
        printf("Masukkan jumlah baris dan kolom lebih dari 0");
    }
    else
    {
        printf("Masukkan nilai elemen matriks\n");
        for (i = 0; i < baris; i++)
        {
            for (j = 0; j < kolom; j++)
            {
                printf("T[%d][%d] = ", i+1, j+1);
                scanf("%d", &T[i][j]);
                if (T[i][j] <= 0)
                {
                    printf("Masukkan nilai elemen matriks lebih dari 0\n");
                    j--;
                }
            }
        }
        
        // Menampilkan matriks
        printf("\nMatriks T:\n");
        for (i = 0; i < baris; i++)
        {
            for (j = 0; j < kolom; j++)
            {
                printf("%d ", T[i][j]);
            }
            printf("\n");
        }
        
        // Menghitung dan menampilkan jumlah setiap baris
        printf("\n");
        for (i = 0; i < baris; i++)
        {
            sumBaris = 0;
            for (j = 0; j < kolom; j++)
            {
                sumBaris = sumBaris + T[i][j];
            }
            printf("Baris ke-%d => ", i+1);
            
            // Menampilkan penjumlahan elemen baris
            for (j = 0; j < kolom; j++)
            {
                printf("%d", T[i][j]);
                if (j < kolom - 1)
                {
                    printf("+");
                }
            }
            printf("=%d\n", sumBaris);
        }
        
        // Menghitung dan menampilkan jumlah setiap kolom
        printf("\n");
        for (j = 0; j < kolom; j++)
        {
            sumKolom = 0;
            for (i = 0; i < baris; i++)
            {
                sumKolom = sumKolom + T[i][j];
            }
            printf("Kolom ke-%d => ", j+1);
            
            // Menampilkan penjumlahan elemen kolom
            for (i = 0; i < baris; i++)
            {
                printf("%d", T[i][j]);
                if (i < baris - 1)
                {
                    printf("+");
                }
            }
            printf("=%d\n", sumKolom);
        }
    }
    
    return 0;
}