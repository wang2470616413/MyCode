#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
#define index index0
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;
struct node
{
    int a,b,m;
    bool operator < (node two) const
    {
        return  a < two.a;
    }
};
int dp[2][N] , ans[N], n,m, index = 1;
node Query[N];
int main()
{
    int num = 1;
    while(~scanf("%d %d",&Query[num].a, &Query[num].b))
    {
        Query[num].m = num;
        num++;
    }
    sort(Query + 1, Query + num);
    dp[0][0] = 1;
    for(int i = 1; i <= 5000; i++)
    {
        int sum = 0;
        for(int j = 0; j <= 5000; j++)
        {
          
            sum = ((sum % MOD) + dp[(i + 1) & 1][j]) % MOD;
            if(j >= i)
            {
                sum = ((sum % MOD) - dp[(i + 1) & 1][j - i] + MOD) % MOD;
            }
            dp[i & 1][j] = sum;
        }
        while(index < num && Query[index].a == i)
        {
            ans[Query[index].m] = dp[i & 1][Query[index].b];
            index++;
        }
    }
    for(int i = 1; i < num; i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}