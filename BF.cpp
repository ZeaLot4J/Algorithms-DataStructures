#include <iostream>
#include <string.h>

using namespace std;

int BF(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i=0, j=0;

    while(i<len1&&j<len2)
    {
        if(str1[i]==str2[j]){
            i++;
            j++;
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }

    if(j>=len2) return i-j;
    else return -1;
}
int main()
{
    char str1[] = "zhanglei18aho";
    char str2[] = "angle";

    cout << BF(str1, str2) << endl;
    return 0;
}
