#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 55, M=  105;
struct node
{
	int a,b,w;
	node 
	{

	};
	node (int p_a,int p_b,int p_w)
	{
		a = p_a;
		b = p_b;
		w = p_w;
	}
	bool operator < (const node y) const 
	{
		return w < y.w;
	}
}
node Edges[M];
int n,m;
int main()
{
	while(scanf("%d", &n),&& n != 0 )	
	{
		scanf("%d",&m);
		for(int i = 1; i <= m; i++)
		{

			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			
		}
	}





	return 0;
}
