#include <stdio.h>
#include <string.h>
#include "../Projeto_1/include/project_headers.h"
#define MAX 504


int main(void) {

    int t, o, flag = 0;
    char num1[MAX], num2[MAX];
    scanf("%d", &t);
    for(int i = 0; i<t; i++) {
        char numAux[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        scanf(" %s %s %d", num1, num2, &o);
        operation(num1,num2,numAux,o,&flag);
        if (flag == 0) {
            printf("%s\n", num1);
        } else if (flag == 1) {
            printf("%s\n", num2);
        } else {
            printf("%s\n", numAux);
        }
    }
    
    return 0;
}
