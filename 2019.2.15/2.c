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
	bool operator > (const node b)const 
	{
		return str.length() == b.str.length() ? str > b.str : str.length() > b.str.length();
	}
	bool operator < (const node b)const 
	{
		return str.length() == b.str.length() ? str < b.str : str.length() < b.str.length();
	}
	bool operator == (const node b)const 
	{
		return str == b.str;
	}
	bool cmp (const node b) const 
	{
		return str.length() < b.str.length();
	}
	node ()
	{
		str = "";
		index = 0;
	}
};
node data[N], sortData[N];
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
		sort(sortData + 1, sortData + 1 + n);
		int index1 = 0,index2 = 0;
		node str1,str2;
		cout<<str1.str <<" "<< str1.index<<endl;
		for(int i = 1; i <= n; i++)
		{
			node temp;
			for(int j = 1; j <= n; j++)if(j != sortData[i].index)
			{
				temp.str += data[j].str;
			}
			//cout<<sortData[i].index<<" " << temp.str<<endl;
			if(str1 < temp)
			{
				index1 = sortData[i].index;
				str1 = temp;
			}
			//cout<<sortData[i].index<<" " << str1.str<<endl;
			if(sortData[i].str.length() != sortData[i+1].str.length())
			{
				break;
			}
		}
		//cout<<index1<<endl;
		for(int i = 1; i <= n; i++) if( i != index1)
		{
			node temp;
			for(int j = 1; j <= n; j++) if( j != index1 && j != i)
			{
				temp.str +=  data[j].str;
			}
		//	cout<<index1<<" "<<i<<" " << temp.str<<endl;
			if(str2 < temp)
			{
				index2 = i;
				str2 = temp;
			}
		//	cout<<index1<<" "<<i<<" " << str2.str<<endl;
			
			
		}
		cout<<"Case #"<<numb++<<": "<<str2.str<<endl;
	}
	return  0;
}







