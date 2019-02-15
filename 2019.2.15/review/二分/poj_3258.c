#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 5e4 + 5;
int data[N],L,n,k;
int count1(int dis)
{
	int sum = 0;
	int temp = 0;
	for(int i = 1; i <= n; i++)
	{
		if(data[i] - data[i-1] + temp < dis)
		{
			sum++;
			temp += data[i] - data[i-1];
		}
		else
		{
			temp = 0;
		}
	}
	return sum; 
}
int main()
{
	while(~scanf("%d %d %d",&L,&n,&k))
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
		}
		data[0] = 0, data[n+1] = L;
		sort(data, data + 1 + n + 1);

		int a = 0, b = 2 * L;
		int m;
		while(a <= b)
		{
			m = (a + b) / 2;
			int key = count1(m);
			if(key > k)
			{
				b = m - 1;
			}
			else 
			{
				a = m + 1;
			}

		}

		printf("%d\n",b);


	}


	return 0;
}
