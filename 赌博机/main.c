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
            printf("������10Ԫ���޷�������������\n");
            break;
        }
        if (Dealermoney<10)
        {
            printf("ׯ�Ҳ���10Ԫ���޷��Ĳ�����Ӯ��\n");
            break;
        }
        bet = GetBet();
        repeat:get = GetAmount();
        if (get>Playermoney)
        {
            printf("�����㣬��������ע\n");
            goto repeat;
        }
        if (get>Dealermoney)
        {
            printf("ׯ�ҽ��㣬��������ע\n");
            goto repeat;
        }
        Throw();
        getch();
        Moneycal();
        if (check(Playermoney, Dealermoney)==0)
            break;
        printf("����ô��y/n��");
        ch = getch();
        if (ch=='n')
            break;
    }
    getch();
    return 0;
}
