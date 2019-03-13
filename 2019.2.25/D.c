#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105, M = 200;
int n,m;
vector <int> data[N];
int aux[N];
int main()
{
	
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= m; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		data[a].push_back(b);
	}
	for(int i = 1; i <= n; i++)
	{
		int min1 = 99999999;
		for(int j = 0; j < data[i].size(); j++)
		{
			int temp = i < data[i][j] ? data[i][j] - i : n - i + data[i][j];
			min1 = min(min1,temp);
		}
		aux[i] = min1;
	}	
	for(int i = 1; i <= n; i++)
	{
		int max1 = -1;
		for(int j = 1; j <= n; j++)if(data[j].size() > 0)
		{
			int dis = j >= i ? j - i : n - i + j;
			int temp = dis + n * (data[j].size() - 1) + aux[j];
			max1 = max(max1,temp);
		}
		printf("%d ",max1);
	}
	printf("\n");


	return 0;
}

