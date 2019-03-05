#include<stdio.h>
#include<string.h>
#include<stack>
#include<algorithm>
#define ll long long 
#define mmse(a,b) memset(a,b,sizeof(a))
using namespace std;
int path[100];
void printhPath(int p);
void printhPath1(int p);
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&path[i]);
	}
	//printhPath(n);
	printhPath1(n);
	return 0;
}
void printhPath(int p)
{
	if(p == 0)
	{
		return;
	}
	printhPath(path[p]);
	printf("%d\n",p);
}
void printhPath1(int p)
{
	stack <int> sta;
	while(p != 0)
	{
		sta.push(p);
		p = path[p];
	}
	while(sta.size() != 0)
	{
		printf("%d\n",sta.top());
		sta.pop();
	}

}
