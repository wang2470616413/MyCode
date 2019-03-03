#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e3 + 5, M = 1e5 + 5;
int data[N];
int mark[2 * M];
int mark1[M];
int n;
int main()
{
	mmset(mark,0);
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&data[i]);
	}
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			int sum = data[i] + data[j];
			mark[sum]++;
		}
	}
	int res = 0;
	for(int i = 1; i <= M; i++)
	{
		res = max(res,mark[i]);
	}
	printf("%d\n",res);
	return 0;
}
