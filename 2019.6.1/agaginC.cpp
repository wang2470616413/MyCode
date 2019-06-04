#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e6 + 5;
char str1[N], str2[N];
bool isCount(char* str1,char* str2)
{
    int len1 = strlen(str1 + 1);
    int len2 = strlen(str2 + 1);
    if(len1 != len2 + 2)
    {
        return false;
    }
    else
    {
        int j = 1;
        for(int i = 1; i <= len2; i++)
        {
            while(str2[i] != str1[j] && j <= len1)
            {
                j++;
            }
            if(j > len1)
            {
                return false;
            }
            j++;
        }
        return true;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str1 + 1);
        scanf("%s",str2 + 1);
        if(isCount(str1, str2) == true)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        
    }
    return 0;
}