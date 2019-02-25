#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 55;
struct node
{
	int x,y;
	node()
	{

	};
	node (int px, int py)
	{
		x = px, y = py;
	};
};
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int data[N][N],mark[N][N];
vector <node> aux1;
vector <node> aux2;
int n,sx,sy,ex,ey;
int main()
{
	scanf("%d",&n);
	scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			scanf("%d",&data[i][j]);
		}
	}
	queue <node> que1;
	que1.push(node(sx,sy));
	mmset(mark,0);
	mark[sx][sy] = 1;
	while(!que1.empty())
	{
		node fro = que1.front();
		que1.pop();
		aux1.push_back(fro);
		for(int i = 0; i < 4; i++)
		{
			int nx = fro.x + dir[i][0];
			int ny = fro.y + dir[i][1];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && mark[nx][ny] == 0 && data[nx][ny] == 0)
			{
				mark[nx][ny] = 1;
				que1.push(node(nx,ny));
			}
		}
	}
	queue <node> que2;
	que2.push(node(ex,ey));
	mmset(mark,0);
	mark[ex][ey] = 1;
	while(!que2.empty())
	{
		node fro = que2.front();
		que2.pop();
		aux2.push_back(fro);
		for(int i = 0; i < 4; i++)
		{
			int nx = fro.x + dir[i][0];
			int ny = fro.y + dir[i][1];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && mark[nx][ny] == 0 && data[nx][ny] == 0)
			{
				mark[nx][ny] = 1;
				que2.push(node(nx,ny));
			}
		}
	}
	int res = 99999999;
	for(int i = 0; i < aux1.size(); i++)
	{
		for(int j = 0; j < aux2.size();j++)
		{
			int dis = (aux1[i].x - aux2[j].x) * (aux1[i].x - aux2[j].x) + (aux1[i].y - aux2[j].y) * (aux1[i].y - aux2[j].y);
			res = min(res,dis);
		}
	}	
	printf("%d\n",res);
	return 0;
}
