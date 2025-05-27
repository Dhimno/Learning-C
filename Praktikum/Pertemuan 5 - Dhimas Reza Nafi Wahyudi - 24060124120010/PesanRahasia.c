/*Nama File 	: PesanRahasia.c*/
/*Deskripsi 	: Mendekripsi pesan yang di enkripsi dengan offset*/
/*Pembuat   	: <24060124120010 - Dhimas Reza Nafi Wahyudi>*/
/*Tgl Pembuatan	: <26-03-2025 dan 22:45>*/

#include <stdio.h> /*header file*/

int hitungPanjang(const char *str) {
	int panjang = 0;
	while (str[panjang] != '\0') {
		panjang++;
	}
	return panjang;
}

void dekripsi(int offset, char *Pesan) {
    for (int i = 0; i < hitungPanjang(Pesan); i++) {
        if (Pesan[i] >= 'a' && Pesan[i] <= 'z') {
            Pesan[i] = ((Pesan[i] - 'a' - offset + 26) % 26) + 'a';
        } else if (Pesan[i] >= 'A' && Pesan[i] <= 'Z') {
            Pesan[i] = ((Pesan[i] - 'A' - offset + 26) % 26) + 'A';
        }
    }
}

/*Program Utama*/
int main() {
    /*Kamus*/
    int offset;
    char Pesan[100];

    /*Algoritma*/
    printf("Masukkan nilai pergeseran: ");
    scanf("%d", &offset);
    printf("Masukkan teks terenkripsi: ");
    scanf("%s", Pesan);
    dekripsi(offset, Pesan);
    printf("Pesan asli: %s\n", Pesan);

    return 0;
}