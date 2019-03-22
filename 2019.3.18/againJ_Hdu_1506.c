#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N  = 1e5 + 10;
int data[N];
int left[N],right[N];
int main()
{
	int n;
	while(~scanf("%d",&n) && n != 0)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
		}
		stack <int> sta1;
		for(int i = 1; i <= n; i++)
		{
			while(!sta1.empty() && data[sta1.top()] >= data[i] )
			{
				sta1.pop();
			}
			if(sta1.empty())
			{
				left[i] = 0;
			}
			else 
			{
				left[i] = sta1.top();
			}
			sta1.push(i);
		}
		stack <int> sta2;
		for(int i = n; i >= 1; i--)
		{
			while(!sta2.empty() && data[sta2.top()] >= data[i])
			{
				sta2.pop();
			}
			if(sta2.empty())
			{
				right[i] = n+1;
			}
			else
			{
				right[i] = sta2.top();
			}
			sta2.push(i);
		}
		ll res = -1;
		for(int i = 1; i <= n; i++)
		{

			ll diff = right[i] - left[i] - 1;
			ll temp = data[i];
			res = max(res,diff * temp);
		}
		printf("%lld\n",res);
	}
	

		





	return 0;
}
