#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
//一。初始化
	vector <int> data1(10,1);//初始化data110个元素，值为1
	vector <int> data2(data1);//初始化data2为data1
	vector <int> data3(data2.begin(),data2.begin() + 3);//将data2从0开始的3个元素作为data3的值
	int data[10] = {1,2,3,4,5,6,7,8,9,10};
	vector <int> data4(data,data + 10);//将数组作为data4的初始化值
	





	return 0;
}
