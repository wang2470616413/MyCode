#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,szieof(a))
using namespace std;
const int N = 1e6 + 5; 
char map1[] = "0123456789abcdefgh";
char str[N];
int aux[N];
void count1(char* data)
{
	int len = strlen(data);
	int index = 1;
	for(int i = len - 1; i >= 0;)
	{
		int num = 0;
		for(int j = 0; j < 4; j++)if(i >= 0)
		{
			num += pow(2,j) * (data[i] - '0');
			i--;
		}
		aux[index++] = num;
	}
	for(int i = index - 1; i >= 1; i--)
	{
		printf("%c",map1[aux[i]]);
	}
	printf("\n");
	 
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		count1(str);
	}
	
	
	
	return 0;
} 
