#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
	ll a,b,c,d;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	if(a + b +  c + d == 0)
	{
		printf("0\n");
	}
	else 
	{
		if(a == d)
		{
			if(a  == 0)
			{
				if(b > 0 && c ==0)
				{
					printf("1\n");
				}
				else 
				{
					printf("0\n");
				}
			}
			else 
			{
				printf("1\n");
			}
		}
		else 
		{
			printf("0\n");
		}
	}



	return 0;
}
