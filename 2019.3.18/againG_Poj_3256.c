#include<stdio.h>
#include<string.h>
#include<queue> 
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 505, M = 6500;
struct node
{
	int to,w,next;
	node ()
	{
		
	};
	node(int p_to,int p_w,int p_next)
	{
		to = p_to;
		w = p_w;
		next = p_next;
	}
};
int head[N],mark[N],dis[N],cnt[N];
node edges[M];
int n,m,k;
void addEdge(int a, int b, int w,int& len)
{
	edges[len] = node(b,w,head[a]);
	head[a] = len++;
}

bool spfa(int s,int e)
{
	mmset(mark,0);
	mmset(cnt,0);
	mmset(dis,0x3f);
	dis[s] = 0;
	cnt[s]++;
	queue <int> que;
	que.push(s);
	while(!que.empty()) 
	{
		int now = que.front();
		que.pop();
		mark[now] = 0;
		for(int i = head[now]; i != -1; i = edges[i].next)
		{
			int to = edges[i].to;
			int w = edges[i].w;
			if(dis[to] > dis[now] + w)
			{
				dis[to] = dis[now] + w;
				if(mark[to] == 0)
				{
					mark[to] = 1;
					que.push(to);
					if(++cnt[to] >  n )
					{
						return false;
					}
					
				}
			}
		}
	}
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&k);
		mmset(head,-1);
		int len = 1;
		for(int i = 1; i <= m; i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c,len);
			addEdge(b,a,c,len);
		}
		for(int i = 1; i <= k; i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,-c,len);
		}
		if(spfa(1,n) == false)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		
	} 
	
	
	
	
	return 0;
}
