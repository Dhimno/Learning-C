#include <stdio.h>

void sort(int arr[], int N){
    for (int pass = 1; pass < N; pass++)
    {
        
        int temp = arr[pass];
        int i = pass - 1;
        while (temp < arr[i] && i > 0)  
        {
            arr[i+1] = arr[i];
            i--;
        }
        if (temp >= arr[i])
        {
            arr[i+1] = temp;
        } else
        {
            arr[i+1] = arr[i];
            arr[i] = temp;
            
        }
        
    }
    
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int N = sizeof(arr)/sizeof(arr[0]);
    
    sort(arr, N);
    
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    return 0;
}