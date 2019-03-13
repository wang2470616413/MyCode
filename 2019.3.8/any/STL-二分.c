#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
	int data[100] = {0,1,1,2,2,2,3,4,7};
	int key ;
	while(scanf("%d",&key))
	{
		int res = upper_bound(data + 1,data + 4,key) - data;
		printf("%d\n",res);
	}



	return 0;
}	
