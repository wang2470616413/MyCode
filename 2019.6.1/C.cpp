#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e6 + 6;
char str1[N], str2[N];
vector <int> charIndex1[200];

void precount(char* str1, char* str2, int len1, int len2)
{
	for(int i = 'a'; i <= 'z'; i++)
	{
		charIndex1[i].clear();
	}
	for(int i = 1; i <= len1; i++)
	{
		charIndex1[str1[i]].push_back(i);
	}

}
bool count1(char* str1, char* str2, int len1, int len2)
{
	precount(str1, str2, len1, len2);
	int last;
	if(charIndex1[str2[1]].size() > 0)
	{
		last = charIndex1[str2[1]][0];
		charIndex1[str2[1]].erase(charIndex1[str2[1]].begin());
	}
	else
	{
		return false;
	}
	for(int i = 2; i <= len2; i++)
	{
		int index1;
		while(charIndex1[str2[i]].size() != 0 && charIndex1[str2[i]][0] <= last)
		{
			index1 = charIndex1[str2[i]][0];
			charIndex1[str2[i]].erase(charIndex1[str2[i]].begin());
		}
		if(charIndex1[str2[i]].size() == 0)
		{
			return false;
		}
		else if(charIndex1[str2[i]][0] > last)
		{
			last = charIndex1[str2[i]][0];
			charIndex1[str2[i]].erase(charIndex1[str2[i]].begin());
		}
	}
	return true;
}
int main()
{
	int n ;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s",str1 + 1);
		scanf("%s",str2 + 1);
		int len1 = strlen(str1 + 1);
		int len2 = strlen(str2 + 1);
		if(len2 + 2 != len1)
		{
			printf("0\n");
		}
		else
		{
			if(count1(str1, str2, len1, len2) == true)
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}