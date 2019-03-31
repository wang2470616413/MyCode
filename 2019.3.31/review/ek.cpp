#include<stdio.h>
#include<string.h> 
#include<algorithm>
#include<queue>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
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
		for(int i = 0; i < n; i++
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
			while(!Q.empty)
			{
				int now = Q.front();
				Q.pop();
				for(int i = 0; i < G[x].size(); i++)
				{
					node& e = edges[G[x][i]];
					if(!a[e.to] && e.cap > e.flow)
					{
						p[e,to] = G[x][i];
						a[e.to] = min(a[x],e.cap - e.flow);
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
}


int main()
{
	
	
	
	
	
	return 0;
}
 
