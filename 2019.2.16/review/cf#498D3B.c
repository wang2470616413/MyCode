#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
const int N = 2005;
using namespace std;
struct node
{
	int index,v;
	bool operator < (const node b) const 
	{
		return v > b.v; 
	}
};
node data[N];
int n,m;
/*
8 3
5 4 2 6 5 1 9 2
outputCopy
20
3 2 3
inputCopy
5 1
1 1 1 1 1
outputCopy
1
5
inputCopy
4 2
1 2000 2000 2
outputCopy
4000
2 2
 */
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i].v);
			data[i].index = i;
		}
		sort(data + 1, data + 1 + n);
/*		for(int i = 1; i <= n; i++)
		{
			printf("%d %d\n",data[i].index, data[i].v);
		}
*/
		int aux[N];
		int res = 0;
		for(int i = 1; i <= m; i++)
		{
			res += data[i].v;
			aux[i] = data[i].index;
		}
		printf("%d\n",res);
		sort(aux + 1, aux + 1 + m);
		if(aux[1] == 1)
		{
			aux[m+1] = n + 1;
			for(int i = 1; i <= m; i++)
			{
				printf("%d ",aux[i+1] - aux[i] );
			}
			printf("\n");
		}
		else
		{
			aux[0] = 0;
			aux[m] = n  ;
			for(int i = 1; i <= m; i++)
			{
				printf("%d ",aux[i] - aux[i-1]);
			}
			printf("\n");
		}	
	}






	return 0;
}
