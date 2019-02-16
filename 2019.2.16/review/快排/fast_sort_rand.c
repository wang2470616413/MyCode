#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void fastSortRand(int a, int b, int* data)
{
	if(a >= b)
	{
		return;
	}
	int index = (rand() % (b - a)) + a;
	Swap(data[a],data[index]);
	int i = a, j = b, key = data[a];
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
		if(data[i] > key && data[j] < key) 
		{
			Swap(data[i],data[j]);
		}
	}
	Swap(data[a],data[j]);
	fastSortRand(a, j - 1, data);
	fastSortRand(j + 1, b, data);
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
	fastSortRand(1,n,data);
	for(int i = 1; i <= n; i++)
	{
		printf("%d ",data[i]);
	}
	printf("\n");





	return 0;
}


