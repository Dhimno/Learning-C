#include <stdio.h>

#define NMax 100
#define ValMin 0
#define ValMax 100

typedef int TabInt[NMax + 1]; // +1 karena indeks mulai dari 1

void CountSORT(TabInt T, int N) {
    int TabCount[ValMax - ValMin + 1] = {0}; // Inisialisasi semua elemen ke 0
    int i, K;

    // Counting: hitung frekuensi tiap elemen
    for (i = 1; i <= N; i++) {
        TabCount[T[i] - ValMin]++;
    }

    // Pengisian kembali (sorting)
    K = 0;
    for (i = ValMin; i <= ValMax; i++) {
        while (TabCount[i - ValMin] != 0) {
            K++;
            T[K] = i;
            TabCount[i - ValMin]--;
        }
    }
}

// Fungsi main untuk uji coba
int main() {
    TabInt T;
    int N, i;

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &N);

    printf("Masukkan %d elemen:\n", N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &T[i]);
    }

    CountSORT(T, N);

    printf("Hasil setelah Count Sort:\n");
    for (i = 1; i <= N; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");

    return 0;
}