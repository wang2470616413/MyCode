#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005,M = 1005;
const int INF = 0x3f3f3f3f;
struct node
{
	int from, to,cap,flow,next;
	node()
	{
		
	};
	node(int p_from, int p_to, int p_cap, int p_flow, int p_next)
	{
		from = p_from;
		to = p_to;
		cap = p_cap;
		flow = p_flow;
		next = p_next;
	};
};
int head[N],dep[N];
node edges[2 * M];
struct EK
{
	int st,ed,len;
	void init(int s, int t)
	{
		st = s;
		ed = t;
		len = 0;
		mmset(head,-1);
	}
	void addEdge(int a,int b, int c)
	{
		edges[len] = node(a,b,c,0,head[a]);
		head[a] = len++;
		edges[len] = node(b,a,0,0,head[b]);
		head[b] = len++;
	}
	void bfs(int s, int t)
	{
		mmset(dep,-1);
		queue <int> que;
		que.push(s);
		dep[s] = 1;
		while(!que.empty())
		{
			int now = que.front();
			que.pop();
			for(int i = head[now]; i != -1; i = edges[i].next)
			{
				node& e = edges[i];
				if(dep[e.to] == -1 && e.cap > e.flow)
				{
					dep[e.to] = dep[now] + 1;
				}
				if(dep[t] > 0)
				{
					return true;
				}
			}
		}
		return false;
	}
} 
int main()
{
	
	
	
	
	
	
	return 0;
}                                          
