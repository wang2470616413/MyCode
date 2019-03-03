#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e3 + 5, M = 1e5 + 5;
int data[N];
int mark[M];
int mark1[M];
int n;
int main()
{
	mmset(mark,0);
	scanf("%d",&n);
	vector <int> aux;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
		mark[data[i]] ++;
		if(mark[data[i]] == 1)
		{
			aux.push_back(data[i]);
		}

	}
	int res = 0; 
	for(int i = 0; i < aux.size() - 1; i++)
	{
		for(int j = i + 1; j < aux.size(); j++)
		{
			int a = aux[i],  b = aux[j];
			int sum = a + b;
			int num = 0;
			mmset(mark1,0);
			for(int k = 0; k < aux.size(); k++)
			{
				mark1[aux[k]] = mark[aux[k]];
			}
			for(int k = 0; k < aux.size(); k++)if(aux[k] != sum && sum - aux[k] != sum)
			{
				if(aux[k] < sum )
				{
					continue;
				}
				if(sum % 2 == 0)
				{
					if(aux[k] == sum / 2)
					{
						continue;
					}
				}
				int temp1 = num;
				num += min(mark1[aux[k]],mark1[sum - aux[k]]);
				if(num != temp1)
				{
					mark1[aux[k]] = mark1[aux[k]] >= 1 ? mark1[aux[k]] - 1 : 0;
					mark1[sum - aux[k]] = mark1[sum - aux[k]] >= 1 ? mark1[sum - aux[k]] - 1 : 0;
				}
			}
			res = max(res,num);
		}
	}
	printf("%d\n",res);
	return 0;
}
