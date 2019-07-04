#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
    double n,m;
    while(~scanf("%lf %lf",&n,&m))
    {
        printf("%0.5lf\n",n / (n + m));
    }
    return 0;
}