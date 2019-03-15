#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
string str1,str2;
int main()
{
	while(cin>>str1>>str2)
	{
		int len = str1.length();
		int res1 = 0;
		for(int i = 0; i < len; i++)
		{
			if(str1[i] == str2[i])
			{
				res1++;
			}
			else 
			{
				break;
			}
		}
		int res2 = 0;
		for(int j = len - 1; j >=0; j--)
		{
			if(str1[j] == str2[j])
			{
				res2++;

			}
			else 
			{
				break;
			}
		}
		printf("%d\n",res1 * res2 + res1 + res2);
	}







	return 0;
}
