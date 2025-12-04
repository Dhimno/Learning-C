    #include <stdio.h>
    #include <stdlib.h> 

    int main() {
        int N, X;
        scanf("%d %d", &N, &X);

        int arr[1000];
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        int Terdekat = arr[0];
        int MinSelisih = abs(arr[0] - X);

        for (int i = 1; i < N; i++) {
            int diff = abs(arr[i] - X);
            if (diff < MinSelisih || (diff == MinSelisih && arr[i] < Terdekat)) {
                Terdekat = arr[i];
                MinSelisih = diff;
            }
        }

        printf("%d\n", Terdekat);
        return 0;
    }