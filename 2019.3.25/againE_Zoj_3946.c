#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N =  1e5 + 10;
struct node
{
	int to,next;
	ll d,c;
	node()
	{
		
	};
	node(int p_to,ll p_d, ll p_c, int p_next)
	{
		to = p_to;
		d= p_d;
		c = p_c;
		next = p_next;
	};
} ;
int head[N], mark[N];
node edges[2 * N];
ll dis[N];
ll dis1[N];
void addEdge(int a, int b, ll d, ll c, int& len) 
{
	edges[len] = node(b,d,c,head[a]);
	head[a] = len++;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		mmset(head,-1);
		int n,m;
		scanf("%d %d",&n,&m);
		int len = 1;
		for(int i = 1; i <= m; i++)
		{
			int a,b;
			ll d,c;
			scanf("%d %d %lld %lld",&a,&b,&d,&c);
			addEdge(a,b,d,c,len);
			addEdge(b,a,d,c,len);
		}
		mmset(mark,0);
		mmset(dis,0x3f);
		mmset(dis1,0x3f);
		mark[0] = 1;
		dis[0] = 0;
		dis1[0] = 0;
		queue <int> que;
		que.push(0);
		while(!que.empty())
		{
			int now = que.front();
			que.pop();
			mark[now] = 0;
			for(int i = head[now]; i != -1; i = edges[i].next) 
			{
				
				int to = edges[i].to;
				ll d = edges[i].d;
				ll c = edges[i].c;
				if(dis[to] > dis[now] + d)
				{
					dis1[to] = c;
					dis[to] = dis[now] + d;
					if(mark[to] == 0)
					{
						mark[to] = 1;
						que.push(to);
					}
				}
				else if(dis[to] == dis[now] + d)
				{
					if(dis1[to] >  c)
					{
						dis1[to] =  c;
						if(mark[to] == 0)
						{
							mark[to] = 1;
							que.push(to);
						}
					}

				}
			}
		}
		ll res1 = 0, res2 = 0;
		for(int i = 0; i <= n-1; i++)
		{
			res1 += dis[i];
			res2 += dis1[i];
		}
		printf("%lld %lld\n",res1, res2);
		
	}
	
	
	
	
	
	
	return 0;
}

