#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 20;
struct node 
{
	int x, y;
	int key;
};
int data[N * N];
int data1[N * N];
int res[N * N];
int mark[1005];
int mark[1005];
int n;
int main()
{
	mmset(mark,0);
	scanf("%d",&n);
	int m = n * n, t = 1 t1 = 1;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d",&data[i]);
		mark[data[i]] ++;
		if(mark[data[i]] == 4)
		{
			data1[t++] = data[i];
			mark[data[i]] = 0;
		}
	}
		
		int tempm = m % 2 == 0? m : m - 1;
		if(t != m / 4 + 1 )
		{
			printf("NO\n");
		}
		else 
		{
			int index = 1;
			int index1 = 1;
			int index2 = m;
			int mid = (n + 1) / 2;
			int key = 0;
			for(int j = 1; j <= m; j++)
			{
				if(mark[data[j]] == 1)
				{
					key = data[j];
				}
			}
			if(m % 2 == 0)	
			{
				for(int i = 1; i <=		
			}
			else 
			{
			}
			printf("YES\n");
			int index3 = 1;
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= n; j++)
				{
					printf("%d ",res[index3++]);
				}
				printf("\n");
			}
		}


			



	return 0;
}
