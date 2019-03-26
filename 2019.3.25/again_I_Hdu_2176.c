#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a)) 
using namespace std;
const int N = 2e5 + 10;
int data[N];
int main()
{
	int n;
	while(scanf("%d",&n) && n != 0)
	{
		
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
		}
		int temp = 0;
		for(int i = 1; i <= n; i++)
		{
			temp = temp ^ data[i];
		}
		if(temp == 0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
			for(int i = 1; i <= n; i++)
			{
				if(data[i] >= (temp ^ data[i]))
				{
					printf("%d %d\n",data[i],temp ^ data[i]);
				}
			}
		}

	}
	return 0;
}
