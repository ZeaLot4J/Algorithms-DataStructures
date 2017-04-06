/*
模式匹配算法KMP;
*/
void getNext(String &sub, int next[])
{
    int i=0, j=-1;
    next[0] = -1;
    while(i<sub.length)
    {
        if(j==-1 || sub.ch[j]==sub.ch[i])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int KMP(String &str1, String &str2)
{
    int i=0, j=0;
    int next[100];
    getNext(str2, next);
    while(i<str1.length && j<str2.length)
    {
        if(str1.ch[i] == str2.ch[j])
        {
            i++;
            j++;
        }
        else if(j==0)
        {
            i++;
        }
        else
        {
            j = next[j];
        }
    }
    int pos;
    if(j>=str2.length)
        pos = i-j;
    else
        pos = -1;
    return pos;
}
