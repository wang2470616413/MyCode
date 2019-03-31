#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a)) 
using namespace std;
int main()
{
	int a1,a2,a3,a4,b1,b2,b3,b4;
	scanf("%d %d %d %d %d %d %d %d",&a1,&a2,&a3,&a4,&b1,&b2,&b3,&b4);
	int k1 = max(a1,b1);
	int k2 = max(a2,b2);
	int k3 = min(a3,b3);
	int k4 = min(a4,b4);
	int sum = (a3 - a1) * (a4 - a2) + (b3 - b1) * (b4 - b2);
	int res = sum -  ((k3 - k1) * (k4 - k2));
	printf("%d\n",res);
	 
	
	
	
	return 0;
}
