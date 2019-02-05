#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			printf("(%d,%d) ",i,j);
		}
		printf("\n");
	}

	return 0;



}
