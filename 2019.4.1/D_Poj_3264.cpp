#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 50005;
int dpMax[N][20];
int dpMin[N][20];
void STMax();
void STMin();
int RMQMax(int i ,int j);
int RMQMin(int i, int j);
int data[N];
int n,q;
int main()
{
	scanf("%d %d",&n,&q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
	}
	STMax();
	STMin();
	for(int i = 1; i <= q; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",RMQMax(a,b) - RMQMin(a,b));
	}
	
	
	
	
	return 0;
}
void STMax()
{
	for(int i = 1 ; i <= n; i++)
	dpMax[i][0] = data[i];
	
	for(int j = 1; (1 << j) <= n; j++)
	{
		for(int i =1; i + (1 << j) -1 <= n; i++)
		{
			dpMax[i][j]=max(dpMax[i][j-1],dpMax[i+(1<<(j-1))][j-1]);
		}
	}
}
void STMin()
{
	for(int i = 1 ; i <= n; i++)
	dpMin[i][0] = data[i];
	
	for(int j = 1; (1 << j) <= n; j++)
	{
		for(int i =1; i + (1 << j) -1 <= n; i++)
		{
			dpMin[i][j]=min(dpMin[i][j-1],dpMin[i+(1<<(j-1))][j-1]);
		}
	}
}
int RMQMax(int i ,int j)
{
	if(i > j)
	return 0; 
	int k = 0;
	
	while((1<<(k + 1)) <= j -i +1)k++;			
	
	return max(dpMax[i][k], dpMax[j - (1 << k) + 1][k]);
	
}
int RMQMin(int i, int j)
{
	if(i > j)
	return 0; 
	int k = 0;
	
	while((1<<(k + 1)) <= j -i +1)k++;			
	
	return min(dpMin[i][k], dpMin[j - (1 << k) + 1][k]);
	
}
