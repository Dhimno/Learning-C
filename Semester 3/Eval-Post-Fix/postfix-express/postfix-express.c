/* Nama Anggota  :  */
/* Tanggal       :  */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
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

/* function postfixExpress(infix: string) -> string 
    {menerima masukan string berisi infix expression dan menghasilkan ouput string berupa postfix expression } */
char *postfixExpress(char *infix) {
    // kamus lokal
    Tstack S;
    int lenght;
    int i, j;
    char c, e;
    char *postFix;

    // algoritma
    postFix  = (char *)malloc((lenght + 1) *sizeof(char));
    CreateStack(&S);
    lenght = countStr(infix);

    j = 0;
    for (i = 0; i < lenght; i++) {
        c = infix[i];

        if (c >= '0' && c <= '9') {
            postFix[j] = c;
            j++;
        } else if (c == '(') {
            Push(&S, c);
        } else if ( c == ')') {
            while (!isEmptyStack(S) && Infotop(S) != '(') {
                Pop(&S, &e);
                postFix[j] = e;
                j++;
            }
            Pop(&S, &e);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!isEmptyStack(S) && (Infotop(S) == '*' || Infotop(S) == '/')) {
                Pop(&S, &e);
                postFix[j] = e;
                j++;
            }
            Push(&S, c);
        }
    }

    while (!isEmptyStack(S)) {
        Pop(&S, &e);
        postFix[j] = e;    
        j++;
    }

    postFix[j] = '\0';
    
    return postFix;
}

// program utama
int main() {
    // kamus
    char infix1[] = "3+4";                     
    char infix2[] = "3+4*5";                   
    char infix3[] = "(3+4)*5";                 
    char infix4[] = "3+4*5/2";                 
    char infix5[] = "(1+2)*(3+4)";             
    char infix6[] = "9*(5-3)/2";               

    char *postfix;

    // algoritma
    printf("\n===========================\n");
    printf("==== Tes postFixExpress ====\n");
    printf("===========================\n");
    
    postfix = postfixExpress(infix1);
    printf("Infix  : %s\nPostfix: %s\n\n", infix1, postfix);
    free(postfix);
    
    postfix = postfixExpress(infix2);
    printf("Infix  : %s\nPostfix: %s\n\n", infix2, postfix);  
    free(postfix);
    
    postfix = postfixExpress(infix3);
    printf("Infix  : %s\nPostfix: %s\n\n", infix3, postfix);  
    free(postfix);
    
    postfix = postfixExpress(infix4);
    printf("Infix  : %s\nPostfix: %s\n\n", infix4, postfix);  
    free(postfix);
        
    postfix = postfixExpress(infix5);
    printf("Infix  : %s\nPostfix: %s\n\n", infix5, postfix);  
    free(postfix);
    
    postfix = postfixExpress(infix6);
    printf("Infix  : %s\nPostfix: %s\n\n", infix6, postfix); 
    free(postfix);

    return 0;
}