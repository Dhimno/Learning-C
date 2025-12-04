/* Nama Anggota  :  */
/* Tanggal       :  */
/***********************************/

#include <stdio.h>
#include "stack.h"

/* function countStr(kata: string) -> integer 
    {menghitung panjang dari string yang diinputkan } */
int countStr(char *kata) {
    // kamus lokal
    int i;

    // algoritma
    i = 0;
    while (kata[i] != '\0') {
        i++;
    }

    return i;
}

/* function evalPostfix(postfix: string) -> real 
    {menerima sebua input string berupa operasi postfix, lalu menghasilkan output berupa bilangan real 
    hasil dari evaluasi ekspresi tersebut } */
float evalPostfix(char *postfix) {
    // kamus lokal
    int i;
    int lenght;
    float val1, val2;
    char c;
    Tstack S;

    // algoritma
    CreateStack(&S);
    lenght = countStr(postfix);

    for (i = 0; i < lenght; i++) {
        c = postfix[i];

        if (c >= '0' && c <= '9') {
            val1 = c - '0';
            Push(&S, val1);
        } else if (c == '*' || c == '/' || c == '+' || c == '-') {
            if (c == '*') {
                Pop(&S, &val1);
                Pop(&S, &val2);

                Push(&S, val1 * val2);
            } else if (c == '/'){
                Pop(&S, &val1);
                Pop(&S, &val2);

                Push(&S, val2 / val1);
            } else if (c == '+') {
                Pop(&S, &val1);
                Pop(&S, &val2);

                Push(&S, val1 + val2);
            } else {
                Pop(&S, &val1);
                Pop(&S, &val2);

                Push(&S, val2 - val1);
            }
        }
    }

    Pop(&S, &val1);

    return val1;
}

// program utama
int main() {
    // kamus
    char test1[] = "9 3 4 * 8 + 4 / -";  
    char test2[] = "5 1 2 + 4 * + 3 -";  
    char test3[] = "1 2 /";              
    char test4[] = "9 2 /";               
    char test5[] = "7 3 - 2 *";           

    // algoritma
    printf("===========================\n");
    printf("===== Tes evalPostfix =====\n");
    printf("===========================\n");
    printf("Test 1: %s = %.2f\n", test1, evalPostfix(test1));
    printf("Test 2: %s = %.2f\n", test2, evalPostfix(test2));
    printf("Test 3: %s = %.2f\n", test3, evalPostfix(test3));
    printf("Test 4: %s = %.2f\n", test4, evalPostfix(test4));
    printf("Test 5: %s = %.2f\n", test5, evalPostfix(test5));

    return 0;
}