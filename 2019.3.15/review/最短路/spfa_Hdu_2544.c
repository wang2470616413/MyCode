#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005;
const int M = 1005;
struct node
{
	int to,w,next;
	node ()
	{

	};
	node (int p_to,int p_w,int p_next)
	{
		to = p_to;
		w = p_w;
		next = p_next;
	}
};
node edges[M];
int head[N];
int mark[N],dis[N];
void addEdge(int a, int b, int c,int& t)
{
	edges[t] = node(b,c,head[a]);
	head[a] = t++;
}
int n,m;
int main()
{
	while(scanf("%d %d",&n,&m) && n + m != 0)
	{
		int len = 1;
		mmset(head,-1);
		for(int i = 1; i <= m; i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c,len);
			addEdge(b,a,c,len);
		}	
		mmset(dis,0x3f3f3f3f);
		mmset(mark,0);
		mark[1] = 1;
		dis[1] = 0;
		queue <int> que;
		que.push(1);
		while(!que.empty())
		{
			int front = que.front();
			que.pop();
			mark[front] = 1;
			for(int i = head[front]; i != -1; i = edges[i].next)
			{
				int to = edges[i].to;
				if(dis[to] > dis[front] + edges[i].w)
				{
					dis[to] = dis[front] + edges[i].w;
					if(mark[edges[i].to] == 0)
					{
						que.push(edges[i].to);
						mark[edges[i].to] = 1;
					}
				}
			}
		}
		printf("%d\n",dis[n]);
	}






	return 0;
}
