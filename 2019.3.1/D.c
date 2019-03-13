#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1 << 20;
int n,m;
int dis[N + 5];
int main()
{
	mmset(dis,0x3f3f3f3f);
	scanf("%d %d",&n,&m);
	char str[100];
	queue <int> que;
	for(int i = 1; i <= n; i++)
	{
		int num = 0;
		scanf("%s",str);
		for(int j = 0; j < m; j++)if(str[j] == '1')
		{
			num |= (1 << j);
		}
		que.push(num);
		dis[num] = 0;
	}
	while(!que.empty())
	{
		int front = que.front();
		que.pop();
		for(int i = 0; i < m; i++)
		{
			int next = front ^ (1 << i);
			if(dis[next] > dis[front] + 1)
			{
				dis[next] = dis[front] + 1;
				que.push(next);
			}
		}
	}
	int ans = 0;
	for(int i  = 0; i < (1 << m); i++)
	{
		ans = max(ans,dis[i]);
	}
	printf("%d\n",m - ans);





	return 0;
}
