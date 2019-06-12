// luogu-judger-enable-o2
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 5e5 + 5, M = 5e5 + 5;
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
int head[N],headQuery[M],father[N],ans[M], vis[N];
int n,m,k,root;
node edges[2 * M];
node queryData[2 * M];
void addEdge(int a, int b, int c, int& len) //建图
{
    edges[len] = node(b,c,head[a]);
    head[a] = len++;
}
void addQuey(int a, int b, int index, int& len) //建立查询关系图
{
    queryData[len] = node(b,index,headQuery[a]);
    headQuery[a] = len++;
}
void init(int a, int b)
{
    for(int i = a; i <= b; i++)
    {
        father[i] = i;
    }
    mmset(head,-1);
    mmset(vis,0);
    mmset(headQuery,-1);
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
void dfs(int rt,int fa)
{
    for(int i = head[rt]; i != -1; i = edges[i].next) if(edges[i].to != fa)
    {
        dfs(edges[i].to,rt);
        merge(edges[i].to, rt);
        vis[edges[i].to] = 1;
    }
    for(int i = headQuery[rt]; i != -1; i = queryData[i].next)
    {
        int to = queryData[i].to;
        if(vis[to] == 1)
        {
            ans[queryData[i].w] = find(to);
        }
    }
}

/* 
9 8 4
1 2
2 4
2 5
5 7
5 8
7 9
1 3
3 6

9 8
4 6
7 5
5 3
*/
int main()
{
    scanf("%d %d %d",&n,&k,&root);
    int len = 1,lenQuery = 1;
    init(1,n);
    for(int i = 1; i <= n - 1; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        addEdge(a,b,1,len);
        addEdge(b,a,1,len);
    }
    for(int i = 1; i <= k; i++)
    {
        int a, b;
        scanf("%d %d",&a,&b);
        addQuey(a,b,i,lenQuery);
        addQuey(b,a,i,lenQuery);
    }
    dfs(root,root);  //求lca
    for(int i = 1; i <= k; i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}