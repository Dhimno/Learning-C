#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], ganjil[n], genap[n];
    int ganjilC = 0, genapC = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 != 0) {
            ganjil[ganjilC++] = arr[i];  
        } else {
            genap[genapC++] = arr[i];  
        }
    }

    for (int i = 0; i < ganjilC; i++) {
        printf("%d ", ganjil[i]);
    }

    for (int i = 0; i < genapC; i++) {
        printf("%d ", genap[i]);
    }

    printf("\n");
    return 0;
}