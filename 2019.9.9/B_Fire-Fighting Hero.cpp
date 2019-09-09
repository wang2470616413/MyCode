#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e3 + 5,M = 5e5 + 2e3;
struct node
{
	int to,w,next;
	node()
	{
		
	};
	node(int _to, int _w, int _next)
	{
		to = _to;
		w = _w;
		next = _next;
	};
};
struct point
{
	int p, w;
	point()
	{
		
	};
	point(int _p, int _w)
	{
		p = _p;
		w = _w;
	};
	bool operator < (point two) const
	{
		return w > two.w;
	}
};
node edges[M];
int head[N], dis[N];
void addEdges(int a, int b, int c, int& len)
{
	edges[len] = node(b,c,head[a]);
	head[a] = len++;
}
void dijstra(int s)
{
	mmset(dis,0x3f);
	dis[s] = 0;
	priority_queue <point> que;
	que.push(point(s,0));
	while(!que.empty())
	{
		point p = que.top();
		que.pop();
		for(int i = head[p.p]; i != -1; i = edges[i].next)if(dis[edges[i].to] > dis[p.p] + edges[i].w)
		{
			dis[edges[i].to] = dis[p.p] + edges[i].w;
			que.push(point(edges[i].to,dis[edges[i].to]));
		}
	}
}
/*
1
4 7 3 2 2
1 4
1 2 7
1 3 2
1 4 6 
2 1 1
2 4 1
3 2 1
3 4 3
*/
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,s,k,p,num,ordP = 0,len = 1;
		ll c;
		scanf("%d %d %d %d %lld",&n,&m,&s,&k,&c);
		mmset(head,-1);
		for(int i = 1; i <= k; i++) 
		{
			scanf("%d",&num);
			addEdges(ordP,num,0,len);
			addEdges(num,ordP,0,len);
		}
		int a,b,w;
		for(int i = 1;i <= m;i++)
		{
			scanf("%d %d %d",&a,&b,&w);
			addEdges(a,b,w,len);
			addEdges(b,a,w,len);
		}
		ll maxHero = -1, maxTeam = -1;
		dijstra(s);
		for(int i = 1; i <= n; i++)if(dis[i] != 0x3f3f3f3f)
		{
			if(maxHero < dis[i])
			{
				maxHero = dis[i];
			}
		}
		dijstra(ordP);
		for(int i = 1; i <= n; i++)if(dis[i] != 0x3f3f3f3f)
		{
			if(maxTeam < dis[i])
			{
				maxTeam = dis[i];
			}
		}
		printf("%lld\n",maxTeam <= c * maxHero ? maxTeam : c * maxHero);;
		
	}
	
	
	
	
	return 0;
} 
