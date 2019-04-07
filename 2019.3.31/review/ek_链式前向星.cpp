#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005, M = 1005 * 2;
const int INF = 0x3f3f3f3f;
struct node
{
	int from,to,cap,flow,next;
	node()
	{
		
	};
	node(int p_from,int p_to, int p_cap, int p_flow, int p_next)
	{
		from = p_from;
		to = p_to;
		cap = p_cap;
		flow = p_flow;
		next = p_next;
	};
};
int head[N],a[N],pre[N];
node edges[2 * M];
struct EK
{
	void init()
	{
		mmset(head,-1);
		mmset(a,0);
		mmset(pre,0);
	}
	void addEdge(int a,int b, int c,int& len)
	{
		edges[len] = node(a,b,c,0,head[a]);
		head[a] = len++;
		edges[len] = node(b,a,0,0,head[b]);
		head[b] = len++;
	}
	int MaxFlow(int s, int t)
	{
		int flow = 0;
		while(true)
		{
			mmset(a,0);
			a[s] = INF;
			queue <int> que;
			que.push(s);
			while(!que.empty())
			{
				int now = que.front();
				que.pop();
				for(int i = head[now]; i != -1; i = edges[i].next)
				{
					node& e = edges[i];
					if(a[e.to] == 0 && e.cap > e.flow)
					{
						pre[e.to] = i;
						a[e.to] = min(a[now],e.cap - e.flow);
						que.push(e.to);
					}
				}
				if(a[t] > 0)
				{
					break;
				}
			}
			if(a[t] == 0)
			{
				break;
			}
			int w = pre[t];
			edges[w];
			for(int u = pre[t];; u = pre[edges[u].from])
			{
				edges[u].flow += a[t];
				edges[u ^ 1].flow -= a[t];
				if(edges[u].from == s)
				{
					break;
				}
			}
			flow += a[t];
		}
		return flow;
	}
};
int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		EK slove;
		slove.init();
		int len = 0;
		for(int i = 1; i <= n; i++) 
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			slove.addEdge(a,b,c,len);
		}
		int res = slove.MaxFlow(1,m);
		printf("%d\n",res);
	}

	
	
	
	
	return 0;
}

