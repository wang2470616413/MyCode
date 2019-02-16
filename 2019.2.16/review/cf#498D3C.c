#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N  = 2e5 + 5;
int data[N],n;
ll count1(ll sum, ll a)
{
	if(sum % a == 0)
	{
		ll mark = sum / a;
		int num = 0;
		ll temp = 0;
		for(int i = 1; i <= n; i++)
		{
			temp += data[i];
			if(temp == mark)
			{
				num++;
				temp = 0;
			}
		}
		if(num == a && temp == 0)
		{
			return mark;
		}
		else 
		{
			return -1;
		}	
						
	}
	return -1;
}
/*
 * 5
1 3 1 1 4
outputCopy
5
inputCopy
5
1 3 2 1 4
outputCopy
4
inputCopy
3
4 1 2
outputCopy
0
*/
int main()
{
	while(~scanf("%d",&n))
	{
		ll sum = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
			sum += data[i];	
				
		}
		if(count1(sum,2) != -1)
		{
			printf("%lld\n",sum / 2);
		}
		else 
		{
			ll res = 0;
			ll temp = 0;
			for(int i = 1; i <= n - 1; i++)
			{
				temp += data[i];
				ll temp1 = 0; 	
				for(int j = n; j > i; j--)
				{
					temp1 += data[j];
					if(temp1 == temp)
					{
						res = max(temp,res);
						break;
					}
				}
			}
			printf("%lld\n",res);
		}
	}




	return 0;
}
