#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
	int data[199];
	mmset(data,-0x3f);
	for(int i = 1; i <= 10; i++)
	{
		printf("%d ",data[i]);
	}



	return 0;
}

