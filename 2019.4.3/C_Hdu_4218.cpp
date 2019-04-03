#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const double esp = 1.732050807569877293527446341505872366942805253810380628055806979451933016908800037081146186757248575675626141415406703029969945094998952478811655512094373648528093231902305582067974820101084674923265015312343266903322886650672254668921837971227047131660367861588019049986537379859389467650347506576051;
const double esp1 = 1.82;
bool count1(double x1,double y1,double x, double y,double r)
{
	double dis1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
	double dis2 = r * r;
	double res1 = fabs(dis1 - dis2);
	double res = sqrt(dis1 - dis2);
	if(res1 < esp * esp)
	{
		return true;
	}
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	int num = 1;
	while(T--)
	{
		double n;
		scanf("%lf", &n);
		printf("Case %d:\n",num++);
		for(double i = 0.0; i <2 * n + 1; i++)
		{
			for(double j = 0.0; j < 2 * n + 1; j++)
			{
				if(count1(i,j,n,n,n))
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		
		
	}
	
	
	
	
	
	return 0;
}
