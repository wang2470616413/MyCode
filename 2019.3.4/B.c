#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e3 + 5, M = 1e5 + 5;
int data[N];
int mark[M];
int mark1[M];
int n;
int main()
{
	mmset(mark,0);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
		mark[data[i]] ++;
	}
	int res = 0; 
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			int a = data[i],  b = data[j];
			int sum = a + b;
			int num = 0;
			mmset(mark1,0);
			for(int k = 0; k < n; k++)
			{
				mark1[data[k]] = mark[data[k]];
			}
			for(int k = 0; k < n; k++)if(data[k] != sum )
			{
				if(data[k] > sum )
				{
					continue;
				}
				if(sum % 2 == 0)
				{
					if(data[k] == sum / 2)
					{
						continue;
					}
				}
				int temp1 = num;
				num += min(mark1[data[k]],mark1[sum - data[k]]);
				if(num != temp1)
				{
					mark1[data[k]] = mark1[data[k]] >= 1 ? mark1[data[k]] - 1 : 0;
					mark1[sum - data[k]] = mark1[sum - data[k]] >= 1 ? mark1[sum - data[k]] - 1 : 0;
				}
			}
			res = max(res,num);
		}
	}
	printf("%d\n",res);
	return 0;
}
