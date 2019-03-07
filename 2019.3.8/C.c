#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2e5 + 10;
int data[N];
int n;
int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		 scanf("%d",&data[i]);
	}
	sort(data + 1, data + 1 + n);
	int i = 1;
	int j = 1;
	int res = 0;
	int temp = 0;
	int ans = 1;
	while(j <= n)
	{
		if(data[j] >= data[i] && data[j] <= data[i] + 5)
		{
			res++;
		}
		else 
		{
			i = j + 1;
			ans = max(ans,res);
			res = 0;
		}
		j++;
	}
	ans = max(ans,res);
	printf("%d\n",ans);



	return 0;
}
