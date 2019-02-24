#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define iter map<string,int>::iterator
#define riter map<string,int>::reverse_iterator
#define value map<string,int>::value_type
using namespace std;
int main()
{
	map<string, int> data;
	data.insert(pair<string, int>("b",2));
	value b("a",2);
	data.insert(b);
	data["c"] = 3; //注意会覆盖之前的值
	for(iter i = data.begin(); i != data.end(); i++)
	{
		cout<<i->first<<" "<<i->second<<endl;
	}
	for(riter i = data.rbegin(); i != data.rend(); i++)
	{
		cout<<i->first<<" "<<i->second<<endl;
	}
	cout<<data.count("1")<<endl;
	cout<<data.count("a")<<endl;
	iter num = data.find("c");
	cout<<num->first<<" "<<num->second<<endl;
	return 0;
}	

