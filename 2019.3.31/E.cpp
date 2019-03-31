#include<stdio.h>
#include<string.h>
#include<set>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define itera set<char>::iterator
using namespace std;
const int N = 1e6 + 5;
int aux[1000];
int loc[1000];
char data[N];
int mark[1000];
int main()
{
	mmset(aux,0x3f);
	mmset(mark,0);
	scanf("%s",data);
	mmset(loc,-1);
	int len = strlen(data);
	for(int i = 0; i < len; i++)
	{
		char temp = data[i];
		mark[temp]++;
		if(loc[temp] != -1)
		{
			aux[temp] = min(aux[temp],i - loc[temp]);
		}
		loc[temp] = i;
	}
	for(int i = 'a'; i <= 'z'; i++)
	{
		if(mark[i] > 0)
		{
			int res = aux[i] == 0x3f3f3f3f ? 0 : len - aux[i];
			printf("%c:%d\n",i,res);
		}
	}
	for(int i = 'A'; i <= 'Z'; i++)
	{
		if(mark[i] > 0)
		{
			int res = aux[i] == 0x3f3f3f3f ? 0 : len - aux[i];
			printf("%c:%d\n",i,res);
		}
	}
	

	
	
	
	
	return 0;
}
