#include <stdio.h>

int main(){
    float phi = 3.14;
    int jari_jari = 0;
    float luas = 0;
    printf("Masukkan jari-jari yang diinginkan: ");
    scanf("%d", &jari_jari);
    luas = phi * jari_jari * jari_jari;
    printf("Jadi luas lingkaran anda adalah: %.3f\n", luas);
    return 0;

}
