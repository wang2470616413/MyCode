#include<stdio.h>
#include<string.h>
 
const int INF = 505;
 
 
int dfs(int u);			//搜索以u点为起点的增广路经，如果能搜到返回1，不能返回0；
 
int edge[INF][INF];		//以邻接矩阵的形式建立二分图。 
 
int n, k;
 
int vx[INF], vy[INF];	//vy存的是在y集合中已经匹配过的x点，所以匹配边i->j的表示方法为vy[i]=j; 
					 
 
int vis[INF];		//用来标记在搜索过程中某点是否已经在增广路中，如果已经在就不用在向增广路添加了。 
 
 
/*
3 4
1 1
1 3
2 2
3 2
Sample Output
2
*/
int main()
{
	scanf("%d %d",&n, &k);
	
	memset(edge, -1, sizeof(edge));
	
	for(int i=1; i <= k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		edge[x][y] = 1;
	}
	
	memset(vx, -1, sizeof(vx));
	memset(vy, -1, sizeof(vy));		//一开始，二分图中没有点匹配。 
	
	int result = 0;					//一开始二分图匹配数为0；
	 
	for(int u = 1; u <= n; u++)		//对二分图中左边的每个点寻找增广路。 
	{
		memset(vis, 0, sizeof(vis));
		result += dfs(u) ;			//如果知道增广路，那么 匹配数+1； 
	}
	
	printf("%d\n", result) ;
	
	 
	
	
	
	return 0;
}
 
int dfs(int u)
{
	for(int v = 1; v <= n; v++)
	{
		if(edge[u][v] == 1 && vis[v] == 0)	//如果u，v两点之间有边（也就是两点可以匹配），
											//并且v不再增广路中
		{
			vis[v] = 1; 	//将 v点加入增广路。
			if(vy[v] == -1 ||dfs(vy[v]) == 1)	//如果该点为为非匹配点
												//或者能根据该点匹配的x中点找到未匹配点
			{
				vx[u] = v;						//翻转关系 
				vy[v] = u; 
				return 1;
			} 
		} 
	}
	return 0;
}
