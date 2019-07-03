#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 5e3 + 5;
const ll MOD = 1e9 + 7;
int dp[2][N];
int ans[N];
int n,k,cnt, cur;
struct Query { int n, k, index; } query[N];

int main()
{
    //  int data[100];
    // int aux[100];
    // for(int i = 1; i <= 10; i++)
    // {
    //     mmset(data,0);
    //     for(int k = 1; k <= i; k++)
    //     {
    //         aux[k] = k;
    //     }
    //     do 
    //     {
    //         int num = 0;
    //         for(int j = 1; j <= i; j++)
    //         {
    //             for(int q = j + 1; q <= i; q++)
    //             {
    //                 if(aux[j] > aux[q])
    //                 {
    //                     num++;
    //                 }
    //             }
    //         }
    //         data[num]++;
    //     }while (next_permutation(aux + 1, aux + 1 + i));
    //     for(int j = 1; j <= 20; j++)
    //     {
    //         printf("%d ",data[j]);
    //     }
    //     printf("\n");
    // }
    

   while(~scanf("%d %d", &query[cnt].n, &query[cnt].k))
   {
        query[cnt].index = cnt;
        cnt++;
   }

    mmset(dp,0);
    dp[0][0] = 1;
    for(int i = 1; i <= 5000; i++)
    {
        int sum = 0;
        for(int j = 0; j <= 5000; j++)
        {
            if(j < i)
            {
                sum = (sum % MOD)  + (dp[(i + 1) & 1][j]) % MOD;
            }
            else
            {
                sum = (sum % MOD) - (dp[(i + 1) & 1][j - i]) % MOD;
            }
            
            dp[i & 1][j] = (sum % MOD) % MOD; 
        }
             while (cur < cnt && query[cur].n == i) 
             {
            ans[query[cur].index] = dp[i & 1][query[cur].k];
            cur++;
        }
    }
    for (int i = 0; i < cnt; i++) printf("%d\n", ans[i]);

    return 0;
}