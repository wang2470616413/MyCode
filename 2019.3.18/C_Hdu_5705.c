#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int Nh = 12 * 3600;
const int Nm = 3600;
const int Ns = 60;
int main()
{
	double h,m,s;
	int num = 1;
	while(~scanf("%lf:%lf:%lf", &h,&m,&s))
	{
		double ang;
		scanf("%lf",&ang);
		double ts = s;
		double tm = m * 60 + s;
		double th = h * 3600 + tm;
		double ch = 360.0 / (12.0 * 3600.0);
		double cm = 360.0 / (3600.0);
		double cs = 360.0 / 60.0;
		double rh = ((int)th % Nh) * ch;
		double rm = ((int)tm % Nm) * cm;
		double rs = ((int)ts % Ns) * cs;
		int ss = 1;
		while(true)
		{
			rh = ((int)(th + ss) % Nh) * ch;	
			rm = ((int)(tm + ss) % Nm) * cm;	
			if(fabs(ang - fabs(rh - rm)) < 0.09)
			{
				break;
			}
			ss++;
		} 
		int hh = (int(th + ss) % Nh) / Nm;
		int mm = (int(tm + ss) % Nm) / Ns ;
		ss = ((int)(ts +ss) % Ns) / 1;
		printf("Case #%d: %02d:%02d:%02d\n",num++,hh,mm,ss);
	} 
	
	
	
	
	return 0;
}

