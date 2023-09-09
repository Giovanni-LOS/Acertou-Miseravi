#include <stdio.h>
#include <string.h>
#define MAX 504

void operation(char num1[], char num2[], char numAux[], int o, int* flagPtr);
void add(char num1[], char num2[],int* flagPtr);
void mult(char num1[], char num2[], char numAux[], int *flagPtr);
void subtrac(char num1[], char num2[], int* flagPtr);
int numCompare(char num1[], char num2[], int len);
void zeroFormated(char num[], int len);
void multFormated(char numAux[], int zeroQuant);

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

void operation(char num1[], char num2[], char numAux[], int o, int* flagPtr) {
    switch (o) {
        case 1:
            add(num1,num2,flagPtr);
        break;
        case 2:
            subtrac(num1,num2,flagPtr);
        break;
        case 3:
            mult(num1,num2,numAux,flagPtr);
        break;
        default:
        break;
    }
}

void add(char num1[], char num2[], int* flagPtr) {
    
    int len1 = strlen(num1), len2 = strlen(num2), r=0;
    if (len1>=len2) {
        for(int i = len1-1, j = len2-1; i >= 0 || j >=0;) {
            if (j >= 0) {
                if (num1[i]+(num2[j]-48)+r < 58) {
                    num1[i] = num1[i]+(num2[j]-48+r);
                    i--;
                    j--;
                    r=0;
                } else {
                    num1[i] = (num1[i]+(num2[j]-48))-10+r;
                    r=1;
                    i--;
                    j--;
                    if (i == -1) {
                        printf("1");
                    }
                }
            } else {
                if (r==1) {
                    if (i == 0) {
                        if (num1[i] == '9') {
                            num1[i] = '0';
                            i--;
                            printf("1");
                        } else {
                            num1[i] += 1;
                            i--;
                            r=0;
                        }
                    } else {

                        if (num1[i] == '9') {
                            num1[i] = '0';
                            i--;
                        } else {
                            num1[i] += 1;
                            i--;
                            r=0;
                        }
                    }
                } else {
                    break;
                }
            }
        }
    } else {
        *flagPtr = 1;
        for(int i = len2-1, j = len1-1; i >= 0 || j >=0;) {
            if (j >= 0) {

                if (num2[i]+(num1[j]-48)+r < 58) {
                    num2[i] = num2[i]+(num1[j]-48+r);
                    i--;
                    j--;
                    r=0;
                } else {
                    num2[i] = (num2[i]+(num1[j]-48))-10+r;
                    r=1;
                    i--;
                    j--;
                    if (i == -1) {
                        printf("1");
                    }
                }
            } else {
                if (r==1) {
                    if (i == 0) {
                        if (num2[i] == '9') {
                           if (len1>=len2) {
        for(int i = len1-1, j = len2-1; i >= 0 || j >=0;) {
            if (j >= 0) {
                if (num1[i]+(num2[j]-48)+r < 58) {
                    num1[i] = num1[i]+(num2[j]-48+r);
                    i--;
                    j--;
                    r=0;
                } else {
                    num1[i] = (num1[i]+(num2[j]-48))-10+r;
                    r=1;
                    i--;
                    j--;
                    if (i == -1) {
                        printf("1");
                    }
                }
            } else {
                if (r==1) {
                    if (i == 0) {
                        if (num1[i] == '9') {
                            num1[i] = '0';
                            i--;
                            printf("1");
                        } else {
                            num1[i] += 1;
                            i--;
                            r=0;
                        }
                    } else {

                        if (num1[i] == '9') {
                            num1[i] = '0';
                            i--;
                        } else {
                            num1[i] += 1;
                            i--;
                            r=0;
                        }
                    }
                } else {
                    break;
                }
            }
        }
    }      num2[i] = '0';
                            i--;
                            printf("1");
                        } else {
                            num2[i] += 1;
                            i--;
                            r=0;
                        }
                    } else {
                        if (num2[i] == '9') {
                            num2[i] = '0';
                            i--;
                        } else {
                            num2[i] += 1;
                            i--;
                            r=0;
                        }
                    }
                } else {
                    break;
                }
            }
        }
    }
}

void subtrac(char num1[], char num2[], int* flagPtr) {
    
    int len1 = strlen(num1), len2 = strlen(num2), r=0;
    if (len1>len2) {
        for(int i = len1-1, j = len2-1; i >= 0 || j >=0;) {
            if (j >= 0) {
                if (r == 1) {
                    if (num1[i] == '0') {
                        num1[i] = '9';
                    } else {
                        num1[i]-=r;
                        r=0;
                    }
                }
                if (num1[i]-(num2[j]-48) >= 48) {
                    num1[i] = num1[i]-(num2[j]-48);
                    i--;
                    j--;
                } else {
                    num1[i] = (num1[i]-(num2[j]-48))+10;
                    r=1;
                    i--;
                    j--;
                }
            } else {
                if (r==1) {
                    if (num1[i] == '0') {
                        num1[i] = '9';
                        i--;
                    } else {
                        num1[i]-=1;
                        i--;
                        r=0;
                    }
                } else {
                    break;
                }
            }
        }
        zeroFormated(num1,len1);
    } else if (len1 == len2) {
        if (numCompare(num1,num2,len1) == 1) {
            for(int i = len1-1, j = len2-1; i >= 0 || j >=0;) {
                if (r == 1) {
                    if (num1[i] == '0') {
                        num1[i] = '9';
                    } else {
                        num1[i]-=r;
                        r=0;
                    }
                }
                if (num1[i]-(num2[j]-48) >= 48) {
                    num1[i] = num1[i]-(num2[j]-48);
                    i--;
                    j--;
                } else {
                    num1[i] = (num1[i]-(num2[j]-48))+10;
                    r=1;
                    i--;
                    j--;
                }
            }
            zeroFormated(num1,len1);
        } else if (numCompare(num1,num2,len1) == 2){
            *flagPtr = 1;
            printf("-");
            for(int i = len1-1, j = len2-1; i >= 0 || j >=0;) {
                if (r == 1) {
                    if (num2[i] == '0') {
                        num2[i] = '9';
                    } else {
                        num2[i]-=r;
                        r=0;
                    }
                }
                if (num2[i]-(num1[j]-48) >= 48) {
                    num2[i] = num2[i]-(num1[j]-48);
                    i--;
                    j--;
                } else {
                    num2[i] = (num2[i]-(num1[j]-48))+10;
                    r=1;
                    i--;
                    j--;
                }
            }
            zeroFormated(num2,len2);
        } else {
            num1[0] = '0';
            num1[1] = '\0';
        }
    } else {
        *flagPtr = 1;
        printf("-");
        for(int i = len2-1, j = len1-1; i >= 0 || j >=0;) {
            if (j >= 0) {
                if (r == 1) {
                    if (num2[i] == '0') {
                        num2[i] = '9';
                    } else {
                        num2[i]-=r;
                        r=0;
                    }
                }
                if (num2[i]-(num1[j]-48) >= 48) {
                    num2[i] = num2[i]-(num1[j]-48);
                    i--;
                    j--;
                } else {
                    num2[i] = (num2[i]-(num1[j]-48))+10;
                    r=1;
                    i--;
                    j--;
                }
            } else {
                if (r==1) {
                    if (num2[i] == '0') {
                        num2[i] = '9';
                        i--;
                    } else {
                        num2[i]-=1;
                        i--;
                        r=0;
                    }
                } else {
                    break;
                }
            }
        }
        zeroFormated(num2,len2);
    }
}

void mult(char num1[], char num2[], char numAux[], int *flagPtr) {
    *flagPtr = 2;
    
    char numAux2[1010];
    strcpy(numAux2, numAux);
    
    int len1 = strlen(num1), len2 = strlen(num2), lenAux = strlen(numAux), r=0;
    
    if((len2 == 1 && num2[0] == '0')||(len1 == 1 && num1[0] == '0')) {
        numAux[1] = '\0';
        return;
    }
    for(int w = 1; w<=len2; w++) {
        if (num2[len2-w]-48>0) {
            for(int i = 0; i<lenAux;i++) {
                numAux[i] = '0';
            }
            for(int i = len1-1, j = lenAux-1; i>=0; i--, j--) {
                numAux[j] = num1[i];
            }
            for(int i = (num2[len2-w]-48);i>1;i--) {
                add(numAux,num1,flagPtr);
            }
            multFormated(numAux, w-1);
            if(w>1) {
               add(numAux,numAux2,flagPtr);
            }
            strcpy(numAux2, numAux);
        } 
    }
    zeroFormated(numAux,lenAux);
}

int numCompare(char num1[], char num2[], int len) {
    
    for (int i = 0; i<len; i++) {
        if (num1[i] > num2[i]) {
            return 1;
        }
        if (num1[i] < num2[i]) {
            return 2;
        }
    }
    return 0;
}

void zeroFormated(char num[], int len) {
    int zeroIndex = 0;
    for(int i = 0; i<len; i++) {
        if (num[i]=='0') {
            zeroIndex++;
        } else {
            break;
        }
    }
    for(int i = zeroIndex, j=0; j < len - zeroIndex;i++, j++) {
        int aux = num[j];
        num[j] = num[i];
        num[i] = aux;
    }
    num[len - zeroIndex] = '\0';
}

void multFormated(char numAux[], int zeroQuant) {
   
    int len = strlen(numAux),end = len;
    
    for (int i = 0; i<len; i++) {
        if (numAux[i] == '0') {
            end--;
        } else {
            break;
        }
    }
    for (int i = len-end, j = i-zeroQuant; j < len-zeroQuant;i++, j++) {
        int aux = numAux[i];
        numAux[i] = numAux[j];
        numAux[j] = aux;
    }
}
