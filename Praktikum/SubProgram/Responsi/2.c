int main() {
    /* Kamus */
    int A, B, C, D, bulan;

    /* Algoritma */
    scanf("%d %d %d %d", &A, &B, &C, &D);
    bulan = 0;

    while (A > 0 || B > 0 || C > 0 || D > 0) {
        int eaten = 0;

        if (A > 0) {
            int eatA = (A >= 3) ? 3 : A;
            A -= eatA;
            eaten += eatA;
        }

        if (eaten < 3 && B > 0) {
            int eatB = (B >= 3 - eaten) ? (3 - eaten) : B;
            B -= eatB;
            eaten += eatB;
        }

        if (eaten < 3 && C > 0) {
            int eatC = (C >= 3 - eaten) ? (3 - eaten) : C;
            C -= eatC;
            eaten += eatC;
        }

        if (eaten < 3 && D > 0) {
            int eatD = (D >= 3 - eaten) ? (3 - eaten) : D;
            D -= eatD;
            eaten += eatD;
        }

        bulan++;
    }

    printf("%d\n", bulan);
    return 0;
}