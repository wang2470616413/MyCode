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
		ll res1 = 0;
		ll res = -1;
		for(int i = 0; i < len; i++)
		{
			if(str1[i] == str2[i])
			{
				res1++;
			}
			else 
			{
				res = max(res,res1);
				res1 = 0;
			}
		}
		printf("%lld\n",res * res + res + res);
	}







	return 0;
}
