#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e4 + 5; 
struct node
{
	int x,y;
	node()
	{
		
	};
	node(int px, int py)
	{
		x = px;
		y = py;
	}
};
vector <node> aux;
node data[N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d %d",&n,&m)	;
		for(int i = 1; i <= m; i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			if(x == 1)
			{
				aux.push_back(node(x,y));
			}
			
			data[i] = node(x,y);
		}
		int flag = 0;
		for(int i = 0; i < aux.size(); i++)
		{
			int now = aux[i].y;
			int res = 0;
			for(int j = 1; j <= m; j++)
			{
				if(data[j].x == -1)
				{
					break;
				}
				else if((data[j].x - 1) == (now - data[j].y))
				{
					data[j].x = -1;
					res++;
				}
			}
			if(res == now)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes %d\n",(n - 1) * 2);
		}
		aux.clear();
		
	
	}
	
	
	
	
	
	return 0;

