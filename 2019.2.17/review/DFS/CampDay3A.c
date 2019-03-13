#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const  double esp = 1e-6;
double data[100],aux[100];
int vis[100],ans = 0;
int auxDfs(int len,double* data)
{
	for(int i = 1; i <= len; i++)if(vis[i] == 0)
	{
		for(int j = 1; j <= len; j++)if(vis[j] == 0 && i != j)
		{
			double temp = data[i];
			data[i] = temp + data[j], vis[j] = 1;
			if(fabs(data[i] - 24.0) <  esp || auxDfs(len,data) == 1)	
			{
				return 1;
			}
			data[i] = temp - data[j];
			if(fabs(data[i] - 24.0) <  esp || auxDfs(len,data) == 1)	
			{
				return 1;
			}
			data[i] = temp  / data[j];
			if(fabs(data[i] - 24.0) <  esp || auxDfs(len,data) == 1)	
			{
				return 1;
			}
			data[i] = temp * data[j];
			if(fabs(data[i] - 24.0) <  esp || auxDfs(len,data) == 1)	
			{
				return 1;
			}
			data[i] = temp;
			vis[j] = 0;
		}
	}
	return 0;
		

}
void dfs(int index,int auxlen, int len)
{
	if(index == auxlen + 1)
	{
		for(int i = 1; i <= index; i++)
		{
			aux[i] = data[i];
		}
		mmset(vis,0);
		ans += auxDfs(index,aux);
	}
	else 
	{
		
		for(int i = data[index] + 1;i <= len; i++)
		{
			data[index + 1] = i;
			dfs(index + 1, auxlen, len);
		}
	}
}
			
	
/*
 */
int main()
{
	int n;
	scanf("%d",&n);
	double data1[100] = {0,1.0,2.0,3.0};
	for(int i = 1; i <= n; i++)
	{
		data[0] = 0;
		dfs(0,i,n);
	}
	printf("%d\n",ans);
	return 0;
}

