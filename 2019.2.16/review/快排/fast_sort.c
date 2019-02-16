#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;

void fastSort(int a, int b, int* data)
{
	if(a >= b )
	{
		return ;
	}
	int i = a, j = b;
	int key = data[a];
	while(i < j)
	{
		if(data[j] >= key)
		{
			j--;
		}
		if(data[i] <= key)
		{
			i++;
		}
		if(data[j] < key && data[i] > key && i < j)
		{
			int temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	data[a] = data[j];
	data[j] = key;
	fastSort(a,j-1,data);
	fastSort(j+1,b,data);
}	
int main()
{
	int n;
	scanf("%d",&n);
	int data[1000];
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
	}
	fastSort(1,n,data);
	for(int i = 1; i <= n; i++)
	{
		printf("%d ",data[i]);
	}
	printf("\n");
	return 0;
}

