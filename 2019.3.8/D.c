#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const double esp = 1e-6;
const int N = 2e5 + 5;
int n;
double data1[N],data2[N];
vector <double> aux;
int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf",&data1[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf",&data2[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		if(data1[i] == 0)
		{
			continue;
		}
		else 
		{
			double temp = data2[i] == 0 ? 0 :data1[i] / data2[i];
			aux.push_back(temp);
		}
	}
	sort(aux.begin(),aux.end());
	int res = aux.size() == 0 ? 0 : 1; 
	int ans = 0;
	int len = aux.size() - 1;
	for(int i = 0; i < len; i++)
	{
		if(aux[i + 1] - aux[i] < esp && aux[i] != -100)
		{
			res++;
		}
		else 
		{
			ans = max(res,ans);
		}
	}
	ans = max(res,ans);	
	printf("%d\n",ans);



	return 0;
}
