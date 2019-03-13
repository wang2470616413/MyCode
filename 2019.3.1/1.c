#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		if(n == m)
		{
			printf("Yes\n");
		}
		else 
		{
			printf("No\n");
		}
	}


	return 0;
}
