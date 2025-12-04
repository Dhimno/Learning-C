#include <stdio.h>

void bubbleSort(int arr[], int N){
    int pass, K, temp;
    for (pass = 1; pass < N; pass++)
    {
        for (K = N-1; K >= pass; K--)
        {
            if (arr[K]<arr[K-1])
            {
                temp = arr[K];
                arr[K] = arr[K-1];
                arr[K-1] = temp;
            }
            
        }
        
    }
    
}

float cariNilaiTengah(int arr[], int N) {
    if (N == 0) return 0;
    if (N % 2 == 1) {
        return arr[N / 2];
    } else {
        return (arr[N / 2 - 1] + arr[N / 2]) / 2.0;
    }
}

int main() {
    int N;
    scanf("%d", & N);
    int totalData[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", & totalData[i]);
    }

    bubbleSort(totalData, N);

    int totalGenap = 0;
    int totalGanjil = 0;

    for (int i = 0; i < N; i++) {
        if (totalData[i] % 2 == 0)
            totalGenap++;
        else
            totalGanjil++;
    }

    int arrGenap[totalGenap];
    int arrGanjil[totalGanjil];
    int indexGenap = 0, indexGanjil = 0;

    for (int i = 0; i < N; i++) {
        if (totalData[i] % 2 == 0)
            arrGenap[indexGenap++] = totalData[i];
        else
            arrGanjil[indexGanjil++] = totalData[i];
    }

    float medianGenap = cariNilaiTengah(arrGenap, totalGenap);
    float medianGanjil = cariNilaiTengah(arrGanjil, totalGanjil);
    float hasil = (medianGenap + medianGanjil) / 2;

    printf("%.3f\n", hasil);
    return 0;
}