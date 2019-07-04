#include<stdio.h>
#include<algorithm>
#include<string.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2e5 + 10;
int gril[N], boy[N];
int n,m;
/*
1
3 4
1 2 3
1 2 3

45
3 4 
1 2 3
6 6 6
 */
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&gril[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&boy[i]);
        }
        sort(gril +1 , gril + 1 + n,[](int a, int b){return  a > b;});
        sort(boy + 1, boy + 1 + n);
        int a = 1;
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            a = lower_bound(boy + a, boy + 1 + n, m - gril[i]) - boy;
           // printf("%d\n",a);
            if(a <= n)
            {
                a++;
                res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}