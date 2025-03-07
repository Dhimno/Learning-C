#include <stdio.h>

int main(){
    for(int i = 0; i < 10; i++){
        if(i&i){
            printf("%d",i);
        }
    }
    return 0;
}

