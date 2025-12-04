/*Nama File     : isiMatrik.c*/
/*Deskripsi     : Mengisikan nilai pada elemen matrik yang ber-ordo sama dengan aturan bahwa nilai 1 diisikan pada diagonal utama matrik, nilai 0 diiskan pada bagian diatas diagonal utama matrik, 2 diisikan pada elemen yang dibawah diagonal utama*/
/*Pembuat   	: <24060124120010-Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <08-04-2025 dan 09:12>*/

# include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{
    /*Kamus*/
    int i;
    int j;
    int M;
    int N;
    int T[10][10];
    
    /*Algoritma*/
    printf("Masukkan jumlah elemen baris (M): ");
    scanf("%d", &M);
    printf("Masukkan jumlah elemen kolom (N): ");
    scanf("%d", &N);
    
    if (M < 1 || N < 1)
    {
        printf("Nilai M dan N harus lebih dari 0");
    }
    else if (M != N)
    {
        printf("Nilai M dan N harus sama");
    }
    else
    {
        // Mengisi nilai matriks berdasarkan posisi relatif terhadap diagonal utama
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (i == j)
                {
                    // Diagonal utama
                    T[i][j] = 1;
                }
                else if (i < j)
                {
                    // Di atas diagonal utama
                    T[i][j] = 0;
                }
                else
                {
                    // Di bawah diagonal utama
                    T[i][j] = 2;
                }
            }
        }
        
        // Menampilkan matriks
        printf("\nMatriks hasil:\n");
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("%d ", T[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}