#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 10;
int data[N];
vector <int> aux[N];
int mark[N];
int n,m;
int main()
{
	while(scanf("%d %d",&n,&m) && (n != 0 && m != 0))
	{
		mmset(mark,0);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d",&data[i]);
			mark[data[i] % n] ++;
			aux[data[i] % n].push_back(i);
		}
		int res = -1;
		for(int i = 0; i <= n; i++)
		{
			if(i != 0)
			{
				if(mark[i] > 0 && mark[n - i] > 0)
				{
					res = i;
					break;
				}
			}
			else
			{
				if(mark[i] > 0)
				{
					res = i;
					break;
				}
			}

		}
		if(res == -1)
		{
			printf("no sweets\n");
		}
		else if(res == 0) 
		{
			printf("%d\n",aux[res][0]);
		}
		else 
		{
			printf("%d %d\n",aux[res][0],aux[n - res][0]);
		}
	}
	return 0;
}
