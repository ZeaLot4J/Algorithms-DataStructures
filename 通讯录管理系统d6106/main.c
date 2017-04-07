#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define CALSS_NUM 3

char logname[] = "zhanglei";
char logpwd[] = "zhanglei18hao";
int count = 0;
struct Contact
{
    char name[20];
    char tel[20];
    char qq[20];
    char addr[50];
    struct Contact * next;
};

void showMainMenu();
void copyright();
void title();
void staff();
void pressAnyKey();
int login();
struct Contact * createContact();
struct Contact * insertContact(struct Contact *);
void showAllContacts(struct Contact *);
struct Contact * freeMemory(struct Contact *);
void calculateNum();
void findContactByName(struct Contact *);
struct Contact * delContact(struct Contact *);
void updateContact(struct Contact *);
void saveContact(struct Contact *);
struct Contact * loadContact();


int main()
{
    int choice;
    char exitchoice;
    do
    {
        system("cls");
        title();
        printf("=====================================================================\n");
        printf("|　　　　　　　　　             1.登录                              |\n\n");
        Sleep(100);
        printf("|                               2.版权                              |\n\n");
        Sleep(100);
        printf("|                               3.工作人员                          |\n\n");
        Sleep(100);
        printf("|                               4.退出                              |\n");
        printf("=====================================================================\n");
        printf("请输入您的选择(1/2/3/4),按回车键确认...");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            if(login()==1)
            {
                printf("登录成功，请稍候...");
                Sleep(1000);
                showMainMenu();
            }
            else
            {
                system("cls");
                printf("登录失败...\n");
                pressAnyKey();
            }
            break;
        case 2:
            copyright();
            break;
        case 3:
            staff();
            break;
        case 4:
            system("cls");
            printf("您确定要退出通讯录管理系统1.0？（y/n）");
            fflush(stdin);
            exitchoice = getchar();
            if(exitchoice == 'y')
            {
                exit(0);
            }
            break;
        default:
            printf("请输入有效选项(1,2,3,4)...\n");
		    pressAnyKey();
        }
    }while(1);

    return 0;
}

void title()
{
    printf("\t\t\t欢");
    Sleep(50);
    printf("迎");
    Sleep(50);
    printf("使");
    Sleep(50);
    printf("用");
    Sleep(50);
    printf("通");
    Sleep(50);
    printf("讯");
    Sleep(50);
    printf("录");
    Sleep(50);
    printf("管");
    Sleep(50);
    printf("理");
    Sleep(50);
    printf("系");
    Sleep(50);
    printf("统");
    Sleep(50);
    printf("1.0\n");
    Sleep(50);
}
void copyright()
{
    system("cls");
    printf("=====================================================================\n");
    printf("\t\t\tH");
    Sleep(50);
    printf("u");
    Sleep(50);
    printf("n");
    Sleep(50);
    printf("a");
    Sleep(50);
    printf("n");
    Sleep(50);
    printf(" ");
    Sleep(50);
    printf("I");
    Sleep(50);
    printf("n");
    Sleep(50);
    printf("s");
    Sleep(50);
    printf("t");
    Sleep(50);
    printf("i");
    Sleep(50);
    printf("t");
    Sleep(50);
    printf("u");
    Sleep(50);
    printf("t");
    Sleep(50);
    printf("e");
    Sleep(50);
    printf(" ");
    Sleep(50);
    printf("o");
    Sleep(50);
    printf("f");
    Sleep(50);
    printf(" ");
    Sleep(50);
    printf("T");
    Sleep(50);
    printf("e");
    Sleep(50);
    printf("c");
    Sleep(50);
    printf("h");
    Sleep(50);
    printf("n");
    Sleep(50);
    printf("o");
    Sleep(50);
    printf("l");
    Sleep(50);
    printf("o");
    Sleep(50);
    printf("g");
    Sleep(50);
    printf("y\n");
    Sleep(50);
    printf("\t\t\t\t   D");
    Sleep(50);
    printf("6");
    Sleep(50);
    printf("1");
    Sleep(50);
    printf("0");
    Sleep(50);
    printf("6\n");
    Sleep(50);
    printf("\t\t\t       A");
    Sleep(50);
    printf("l");
    Sleep(50);
    printf("l");
    Sleep(50);
    printf(" ");
    Sleep(50);
    printf("R");
    Sleep(50);
    printf("e");
    Sleep(50);
    printf("s");
    Sleep(50);
    printf("e");
    Sleep(50);
    printf("r");
    Sleep(50);
    printf("v");
    Sleep(50);
    printf("e");
    Sleep(50);
    printf("d\n");
    printf("=====================================================================\n");
    pressAnyKey();
}

void pressAnyKey()
{
      printf("按任意键继续...\n");
	  getch();
}
void staff()
{
    system("cls");
    printf("=====================================================================\n");
    printf("\t\t\t\t 张");
    Sleep(50);
    printf("磊\n\n");
    Sleep(50);
    printf("\t\t\t       欧");
    Sleep(50);
    printf("阳");
    Sleep(50);
    printf("孝");
    Sleep(50);
    printf("俊\n\n");
    Sleep(50);
    printf("\t\t\t\t谭");
    Sleep(50);
    printf("琳");
    Sleep(50);
    printf("琪\n\n");
    Sleep(50);
    printf("\t\t\t\t李");
    Sleep(50);
    printf("先");
    Sleep(50);
    printf("来\n");
    printf("=====================================================================\n");
    pressAnyKey();
}

int login()
{
    char inputname[20];
    char inputpwd[30];
    char choice;
    int i, j;
    for(i=1; i<=3; i++)
    {
        system("cls");
        printf("请输入用户名：");
        scanf("%s", inputname);
        printf("请输入用户密码：");
        for(j=0; (inputpwd[j]=getch())!='\r'; j++)
        {
            printf("*");
        }
        inputpwd[j] = '\0';
        printf("\n");

        if(strcmp(inputname, logname)==0&&strcmp(inputpwd, logpwd)==0)
            return 1;
        if(i==3)
        {
            printf("您的输入错误，已经达到最大输入次数\n");
            printf("为了系统的安全，系统将自动退出...\n");
            printf("如有疑问，请播打18879538430咨询...\n");
            exit(0);
        }
        printf("您输入的用户名或密码错误，请检查大小写后重新输，您还有%d次机会，是否继续（y/n）？", 3-i);
        fflush(stdin);
        choice = getchar();
        if(choice=='n')
            return 0;
    }
    return 0;
}
void showMainMenu()
{
    int choice = 0;
    struct Contact * head;
    char exitchoice;
    head = NULL;
    do{
		system( "cls");
		printf("\t\t   通讯录管理系统%s的帐户\n", logname);
		printf("=====================================================================\n");
		printf("|　　　　　　　　　     1.添加联系人                                |\n\n");
		Sleep(50);
		printf("|　　　　　　　　　     2.删除联系人                                |\n\n");
		Sleep(50);
		printf("|　　　　　　　　　     3.更新联系人信息                            |\n\n");
		Sleep(50);
		printf("|　　　　　　　　　     4.显示所有联系人信息                        |\n\n");
		Sleep(50);
		printf("|　　　　　　　　　     5.根据联系人姓名查询联系人信息              |\n\n");
		Sleep(50);
		printf("|　　　　　　　　　     6.统计总联系人人数                          |\n\n");
		Sleep(50);
		printf("|　　　　　　　　　     7.保存                                　　　|\n\n");
		Sleep(50);
		printf("|                       8.载入                                      |\n\n");
		Sleep(50);
		printf("|　　　　　　　　　     9.退出登录                                  |\n");
		Sleep(50);
		printf("=====================================================================\n");
		printf("请输入您的选项(1,2,3,4,5,6,7,8),以回车结束");
		scanf("%d",  &choice);

		switch(choice)
		{
        case 1:
            if(head==NULL)
                head = createContact();
            else
            {
                head = insertContact(head);
            }
            break;
        case 2:
            head = delContact(head);
            break;
        case 3:
            updateContact(head);
            break;
        case 4:
            showAllContacts(head);
            break;
        case 5:
            findContactByName(head);
            break;
        case 6:
            calculateNum();
            break;
        case 7:
            saveContact(head);
            break;
        case 8:
            head = loadContact();
            break;
        case 9:
            system("cls");
            printf("一旦退出登录，未保存的数据将会丢失，您是否确定退出登录？(y/n)");
            fflush(stdin);
            exitchoice = getchar();
            if(exitchoice=='y')
            {
                head = freeMemory(head);
                return;
            }

            break;
       default:
            printf("请输入有效选项(1,2,3,4,5,6,7,8,9)...\n");
            pressAnyKey();
		}
    }while(1);
}
struct Contact * createContact()
{
    struct Contact * head, * p1, * p2;
    char choice;
    head = NULL;
    system("cls");
    printf("您要添加联系人吗（y/n）？");
    fflush(stdin);
    choice = getchar();
    while(choice=='y')
    {
        system("cls");
        count++;
        p1 = (struct Contact *)malloc(sizeof(struct Contact));
        if(count==1)
        {
            head = p1;
            fflush(stdin);
            printf("请输入要添加的联系人的姓名：");
            gets(p1->name);
            printf("请输入要添加的联系人的电话号码：");
            gets(p1->tel);
            printf("请输入要添加的联系人的QQ：");
            gets(p1->qq);
            printf("请输入要添加的联系人的地址：");
            gets(p1->addr);
            system("cls");
            printf("\t\t\t您添加的联系人的信息如下：\n");
            printf("=====================================================================\n");
            printf("姓名\t\t电话号码\t\tQQ\t\t地址\n");
            printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
            p2 = p1;
            p1->next = NULL;
        }
        else
        {
            fflush(stdin);
            printf("请输入要添加的联系人的姓名：");
            gets(p1->name);
            printf("请输入要添加的联系人的电话号码：");
            gets(p1->tel);
            printf("请输入要添加的联系人的QQ：");
            gets(p1->qq);
            printf("请输入要添加的联系人的地址：");
            gets(p1->addr);
            system("cls");
            printf("\t\t\t您添加的联系人的信息如下：\n");
            printf("=====================================================================\n");
            printf("姓名\t\t电话号码\t\tQQ\t\t地址\n");
            printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
            p2->next = p1;
            p2 = p1;
            p1->next = NULL;
        }
        if(count==3)
        {
            printf("至此通讯录已达最大人数上限，如想继续添加联系人，请扩充磁盘或清除部分数据后再操作...\n");
            pressAnyKey();
            return head;
        }
        printf("您还可以添加%d个联系人，您要继续添加联系人吗（y/n）？", CALSS_NUM-count);
        fflush(stdin);
        choice = getchar();
    }
    return head;
}
struct Contact * insertContact(struct Contact * head)
{
    struct Contact * p1;
    char choice;
    system("cls");
    if(count==3)
    {
        printf("通讯录已达最大人数上限，如想继续添加联系人，请扩充磁盘或清除部分数据后再操作...\n");
        pressAnyKey();
        return head;
    }
    printf("您还可以添加%d个联系人，您要添加联系人吗（y/n）？", CALSS_NUM-count);
    fflush(stdin);
    choice = getchar();
    while(choice=='y')
    {
        system("cls");
        count++;
        p1 = (struct Contact *)malloc(sizeof(struct Contact));
        fflush(stdin);
        printf("请输入要添加的联系人的姓名：");
        gets(p1->name);
        printf("请输入要添加的联系人的电话号码：");
        gets(p1->tel);
        printf("请输入要添加的联系人的QQ：");
        gets(p1->qq);
        printf("请输入要添加的联系人的地址：");
        gets(p1->addr);
        system("cls");
        printf("\t\t\t您添加的联系人的信息如下：\n");
        printf("=====================================================================\n");
        printf("姓名\t\t电话号码\t\tQQ\t\t地址\n");
        printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
        p1->next = head;
        head = p1;
        if(count==3)
        {
            printf("至此通讯录已达最大人数上限，如想继续添加联系人，请扩充磁盘或清除部分数据后再操作...\n");
            pressAnyKey();
            return head;
        }
        printf("您还可以添加%d个联系人，您要继续添加联系人吗（y/n）？", CALSS_NUM-count);
        fflush(stdin);
        choice = getchar();
    }
    return head;
}
void showAllContacts(struct Contact * head)
{
    struct Contact * p;
    p = head;
    if(p==NULL)
    {
        system("cls");
        printf("目前没有联系人\n");
        pressAnyKey();
        return;
    }
    system("cls");
    printf("--------------------------所有联系人信息如下-------------------------\n");
    printf("=====================================================================\n");
    printf("姓名\t\t电话号码\t\tQQ\t\t地址\n");
    do
    {
        printf("%-16s%-24s%-16s%s\n", p->name, p->tel, p->qq, p->addr);
        p = p->next;
    }while(p!=NULL);
    pressAnyKey();
}
struct Contact * freeMemory(struct Contact * head)
{
    struct Contact * p1, * p2;
    p1 = p2 = head;
    if(p1==NULL)
    {
        return NULL;
        count = 0;
    }
    do
    {
        p1 = p1->next;
        free(p2);
        p2 = p1;
    }while(p1!=NULL);
    count = 0;
    return NULL;
}
void calculateNum()
{
    system("cls");
    printf("总共有%d个联系人\n", count);
    pressAnyKey();
}
void findContactByName(struct Contact * head)
{
    struct Contact * p;
    char tofindname[20];
    p = head;
    if(p==NULL)
    {
        system("cls");
        printf("目前还没有联系人，请添加后再操作...\n");
        pressAnyKey();
        return;
    }
    system("cls");
    printf("请输入要查找的联系人的姓名：");
    fflush(stdin);
    gets(tofindname);
    while(strcmp(tofindname, p->name)!=0)
    {
        p = p->next;
        if(p==NULL)
        {
            printf("无此联系人...\n");
            pressAnyKey();
            return;
        }
    }
    system("cls");
    printf("\t\t\t您所要查找的联系人的信息如下\n");
    printf("=====================================================================\n");
    printf("姓名\t\t电话号码\t\tQQ\t\t地址\n");
    printf("%-16s%-24s%-16s%s\n", p->name, p->tel, p->qq, p->addr);
    pressAnyKey();
}
struct Contact * delContact(struct Contact * head)
{
    struct Contact * p1, * p2, * p3;
    char delname[20], choice;
    p1 = p2 = head;
    if(p1==NULL)
    {
        system("cls");
        printf("目前没有联系人，无法执行删除操作...\n");
        pressAnyKey();
        return head;
    }
    system("cls");
    printf("请输入要删除的联系人的姓名：");
    fflush(stdin);
    gets(delname);
    while(strcmp(delname, p1->name)!=0)
    {
        p1 = p1->next;
        if(p1==NULL)
        {
            system("cls");
            printf("无此联系人...\n");
            pressAnyKey();
            return head;
        }
    }
    printf("\t\t\t您所要操作的联系人信息如下\n");
    printf("=====================================================================\n");
    printf("姓名\t\t电话号码\t\tQQ\t\t地址\n");
    printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
    printf("是否要删除（y/n）？");
    fflush(stdin);
    choice = getchar();
    if(choice == 'y')
    {
        if(p1==head)
        {
            p2 = p1;
            p1 = p1->next;
            head = p1;
            free(p2);
            count--;
            system("cls");
            printf("删除成功！");
            pressAnyKey();
            return head;
        }
        if(p1->next==NULL)
        {
            while(p2->next!=p1)
            {
                p2 = p2->next;
            }
            p2->next = NULL;
            free(p1);
            count--;
            system("cls");
            printf("删除成功！");
            pressAnyKey();
            return head;
        }
        else
        {
            while(p2->next!=p1)
            {
                p2 = p2->next;
            }
            p2->next = p1->next;
            free(p1);
            count--;
            system("cls");
            printf("删除成功！");
            pressAnyKey();
            return head;
        }
    }
    return head;
}
void updateContact(struct Contact * head)
{
    struct Contact * p1;
    char updatename[20], exitchoice;
    int choice;

    p1 = head;
    if(p1==NULL)
    {
        system("cls");
        printf("目前没有联系人，无法执行更新操作...\n");
        pressAnyKey();
        return head;
    }
    system("cls");
    printf("请输入要更新的联系人的姓名：");
    fflush(stdin);
    gets(updatename);
    while(strcmp(updatename, p1->name)!=0)
    {
        p1 = p1->next;
        if(p1==NULL)
        {
            system("cls");
            printf("无此联系人...\n");
            pressAnyKey();
            return;
        }
    }
    system("cls");
    printf("\t\t\t您所要操作的联系人信息如下\n");
    printf("=====================================================================\n");
    printf("姓名\t\t电话号码\t\tQQ\t\t地址\n");
    printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
    printf("确定要执行更新操作吗？（y/n）");
    exitchoice = getchar();
    if(exitchoice == 'y')
    {
        do
        {
            system("cls");
            printf("1.电话号码\n");
            printf("2.QQ\n");
            printf("3.地址\n");
            printf("4.确认更新后退出更新\n\n");
            printf("请输入您的选项(1,2,3,4),以回车结束");
            scanf("%d", &choice);
            switch(choice)
            {
            case 1:
                printf("请输入新的电话号码：");
                fflush(stdin);
                gets(p1->tel);
                printf("更新完成...");
                pressAnyKey();
                break;
            case 2:
                printf("请输入新的QQ：");
                fflush(stdin);
                gets(p1->qq);
                printf("更新完成...");
                pressAnyKey();
                break;
            case 3:
                printf("请输入新的地址：");
                fflush(stdin);
                gets(p1->addr);
                printf("更新完成...");
                pressAnyKey();
                break;
            case 4:
                system("cls");
                printf("此联系人更新完毕!\n");
                printf("=====================================================================\n");
                printf("姓名\t\t电话号码\t\tQQ\t\t地址\n");
                printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
                pressAnyKey();
                return;
            default:
                printf("请输入有效选项(1,2,3)...\n");
                pressAnyKey();
            }
        }while(1);
    }
    return;

}
void saveContact(struct Contact * head)
{
    FILE * fp;
    struct Contact * p1;
    char savechoice;
    p1 = head;
    if(p1==NULL)
    {
        system("cls");
        printf("目前无联系人，无需保存...\n");
        pressAnyKey();
        return;
    }
    system("cls");
    printf("保存将会覆盖已有存档，您确定保存吗？(y/n)");
    fflush(stdin);
    savechoice = getchar();
    if(savechoice == 'y')
    {
        if((fp=fopen("Contact.dat", "wb"))==NULL)
        {
            printf("cannot open file\n");
            exit(0);
        }
        while(p1!=NULL)
        {
            if(fwrite(p1, sizeof(struct Contact), 1, fp)!=1)
                printf("file write error\n");
            p1 = p1->next;
        }
        system("cls");
        printf("保存成功！\n");
        pressAnyKey();
        fclose(fp);
    }
    else
    {
        return;
    }

}
struct Contact * loadContact()
{
    struct Contact * head, * p1, * p2;
    FILE * fp;
    char loadchoice;
    count = 0;
    system("cls");
    printf("您确定载入记录?(y/n)");
    fflush(stdin);
    loadchoice = getchar();
    if(loadchoice == 'y')
    {
        if((fp=fopen("Contact.dat", "rb"))==NULL)
        {
            printf("目前无存档文件\n");
            pressAnyKey();
            return;
        }
        p1 = p2 = head = (struct Contact *)malloc(sizeof(struct Contact));
        while(fread(p1, sizeof(struct Contact), 1, fp)==1)
        {
            count++;
            p2 = p1;
            p1 = (struct Contact *)malloc(sizeof(struct Contact));
            p2->next = p1;
        }
        p2->next = NULL;
        fclose(fp);
        printf("载入成功！\n");
        pressAnyKey();
        return head;
    }
    else
    {
        return;
    }
}


