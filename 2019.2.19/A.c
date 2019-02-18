#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 5;
int data[N], n;
int aux[N];
int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
		aux[i] = data[i];
	}
	sort(aux + 1, aux + 1 + n);
	int res = 1, temp = aux[n];
	int i = 1;
	while(i <= n)
	{
		if(data[i] == temp)
		{
			int temp1 = 0;
			while(data[i] == temp)
			{
				temp1++;
				i++;
			}
			res = max(res,temp1);
		}
		i++;
	}		
	printf("%d\n",res);
	


	return 0;
}
