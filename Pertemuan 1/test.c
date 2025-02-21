#include <stdio.h>

int main(){
    int panjang = 0;
    int lebar = 0;
    int luas = 0;
    printf("Masukkan nilai panjang: ");
    scanf("%d", &panjang); 
    printf("Masukkan nilai lebar: ");
    scanf("%d", &lebar); 
    luas = panjang * lebar;
    printf("Jadi luas dari persegi panjang anda adalah: %d\n", luas);

    return 0;
}
