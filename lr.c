#include "lr.h"
#include <stdio.h>
#define GRAVITY 9.8
#define MAX_STR_SIZE 100
int lr1() {
float U,H,t,g;
printf("Высота равна - ");
scanf("%f",&H);
printf("Время равно - ");
scanf("%f",&t);
g=9.8;
U = (H-(g*t*t/2))/t;
printf("Начальная скорость - %f", U);
return 0;
}
int lr1dop() {
float U,H,t,g;
printf("Высота равна - ");
scanf("%f",&H);
printf("Время равно - ");
scanf("%f",&t);
U = (H-(GRAVITY*t*t/2))/t;
printf("Начальная скорость - %f", U);
return 0;
}
int lr2() {
int N;
float x;
printf("N = ");
scanf("%d", &N);//Вводим кол-во дробей
printf("x = ");
scanf("%f", &x); //Вводим x
float s = 0; //Сумма
for(int i=1; i<=N; ++i) {
s += i/x; //Считаем сумму
x*=x;}
printf("result = %.2f", s);
return 0;
}
#include <math.h>
int lr2dop() {
int N;
float x;
printf("N = ");
scanf("%d", &N);//Вводим кол-во дробей
printf("x = ");
scanf("%f", &x); //Вводим x
float s = 0; //Сумма
for(int i=N; i>=0; --i) {
s += i/pow(x,i); //Считаем сумму
    }
printf("result = %.2f", s);
return 0;
}
int lr3() {
    char str[100];
    int words_odd = 0;
    int symb=0;
    printf("Введите строку: ");
    getchar();
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' '||str[i] == '.'||str[i] == ','||str[i] == '\n') {
            if (symb%2!=0)
            ++words_odd;
            symb=0;
        }
        else{
            ++symb;
        }
    }
    printf("Количество слов с нечетным количеством букв: %d\n", words_odd);
    return 0;
}
int lr3dop() {
    char str[100];
    int words_odd = 0;
    int symb=0;
    printf("Введите строку: ");
    getchar();
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' '||str[i] == '.'||str[i] == ','||str[i] == '\n') {
            if ((symb%2!=0)&&(symb>4))
            ++words_odd;
            symb=0;
        }
        else{
            ++symb;
        }
    }
    printf("Количество слов с нечетным количеством букв: %d\n", words_odd);
    return 0;
}
int lr4()
{
    char str[1000];
    char strnew[1000];
    int symb=0;
    int symbword=0;
    int fla=0;
    printf("Введите строку: ");
    getchar();
    fgets(str,sizeof(str),stdin);
    for (int i=0;str[i]!='\0';i++){
        if (str[i]==' '||str[i]=='.'||str[i]==','||str[i]=='\n'){
            if (symb>symbword){
                symbword=symb;
                fla=i;
                symb=0;
                
            }
        }
        else{
            ++symb;
        }
    }
    for (int i=0;str[i]!='\0';i++){
        if (i>=fla-symbword){
            strnew[i]=str[i+symbword+1];
        }
        else{
            strnew[i]=str[i];
        }
    }
    printf("Полученная строка: %s",strnew);
    return 0;
}
int getMaxLen(char str[MAX_STR_SIZE]) {
    int curLen = 0;
    int maxLen = 0;
    for(int i=0; str[i]; ++i) {
        if(str[i] == ' ' || str[i] == '\n') {
            if(curLen > maxLen) 
                maxLen = curLen;
            curLen = 0;
        } else
            ++curLen;
    }
    return curLen > maxLen ? curLen : maxLen;
}
void printStrWithoutMaxLenWords(char str[MAX_STR_SIZE]) {
    int maxLen = getMaxLen(str);
    char buffer[MAX_STR_SIZE];
    
    int j=0;
    
    for(int i=0; str[i]; ++i) {
        if(str[i] == ' ' || str[i] == '\n') {
            if(j < maxLen) { 
                for(int k=0; k<j; ++k) printf("%c", buffer[k]);
                printf(" ");
            }
            j = 0;
        } else
            buffer[j++] = str[i];
    }
    if(j < maxLen) for(int k=0; k<j; ++k) printf("%c", buffer[k]);
}
int lr4dop()
{
    char str[MAX_STR_SIZE];
    printf("Введите строку: ");
    getchar();
    fgets(str,sizeof(str),stdin);
    printf("Ответ: ");
    printStrWithoutMaxLenWords(str);
    return 0;
}
int lr5() {
    int arr[10];
    int positive_count = 0, negative_count = 0;
    printf("Введите 10 целых чисел:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > 0) {
            positive_count++;
        } else if (arr[i] < 0) {
            negative_count++;
        }
    }
    if (negative_count < positive_count) {
        for (int i = 0; i < 10; i++) {
            if (arr[i] < 0) {
                arr[i] = 0;
            }
        }
    } else {
        for (int i = 0; i < 10; i++) {
            if (arr[i] > 0) {
                arr[i] = 0;
            }
        }
    }
    printf("Измененный массив:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
int lr5dop(){
    int num[10];
    int positiveCount = 0;
    int negativeCount = 0;
    printf("Введите 10 чисел:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < 9; i++) {
        if ((num[i] >= 0 && num[i+1] >= 0) || (num[i] < 0 && num[i+1] < 0)) {
            if (num[i] >= 0) {
                positiveCount++;
            } else {
                negativeCount++;
            }
        }
    }
    if (positiveCount > 0 && negativeCount > 0) {
        printf("Ответ: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", num[i]);
        }
    } else {
        for (int i = 0; i < 10; i++) {
            if (num[i] >= 0 && positiveCount > 0) {
                num[i] = 0;
            }
            if (num[i] < 0 && negativeCount > 0) {
                num[i] = 0;
            }
        }
        printf("Ответ:\n");
        for (int i = 0; i < 10; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
    }
    return 0;
}
int lr6() {
    int N=3;
    int arr[1000][1000];
    printf("Введите элементы массива:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int max = arr[0][0];
    int max_row = 0, max_col = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    int temp;
    for (int i = 0; i < N; i++) {
        temp = arr[max_row][i];
        arr[max_row][i] = arr[i][max_col];
        arr[i][max_col] = temp;
    }
    printf("Измененный массив:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
int lr6dop(){
int size=3;
int arr[1000][1000];
printf("Введите элементы массива:\n");
for(int i=0; i<size; i++) {
    for(int j=0; j<size; j++) {
        scanf("%d", &arr[i][j]);
    }
}
for(int i=0; i<size; i++) {
    for(int j=0; j<size; j++) {
        for(int k=0; k<size; k++) {
            for(int l=0; l<size; l++) {
                if(arr[k][l] < arr[i][j]) {
                    int temp = arr[k][l];
                    arr[k][l] = arr[i][j];
                    arr[i][j] = temp;
                }
            }
        }
    }
}
printf("Отсортированный массив в порядке убывания:\n");
for(int i=0; i<size; i++) {
    for(int j=0; j<size; j++) {
        printf("%d ", arr[i][j]);
    }
    printf("\n");
}
return 0;
}
#define MASK0 0x0F0F0F0F
#define MASK1 0xF0F0F0F0
unsigned int swapNibbles(unsigned int num) {
return ((num & MASK0) << 4) | ((num & MASK1) >> 4);
}
int lr7(){
unsigned int N;
printf("Введите целое число: ");
scanf("%u", &N);
unsigned int swapped = swapNibbles(N);
printf("Число после замены тетрад: %u\n", swapped);
return 0;
}