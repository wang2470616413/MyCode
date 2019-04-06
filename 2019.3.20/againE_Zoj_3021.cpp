#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const double esp = 1e-3;
int main()
{
	double n,k,l,m;
	scanf("%lf %lf %lf %lf",&n,&k,&l,&m);
	ll a = 1, b = 1000000000000;
	ll  mid;
	while(a < b)
	{
		mid = (a + b) / 2;
	
		int res = (int(((k * m + mid) / (m + mid) + 0.05 )* 100)) ;
		if(res <= l*100)
		{
			b = mid;
		}
		else 
		{
			a = mid + 1;
		}
	}
	printf("%lld\n",mid);
	
	
	
	return 0;
}

