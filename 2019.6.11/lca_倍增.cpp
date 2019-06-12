#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 5e5 + 5, DEP = 20;

struct node
{
	int to, w, next;
	node()
	{
		
	};
	node(int p_to, int p_w, int p_next)
	{
		to = p_to;
		w = p_w;
		next = p_next;
	}
 };
int fa[N][DEP + 6],vis[N],head[N],dep[N];
int n,m,k,root;
node edges[2 * N];
void addEdge(int a, int b, int c, int& len)
{
	edges[len] = node(b,c,head[a]);
	head[a] = len++;
}
void init()
{
	mmset(vis,0);
	mmset(head,-1);
}
void bfs(int root)
{
	queue <int> que;
	que.push(root);
	vis[root] = 1;
	fa[root][0] = -1;
    dep[root] = 1;
	while(!que.empty())
	{
		int temp = que.front();
		que.pop();
		for(int i = 1; i < DEP; i++)
		{
			fa[temp][i] = fa[fa[temp][i-1]][i-1];
		}
		for(int i = head[temp]; i != -1; i = edges[i].next)if(vis[edges[i].to] == 0)
		{
			vis[edges[i].to] = 1;
			que.push(edges[i].to);
			fa[edges[i].to][0] = temp;
            dep[edges[i].to] = dep[temp] + 1;
		}
	}

}
int lca(int a, int b)
{
	if(dep[a] < dep[b])
	{
		swap(dep[a],dep[b]);
	}
	int len = dep[a] - dep[b];
	
}

/*
16 4 1
1 2
1 3
2 4
2 5
3 6
3 7
5 8
5 9
6 10
8 11
8 12
11 13
11 14
13 15
13 16
*/
int main()
{
	scanf("%d %d %d",&n,&k,&root);
	int len = 1; 
	init();
	for(int i = 1; i <= n-1; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		addEdge(a,b,1,len);
		addEdge(b,a,1,len);
	}
	bfs(1);
	for(int i = 1; i <= n; i++)
	{
		printf("%d \t",i);
		for(int j = 0; j < 8; j++)
		{
			printf("%d ",fa[i][j]);
		 } 
		 printf("\n");
	 }
	return 0;
} 