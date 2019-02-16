#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e6 + 5;
void fast_sort(int a, int b, int* data)
{
	if(a >= b)
	{
		return;
	}
	int index = (rand() % (b - a)) + a;
	int i = a, j = b, key = data[index];
	while(i < j)
	{
		while(data[j] >= key && i < j)
		{
			j--;
		}
		while(data[i] <= key && i < j)
		{
			i++;
		}
		if(data[i] > key && data[j] < key && i < j)
		{
			int temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	data[index] =  data[j];
	data[j] = key;
	fast_sort(a, j - 1, data);
	fast_sort(j + 1, b, data);
	
}

int data[N];
int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
		}
		fast_sort(1,n,data);
		for(int i = n; i > n - m + 1; i--)
		{
			printf("%d ",data[i]);
		}
		printf("%d\n",data[n - m + 1]);
	}





	return 0;
}
