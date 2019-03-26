#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
	int T;
	scanf("%d",&T) ;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int aux = 0;
		int sum = 0;
		for(int i= 1; i <= n; i++)
		{
			int num;
			scanf("%d",&num) ;
			if((num + 2) % 2 == 1)
			{
				aux++;
				sum += (num - 1);
			}
			else
			{
				sum += num;
			}
		}
		if(aux >= 1) 
		{
			printf("%d\n",sum / (aux * 2) * 2 + 1);
		}
		else
		{
			printf("%d\n",sum);
		}
	}
	
	
	
	
	
	
	return 0;
}

