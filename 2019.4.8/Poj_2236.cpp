#include<stdio.h>
#include<math.h>
const int N = 1205;
double data[N];
int father[N];
double map[N][2];
int mark[N];
double find(int x)
{
	if(data[x] != x)
	data[x] = find(data[x]);
	return data[x];
	
}
double merge(int x, int y)
{
	if(x != y)
	{
		data[x]=y;
		return 1;
	}
	else
	return 0;
}
double sum(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
double init(int length)
{
	for(int i = 0;i < length;i++)
	data[i] = i;
}
int main()
{
	int n, m;
	int n1,m1;
	scanf("%d %d", &n1, &m1);
	init(n1+2);
	for(int i = 1;i <= n1;i++)
	scanf("%lf%lf", &map[i][0], &map[i][1]);
	char flag;
	while(~scanf("%c", &flag))
	{
		if(flag == 'O')
		{
			scanf("%d", &n);
			mark[n] = 1;
			for(int i = 0;i <= n1;i++)
			{
				if(mark[i] == 1&&i != n)
				{
					if(sum(map[n][0],map[n][1],map[i][0],map[i][1]) <= m1)
					{
						int a = find(n);
						int b = find(i);
						merge(a,b);
					}
				}
			}
			
		}
		else if(flag == 'S')
		{
			scanf("%d%d", &n, &m);
			int a = find(n);
			int b = find(m);
			if(a == b)
			printf("SUCCESS\n");
			else
			printf("FAIL\n");
		}
	}
	
	
	
	return 0;
}
