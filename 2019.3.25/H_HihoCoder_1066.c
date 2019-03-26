#include<stdio.h>
#include<string.h>
#include<string> 
#include<iostream>
#include<algorithm>
#include<map> 
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a)) 
using namespace std;
const int N = 1e5 + 5;
struct node
{
	int mark;
	string a,b;
	node()
	{
		
	};
	node(int p_mark, string p_a, string p_b)
	{
		mark = p_mark;
		a = p_a;
		b = p_b;
	}
};
node aux[N];
int father[N];
int data[N][3];
map <string, int> map1;
int addMap(string a, int& index)
{
	int res = 0;
	if(map1.count(a) == 0)
	{
		map1[a] = index++;
		return index - 1;
	}
	return map1[a];
	
}
void init(int a, int b)
{
	for(int i = 0; i <= b; i++)
	{
		father[i] = i;
	}
}
int find(int x)
{
	return x == father[x] ? x : find(father[x]);
}
void merge(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) 
	{
		father[fx] = fy;
	}
}
int main()
{
	int n;
	cin>>n;
	int len = 1;
	for(int i = 1; i <= n; i++)
	{
		int a;
		string b,c;
		cin>>aux[i].mark>>aux[i].a>>aux[i].b;
		data[i][0] = aux[i].mark;
		data[i][1] = addMap(aux[i].a,len);
		data[i][2] = addMap(aux[i].b,len);
	}
	init(0,n);
	for(int i = 1; i <= n; i++)
	{

		if(data[i][0] == 0)
		{
			merge(data[i][1],data[i][2]);
		}
		else
		{
			int fx = find(data[i][1]);
			int fy = find(data[i][2]);
			if(fx == fy)
			{
				cout<<"yes"<<endl;
			}
			else
			{
				cout<<"no"<<endl;
			}
		}
	}
	
	
	
	return 0;
}

