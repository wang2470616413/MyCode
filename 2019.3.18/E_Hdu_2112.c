#include<stdio.h>
#include<string.h>
#include<iostream> 
#include<queue> 
#include<algorithm>
#include<string> 
#include<map>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N =  200;
const int M = 20005;
int n;
struct node
{
	int to,w,next;
	node ()
	{
	};
	node (int p_to,int p_w,int p_next)
	{
		to = p_to;
		w = p_w;
		next = p_next;
	};
};
struct str
{
	string a, b;
	int w;
};
str strData[M]; 
node edges[M];
int s,e,mark[N],dis[N],head[N];
string ss, ee;
map <string,int> aux;
void addAux(string a,int &index)
{
	if(aux.count(a) == 0)
	{
		aux[a] = index++;
	}
} 
void addEdge(int a,int b,int w,int& len)
{
	edges[len] = node(b,w,head[a]);
	head[a] = len++;
}
/*
6
xiasha westlake
xiasha station 60
xiasha ShoppingCenterofHangZhou 30
station westlake 20
ShoppingCenterofHangZhou supermarket 10
xiasha supermarket 50
supermarket westlake 10
-1
*/ 
int main()
{
	while(cin>>n && n != -1)
	{
		aux.clear();
		mmset(head,-1);
		int len = 1;
		int len1 = 1;
		cin >> ss >>ee;
		addAux(ss,len);
		addAux(ee,len);
	 	for(int i = 1; i <= n; i++)
	 	{
	 		cin>>strData[i].a>>strData[i].b>>strData[i].w;
	 		addAux(strData[i].a,len);
	 		addAux(strData[i].b,len);
	 	}
	 	for(int i = 1; i <= n; i++)
	 	{
	 		map <string,int>::iterator a = aux.find(strData[i].a); 
	 		map <string,int>::iterator b = aux.find(strData[i].b); 
	 		addEdge(a->second,b->second,strData[i].w,len1);
	 		addEdge(b->second,a->second,strData[i].w,len1);
	 	}
	 	map <string,int>::iterator a1 = aux.find(ss);
	 	map <string,int>::iterator a2 = aux.find(ee);
	 	s = a1->second;
	 	e = a2->second;
	 	queue <int> que;
	 	mmset(dis,0x3f);
	 	mmset(mark,0);
	 	dis[s] = 0;
	 	que.push(s);
	 	while(!que.empty())
	 	{
	 		int front = que.front();
	 		que.pop();
	 		mark[front] = 0;
	 		for(int i = head[front]; i != -1; i = edges[i].next)
	 		{
	 			int to = edges[i].to;
	 			int w = edges[i].w;
	 			if(dis[to] > dis[front] + w)
	 			{
	 				dis[to] = dis[front] + w;
	 				if(mark[to] == 0)
	 				{
	 					mark[to] = 1;
	 					que.push(to);
	 				}
	 			}
	 		}
	 		
	 	}
	 	printf("%d\n",dis[e] == 0x3f3f3f3f ? -1 : dis[e]);
	 	
	}
	
	
	
	
	return 0;
}
