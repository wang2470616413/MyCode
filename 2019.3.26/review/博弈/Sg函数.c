#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005;
int f[N],SG[N],mark[N];
int getSG(int n, int len)
{
	mmset(SG,0);
	for(int i = 1; i <= n; i++)
	{
		mmset(mark,0);
		for(int j = 0; j <= SG[i] && j <= len; j++)
		{
			mark[SG[i - f[j]]] = 1;
		}
		for(int j = 0; ; j++)
		{
			if(mark[j] == 0)
			{
				SG[i] = j;
				break;
			}
		}
	}
}
int main()
{






	return 0;
}

