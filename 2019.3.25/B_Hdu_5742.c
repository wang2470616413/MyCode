#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a)) 
using namespace std;
const int N = 105;
int data[N]; 
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		mmset(data,-1);
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i = 1; i <= m; i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			data[a] = b;
		}		
		data[n+1] = 0;
		for(int j = n; j >= 3; j--)
		{
			if(data[j] == -1)
			{
				data[j] = data[j+1];
			}
		}
		if(data[1] == -1 && data[2] == -1)
		{
			data[1] = data[2] = 100;
		}
		if(data[1] == -1 && data[2] != -1)
		{
			data[1] = 100;
		}
		if(data[2] == -1 &&  data[1] != -1)
		{
			data[2] = data[1];
		}
		int a = data[1] + data[2];
		int b = 0;
		for(int i = 1; i <= n; i++)
		{
			b += data[i];
		}
		int temp = gcd(a,b);
		a /= temp;
		b /= temp;
		printf("%d/%d\n",a,b) ;
		
	}
	return 0;
}
