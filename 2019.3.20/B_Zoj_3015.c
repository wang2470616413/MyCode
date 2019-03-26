#include<stdio.h>
#include<string.h>
#include<math.h> 
#include<algorithm>
#define ll long long 
#define mmset (a,b) memset(a,b,sizeof(a))
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-6;
int sgn(double x)
{
	if(fabs(x) < eps)
	{
		return 0;
	}
	if(x < 0)
	{
		return -1;
	}
	else 
	{
		return 1;
	}
};
struct point
{
	double x,y;
	point()
	{
		
	}
	point(double p_x, double p_y)
	{
		x = p_x;
		y =  p_y;
	}
	point operator + (const point &b)const
	{
		return point(x+b.x,y+b.y);
	}
	point operator - (const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
	point operator * (const double &k)const
	{
		return point(x*k,y*k);
	}
	point operator / (const double &k)const
	{
		return point(x/k,y/k);
	}
	
	double operator * (const point &b)const
	{
		return x*b.x + y*b.y;
	}
	double len2()
	{
		return x * x + y * y; 
	}
};
struct line
{
	point s,e;
	line(point p, double angle)
	{
		s = p;
		if(sgn(angle - pi/2) == 0)
		{
			e = (s + point(0,1));
		}
		else
		{
			e = (s + point(1,tan(angle)));
		}
	}
	point lineprog(point p)
	{
		return s + (((e - s) * ((e -s ) * (p - s))) / ((e - s).len2()));
	}
	point symmetryoiubt(point p)
	{
		point q = lineprog(p);
		return point(2 * q.x - p.x, 2 * q.y - p.y);
	}
};
int main()
{
	double k,h,a,b;
	while(~scanf("%lf %lf %lf %lf",&k,&h,&a,&b))
	{
		point h1 = point(0,h);
		point a1 = point(0,a);
		point b1 = point(b,0);
		line l1 = line(h1,pi * ((180.0 - k)/ 180.0));
		point x = l1.symmetryoiubt(a1);
		double res = sqrt((x.x - b1.x)*(x.x - b1.x) + (x.y - b1.y) * (x.y - b1.y));
		printf("%0.2lf\n",res);
	} 
	
	
	
	
	return 0;
} 

