#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 15;
struct node
{
	string str;
	int a,b;
}
int dp[1 << N + 10];
int const<1 << N  + 10];
node data[N + 5];
int n;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i = 0; i < n; i++)
		{
			cin>>data[i].str>>data[i].a>>data[i].b;
		}

	}





	return 0;
}
