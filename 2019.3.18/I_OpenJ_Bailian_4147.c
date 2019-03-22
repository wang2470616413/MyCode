#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a)) 
using namespace std;
void dfs(int n,char a, char b, char c)
{
	if(1 == n)
	{
		printf("%d:%c->%c\n",n,a,c);
	}
	else 
	{
		dfs(n - 1,a,c,b);
		printf("%d:%c->%c\n",n,a,c);
		dfs(n -1,b,a,c);
	}
}
int main()
{
	int n;
	char a,b,c;
	while(~scanf("%d %c %c %c",&n,&a,&b,&c))
	{
		dfs(n,a,b,c);	
	}
	
	
	
	
	return 0;
}

