#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105;
int data[N];
int n;
int main()
{
	scanf("%d",&n);
	int res1 = 0,res2 = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
		if(data[i] < 0)
		{

			res1++;
		}
		else if(data[i] > 0)
		{

			res2++;
		}
	}
	int num = (n - 1) / 2 + 1;
	if(res1 < num &&res2 < num)
	{
		printf("0\n");
	}
	else if(res1 >= num)
	{
		printf("-1\n");
	}
	else 
	{
		printf("1\n");
	}




	return 0;
}
