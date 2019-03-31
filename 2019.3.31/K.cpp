#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a)) 
using namespace std;
const int N = 1e5 + 5;
int data[N];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int sum = n * m;
	int tsum = 0;
	for(int i = 1; i <= n; i++) 
	{
		scanf("%d",&data[i]);
		tsum += data[i];
	}
	int aux = sum - tsum;
	sort(data + 1,data + 1 + n);
	int res = 0;
	if(aux <= 0)
	{
		printf("0\n");
	}
	else 
	{
	for(int i = 1; i <= n; i++)
	{
		if(1000 - data[i] >= aux)
		{
			res++;
			break;
		}
		else
		{
			res ++;
			aux -= (1000 - data[i]);
		}
	}
	printf("%d\n",res);
	
	}

	
	
	return 0;
}
