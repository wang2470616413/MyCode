#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2e5 + 5;
char str1[N], str2[N];
vector <int> aux[5];
int res[2 * N][2];
/*
8
babbaabb
abababaa
*/
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",str1 + 1);
	scanf("%s",str2 + 1);
	for(int i = 1; i <= n; i++)
	{
		if(str1[i] != str2[i])
		{
			aux[str1[i] - 'a'].push_back(i);
		}
	}
	int a = aux[0].size();
	int b = aux[1].size();
	int index = 1;
	for(int i = 1; i + 1 <= a; i += 2)
	{
		res[index][0] = aux[0][i-1];
		res[index++][1] = aux[0][i];
	}
	for(int i = 1; i + 1 <= b; i += 2)
	{
		res[index][0] = aux[1][i-1];
		res[index++][1] = aux[1][i];
	}
	if(a % 2 == 0 && b % 2 == 0)
	{
		printf("%d\n",index - 1);
		for(int i = 1; i < index; i++)
		{
			printf("%d %d\n",res[i][0],res[i][1]);
		}
	}
	else if(a % 2 == 1 && b % 2 == 1)
	{
		printf("%d\n",index + 1);
		for(int i = 1; i < index; i++)
		{
			printf("%d %d\n",res[i][0],res[i][1]);
		}
		printf("%d %d\n%d %d\n",aux[0][a - 1],aux[0][a-1],aux[0][a-1],aux[1][b-1]);
	}
	else
	{
		printf("-1\n");
	}
	
	return 0;
} 