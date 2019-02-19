#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2e5 + 5;
int data[N];
int preData[N],auxData[N];
int main()
{
	int n;
	scanf("%d",&n);
	mmset(preData,0);
	mmset(auxData,0);

	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
		if(i % 2 == 0)
		{
			if(i == 2)
			{
				auxData[i] = data[i];
			}
			else
			{
				auxData[i] = data[i] + auxData[i - 2];
			}
		}
		else 
		{
			if(i == 1)
			{
				preData[i] = data[i];
			}
			else
			{
				preData[i] = data[i] + preData[i-2];
			}
		}
			
	}
	preData[n] = max(preData[n-1],preData[n]);
	auxData[n] = max(auxData[n-1],auxData[n]);	
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i % 2 == 0)
		{
			if(preData[i - 1] + auxData[n] - auxData[i] == auxData[i - 2] + preData[n] - preData[i - 1])
			{
				res++;
			}
		}
		else 
		{
			if(auxData[i-1] + preData[n] - preData[i] == preData[i - 2] + auxData[n] - auxData[i-1])
			{
				res++;
			}
		}
	}
	printf("%d\n",res);





	return 0;
}	
