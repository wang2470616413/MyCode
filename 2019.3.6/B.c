#include<stdio.h>
#include<algorithm>
#include<string.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 3e5;
int data[N];
int n = 0;
ll sum = 0;
int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
		sum += data[i];
	}	
	sort(data + 1, data + 1 + n);
	int m;
	scanf("%d",&m);
	for(int i = 1; i <= m; i++)
	{

		int num ;
		scanf("%d",&num);
		printf("%lld\n",sum - data[n - num + 1]);
	}



	return 0;
}

