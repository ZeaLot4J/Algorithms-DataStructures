#include "fruitmachine.h"
void Rule()
{
    printf("规则略\n");
}
int GetBet()
{
    int BetType;
    printf("\n请选择下注方式：");
    printf("1. 买大 2. 买小 3. 买豹子\n");
    scanf("%d", &BetType);
    if (BetType==1||BetType==2||BetType==3)
        return BetType;
    else
        return 1;
}
int GetAmount()
{
    int BetMoney;
    printf("请下注（最少10元，最多100元）：");
    scanf("%d", &BetMoney);
    if (BetMoney<10)
        BetMoney = 10;
    if (BetMoney>100)
        BetMoney = 100;
    return BetMoney;
}
void Throw()
{
    printf("按任意键掷出骰子\n");
    getch();
    srand(time(0));
    while (!kbhit())
    {
        a = rand() % 1 + 1;
        b = rand() % 1 + 1;
        c = rand() % 1 + 1;
        system("cls");
        printf("骰子在转动..........按键盘上的任意键来终止转动\n");
        printf("第一粒骰子的点数:%d\n第二粒骰子的点数:%d\n第三粒骰子的点数:%d\n", a, b, c);
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
        printf("平局!\n");
    }
    if (Judge(a, b, c)==1)
    {
        Betmoney = 2*get;
        if (bet==1)
        {
            Playermoney += Betmoney;
            Dealermoney -= Betmoney;
            printf("大!您赢了%d元，您还剩%d元，庄家还剩%d元\n", Betmoney, Playermoney, Dealermoney);
        }
        else
        {
            Playermoney -= Betmoney;
            Dealermoney += Betmoney;
            printf("大!您输了%d元，您还剩%d元，庄家还剩%d元\n", Betmoney, Playermoney, Dealermoney);
        }
    }
    if (Judge(a, b, c)==2)
    {
        Betmoney = 2*get;
        if (bet==2)
        {
            Playermoney += Betmoney;
            Dealermoney -= Betmoney;
            printf("小!您赢了%d元，您还剩%d元，庄家还剩%d元\n", Betmoney, Playermoney, Dealermoney);
        }
        else
        {
            Playermoney -= Betmoney;
            Dealermoney += Betmoney;
            printf("小!您输了%d元，您还剩%d元，庄家还剩%d元\n", Betmoney, Playermoney, Dealermoney);
        }
    }
    if (Judge(a, b, c)==3)
    {
       if (bet==3)
       {
           Betmoney = 10*get;
           Playermoney += Betmoney;
           Dealermoney -= Betmoney;
           printf("豹子!您赢了%d元，您还剩%d元，庄家还剩%d元\n", Betmoney, Playermoney, Dealermoney);
       }
       else
       {
            Betmoney = 2*get;
            Playermoney -= Betmoney;
            Dealermoney += Betmoney;
            printf("豹子!您输了%d元，您还剩%d元，庄家还剩%d元\n", Betmoney, Playermoney, Dealermoney);
       }
    }
}
int check(int pm, int dm)
{
    if (pm<=0)
    {
        if (pm==0)
        {
            printf("您已经输光了所有的钱，无法再进行赌博！！！\n");
        }
        if (pm<0)
        {
            printf("您已经欠款%d元，如果您无法在三天还清，后果不堪设想！！！\n", abs(pm));
        }
        return 0;
    }
    if (dm<=0)
    {
        if (dm==0)
        {
            printf("庄家已经输掉了所有的钱，他不想跟你赌了！！！\n");
        }
        if (dm<0)
        {
            printf("庄家已经欠款%d元，如果庄家无法在三天还清，赌场将抵押给您！！！\n", abs(dm));
        }
        return 0;
    }
    return 1;
}
