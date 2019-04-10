#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005;
const int INF = 0x3f3f3f3f;
int n;
int map1[N][N];
int point[N];
int dis[N][N];
int mark[N];
int pre[N][N];
void print(int mark, int p, int end)
{
	if(p == mark)
	{
		printf("%d-->",p)	;
		return ;
	}	
	else
	{
		print(mark,pre[mark][p],end);
		if(p == end)
		{
			printf("%d",p);
		}
		else
		{
			printf("%d-->",p);
		}	
	}
}
bool judge(int u, int v,int* path)
{
	int str1[N];
	int str2[N];
	int index1 = 1, index2 = 1;
	int p = v;
	while(p != -1)
	{
		str1[index1] = p;
		index1++;
		p = path[p];
	}
	str2[index2] = v;
	index2++;
	p = u;
	while(p != -1)
	{
		str2[index2] = p;
		index2++;
		p = path[p];
	}
	int i = index1 - 1, j = index2 - 1;
	if(j < i)
	{
		return true;
	}
	else
	{
		while(i > 0 && j> 0)
		{
			if(str2[j] > str1[i])
			{
				return false; 
			}
			if(str2[j] < str1[i])
			{
				return true;
			}
			i--;
			j--;
		}
		return  false;
	}

}
int spfa(int s)
{
	queue <int> que;
	que.push(s);
	dis[s][s] = 0;
	mark[s] = 1;
	while(!que.empty())
	{
		int now = que.front();
		que.pop();
		mark[now]= 0;
		int temp = (now == s ? 0 : point[now]);
		for(int i = 1; i <= n; i++) if(map1[now][i] != -1 && i != now)
		{
			if(dis[s][i] > dis[s][now] + map1[now][i] + temp)
			{
				pre[s][i] = now;
				dis[s][i] =  dis[s][now] + map1[now][i] + temp;
				if(mark[i] == 0)
				{
					mark[i] = 1;
					que.push(i);
				}
			}
			else if(dis[s][i] == dis[s][now] + map1[now][i] + temp)
			{
				if(judge(now,i,pre[s]))
				{
					pre[s][i] = now;
					if(mark[i] == 0)
					{
						mark[i] = 1;
						que.push(i);
					}
				}
			}
		}
		
	}
}
int main()
{

	while(~scanf("%d",&n) && n != 0)
	{
        mmset(pre,-1);
		for(int i = 1; i <= n ;i++)
		{
			for(int j = 1; j <= n; j++)
			{
				scanf("%d",&map1[i][j]);
			}
		}
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&point[i]);
		}
		mmset(dis,0x3f);
		for(int i = 1; i <= n; i++)
		{
			mmset(mark,0);
			spfa(i);
		}
		int a,b;
		while(~scanf("%d %d",&a,&b) && a != -1 && b != -1)
		{
			if(a == b)
			{
				printf("From %d to %d :\n",a,b);
				printf("Path: %d",a);
				printf("\n");
				printf("Total cost : %d\n",0);
				printf("\n");
			}
			else
			{
				printf("From %d to %d :\n",a,b);
				printf("Path: ");
				print(a,b,b);
				printf("\n");
				printf("Total cost : %d\n",dis[a][b]);
				printf("\n");
			}
		}
	}
	return 0;
} 

