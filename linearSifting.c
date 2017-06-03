#include <stdio.h>
#define N 10000
/* 线性时间筛选素数 */
/*
假设当前素数表为:2 3
而此时i为4，
在标记完2*4=8为合数之后，判断出4能够整除2，按照算法此时应该不用管3了，而是直接i++之后素数表从头开始与i相乘标记后面的合数。
分析一下，既然i为4能够整除2，那么i的倍数肯定也能整除2（这是理所当然的），比如下一个素数3，也就是说有下面的等式

当前i * 3 == X * 2    （X表示某个数，因为2<3,所以X>当前i）

而i不断递增总有一天会等于X,所以

当前i * 3 == 未来i * 2

所以当前的i不要去急着去把未来的事给做了，等将来i由4递增变成了6，就可以去完成这一步将12给标记为合数了，否则会导致重复运算一次。

同理，当素数表为:2 3 5 7
当前i=9时，
isPrime[9*2] = isPrime[18] = 0
isPrime[9*3] = isPrime[27] = 0
此时9 % 3 == 0，如果现在把5*9=45给做了的话，根据

当前i * 5 = 未来i * 3

当i递增到15时，又会重复运算一遍，这样就达不到线性时间了。
*/

void primeTable(int *prime, int *isPrime){
    int pnum = 0, i,j;
    for(i=0; i<N; i++)
        isPrime[i] = 1;
    for(i=2; i<N; i++){
        if(isPrime[i] == 1)
            prime[pnum++] = i;
        for(j=0; j<pnum && prime[j]*i<N; j++){
            isPrime[prime[j]*i] = 0;
            if(i % prime[j] == 0) break;
        }
    }
}

int main(){
    int prime[N], isPrime[N];
    primeTable(prime, isPrime);
    int i;
    for(i=0; i<100; i++)
        printf("%d ", prime[i]);

    return 0;
}
