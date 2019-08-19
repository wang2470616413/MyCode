#include<stdio.h>
#include<algorithm>
#include<string.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int res = -1;
        int num = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&num);
            res = max(res,num);
        }
        printf("%d\n",res);
    }



    return 0;
}