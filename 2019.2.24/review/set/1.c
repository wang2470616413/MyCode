#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<set>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define iter set<string>::iterator
#define riter set<string>::reverse_iterator
using namespace std;
int main()
{
	set<string> data;
	//插入
	data.insert("123");
	data.insert("12342");
	data.insert("0000");
	data.insert("01");
	data.insert("02");
	data.insert("03");
	data.insert("04");
	data.insert("05");

	//遍历
	for(iter i = data.begin(); i != data.end(); i++)
	{
		cout<<*i<<endl;
	}	
	//反向遍历
	for(riter i = data.rbegin(); i != data.rend(); i++)
	{
		cout<<*i<<endl;
	}
	//查找，如果存在输出1,不存在输出0
	cout<<data.count("123")<<endl;
	cout<<data.count("484854")<<endl;
	//返回查找的值的迭代器
	cout<<*(data.find("123"))<<endl;
	//删除
	data.erase("123");//删除值
	data.erase(data.find("01"));//删除某个迭代器
	data.erase(data.find("02"),++data.find("05"));//删除两个迭代器之间的内容
	//验证删除
	for(iter i = data.begin(); i != data.end(); i++)
	{
		cout<<*i<<endl;
	}
	return 0;
}
