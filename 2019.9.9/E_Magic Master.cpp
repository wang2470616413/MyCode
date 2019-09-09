#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 4e7 + 5;
int data[N];
void count1(int n,int m)
{
	deque <int> que;
    for(int i = n; i >= 2; i--)
	{
        que.push_front(i);
        for(int j = 0; j < m; j++)
		{
            que.push_front(que.back());
            que.pop_back();
        }
    }
    que.push_front(1);
    for(int i = 0; i < n; i++)
    {
    	data[i+1] = que.at(i);
    }
}
/*
1
5
1
2
2
3
*/
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,k,num;
		scanf("%d %d %d",&n,&m,&k);
		count1(n,m);
		for(int i = 1; i <=k;i++)
		{
			scanf("%d",&num);
			printf("%d\n",data[num]);
		}
		
	}
	return 0;
}