#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 3e5 + 5;
struct node
{
	int to,w,next;
	node()
	{
		
	};
	node(int p_to, int p_w, int p_next)
	{
		to = p_to;
		w = p_w;
		next = p_next;
	};
};
int head[N];
node edges[N];
void addEdge(int a,int cb, int c,int& len)
{
	edges[len] = node(b,c,head[a]);
	head[a] = len++;
}
void dijkstra(int s, int e)
{
	
}
int main()
{
	
	
	
	
	return 0;
}
