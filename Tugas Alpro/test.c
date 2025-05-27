#include <stdio.h>

int main() {
    int N, Q;
    scanf("%d", &N);
    int Arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &Arr[i]);
    }
    
    scanf("%d", &Q);
    int xi, yi;
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &xi, &yi);
        int counter = 0;
        for (int j = 0; j < N; j++) {
            if (Arr[j] > xi && Arr[j] <= yi) {
                counter = counter + 1;
            }
        }
        printf("%d\n", counter);
    }

    return 0;
}
