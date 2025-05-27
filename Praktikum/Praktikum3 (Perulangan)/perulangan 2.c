#include <stdio.h>

typedef enum{
        false, true
}bool;

int main(){
        int k = 0;
        while(true){
                printf("k %d\n", k);
                k++;
                if(k > 5){
                        break;
                }
        }
        printf("k akhir %d\n", k);

        for(int i = 0; i < 10; i++){
                if(i & 1){
                        printf("%d\n", i);
                }
        }
        return 0;
}