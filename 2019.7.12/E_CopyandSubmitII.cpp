#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int MOD = 1000000007;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        ll res = 1;
        int num = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&num);
            res  = (res % MOD) * ((num + 1) % MOD);
        }
        printf("%lld\n",res % MOD);
    }
    return 0;
}