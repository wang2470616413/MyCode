#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 10;
int aux[N];
int main()
{
    int T,n,num;
    scanf("%d",&T);
    while(T--)
    {
        mmset(aux,0);
        scanf("%d",&n);
        for(int i = 0; i < 2; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                scanf("%d",&num);
                aux[num % 3] ++;
            }
        }
        int flag = 0;
        if(aux[0] <= 1 && (aux[1] == 0 || aux[2] == 0))
        {
            flag = 1;
        }
        if(aux[0] == 2 && ((aux[1] % 2 == 1 && aux[2] % 2 == 1) || (aux[1] == 0 || aux[2] == 0)) )
        {
            flag = 1;
        }
        if(aux[0] >= 3 && aux[0] <= n)
        {
            flag = 1;
        }
        if(flag == 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
        
    }





    return 0;
}