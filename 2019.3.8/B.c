#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2e5 + 5;
ll  data[N];
int mark[N];
int n,m;
int main()
{
	mmset(mark,0);
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld",&data[i]);
	}
	int res = 0;
	for(int i = 1; i < n; i++)if(mark[i] == 0)
	{
		
		for(int j = i + 1; j <= n; j++)if(mark[j] == 0)
		{
			if((data[i] + data[j]) % m == 0 && (data[i] + data[j] != 0))
			{
				mark[j] = 1;
				res++;
				break;
			}
		}
	}
	printf("%d\n",res * 2);



	return 0;
}
