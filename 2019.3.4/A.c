#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105;
struct node 
{
	int id,pow;
	node ()
	{

	};
	node (int p_id,int p_pow)
	{
		id = p_id;
		pow = p_pow;
	}
	bool operator < (const node b)
	{
		return pow > b.pow;
	}
};
vector <node> aux[N];
int data[N], data1[N];
int n,m,k;
int main()
{
	
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data1[i]);
		aux[data1[i]].push_back(node(i,data[i]));
	}
	int res = 0;
	for(int i = 1; i <= m; i++)
	{
		sort(aux[i].begin(),aux[i].end());
	}
	for(int i = 1; i <= k; i++)
	{
		int num = 1;
		scanf("%d",&num);
		int key = data[num];
		int index = data1[num];
		if(aux[index][0].pow != key)
		{
			res++;
		}
	}
	printf("%d\n",res);
		




	return 0;
}
