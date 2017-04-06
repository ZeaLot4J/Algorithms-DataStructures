#include <stdio.h>
#include <string.h>
#include <math.h>

int prefixZero[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int f[100];         //
void numberTypeStatistics(int number){
    int i, j, len = 0;
    int typeNum[10] = {0};    //数字种类计数
    for(i=number; i!=0; i/=10){
        len++;          //位数
    }
    int firstNumber,lastNumber,cnt;
    for(i=1; i<=len; i++){
        firstNumber = number / pow(10, len-i);                  //3       4
        lastNumber = number - firstNumber * pow(10, len-i);     //4567    567
        cnt = firstNumber * f[len-i];//每一种数字次数都是相同的 //3*4000

        for(j=0; j<10; j++){
            typeNum[j] += cnt;
        }

        for(j=0; j<firstNumber; j++){
            typeNum[j] += pow(10, len-i);
        }
        typeNum[j] += lastNumber + 1;

        number = lastNumber;
    }
    for(i=1; i<=len; i++){
        typeNum[0] -= prefixZero[i];
    }

    for(i=0; i<10; i++){
            printf("%d\n", typeNum[i]);
        }
        printf("\n\n\n\n");
}
int main(){
    int number;   //输入的数字

    time_t t;
    srand((unsigned) time(&t));

    int i=2000000;
    //先迭代好递推数组
    f[0] = 0;
    f[1] = 1;
    for(i=2; i<=100; i++){
        f[i] = 10 * f[i-1] + pow(10, i-1);
    }
    while(i--){//int 2147483647 scanf("%d", &number)!=EOF
        numberTypeStatistics(rand() % 100);
        //printf("%d\n", rand() % 100);
    }

    return 0;
}
