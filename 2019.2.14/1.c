#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 6005;
struct node
{
	string str;
	bool operator > (const node b) const 
	{
		return str.length() == b.str.length() ? str > b.str : str.length() > b.str.length();
	}
	bool operator < (const node b) const 
	{
		return str.length() == b.str.length() ? str < b.str : str.length() < b.str.length();
	}
	bool operator == (const node b) const 
	{
		return str == b.str;
	}
};
node data[N],sufData[N];
int n,numb = 1;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		data[1].str = data[n+1].str = "";
		sufData[n+1].str = "";
		for(int i = 1; i<= n; i++)
		{
			cin>>data[i].str;
		}
		for(int j = n; j >= 1; j--)
		{
			sufData[j].str = data[j+1].str + sufData[j+1].str;
		}
	}
	return 0;
}



