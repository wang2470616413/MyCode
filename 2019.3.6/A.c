#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(a + b +  c + d == 0)
	{
		printf("0\n");
	}
	else 
	{
		if(a == d)
		{
			printf("1\n");
		}
		else 
		{
			printf("0\n");
		}
	}



	return 0;
}
