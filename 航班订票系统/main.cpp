#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>



/*航班信息*/
typedef struct Flight
{
    char flightID[10];           //航班号
    char takeOffTime[20];   //起飞时间
    char landOnTime[20];    //降落时间
    char origin[20];        //出发地
    char destination[20];   //目的地
    float price;           //单位票价
    float discount;                         //折扣
    int maxNum;             //可容纳最大乘客数量
    int currNum;            //当前人数
    struct Flight* next;
}Flight;
/*订单信息*/
typedef struct OrderList
{
    int orderID;            //订单编号
    char flightID[10];    //预订的航班的航班号
    Flight* orderFlight;//预订的航班
    struct OrderList* next;
}OrderList;
/*用户信息*/
typedef struct User
{
    char userName[50];      //用户名
    char userPwd[18];       //用户密码
    char name[50];          //用户真实姓名
    char ID[19];            //用户的身份证号码
    int ticketNum;          //用户的订票数量
    OrderList* ol;          //用户的订单
    struct User* next;
}User;

const char* adminName = "admin";//管理员用户名
const char* adminPwd = "admin";//管理员密码


void loadUser(User* user);          //加载用户信息
void loadFlight(Flight* flight);    //加载航班信息
void saveUser(User* user);          //保存用户信息
void saveFlight(Flight* flight);    //保存航班信息
void pressAnyKey();                 //按任意键继续
void logIn(User* user,Flight* flight);                       //登录
void signIn(User* user);            //注册
void displayAllUsers(User* user);   //显示所有用户信息表
User* searchUserByName(User* user, char* userName); //通过用户名查找用户
void normalUserMenu(User* currUser, Flight* flight, User* user); //进入当前的普通用户菜单
void adminMenu(User* user, Flight* flight);                    //进入管理员菜单
void addFlight(Flight* flight);         //添加新的航班信息
void displayAllFlights(Flight* flight); //显示所有航班信息
Flight* searchFlightByID(Flight* flight);  //根据航班号查找航班信息
void updateFlight(Flight* searchedFlight); //对打到的航班进行修改
void saveAllFlgihts(Flight* flight);           //保存更改过的航班文件（即全部保存一遍）
void deleteFlight(Flight* currFlight, Flight* flight);//删除查找到的航班记录
void updateUser(User* currUser);                //修改当前用户的信息
void saveAllUsers(User* user);                   //保存更改过的用户文件（即全部保存一遍）
void searchFlightByOrigin(Flight* flight);   //根据出发地查找航班信息
void searchFlightByDestination(Flight* flight);   //根据目的地查找航班信息
void loadOrderListByUserName(User* currUser,Flight* flight);//不同的用户载入不同的订单
void displayOrderList(User* currUser);      //显示当前用户的订单信息
void orderOperation(User* currUser, Flight* flight);//订票操作
void saveOrder(OrderList* order, char* userName);//保存新添加的订票记录
void saveAllOrders(User* currUser);//保存当前用户的所有的订单记录
int deleteOrder(OrderList* currOrder, OrderList* order);

int main()
{
    char choice;
    User* user = (User*)malloc(sizeof(User));
    user->next = NULL;
    Flight* flight = (Flight*)malloc(sizeof(Flight));
    flight->next = NULL;
    //首先从数据文件中把航班信息和用户信息提取到两个链表中
    loadUser(user);
    loadFlight(flight);

    do{
        system("cls");
        printf("============================欢迎使用航班订票系统============================\n");
        printf("|                                 1.登录                                   |\n");
        printf("|                                 2.注册                                   |\n");
        printf("|                                 3.退出                                   |\n");
        printf("============================================================================\n");
        printf("请输入相应序号后按回车键进行相关操作(1,2,3):");
        scanf("%c", &choice);
        fflush(stdin);
        if(choice=='1')
        {
            logIn(user,flight);
        }else if(choice=='2')
        {
            signIn(user);
        }else if(choice=='3')
        {
            break;
        }else
        {
            printf("输入的选项无效，请重新输入有效选项...");
            pressAnyKey();
        }
    }while(true);
    return 0;
}
void normalUserMenu(User* currUser, Flight* flight, User* user)
{
    currUser->ol = (OrderList*)malloc(sizeof(OrderList));
    currUser->ol->next = NULL;
    char choice;
    int logout = 1;
    loadOrderListByUserName(currUser,flight);//登录进来之后，立刻载入订单记录到当前用户
    do{
        system("cls");
        printf("                                   %s的主菜单\n",currUser->userName);
        printf("===============================================================================\n");
        printf("|                               1.查看或更改个人用户信息                      |\n");
        printf("|                               2.查看所有航班信息                            |\n");
        printf("|                               3.根据航班号查找航班信息                      |\n");
        printf("|                               4.根据出发地查找航班信息                      |\n");
        printf("|                               5.根据目的地查找航班信息                      |\n");
        printf("|                               6.订票                                        |\n");
        printf("|                               7.查看订单                                    |\n");
        printf("|                               8.注销                                        |\n");
        printf("===============================================================================\n");
        printf("请输入相应序号后按回车键进行相关操作(1,2,3...):");
        scanf("%c",&choice);
        fflush(stdin);
        switch(choice)
        {
        case '1':
            updateUser(currUser);
            saveAllUsers(user);
            break;
        case '2':
            displayAllFlights(flight);
            break;
        case '3':
            searchFlightByID(flight);
            break;
        case '4':
            searchFlightByOrigin(flight);
            break;
        case '5':
            searchFlightByDestination(flight);
            break;
        case '6':
            orderOperation(currUser, flight);
            break;
        case '7':
            displayOrderList(currUser);
            break;
        case '8':
            logout = 0;
            saveAllOrders(currUser);
            saveAllFlgihts(flight);
            break;
        default:
            printf("输入的选项无效，请重新输入有效选项...");
            break;
        }
        pressAnyKey();
    }while(logout);
}
void orderOperation(User* currUser, Flight* flight)
{
    char choice;

    system("cls");
    printf("订票\n");
    Flight* searchedFlight = searchFlightByID(flight);
    if(searchedFlight==NULL)
    {
        printf("无此航班...\n");
    }else
    {
        printf("您要预定此航班吗？(y/n):");
        scanf("%c",&choice);
        fflush(stdin);
        if(choice=='y')
        {
            if(searchedFlight->currNum!=searchedFlight->maxNum)
            {
                OrderList* p = (OrderList*)malloc(sizeof(OrderList));
                strcpy(p->flightID,searchedFlight->flightID);
                p->orderFlight = searchedFlight;
                if(currUser->ol->next==NULL)
                {
                    p->orderID = 10001;
                }else
                {
                    p->orderID = currUser->ol->next->orderID+1;
                }

                p->next = currUser->ol->next;
                currUser->ol->next = p;
                saveOrder(p,currUser->userName);
                currUser->ticketNum++;
                searchedFlight->currNum++;
            }else
            {
                printf("当前航班机票已售完！");
            }
        }else
        {
            printf("已取消订票...\n");
        }
    }
}

void saveOrder(OrderList* order, char* userName)
{
    FILE* out = NULL;
    char str[] = "_order.dat";
    char tempName[50];
    strcpy(tempName,userName);
    strcat(tempName,str);
    if((out=fopen(tempName,"ab"))==NULL)
    {
        printf("订单信息文件保存失败\n");
        exit(0);
    }
    fwrite(order,sizeof(OrderList),1,out);
    fclose(out);

}
void loadOrderListByUserName(User* currUser,Flight* flight)
{
    FILE* in = NULL;
    char str[] = "_order.dat";
    char tempName[50];
    strcpy(tempName,currUser->userName);
    strcat(tempName,str);
    if((in=fopen(tempName,"rb"))==NULL)
    {
        printf("订单信息文件载入失败\n");
        exit(0);
    }

    OrderList* newOrder = (OrderList*)malloc(sizeof(OrderList));
    while(fread(newOrder,sizeof(OrderList),1,in)==1)
    {
        newOrder->next = currUser->ol->next;
        currUser->ol->next = newOrder;

        Flight* p = flight->next;
        while(p)
        {
            if(strcmp(newOrder->flightID,p->flightID)==0)
            {
                newOrder->orderFlight = p;
                break;
            }
            p = p->next;
        }

        newOrder = (OrderList*)malloc(sizeof(OrderList));
    }
    free(newOrder);
    fclose(in);
}
void displayOrderList(User* currUser)
{
    char choice;
    OrderList* p = NULL;
    do{
        p = currUser->ol->next;
        system("cls");
        printf("                                用户%s的订单如下\n",currUser->userName);
        printf("===============================================================================\n");
        printf("订单编号 客户  航班号 起飞时间         降落时间         出发地  目的地  票价\n");
        printf("===============================================================================\n");

        if(p==NULL) break;

        while(p)
        {
            printf("%-9d%-6s%-7s%-17s%-17s%-8s%-8s%-9.2f\n",p->orderID, currUser->userName, p->orderFlight->flightID,p->orderFlight->takeOffTime,p->orderFlight->landOnTime,p->orderFlight->origin,p->orderFlight->destination,p->orderFlight->price);
            p = p->next;
        }
        p = currUser->ol->next;

        printf("1.退票\n");
        printf("0.返回上一层\n");
        scanf("%c",&choice);
        fflush(stdin);
        if(choice=='1')
        {
            int orderID;
            printf("请输入订单编号:");
            scanf("%d",&orderID);
            fflush(stdin);
            while(p)
            {
                if(p->orderID == orderID)
                {
                    printf("%-9d%-6s%-7s%-17s%-17s%-8s%-8s%-9.2f\n",p->orderID, currUser->userName, p->orderFlight->flightID,p->orderFlight->takeOffTime,p->orderFlight->landOnTime,p->orderFlight->origin,p->orderFlight->destination,p->orderFlight->price);
                    if(deleteOrder(p,currUser->ol)==1)//退了
                    {
                        currUser->ticketNum--;
                    }
                    break;
                }
                p = p->next;
            }
        }else
        {
            break;
        }
    }while(true);
}
int deleteOrder(OrderList* currOrder, OrderList* order)
{
    OrderList* p = order->next;
    char choice;
    printf("确定要退票吗？(y/n)");
    scanf("%c",&choice);
    fflush(stdin);
    if(choice=='y' || choice=='Y')
    {
        printf("%d订单已删除...\n",currOrder->orderID);
        currOrder->orderFlight->currNum--;
        if(p==currOrder)
        {
            order->next = currOrder->next;
            free(currOrder);
        }else
        {
            while(p)
            {
                if(p->next == currOrder)
                {
                    p->next = currOrder->next;
                    free(currOrder);
                    break;
                }
                p = p->next;
            }
        }
        return 1;//退了
    }
    return 0;//没退
}
void saveAllOrders(User* currUser)
{
    FILE* out = NULL;
    char str[] = "_order.dat";
    char tempName[50];
    strcpy(tempName,currUser->userName);
    strcat(tempName,str);
    if((out=fopen(tempName,"wb"))==NULL)
    {
        printf("用户信息文件保存失败\n");
        exit(0);
    }
    OrderList* p = currUser->ol->next;
    while(p)
    {
        fwrite(p,sizeof(OrderList),1,out);
        p = p->next;
    }
    fclose(out);
}
void searchFlightByOrigin(Flight* flight)
{
    char origin[20];
    Flight* p = flight->next;
    system("cls");
    printf("请输入出发地:");
    scanf("%s", origin);
    fflush(stdin);
    printf("查找的结果如下:\n");
    printf("===============================================================================\n");
    printf("航班号 起飞时间         降落时间         出发地   目的地   机票单价 折扣 总人数\n");
    printf("===============================================================================\n");
    while(p)
    {
        if(strcmp(p->origin,origin) == 0)
        {
            printf("%-7s%-17s%-17s%-9s%-9s%-9.2f%-5.2f%3d/%d\n", p->flightID,p->takeOffTime,p->landOnTime,p->origin,p->destination,p->price,p->discount,p->currNum,p->maxNum);
        }
        p = p->next;
    }
}
void searchFlightByDestination(Flight* flight)
{
    char destination[10];
    Flight* p = flight->next;
    system("cls");
    printf("请输入目的地:");
    scanf("%s", destination);
    fflush(stdin);
    printf("查找的结果如下:\n");
    printf("===============================================================================\n");
    printf("航班号 起飞时间         降落时间         出发地   目的地   机票单价 折扣 总人数\n");
    printf("===============================================================================\n");
    while(p)
    {
        if(strcmp(p->destination,destination) == 0)
        {
            printf("%-7s%-17s%-17s%-9s%-9s%-9.2f%-5.2f%3d/%d\n", p->flightID,p->takeOffTime,p->landOnTime,p->origin,p->destination,p->price,p->discount,p->currNum,p->maxNum);
        }
        p = p->next;
    }
}
void updateUser(User* currUser)
{
    char choice;
    int flag = 1;
    do{
        system("cls");
        printf("                               用户%s信息如下\n",currUser->userName);
        printf("===============================================================================\n");
        printf("姓名\t    身份证\t\t 用户名\t\t   密码\t\t     订票数\n");
        printf("===============================================================================\n");
        printf("%-12s%-21s%-18s%-18s%d\n",currUser->name,currUser->ID,currUser->userName,currUser->userPwd,currUser->ticketNum);
        printf("1.姓名\n");
        printf("2.身份证\n");
        printf("3.用户名\n");
        printf("4.密码\n");
        printf("0.返回上一层\n");
        printf("要修改哪一项(1,2,3...):\n");
        scanf("%c", &choice);
        fflush(stdin);
        switch(choice)
        {
        case '1':
            printf("请输入新的姓名:");
            scanf("%s",currUser->name);
            break;
        case '2':
            printf("请输入新的身份证号码:");
            scanf("%s",currUser->ID);
            break;
        case '3':
            printf("请输入新的用户名:");
            scanf("%s",currUser->userName);
            break;
        case '4':
            printf("请输入新的密码:");
            scanf("%s",currUser->userPwd);
            break;
        case '0':
            flag = 0;
            break;
        default:
            break;
            printf("请输入有效选项(1,2,3...)");
            pressAnyKey();
            break;
        }
    }while(flag);
}
void adminMenu(User* user, Flight* flight)
{
    char choice;
    int logout = 1;
    Flight* searchedFlight = NULL;
    do{
        system("cls");
        printf("                               管理员%s的主菜单\n",adminName);
        printf("===============================================================================\n");
        printf("|                               1.添加航班信息                                |\n");
        printf("|                               2.删除航班信息                                |\n");
        printf("|                               3.修改航班信息                                |\n");
        printf("|                               4.根据航班号查找航班信息                      |\n");
        printf("|                               5.显示所有航班的相关信息                      |\n");
        printf("|                               6.显示所有用户的相关信息                      |\n");
        printf("|                               7.注销                                        |\n");
        printf("===============================================================================\n");
        printf("请输入相应序号后按回车键进行相关操作(1,2,3...):");
        scanf("%c",&choice);
        fflush(stdin);
        switch(choice)
        {
        case '1':
            addFlight(flight);
            break;
        case '2':
            searchedFlight = searchFlightByID(flight);
            if(searchedFlight)
            {
                deleteFlight(searchedFlight,flight);
            }else
            {
                printf("无此航班...\n");
            }
            break;
        case '3':
            searchedFlight = searchFlightByID(flight);
            if(searchedFlight)
            {
                updateFlight(searchedFlight);
            }else
            {
                printf("无此航班...\n");
            }
            break;
        case '4':
            searchFlightByID(flight);
            break;
        case '5':
            displayAllFlights(flight);
            break;
        case '6':
            displayAllUsers(user);
            break;
        case '7':
            printf("即将注销当前用户\n");
            saveAllFlgihts(flight);
            logout = 0;
            break;
        default:
            printf("输入的选项无效，请重新输入有效选项...");
            break;
        }
        pressAnyKey();
    }while(logout);
}

void deleteFlight(Flight* currFlight, Flight* flight)
{
    Flight* p = flight->next;
    char choice;
    printf("确定要删除此航班记录吗？(y/n)");
    scanf("%c",&choice);
    fflush(stdin);
    if(choice=='y' || choice=='Y')
    {
        printf("%s航班记录已删除...\n",currFlight->flightID);
        if(p==currFlight)
        {
            flight->next = currFlight->next;
            free(currFlight);
        }else
        {
            while(p)
            {
                if(p->next == currFlight)
                {
                    p->next = currFlight->next;
                    free(currFlight);
                    break;
                }
                p = p->next;
            }
        }
    }
}
void updateFlight(Flight* currFlight)
{
    char choice;
    int flag = 1;
    do{
        system("cls");
        printf("===============================================================================\n");
        printf("航班号 起飞时间         降落时间         出发地   目的地   机票单价 折扣 总人数\n");
        printf("===============================================================================\n");
        printf("%-7s%-17s%-17s%-9s%-9s%-9.2f%-5.2f%3d/%d\n", currFlight->flightID,currFlight->takeOffTime,currFlight->landOnTime,currFlight->origin,currFlight->destination,currFlight->price,currFlight->discount,currFlight->currNum,currFlight->maxNum);
        printf("1.起飞时间\n");
        printf("2.降落时间\n");
        printf("3.出发地\n");
        printf("4.目的地\n");
        printf("5.票价\n");
        printf("6.折扣\n");
        printf("0.返回上一层\n");
        printf("要修改哪一项(1,2,3...):");
        scanf("%c", &choice);
        fflush(stdin);
        switch(choice)
        {
        case '1':
            printf("请输入新的起飞时间(yyyy-mm-dd-hh:mm):");
            scanf("%s",currFlight->takeOffTime);
            break;
        case '2':
            printf("请输入新的降落时间(yyyy-mm-dd-hh:mm):");
            scanf("%s",currFlight->landOnTime);
            break;
        case '3':
            printf("请输入新的出发地:");
            scanf("%s",currFlight->origin);
            break;
        case '4':
            printf("请输入新的目的地:");
            scanf("%s",currFlight->destination);
            break;
        case '5':
            printf("请输入新的票价:");
            scanf("%f",&(currFlight->price));
            break;
        case '6':
            printf("请输入新的折扣:");
            scanf("%f",&(currFlight->discount));
            break;
        case '7':
            printf("请输入新的当前人数:");
            scanf("%d",&(currFlight->currNum));
            break;
        case '0':
            flag = 0;
            break;
        default:
            printf("请输入有效选项(1,2,3...)");
            pressAnyKey();
            break;
        }
        fflush(stdin);
    }while(flag);
}

Flight* searchFlightByID(Flight* flight)
{
    char flightID[10];
    Flight* p = flight->next;
    system("cls");
    printf("请输入航班号:");
    scanf("%s", flightID);
    fflush(stdin);
    printf("查找的结果如下:\n");
    printf("===============================================================================\n");
    printf("航班号 起飞时间         降落时间         出发地   目的地   机票单价 折扣 总人数\n");
    printf("===============================================================================\n");
    while(p)
    {
        if(strcmp(p->flightID,flightID) == 0)
        {
            printf("%-7s%-17s%-17s%-9s%-9s%-9.2f%-5.2f%3d/%d\n", p->flightID,p->takeOffTime,p->landOnTime,p->origin,p->destination,p->price,p->discount,p->currNum,p->maxNum);
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void addFlight(Flight* flight)
{
    Flight* newFlight = (Flight*)malloc(sizeof(Flight));

    printf("添加航班信息\n");
    printf("航班号:");
    scanf("%s", &newFlight->flightID);
    printf("起飞时间(yyyy-mm-dd-hh:mm):");
    scanf("%s", newFlight->takeOffTime);
    printf("降落时间(yyyy-mm-dd-hh:mm):");
    scanf("%s", newFlight->landOnTime);
    printf("出发地点:");
    scanf("%s", newFlight->origin);
    printf("目的地点:");
    scanf("%s", newFlight->destination);
    printf("机票单价:");
    scanf("%f", &(newFlight->price));
    printf("票价折扣:");
    scanf("%f", &(newFlight->discount));
    printf("最大乘客数量:");
    scanf("%d", &(newFlight->maxNum));
    newFlight->currNum = 0;

    saveFlight(newFlight);
    newFlight->next = flight->next;
    flight->next = newFlight;

    printf("航班添加成功...\n");
    fflush(stdin);
    Sleep(1000);
}
User* searchUserByName(User* user, char* userName)
{
    User* p = user->next;
    while(p)
    {
        if(strcmp(p->userName, userName) == 0)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
void displayAllFlights(Flight* flight)
{
    Flight* p = flight->next;
    system("cls");
    printf("==================================所有航班信息=================================\n");
    printf("航班号 起飞时间         降落时间         出发地   目的地   机票单价 折扣 总人数\n");
    printf("===============================================================================\n");
    while(p!=NULL)
    {
        printf("%-7s%-17s%-17s%-9s%-9s%-9.2f%-5.2f%3d/%d\n", p->flightID,p->takeOffTime,p->landOnTime,p->origin,p->destination,p->price,p->discount,p->currNum,p->maxNum);
        p = p->next;
    }
}
void displayAllUsers(User* user)
{
    User* p = user->next;
    system("cls");
    printf("==================================所有用户信息==================================");
    printf("姓名\t    身份证\t\t 用户名\t\t   密码\t\t     订票数\n");
    printf("===============================================================================\n");
    while(p!=NULL)
    {
        printf("%-12s%-21s%-18s%-18s%d\n",p->name,p->ID,p->userName,p->userPwd,p->ticketNum);
        p = p->next;
    }
}
void loadUser(User* user)
{
    FILE* in = NULL;
    if((in=fopen("user.dat","rb"))==NULL)
    {
        printf("用户信息文件载入失败\n");
        exit(0);
    }

    User* newUser = (User*)malloc(sizeof(User));
    while(fread(newUser,sizeof(User),1,in)==1)
    {
        newUser->next = user->next;
        user->next = newUser;
        newUser = (User*)malloc(sizeof(User));
    }
    free(newUser);
    fclose(in);
}
void loadFlight(Flight* flight)
{
    FILE* in = NULL;
    if((in=fopen("flight.dat","rb"))==NULL)
    {
        printf("航班信息文件载入失败\n");
        exit(0);
    }

    Flight* newFlight = (Flight*)malloc(sizeof(Flight));
    while(fread(newFlight,sizeof(Flight),1,in)==1)
    {
        newFlight->next = flight->next;
        flight->next = newFlight;
        newFlight = (Flight*)malloc(sizeof(Flight));
    }
    free(newFlight);
    fclose(in);
}
void saveAllUsers(User* user)
{
    FILE* out = NULL;
    if((out=fopen("user.dat","wb"))==NULL)
    {
        printf("用户信息文件保存失败\n");
        exit(0);
    }
    User* p = user->next;
    while(p)
    {
        fwrite(p,sizeof(User),1,out);
        p = p->next;
    }
    fclose(out);
}
void saveUser(User* user)
{
    FILE* out = NULL;
    if((out=fopen("user.dat","ab"))==NULL)
    {
        printf("用户信息文件保存失败\n");
        exit(0);
    }
    fwrite(user,sizeof(User),1,out);
    fclose(out);
}
void saveAllFlgihts(Flight* flight)
{
    FILE* out = NULL;
    if((out=fopen("flight.dat","wb"))==NULL)
    {
        printf("航班信息文件保存失败\n");
        exit(0);
    }
    Flight* p = flight->next;
    while(p)
    {
        fwrite(p,sizeof(Flight),1,out);
        p = p->next;
    }
    fclose(out);
}
//void saveUpdatedUser(User* currUser,User* user)
//{
//    User* p = user->next;
//    int cnt = 0;
//    while(p!=currUser)
//    {
//        cnt++;
//        p = p->next;
//    }
//    FILE* out = NULL;
//    if((out=fopen("user.dat","wb"))==NULL)
//    {
//        printf("用户信息文件保存失败\n");
//        exit(0);
//    }
//    fseek(out,cnt*sizeof(User),0);
//    fwrite(currUser,sizeof(User),1,out);
//    fclose(out);
//}
void saveFlight(Flight* flight)
{
    FILE* out = NULL;
    if((out=fopen("flight.dat","ab"))==NULL)
    {
        printf("航班信息文件保存失败\n");
        exit(0);
    }
    fwrite(flight,sizeof(Flight),1,out);
    fclose(out);
}
void signIn(User* user)
{
    User* newUser = (User*)malloc(sizeof(User));
    system("cls");
    printf("注册\n");
    printf("请输入您的真实姓名:");
    scanf("%s",newUser->name);
    printf("请输入您的身份证号码:");
    scanf("%s",newUser->ID);
    printf("请设定您登录的用户名:");
    scanf("%s",newUser->userName);
    printf("请设定您登录的密码:");
    scanf("%s",newUser->userPwd);
    fflush(stdin);
    newUser->ticketNum = 0;
    newUser->ol = NULL;
    saveUser(newUser);
    newUser->next = user->next;
    user->next = newUser;

    FILE* out = NULL;
    char str[] = "_order.dat";
    char tempName[50];
    strcpy(tempName,newUser->userName);
    strcat(tempName,str);
    if((out=fopen(tempName,"wb"))==NULL)
    {
        printf("订单文件创建失败\n");
        exit(0);
    }
    fclose(out);

    printf("注册成功...\n");
    Sleep(1000);
}
void logIn(User* user,Flight* flight)
{
    User* currUser = NULL;
    char userName[50];
    char userPwd[18];
    int cnt = 3;

    do{
        system("cls");
        printf("登录\n");
        printf("请输入用户名:");
        scanf("%s",userName);
        printf("请输入密码:");
        scanf("%s",userPwd);
        fflush(stdin);

        if(strcmp(userName,adminName)==0 && strcmp(userPwd,adminPwd)==0)//管理员
        {
            adminMenu(user,flight);
            break;
        }

        currUser = searchUserByName(user, userName);
        if(currUser!=NULL && strcmp(currUser->userPwd,userPwd)==0)//用户名存在且密码匹配
        {
            normalUserMenu(currUser,flight,user);//进入普通用户当前用户菜单
            break;
        }else
        {
            printf("用户名或密码错误，请重新输入，您还有%d次机会\n", --cnt);
            pressAnyKey();
            if(cnt==0)
            {
                printf("您输入次数已达最大上限，为了系统的安全，将退出系统，如果忘记用户名或密码，请向管理员admin寻求帮助...");
                exit(0);
            }
        }
    }while(true);
    fflush(stdin);
}
void pressAnyKey()
{
    printf("请按任意键继续...\n");
    getch();
}
