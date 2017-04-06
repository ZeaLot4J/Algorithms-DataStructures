#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct
{
    char *ch;
    int length;
}String;

void strAssign(String &str, const char *chars)
{
    int len = strlen(chars);
    if(!len)
    {
        str.ch = NULL;
        str.length = 0;
    }
    else
    {
        if(!(str.ch=new char[len]))
        {
            cerr << "memory allocation failed!" << endl;
            exit(-1);
        }
        else
        {
            for(int i=0; i<len; i++)
                str.ch[i] = chars[i];
            str.length = len;
            str.ch[len] = '\0';
        }
    }
}
int strLength(const String &str)
{
    return str.length;
}
int strCompare(const String &str1, const String &str2)
{
    int i;
    for(i=0; i<str1.length&&i<str2.length; i++)
    {
        if(str1.ch[i] != str2.ch[i])
            break;
    }
    return str1.ch[i] - str2.ch[i];
}
void clearString(String &str)
{
    if(str.ch==NULL)
        return;
    delete[] str.ch;
    str.ch = NULL;
    str.length = 0;
}
void display(const String &str)
{
    if(str.ch==NULL)
    {
        cout << "the current string is empty." << endl;
        return;
    }
    cout << "the current string is: " << str.ch << endl;
    cout << "the length is: " << str.length << endl;
}
void strConcat(String &newstr, const String &str1, const String &str2)
{
    if(!(newstr.ch=new char[str1.length+str2.length]))
    {
        cerr << "memory allocation failed!" << endl;
        exit(-1);
    }
    int i;
    for(i=0; i<str1.length; i++)
        newstr.ch[i] = str1.ch[i];
    for(i=0; i<str2.length; i++)
        newstr.ch[i+str1.length] = str2.ch[i];
    newstr.ch[i+str1.length] = '\0';
    newstr.length = str1.length + str2.length;
}
void subString(String &sub, const String &str, int pos, int len)
{
    if(pos<0 || pos>=str.length || len<0 || len>str.length-pos)
    {
        sub.ch = NULL;
        sub.length =0;
        cerr << "error!" << endl;
        return;
    }
    if(!len)
    {
        sub.ch = NULL;
        sub.length = 0;
        cout << "the substring is empty!" << endl;
        return;
    }
    else
    {
        if(!(sub.ch=new char[len]))
        {
            cerr << "memory allocation failed!" << endl;
            exit(-1);
        }
        int i;
        for(i=0; i<len; i++)
            sub.ch[i] = str.ch[pos+i];
        sub.length = len;
        sub.ch[i] = '\0';
    }
}
void reallocString(String &str, int len)
{
    char * pt = new char[len+str.length];
    int i;
    for(i=0; i<str.length; i++)
        pt[i] = str.ch[i];
    pt[i] = '\0';
    delete[] str.ch;
    str.ch = pt;
}
void strInsert(String &str1, int pos, String &str2)
{
    if(pos<0 || pos>str1.length)
    {
        cerr << "error!" << endl;
        return;
    }
    else if(str2.ch==NULL)
        return;
    else if(str1.ch==NULL)
        strAssign(str1, str2.ch);
    else
    {
        reallocString(str1, str2.length);
        for(int i=str1.length-1; i>=pos; i--)
            str1.ch[i+str2.length] = str1.ch[i];
        str1.length += str2.length;
        for(int i=0; i<str2.length; i++)
            str1.ch[pos+i] = str2.ch[i];
        str1.ch[str1.length] = '\0';
    }
}
int strMatch(String &str1, String &str2)
{
    int i=0, j=0, v;
    while(i<str1.length && j<str2.length)
    {
        if(str1.ch[i] == str2.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= str2.length)
        v = i - j;
    else
        v = -1;
    return v;
}
int KMPnext(String &str)
{
    int  j = -1,  i = 0;
    int next[17];
    next[0] = -1;
    while(i < str.length)
    {
        if(j == -1 || str.ch[i] == str.ch[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}
int main()
{
    String str1, str2;
    strAssign(str1, "zhanga");
    strAssign(str2, "zhang");
    cout << strCompare(str1, str2);


    return 0;
}
