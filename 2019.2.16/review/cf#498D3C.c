#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2e5 + 5;
int data[N],n;
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
		}
		int a = 1, b = n;
		ll res = 0, resa = data[a], resb = data[b];
		while(a < b)
		{
			if(resa == resb)
			{
				resa += data[++a];
				res = resb;
			}
			if(resa < resb)
			{
				resa += data[++a];
			}
			if(resb < resa)
			{
				resb += data[--b];
			}
		}
			printf("%lld\n",res);
	}
	return 0;;
}


