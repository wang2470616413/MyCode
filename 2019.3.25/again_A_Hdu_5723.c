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
	int a,b,w;
	node()
	{

	};
	node(int p_a, int p_b, int p_w)
	{
		a = p_a;
		b = p_b;
		w = p_w;
	}
	bool operator < (const node two) 
	{
		return w < two.w;
	}
};
vector <node> tree[N];
node data[N];
int father[N];
int mark[N],res = 0, sumFree = 0;
int n ,m;
void init(int a, int b)
{
	for(int i = a; i <= b; i++)
	{
		father[i] = i;
	}
}
int find(int x)
{
	return father[x] == x ? x : find(father[x]);
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
	sort(data + 1, data + 1 + m);
	int num = 1;
	for(int i = 1; i <= m; i++)
	{
		int fx = find(data[i].a);
		int fy = find(data[i].b);
		if(fx != fy)
		{
			num++;
			merge(data[i].a,data[i].b);
			sumFree += data[i].w;
			tree[data[i].a].push_back(node(data[i].a,data[i].b,data[i].w));
			tree[data[i].b].push_back(node(data[i].b,data[i].a,data[i].w));
			if(num == n + 1)
			{
				break;
			}
		}
	}

}
int dfs(int now,int w)
{
	if(tree[now].size() == 1)	
	{
		res += (1 * (n-2) * w);
		return  1;
	}
	else 
	{
		int temp = 0;
		for(int i = 0; i < tree[now].size(); i++)if(mark[tree[now][i].b] == 0)
		{
			mark[tree[now][i].b] = 1;
			temp += dfs(tree[now][i].b,tree[now][i].w);
		}
		res += (temp * (n - 1 - temp) * w);
		return temp;
	}
}
double count1()
{
	mmset(mark,0);
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
		scanf("%d %d",&n,&m);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d %d",&data[i].a,&data[i].b,&data[i].w);
		}
		krusual(1,n);
		double res0 = count1();
		printf("%d\n",sumFree);
		
	}



	return 0;
}

