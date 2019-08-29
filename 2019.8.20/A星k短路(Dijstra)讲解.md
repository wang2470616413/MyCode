# A*k最短路讲解
##### 在讲解之前你可能需要了解一下 <font color="red">dijstra的堆实现</font>
#### Dijstra求k短路
##### 在松弛的过程中如果把每个点都加进优先队列(堆)，那么如果有泛化的点p在第t次出队，那么此时就能得到源点到p点的第t短的路。但是这个方法用来求k短路过于慢，所以就有了A*来加速寻找k短路的过程。
#### A*
##### A*本质上就是使用了优先队列的bfs。但是优先队列的优先性由一个确定值与一个估值的和来确定。
##### 在这里我们假定某个点的确定值为g，估值为h，且该点终点的实际距离为h1,那么搜索的过程中，g代表起点到该点的实际距离，h代表该点到终点的估算距离(这个值可由算法设计者自由算出)，h1代表该点到终点的实际距离。
##### 那么我们能得出以下结论：
###### &emsp;&emsp;&emsp;1.当h < h1时，搜索范围较广但结果准确
###### &emsp;&emsp;&emsp;2.当h == h1时，搜索范围较小但结果准确
###### &emsp;&emsp;&emsp;1.当h > h1时，搜索范围最小但结果不准确

#### A* 求最短路
##### poj2449模板题，代码如下
```
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e3 +500,M = 1e5+500;
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
	int p, g, h;
	point()
	{
		
	};
	point(int _p, int _g, int _h)
	{
		p = _p;
		g = _g;
		h = _h;
	};
	bool operator < (point two) const
	{
		return g + h > two.g + two.h;
	}
};
int head[N],dis[N], head2[N];
node edges[M], edges2[M];
int len1,len2;
void addEdge(int a, int b, int c)
{
	edges[len1] = node(b,c,head[a]);
	head[a] = len1++;
	edges2[len2] = node(a,c,head2[b]);
	head2[b] =  len2++;
};
void dijstra(int s)
{
	mmset(dis,0x3f);
	dis[s] = 0;
	priority_queue <point> que;
	que.push(point(s,0,0));
	while(!que.empty())
	{
		point now = que.top();
		que.pop();
		for(int i = head2[now.p]; i != -1; i = edges2[i].next)if(dis[edges2[i].to] > dis[now.p] +  edges2[i].w)
		{
			dis[edges2[i].to] = dis[now.p] +  edges2[i].w;
			que.push(point(edges2[i].to,dis[edges2[i].to],0));
		}
	}
}
int Astart(int s, int e, int k)
{
	priority_queue <point> que;
	que.push(point(s,0,0));
	int t = 1;
	while(!que.empty())
	{
		point now = que.top();
		que.pop();
		if(now.p == e)
		{
			if(t == k)
			{
				return now.g; 
			}
			t++;
		}
		for(int i = head[now.p]; i != -1; i = edges[i].next)
		{
			que.push(point(edges[i].to, now.g + edges[i].w, dis[edges[i].to]));
		}
	}
	return -1;
	
}
/*
2 2
1 2 5
2 1 4
1 2 2
*/
int main()
{
	int n,m;
	int a,b,c;
	len1 = len2 = 1;
	mmset(head,-1);
	mmset(head2,-1);
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		addEdge(a,b,c);
	}
	int s,e,k;
	scanf("%d %d %d",&s,&e,&k);
	dijstra(e);
	if(s == e)
	{
		k++;
	}
	int res = Astart(s,e,k);
	printf("%d\n",res);
	return 0;
}
```
