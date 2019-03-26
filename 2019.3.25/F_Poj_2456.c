#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N =  100000 + 5;
int data[N];
int n,m;
int count1(int mark)
{
	int res = 0, temp = 0;
	for(int i = 2; i <= n; i++)
	{
		if(data[i] - data[i-1]  + temp < mark)
		{
			temp += data[i] - data[i-1];
		}
		else
		{
			res++;
			temp = 0;
		}
	}
	return res;	
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
	}
	data[0] = 0;
	sort(data + 1 , data + 1 + n);
	int a = 1, b = data[n] + 5, mid;
	while(a <= b)
	{
		mid = (a + b) / 2;
		int temp = count1(mid) ;
		if(temp >= m - 1) 
		{
			a = mid + 1;
		}
		else
		{
			b = mid - 1;
		}
	}
	printf("%d\n",b) ;
	
	
	return 0;
}
