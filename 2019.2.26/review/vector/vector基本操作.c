#include<vector>
#include<algorithm>
#include<iostream>
#define iter vector<int>::iterator
using namespace std;
int main()
{
//一。初始化
	vector <int> data1(10,1);//初始化data110个元素，值为1
	vector <int> data2(data1);//初始化data2为data1
	vector <int> data3(data2.begin(),data2.begin() + 3);//将data2从0开始的3个元素作为data3的值
	int data[10] = {1,2,3,4,5,6,7,8,9,10};
	vector <int> data4(data,data + 10);//将数组作为data4的初始化值
//其他操作	
	data4.back(); //返回最后一个元素
	data4.front(); //返回第一个元素
	data4.pop_back();//删掉最后一个元素
	data4.push_back(3);//往尾部插入一个元素3
	data4.insert(data4.begin() + 3,5);//将5插入到data4.begin() + 3位置上
	data4.insert(data4.begin() + 3,3,5); //将3个5插入到data4.begin() + 3位置上
	data4.insert(data4.begin() + 3,data + 1,data + 9);//将data + 1 到 data + 9之间的内容插入到data4.begin()+4位置上
//<algorithm>关于vector的操作
	sort(data4.begin(),data4.end());//将[data4.begin(),data4.end())排序
	reverse(data4.begin(),data4.end());//将[data4.begin().data4.end())倒置
	iter index1 = find(data4.begin(),data4.end(),4);//在区间[data4.begin(),data4.end())查找4,并返回迭代器
	cout<<*index1<<endl;
	




	return 0;
}
