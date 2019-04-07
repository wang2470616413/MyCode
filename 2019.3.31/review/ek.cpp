#include<stdio.h>
#include<string.h> 
#include<algorithm>
#include<queue>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
struct node
{
	int from, to,cap,flow;
	node ()
	{
	};
	node(int pfrom, int pto, int pcap, int pflow)
	{
		from = pfrom;
		to = pto;
		cap = pcap;
		flow = pflow;
	};
};
struct EK
{
	int n,m;
	vector <node> edges;
	vector <int> G[maxn];
	int a[maxn];
	int p[maxn];
	void init(int n)
	{
		for(int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		edges.clear();
	}
	void AddEdge(int from, int to, int cap) 
	{
		edges.push_back(node(from,to,cap,0));
		edges.push_back(node(to,from,0,0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}
	int MaxFlow(int s, int t)
	{
		int flow = 0;
		for(;;)
		{
			mmset(a,0);
			queue <int> Q;
			Q.push(s);
			a[s] = INF;
			while(!Q.empty())
			{
				int now = Q.front();
				Q.pop();
				for(int i = 0; i < G[now].size(); i++)
				{
					node& e = edges[G[now][i]];
					if(!a[e.to] && e.cap > e.flow)
					{
						p[e.to] = G[now][i];
						a[e.to] = min(a[now],e.cap - e.flow);
						Q.push(e.to);
					}
				}
				if(a[t])
				{
					break;
				}
			}
			if(!a[t])
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

/*
6 10 
0 1 16
0 2 13
1 2 10
2 1 4
1 3 12
2 4 14
3 2 9
4 3 7
3 5 20
4 5 4 
*/ 

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	EK ek;
	for(int i = 1; i <= m; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		ek.AddEdge(a,b,c);
	}
	ek.MaxFlow(0,n-1);
	
	
	
	
	
	return 0;
}
 
