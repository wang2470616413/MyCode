#include<stdio.h>
#include<string>
#include<iostream>
#include<set>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define iter set<node>::iterator
#define riter set<node>::reverse_iterator
using namespace std;
struct node 
{
	int x,y;
	node()
	{
	}
	node (int px, int py)
	{
		x = px;
		y = py;
	}
	bool operator < (const node b) const //重载< 
	{
		if(x == b.x) //如果两者相等，返回false,不插入b
		{
			return false;
		}
		else 
		{
			if(y != b.y)
			{
				return y > b.y;//如果y>b.y，那么this排在b前面
			}
			else 
			{
				return x > b.x;
			}
		}

	}
};
int main()
{
	set<node> data;
	data.insert(node(1,2));
	data.insert(node(1,3));
	data.insert(node(1,4));
	data.insert(node(4,2));
	data.insert(node(2,2));
	data.insert(node(3,3));
	data.insert(node(5,5));
	data.insert(node(7,1));
	data.insert(node(9,2));
	for(iter i = data.begin(); i != data.end(); i++)
	{
		cout<<i->x<<" "<<i->y<<endl;
	}
	


	return 0;
}
