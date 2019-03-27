#include<stdio.h>
#include<string>
#include<iostream>
#define size_type string::size_type
#define npos string::npos
using namespace std;
string& count1(string& str, const string& res1)
{
	for(size_type pos(0); pos != npos; )
	{
		if((pos = str.find(res1,pos)) != npos)
		{
			str.erase(pos,res1.length());
		}
		else
		{
			break;
		}
	}
	return str;
}
int main()
{
	string a,b,c;
	cin>>a>>b;
	c = count1(a,b);
	cout<<c<<endl;



	return 0;
}
