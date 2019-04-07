#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005;
const int M = 1005;
const int INF = 0x3f3f3f3f;
struct node
{
	int from,to,cap,flow;
	node()
	{
	};
	node(int p_from, int p_to, int p_cap, int p_flow)
	{
		from = p_from;
		to = p_to;
		cap = p_cap;
		flow = p_flow;
	};
};
struct EK
{
	int n,m;
	vector <node> edges;
	vector <int> G[M];
	int a[N];
	int p[N];
	void init(int n)
	{
		for(int i = 0; i < n; i++)
		{
			G[i].clear(); 
		}
		edges.clear();
	}
	void addEdge(int from, int to, int cap) 
	{
		edges.push_back(node(from,to,cap,0));
		edges.push_back(node(to,from,0,0));
		m = edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	int MaxFlow(int s, int t)
	{
		int flow = 0;
		while(true)
		{
			mmset(a,0);
			queue <int> que;
			que.push(s);
			a[s] = INF;
			while(!que.empty())
			{
				int now = que.front();
				que.pop();
				for(int i = 0; i < G[now].size(); i++)
				{
					node& e = edges[G[now][i]];
					if(a[e.to] == 0 && e.cap > e.flow)
					{
						p[e.to] = G[now][i];
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
			for(int u = t; u != s; u = edges[p[u]].from)
			{
				edges[p[u]].flow += a[t];
				edges[p[u] ^ 1].flow -= a[t];
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
		for(int i = 1; i <= n; i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			slove.addEdge(a,b,c);
		}
		int res = slove.MaxFlow(1,m);
		printf("%d\n",res);
	}

	
	
	
	
	return 0;
} 
