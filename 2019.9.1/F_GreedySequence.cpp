#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define  ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 5;
int data[N];
int res[N],aux[N];
/*
2
3 1
3 2 1
7 2
3 1 4 6 2 5 7
*/
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&data[i]);
            aux[data[i]] = i;
        }
        mmset(res,0);
        for(int i = 1; i <= n; i++)
        {
            int j = i - 1;
            res[i] = 1;
            while(j >= 0 && abs(aux[j] - aux[i]) > k)
            {
               j--; 
            }
            res[i] += res[j];
        }
        for(int i = 1; i <= n; i++)
        {
            printf("%d%c",res[i],i == n ? '\n' : ' ');
        }
    }
    return 0;
}