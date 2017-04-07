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
        printf("|������������������             1.��¼                              |\n\n");
        Sleep(100);
        printf("|                               2.��Ȩ                              |\n\n");
        Sleep(100);
        printf("|                               3.������Ա                          |\n\n");
        Sleep(100);
        printf("|                               4.�˳�                              |\n");
        printf("=====================================================================\n");
        printf("����������ѡ��(1/2/3/4),���س���ȷ��...");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            if(login()==1)
            {
                printf("��¼�ɹ������Ժ�...");
                Sleep(1000);
                showMainMenu();
            }
            else
            {
                system("cls");
                printf("��¼ʧ��...\n");
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
            printf("��ȷ��Ҫ�˳�ͨѶ¼����ϵͳ1.0����y/n��");
            fflush(stdin);
            exitchoice = getchar();
            if(exitchoice == 'y')
            {
                exit(0);
            }
            break;
        default:
            printf("��������Чѡ��(1,2,3,4)...\n");
		    pressAnyKey();
        }
    }while(1);

    return 0;
}

void title()
{
    printf("\t\t\t��");
    Sleep(50);
    printf("ӭ");
    Sleep(50);
    printf("ʹ");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("ͨ");
    Sleep(50);
    printf("Ѷ");
    Sleep(50);
    printf("¼");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("ϵ");
    Sleep(50);
    printf("ͳ");
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
      printf("�����������...\n");
	  getch();
}
void staff()
{
    system("cls");
    printf("=====================================================================\n");
    printf("\t\t\t\t ��");
    Sleep(50);
    printf("��\n\n");
    Sleep(50);
    printf("\t\t\t       ŷ");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("Т");
    Sleep(50);
    printf("��\n\n");
    Sleep(50);
    printf("\t\t\t\t̷");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("��\n\n");
    Sleep(50);
    printf("\t\t\t\t��");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("��\n");
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
        printf("�������û�����");
        scanf("%s", inputname);
        printf("�������û����룺");
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
            printf("������������Ѿ��ﵽ����������\n");
            printf("Ϊ��ϵͳ�İ�ȫ��ϵͳ���Զ��˳�...\n");
            printf("�������ʣ��벥��18879538430��ѯ...\n");
            exit(0);
        }
        printf("��������û�����������������Сд�������䣬������%d�λ��ᣬ�Ƿ������y/n����", 3-i);
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
		printf("\t\t   ͨѶ¼����ϵͳ%s���ʻ�\n", logname);
		printf("=====================================================================\n");
		printf("|������������������     1.�����ϵ��                                |\n\n");
		Sleep(50);
		printf("|������������������     2.ɾ����ϵ��                                |\n\n");
		Sleep(50);
		printf("|������������������     3.������ϵ����Ϣ                            |\n\n");
		Sleep(50);
		printf("|������������������     4.��ʾ������ϵ����Ϣ                        |\n\n");
		Sleep(50);
		printf("|������������������     5.������ϵ��������ѯ��ϵ����Ϣ              |\n\n");
		Sleep(50);
		printf("|������������������     6.ͳ������ϵ������                          |\n\n");
		Sleep(50);
		printf("|������������������     7.����                                ������|\n\n");
		Sleep(50);
		printf("|                       8.����                                      |\n\n");
		Sleep(50);
		printf("|������������������     9.�˳���¼                                  |\n");
		Sleep(50);
		printf("=====================================================================\n");
		printf("����������ѡ��(1,2,3,4,5,6,7,8),�Իس�����");
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
            printf("һ���˳���¼��δ��������ݽ��ᶪʧ�����Ƿ�ȷ���˳���¼��(y/n)");
            fflush(stdin);
            exitchoice = getchar();
            if(exitchoice=='y')
            {
                head = freeMemory(head);
                return;
            }

            break;
       default:
            printf("��������Чѡ��(1,2,3,4,5,6,7,8,9)...\n");
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
    printf("��Ҫ�����ϵ����y/n����");
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
            printf("������Ҫ��ӵ���ϵ�˵�������");
            gets(p1->name);
            printf("������Ҫ��ӵ���ϵ�˵ĵ绰���룺");
            gets(p1->tel);
            printf("������Ҫ��ӵ���ϵ�˵�QQ��");
            gets(p1->qq);
            printf("������Ҫ��ӵ���ϵ�˵ĵ�ַ��");
            gets(p1->addr);
            system("cls");
            printf("\t\t\t����ӵ���ϵ�˵���Ϣ���£�\n");
            printf("=====================================================================\n");
            printf("����\t\t�绰����\t\tQQ\t\t��ַ\n");
            printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
            p2 = p1;
            p1->next = NULL;
        }
        else
        {
            fflush(stdin);
            printf("������Ҫ��ӵ���ϵ�˵�������");
            gets(p1->name);
            printf("������Ҫ��ӵ���ϵ�˵ĵ绰���룺");
            gets(p1->tel);
            printf("������Ҫ��ӵ���ϵ�˵�QQ��");
            gets(p1->qq);
            printf("������Ҫ��ӵ���ϵ�˵ĵ�ַ��");
            gets(p1->addr);
            system("cls");
            printf("\t\t\t����ӵ���ϵ�˵���Ϣ���£�\n");
            printf("=====================================================================\n");
            printf("����\t\t�绰����\t\tQQ\t\t��ַ\n");
            printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
            p2->next = p1;
            p2 = p1;
            p1->next = NULL;
        }
        if(count==3)
        {
            printf("����ͨѶ¼�Ѵ�����������ޣ�������������ϵ�ˣ���������̻�����������ݺ��ٲ���...\n");
            pressAnyKey();
            return head;
        }
        printf("�����������%d����ϵ�ˣ���Ҫ���������ϵ����y/n����", CALSS_NUM-count);
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
        printf("ͨѶ¼�Ѵ�����������ޣ�������������ϵ�ˣ���������̻�����������ݺ��ٲ���...\n");
        pressAnyKey();
        return head;
    }
    printf("�����������%d����ϵ�ˣ���Ҫ�����ϵ����y/n����", CALSS_NUM-count);
    fflush(stdin);
    choice = getchar();
    while(choice=='y')
    {
        system("cls");
        count++;
        p1 = (struct Contact *)malloc(sizeof(struct Contact));
        fflush(stdin);
        printf("������Ҫ��ӵ���ϵ�˵�������");
        gets(p1->name);
        printf("������Ҫ��ӵ���ϵ�˵ĵ绰���룺");
        gets(p1->tel);
        printf("������Ҫ��ӵ���ϵ�˵�QQ��");
        gets(p1->qq);
        printf("������Ҫ��ӵ���ϵ�˵ĵ�ַ��");
        gets(p1->addr);
        system("cls");
        printf("\t\t\t����ӵ���ϵ�˵���Ϣ���£�\n");
        printf("=====================================================================\n");
        printf("����\t\t�绰����\t\tQQ\t\t��ַ\n");
        printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
        p1->next = head;
        head = p1;
        if(count==3)
        {
            printf("����ͨѶ¼�Ѵ�����������ޣ�������������ϵ�ˣ���������̻�����������ݺ��ٲ���...\n");
            pressAnyKey();
            return head;
        }
        printf("�����������%d����ϵ�ˣ���Ҫ���������ϵ����y/n����", CALSS_NUM-count);
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
        printf("Ŀǰû����ϵ��\n");
        pressAnyKey();
        return;
    }
    system("cls");
    printf("--------------------------������ϵ����Ϣ����-------------------------\n");
    printf("=====================================================================\n");
    printf("����\t\t�绰����\t\tQQ\t\t��ַ\n");
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
    printf("�ܹ���%d����ϵ��\n", count);
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
        printf("Ŀǰ��û����ϵ�ˣ�����Ӻ��ٲ���...\n");
        pressAnyKey();
        return;
    }
    system("cls");
    printf("������Ҫ���ҵ���ϵ�˵�������");
    fflush(stdin);
    gets(tofindname);
    while(strcmp(tofindname, p->name)!=0)
    {
        p = p->next;
        if(p==NULL)
        {
            printf("�޴���ϵ��...\n");
            pressAnyKey();
            return;
        }
    }
    system("cls");
    printf("\t\t\t����Ҫ���ҵ���ϵ�˵���Ϣ����\n");
    printf("=====================================================================\n");
    printf("����\t\t�绰����\t\tQQ\t\t��ַ\n");
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
        printf("Ŀǰû����ϵ�ˣ��޷�ִ��ɾ������...\n");
        pressAnyKey();
        return head;
    }
    system("cls");
    printf("������Ҫɾ������ϵ�˵�������");
    fflush(stdin);
    gets(delname);
    while(strcmp(delname, p1->name)!=0)
    {
        p1 = p1->next;
        if(p1==NULL)
        {
            system("cls");
            printf("�޴���ϵ��...\n");
            pressAnyKey();
            return head;
        }
    }
    printf("\t\t\t����Ҫ��������ϵ����Ϣ����\n");
    printf("=====================================================================\n");
    printf("����\t\t�绰����\t\tQQ\t\t��ַ\n");
    printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
    printf("�Ƿ�Ҫɾ����y/n����");
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
            printf("ɾ���ɹ���");
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
            printf("ɾ���ɹ���");
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
            printf("ɾ���ɹ���");
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
        printf("Ŀǰû����ϵ�ˣ��޷�ִ�и��²���...\n");
        pressAnyKey();
        return head;
    }
    system("cls");
    printf("������Ҫ���µ���ϵ�˵�������");
    fflush(stdin);
    gets(updatename);
    while(strcmp(updatename, p1->name)!=0)
    {
        p1 = p1->next;
        if(p1==NULL)
        {
            system("cls");
            printf("�޴���ϵ��...\n");
            pressAnyKey();
            return;
        }
    }
    system("cls");
    printf("\t\t\t����Ҫ��������ϵ����Ϣ����\n");
    printf("=====================================================================\n");
    printf("����\t\t�绰����\t\tQQ\t\t��ַ\n");
    printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
    printf("ȷ��Ҫִ�и��²����𣿣�y/n��");
    exitchoice = getchar();
    if(exitchoice == 'y')
    {
        do
        {
            system("cls");
            printf("1.�绰����\n");
            printf("2.QQ\n");
            printf("3.��ַ\n");
            printf("4.ȷ�ϸ��º��˳�����\n\n");
            printf("����������ѡ��(1,2,3,4),�Իس�����");
            scanf("%d", &choice);
            switch(choice)
            {
            case 1:
                printf("�������µĵ绰���룺");
                fflush(stdin);
                gets(p1->tel);
                printf("�������...");
                pressAnyKey();
                break;
            case 2:
                printf("�������µ�QQ��");
                fflush(stdin);
                gets(p1->qq);
                printf("�������...");
                pressAnyKey();
                break;
            case 3:
                printf("�������µĵ�ַ��");
                fflush(stdin);
                gets(p1->addr);
                printf("�������...");
                pressAnyKey();
                break;
            case 4:
                system("cls");
                printf("����ϵ�˸������!\n");
                printf("=====================================================================\n");
                printf("����\t\t�绰����\t\tQQ\t\t��ַ\n");
                printf("%-16s%-24s%-16s%s\n", p1->name, p1->tel, p1->qq, p1->addr);
                pressAnyKey();
                return;
            default:
                printf("��������Чѡ��(1,2,3)...\n");
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
        printf("Ŀǰ����ϵ�ˣ����豣��...\n");
        pressAnyKey();
        return;
    }
    system("cls");
    printf("���潫�Ḳ�����д浵����ȷ��������(y/n)");
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
        printf("����ɹ���\n");
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
    printf("��ȷ�������¼?(y/n)");
    fflush(stdin);
    loadchoice = getchar();
    if(loadchoice == 'y')
    {
        if((fp=fopen("Contact.dat", "rb"))==NULL)
        {
            printf("Ŀǰ�޴浵�ļ�\n");
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
        printf("����ɹ���\n");
        pressAnyKey();
        return head;
    }
    else
    {
        return;
    }
}


