#include "fruitmachine.h"
void Rule()
{
    printf("������\n");
}
int GetBet()
{
    int BetType;
    printf("\n��ѡ����ע��ʽ��");
    printf("1. ��� 2. ��С 3. ����\n");
    scanf("%d", &BetType);
    if (BetType==1||BetType==2||BetType==3)
        return BetType;
    else
        return 1;
}
int GetAmount()
{
    int BetMoney;
    printf("����ע������10Ԫ�����100Ԫ����");
    scanf("%d", &BetMoney);
    if (BetMoney<10)
        BetMoney = 10;
    if (BetMoney>100)
        BetMoney = 100;
    return BetMoney;
}
void Throw()
{
    printf("���������������\n");
    getch();
    srand(time(0));
    while (!kbhit())
    {
        a = rand() % 1 + 1;
        b = rand() % 1 + 1;
        c = rand() % 1 + 1;
        system("cls");
        printf("������ת��..........�������ϵ����������ֹת��\n");
        printf("��һ�����ӵĵ���:%d\n�ڶ������ӵĵ���:%d\n���������ӵĵ���:%d\n", a, b, c);
    }
}
int Judge(int a, int b, int c)
{
    if (a==b&&a==c)
    {
        return 3;
    }
    if (a+b+c>11)
    {
        return 1;
    }
    if (a+b+c<11)
    {
        return 2;
    }
    else//if (a+b+c==11)
    {
        return 0;
    }
}
void Moneycal()
{
    if (Judge(a, b, c)==0)
    {
        printf("ƽ��!\n");
    }
    if (Judge(a, b, c)==1)
    {
        Betmoney = 2*get;
        if (bet==1)
        {
            Playermoney += Betmoney;
            Dealermoney -= Betmoney;
            printf("��!��Ӯ��%dԪ������ʣ%dԪ��ׯ�һ�ʣ%dԪ\n", Betmoney, Playermoney, Dealermoney);
        }
        else
        {
            Playermoney -= Betmoney;
            Dealermoney += Betmoney;
            printf("��!������%dԪ������ʣ%dԪ��ׯ�һ�ʣ%dԪ\n", Betmoney, Playermoney, Dealermoney);
        }
    }
    if (Judge(a, b, c)==2)
    {
        Betmoney = 2*get;
        if (bet==2)
        {
            Playermoney += Betmoney;
            Dealermoney -= Betmoney;
            printf("С!��Ӯ��%dԪ������ʣ%dԪ��ׯ�һ�ʣ%dԪ\n", Betmoney, Playermoney, Dealermoney);
        }
        else
        {
            Playermoney -= Betmoney;
            Dealermoney += Betmoney;
            printf("С!������%dԪ������ʣ%dԪ��ׯ�һ�ʣ%dԪ\n", Betmoney, Playermoney, Dealermoney);
        }
    }
    if (Judge(a, b, c)==3)
    {
       if (bet==3)
       {
           Betmoney = 10*get;
           Playermoney += Betmoney;
           Dealermoney -= Betmoney;
           printf("����!��Ӯ��%dԪ������ʣ%dԪ��ׯ�һ�ʣ%dԪ\n", Betmoney, Playermoney, Dealermoney);
       }
       else
       {
            Betmoney = 2*get;
            Playermoney -= Betmoney;
            Dealermoney += Betmoney;
            printf("����!������%dԪ������ʣ%dԪ��ׯ�һ�ʣ%dԪ\n", Betmoney, Playermoney, Dealermoney);
       }
    }
}
int check(int pm, int dm)
{
    if (pm<=0)
    {
        if (pm==0)
        {
            printf("���Ѿ���������е�Ǯ���޷��ٽ��жĲ�������\n");
        }
        if (pm<0)
        {
            printf("���Ѿ�Ƿ��%dԪ��������޷������컹�壬����������룡����\n", abs(pm));
        }
        return 0;
    }
    if (dm<=0)
    {
        if (dm==0)
        {
            printf("ׯ���Ѿ���������е�Ǯ�������������ˣ�����\n");
        }
        if (dm<0)
        {
            printf("ׯ���Ѿ�Ƿ��%dԪ�����ׯ���޷������컹�壬�ĳ�����Ѻ����������\n", abs(dm));
        }
        return 0;
    }
    return 1;
}
