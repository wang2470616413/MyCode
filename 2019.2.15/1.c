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
	int index;
	bool operator < (const node b) const 
	{
		return str.length() == b.str.length() ? str < b.str : str.length() < b.str.length(); 
	}
	bool operator > (const node b) const 
	{
		return str.length() == b.str.length() ? str > b.str : str.length() > b.str.length(); 
	}
	bool operator == (const node b) const 
	{
		return str == b.str;
	}
	node()
	{
		index = 0;
		str = "";
	}
	
	node(string p_str,int p_index)
	{
		str = p_str;
		index = p_index;
	}
	bool cmp(const node b) const 
	{
		return str.length() < b.str.length();
	}
};

node data[N],sortData[N];
int n,numb = 1;
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
			data[i].index = i;
			sortData[i] = data[i];
		}
		sort(sortData + 1,sortData + 1 + n);
     		/*for(int i = 1; i <= n; i++)
		{
			cout<<sortData[i].str.length()<<" " << sortData[i].index<<endl;	
		}
		*/
		node res1;
		if(sortData[2].str.length() != sortData[1].str.length())
		{
			for(int i = 2; i <= n; i++)	
			{
				node temp;
				for(int j = 1; j <= n; j++) if(j != sortData[1].index && j != sortData[i].index )
				{
					temp.str += data[i].str;
				}
				res1 = max(temp,res1);
				if(sortData[i].str.length() != sortData[i + 1].str.length())
				{
					break;
				}
			}
		}
		else 
		{
			int m = -1;
			for(int i = 1; data[i].str.length() == data[i+1].str.length() && i < n; i++)
			{
				m = i + 1;
			}
		//	cout<<m<<endl;
			for(int i = 1; i < m; i++)
			{
				for(int j = i + 1; j <= m; j++)
				{
					node temp;
					for(int k = 1; k <= n; k++) if(k != sortData[i].index && k != sortData[j].index)	
					{
						temp.str += data[k].str;
					}
					res1 = max(res1,temp);
				}
			}
		}
		cout<<"Case #"<<numb++<<": "<<res1.str<<endl;	
					
	}

	return 0 ;
}

		
		
