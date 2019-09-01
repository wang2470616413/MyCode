#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue> 
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 300 + 5;
const int M = 500 + 5;
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
node edges[M];
int book[N], dis[N], head[N];
void addEdges(int a, int b, int c, int& len)
{
	edges[len] = node(b,c,head[a]);
	head[a] = len++;
}
void spfa(int s)
{
	mmset(book,0);
	mmset(dis,0x3f);
	queue <int> que;
	que.push(s)	;
	book[s] = 1;
 	dis[s] = 0;
	while(!que.empty())
	{
		int now = que.front();
		que.pop();
		book[now] = 0;
		for(int i = head[now]; i != -1;i = edges[i].next)if(dis[edges[i].to] > dis[now] + edges[i].w)
		{
			dis[edges[i].to] = dis[now] + edges[i].w;
			if(book[edges[i].to] == 0)
			{
				que.push(edges[i].to);
				book[edges[i].to] = 1;
			}
		}
	}
}
/*
1
10 15
4 7 10
7 6 3
5 3 3
1 4 11
0 6 20
9 8 25
3 0 9
1 2 15
9 0 27
5 2 0
7 3 -5
1 7 21
5 0 1
9 3 16
1 8 4
4 1
0 3
6 9
2 1
8 7
0 4
*/
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		mmset(head,-1);
		int n,m,len = 1;
		int a,b,c;
		scanf("%d %d",&n,&m);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			addEdges(a,b,c,len);
		}
		int s,t;
		for(int i = 1; i <= 6; i++)
		{
			scanf("%d %d",&s,&t);
			spfa(t);
			addEdges(s,t,-dis[s],len);
			printf("%d\n",-dis[s]);
		}
	}

	return 0;
}