#include <stdio.h>

#define Nmax 100
#define ValMin 0
#define ValMax 100


void bubblesort(int arr[], int N){
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

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int N = 5;
    
    bubblesort(arr, N);
    
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    return 0;
}