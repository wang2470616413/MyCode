#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
//一。初始化
	string str1("123456",2,2);
	cout<<str1<<endl; //从小标2开始，长度为2的字符，输出34
//二，查找
	string str2 = "11222332224667894";
	int index1 = str2.find("222"); //从头开始查找，返回"222"第一次出现的下标，如果没有的话，返回string::npos 
	cout<<index1<<endl;//输出2
	int index2 = str2.find("222",5); //从下标为5开始查找，返回第一次出现的位置
	cout<<index2<<endl;//输出7
//三，其他常用函数
	string str3 = "0123789";
	str3.insert(4,"456");//将"456"插到下标4
	cout<<str3<<endl;//输出0123456789
	str3.replace(4,3,"654");//将从下标4开始的三个字符替换成"654";
	cout<<str3<<endl;//输出0123654789
	str3.erase(4,3);//删掉从下标4开始的3个字符；
	cout<<str3<<endl; //输出0123789 
	string str4 = "11111";
	str3.swap(str4); //与str4相互交换
	cout<<str3<<" "<<str4<<endl;


	
	return 0;
}
