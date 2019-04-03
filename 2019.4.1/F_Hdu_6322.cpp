#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int k;
		scanf("%d",&k);
		if(k == 1)
		{
			printf("%d\n",5);
		}
		else
		{
			printf("%d\n",k + 5);
		}
	}

	return 0;
}
