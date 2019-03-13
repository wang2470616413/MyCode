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
		double b,c;
		ll a;
		scanf("%lld %lf %lf",&a,&b,&c);
		if(a % 2 == 0)
		{
			double bb = b;
			double cc = c / 2.0;
			if(bb < cc)
			{
				printf("%lld\n",a * (ll)b);
			}
			else 
			{
				printf("%lld\n",a / 2 * (ll)c);
			}
			
		}
		else 
		{
			double bb = b;
			double cc = c / 2.0;
			if(bb < cc)
			{
				printf("%lld\n",a * (ll)b);
			}
			else 
			{
					printf("%lld\n",a / 2 * (ll)c + (ll)b);
			}
		}


	}



	return 0;
}
