#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 3e3;
const double PI = acos(-1.0);
double aux[N];
double data[N][4];
double x,y;
int n;
double getDisDouble(double x1, double y1, double x2, double y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
double getDis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double count1(int i)
{
    double bDou = getDisDouble(data[i-1][1],data[i-1][2],data[i][1],data[i][2]) ;
    double cDou = getDisDouble(data[i+1][1],data[i+1][2],data[i][1],data[i][2]) ;
    double aDou = getDisDouble(data[i-1][1],data[i-1][2],data[i+1][1],data[i+1][2]) ;
    double suma = bDou + cDou - aDou;
    double sumb = 2.0 * sqrt(bDou) * sqrt(cDou);
    return suma / sumb;
}
/*
4
4
0 0
2 0
2 2
0 2
1 1
3
0 0
2 1
1 2
1 1
5
0 0
1 0
2 2
1 3
-1 2
0 0
6
0 0
3 0
4 1
2 2
1 2
-1 1
1 0
 */
int main()
{
    int T;
    scanf("%d",&T);
    int num = 1;
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lf %lf",&data[i][1],&data[i][2]);
        }
        scanf("%lf %lf",&x, &y);
        data[n + 1][1] = data[1][1];
        data[n + 1][2] = data[1][2];
        data[0][1] = data[n][1];
        data[0][2] = data[n][2];
        for(int i = 1; i <= n; i++)
        {
            data[i][3] = 180.0 - (acos(count1(i)) * 180.0 / acos(-1.0));
        }
        double sum = 0;
        for(int i = 1; i <= n; i++)
        {
            double r = getDis(x,y,data[i][1],data[i][2]);
            sum += (data[i][3] / 180.0) * PI * r;
        }
        printf("Case #%d: %0.3lf\n",num++,sum);
    }
    
    return 0;
}

