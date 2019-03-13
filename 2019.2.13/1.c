#include<string.h>
#include<algorithm>
#include<string>
#include<iostream>
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 6005;
struct node
{
	string str;
	bool operator < (const node b) const
	{
		return str.length() == b.str.length() ? str < b.str : str.length() < b.str.length();
	}
	bool operator == (const node b) const 	
	{
		return str == b.str;
	}
	node& operator = (node& b)
	{
		str = b.str;
	}
};
node data[N];
int n;

/*
 3
3
6 6 6
4
21 12 12 21
2
998244353 985661441
*/
int main()
{
	int T;
	int numb = 1;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i =1; i <= n; i++)
		{
			cin>>data[i].str;
		}			
		node max1;
		max1.str = "0";
		int index = 0;
		for(int i = 1; i <= n; i++)
		{
			if(max1 < data[i])
			{
				max1 = data[i];
				index = i;
			}
		}
		node res1;
		res1.str = "0";
		for(int i = 1; i<= n; i++) if(i != index)
		{
			node temp;
			if(i < index)
			{
				temp.str = data[i].str + max1.str;
				if(res1 < temp)
				{
					res1 = temp;
				}
			}
			else
			{
				temp.str = max1.str + data[i].str;
				if(res1 < temp)
				{
					res1 = temp;
				}
			}
		}
		cout<<"Case #"<<numb++<<": "<<res1.str<<endl;
	}	






	return 0;
}
		
