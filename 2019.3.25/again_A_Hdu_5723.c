#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 100005, M = 1000005;

struct node
{
	int a,b;
	int w;
	node()
	{

	};
	node(int p_a, int p_b, int p_w)
	{
		a = p_a;
		b = p_b;
		w = p_w;
	}
};
struct edge
{
	int to,w;
	edge(int p_to,int p_w)
	{
		to = p_to;
		w = p_w;
	}
};
bool cmp(node a,node b)
{
	return a.w < b.w;
}
vector <edge> tree[N];
node data[M];
int father[N];
int mark[N];
ll res = 0, sumFree = 0;
int n ,m;
void init(int a, int b)
{
	for(int i = 0; i <= b; i++)
	{
		tree[i].clear();
		father[i] = i;
	}
}
int find(int x)
{
	return father[x] = father[x] == x ? x : find(father[x]);
}
void merge(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
	{
		father[fx] = fy;
	}
}
void krusual(int a, int b)
{
	init(a,b);
	sort(data + 1, data + 1 + m,cmp);
	int num = 1;
	for(int i = 1; i <= m; i++)
	{
		int fx = find(data[i].a);
		int fy = find(data[i].b);
		if(fx != fy)
		{
			merge(data[i].a,data[i].b);
			sumFree += data[i].w;
			tree[data[i].a].push_back(edge(data[i].b,data[i].w));
			tree[data[i].b].push_back(edge(data[i].a,data[i].w));

		}
	}
}
int dfs(int now,int w)
{
	int temp = 0;
	for(int i = 0; i < tree[now].size(); i++)if(mark[tree[now][i].to] == 0)
	{
		mark[tree[now][i].to] = 1;
		temp += dfs(tree[now][i].to,tree[now][i].w);
	}
	res += (1.0 * (temp + 1) * (n - 1 - temp) * w);
	return temp + 1;
}

/*int dfs(int x)
{
    int cnt=0;
    for(int i=0;i<tree[x].size();i++)if(mark[tree[x][i].to] == 0)
    {
        int y=tree[x][i].to,value=tree[x][i].w;
        mark[y] = 1;

        int now=dfs(y);
        cnt+=now;
        res+=1.0*now*(n-now)*value;

    }
    return cnt+1;
}
*/
double count1()
{
	mmset(mark,0);
	mark[1] = 1;
	res = 0;
	dfs(1,0);
	double fa = (double)res;
	double fb = (n * 1.0) * ((n - 1) * 1.0) / 2.0;
	return fa / fb;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		sumFree = 0;
		scanf("%d %d",&n,&m);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d %d",&data[i].a,&data[i].b,&data[i].w);
		}
		krusual(1,n);
		double res0 = count1();
		printf("%lld %.2lf\n",sumFree,res0);
		
	}
	return 0;
}
