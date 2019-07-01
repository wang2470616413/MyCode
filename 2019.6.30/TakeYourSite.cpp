#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m;
/*
1
2 3
*/
int main()
{
    int T;
    scanf("%d",&T);
    int num = 1;
    while(T--)
    {
        scanf("%d %d",&n,&m);
        double res0 = 0.0, res1 = 0.0;
        if(n == 1)
        {
            res0 = 1.0;
        }
        else
        {
            res0 = 0.5;
        }
        
        if(m == 1)
        {
            res1 = 1.0;
        }
        else
        {
            res1 = (double(m + 1.0)) / (double(2.0 * m));
        }
        printf("Case #%d: %0.6lf %0.6lf\n",num++,res0, res1);
    }






    return 0;
}