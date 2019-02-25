#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 5;
int n;
int mark[N];
vector <ll> aux[N];
int main()
{
	mmset(mark,0);
	scanf("%d",&n);
	n *= 2;
	for(int i = 1; i <= n; i++)
	{
		int num;
		scanf("%d",&num);
		aux[num].push_back(i);
	}
	ll res = 0;
	for(int i = 1; i < n / 2; i++)
	{
		res += min(fabs(aux[i][0] - aux[i+1][0]) + fabs(aux[i][1] - aux[i+1][1]),fabs(aux[i][1] - aux[i+1][0]) + fabs(aux[i][0] - aux[i+1][1]));
	}
	res += (aux[1][0] + aux[1][1] - 2);
	printf("%lld\n",res);

	return 0;
}
