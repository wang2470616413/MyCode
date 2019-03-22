#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 3e4 + 5;
struct node
{
	vector <ll> data;
	vector <ll> sum;
};
node aux[N];
int n,m;
int main()
{
		scanf("%d %d",&n,&m);
		for(int i = 1; i <= n; i++)
		{
			ll a,b;
			scanf("%lld %lld",&a,&b);
			aux[a].data.push_back(b);
		}
		for(int i = 1; i <= m; i++)
		{
			sort(aux[i].data.begin(),aux[i].data.end());
		}

		for(int i = 1; i <= m; i++)
		{

			if(!aux[i].data.empty())
			{
				aux[i].sum.push_back(aux[i].data[0]);
				for(int j = 1; j < aux[i].data.size(); j++)
				{
					aux[i].sum.push_back(aux[i].sum[j-1] + aux[i].data[j]);
				}
			}
		}
		int st = aux[1].data.size(); 
		ll res = 1e18;
		for(int i =  1; i <= n; i++)
		{
			ll temp = 0;
			int num = st;
			vector <ll> aux1;
			for(int j = 2; j <= m; j++)
			{
				int len1 = aux[j].data.size();
				if(len1 == 0)
				{
					continue;
				}
				if(i <= len1)
				{
					num += (len1 - i + 1);
				//	printf("%d\n",j); 
					temp += aux[j].sum[len1 - i];
					for(int k = len1 - i + 1; k < len1; k++)
					{
						aux1.push_back(aux[j].data[k]);
					}
				}
				else 
				{
					for(int k = 0; k < len1; k++)
					{
						aux1.push_back(aux[j].data[k]);
					}
				}
			} 
			if(i <= num)
			{
				res = min(res,temp);
			}
			else if(aux1.size()!= 0)
			{
				sort(aux1.begin(),aux1.end());
				for(int  k = 0; k < (i - num); k++)
				{
					temp += aux1[k];
				}
				res = min(res,temp);
			}
		
		}
		printf("%lld\n",res ); 
	
	
	
	
	
	
	return 0;
} 
