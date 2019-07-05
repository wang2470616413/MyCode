#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105;
const ll MOD = 1e9 + 7;
char sta[10][N];
int indexs[10] = {0,1,2,3,4,5,6};
ll dp[10][N];
int main()
{
  while(~scanf("%s",sta[1] + 1))
  {
     for(int i = 2; i <= 5; i++)
    {
        scanf("%s", sta[i] + 1);
    }
    ll sum = 0;
    ll res = 531192758;
    do
    {
        mmset(dp,0);
        for(int i = 0; i <= 100; i++)
        {
            dp[0][i] = 1;
        }
        for(int i = 1; i <= 5; i++)
        {
            int index = indexs[i];
            int indexPer = indexs[i-1];
            for(int j = 1; j <= 100; j++)
            {
                if(sta[index][j] == '0')
                {
                    dp[index][j] = dp[index][j-1];
                }
                else
                {
                    dp[index][j] = (dp[index][j-1] + dp[indexPer][j-1]) % MOD;
                }
            }
        }
        sum = (sum + dp[indexs[5]][100]) % MOD;
        
    } while (next_permutation(indexs + 1 , indexs + 1 + 5));
    printf("%lld\n",(res * sum) % MOD);
  }
    return 0;
}