#include<stdio.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
string str;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int h,m;
		double utc;
		scanf("%d %d UTC%lf",&h,&m,&utc);
		if(utc >= 8)
		{
			int sums = h * 60 + m;
			int ss = ((utc * 10 - 80))* 60.0 / 10;
			int rs = sums + ss;
			int rh = rs / 60 % 24;
			int rm = rs % 60;
			printf("%02d:%02d\n",rh,rm);
		}
		else 
		{
			int sums = h * 60 + m;
			int ss = ((utc*10 - 80))* 60.0 / 10;
			int rs = sums + ss;
			if(rs < 0)
			{
				rs = 24 * 60 + rs;
			}
			int rh = rs / 60 % 24;
			int rm = rs % 60;
			printf("%02d:%02d\n",rh,rm);
			
		}
		
	}
	return 0;
} 
