#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
//一。初始化
	string str1("123456",2,2);
	cout<<str1<<endl; //从小标2开始，长度为2的字符，输出34
//,查找
	string str2 = "11222334667894";
	int index1 = str2.find("222"); //从头开始查找，返回"222"第一次出现的下标，如果没有的话，返回string::npos 
	cout<<index1<<endl;
	return 0;
}
