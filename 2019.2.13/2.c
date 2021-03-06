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
node data[N];
int n,numb = 1;
/*
 3
3
6 6 6
4
21 12 12 21
6
998 244 353 985 661 441
*/
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i = 1; i <= n; i++)
		{
			cin>>data[i].str;
		}
		node min1;
		min1.str = "9999999999";
		int index = 0;
		for(int i = 1; i <= n; i++)
		{
			if(min1 > data[i])
			{
				index = i;
				min1 = data[i];
			}
		}
		node res1;
		res1.str = "0";
		for(int i = 1; i <= n; i++) if(i != index)
		{
			node temp;
			temp.str = "";
			for(int j = 1; j <= n; j++)if(j != i && j != index)
			{
				temp.str += data[j].str;
			}
			res1 = max(temp,res1);
		}
		cout<<"Case #"<<numb++<<": "<<res1.str<<endl;
	}
	
	return 0;
}

