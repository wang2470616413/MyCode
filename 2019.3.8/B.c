#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2e5 + 5;
int  data[N];
int mark[N];
int mark1[N];
int n,k;
int main()
{
	mmset(mark,0);
	scanf("%d %d",&n,&k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
		data[i] %= k;
		mark[data[i]]++;
	}
	int res = 0;
	for(int i = 1; i < k; i++)if(mark1[i] == 0)
	{
		if(i == k - i)
		{
			res += (mark[i] / 2);
		}
		else 
		{
			res += min(mark[i] , mark[k - i]);
		}
		mark1[k - i] = 1;
	}
	res += mark[0] / 2;
	printf("%d\n",res * 2);



	return 0;
}
