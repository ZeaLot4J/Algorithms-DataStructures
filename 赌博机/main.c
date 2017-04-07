#include "fruitmachine.h"

int a, b, c, Playermoney = 1000, Dealermoney = 1000, Betmoney, bet, get;
int main()
{
    char ch;
    Rule();
    while(1)
    {
        if (Playermoney<10)
        {
            printf("您不足10元，无法继续，您输了\n");
            break;
        }
        if (Dealermoney<10)
        {
            printf("庄家不足10元，无法赌博，您赢了\n");
            break;
        }
        bet = GetBet();
        repeat:get = GetAmount();
        if (get>Playermoney)
        {
            printf("您金额不足，请重新下注\n");
            goto repeat;
        }
        if (get>Dealermoney)
        {
            printf("庄家金额不足，请重新下注\n");
            goto repeat;
        }
        Throw();
        getch();
        Moneycal();
        if (check(Playermoney, Dealermoney)==0)
            break;
        printf("继续么（y/n）");
        ch = getch();
        if (ch=='n')
            break;
    }
    getch();
    return 0;
}
