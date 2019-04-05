#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 3e5 + 5;
struct node
{
	int to,next;
	ll w;
	node()
	{
		
	};
	node(int p_to, ll p_w, int p_next)
	{
		to = p_to;
		w = p_w;
		next = p_next;
	};
};
struct edge
{
	int p;
	ll w;
	edge()
	{
		
	};
	edge(int p_p, ll p_w)
	{
		p = p_p;
		w = p_w;
	};
	bool operator < (const edge two) const
	{
		return w > two.w;
	}
};
int head[N];
ll dis[N];
vector <int> ans;
node edges[2 * N];
int pre[N];
int n,m,k;
void addEdge(int a,int b, int c,int& len)
{
	edges[len] = node(b,c,head[a]);
	head[a] = len++;
}
void dijkstra(int s, int e,int k)
{
	mmset(dis,0x3f);
	dis[s] = 0;
	priority_queue <edge> que;
	que.push(edge(s,0));
	while(!que.empty() && ans.size() <= k)
	{
		edge temp = que.top();
		que.pop();
		if(temp.w > dis[temp.p])
		{
			continue;
		}
		int u = temp.p;
		ans.push_back(pre[u]);
		for(int j = head[u]; j != -1; j = edges[j].next)if(dis[edges[j].to] > dis[u] + edges[j].w) 
		{
			pre[edges[j].to] = (j + 1) / 2;
			dis[edges[j].to] = dis[u] + edges[j].w;
			que.push(edge(edges[j].to,edges[j].w + dis[u]));
		}
	}
}
int main()
{
	
		scanf("%d %d %d",&n,&m,&k);
		ans.clear();
		mmset(head,-1);
		int a,b,c;
		int len = 1;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c,len);
			addEdge(b,a,c,len);
		}
		dijkstra(1,n,k);
		printf("%d\n",ans.size() - 1);
		for(int i = 1; i < ans.size(); i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
	
	return 0;
}
