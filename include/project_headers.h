#ifndef PROJECT_HEADERS_H
#define PROJECT_HEADERS_H

void operation(char num1[], char num2[], char numAux[], int o, int* flagPtr);
void add(char num1[], char num2[],int* flagPtr);
void mult(char num1[], char num2[], char numAux[], int *flagPtr);
void subtrac(char num1[], char num2[], int* flagPtr);
int numCompare(char num1[], char num2[], int len);
void zeroFormated(char num[], int len);
void multFormated(char numAux[], int zeroQuant);

#endif // PROJECT_HEADERSS_H
