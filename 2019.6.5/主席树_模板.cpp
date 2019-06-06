#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m + 1, r, rt << 1| 1 
#define hash hash1
using namespace std;
const int N =  1e5 + 5;
int data[N],hash[N];
int ls[N * 30], rs[N * 30], tree[N * 30];
int tot = 0;
void add(int p, int C,int l, int r,int& rt,int last)
{
	rt = tot++;
	ls[rt] = ls[last],rs[rt] = rs[last];
	tree[rt] = tree[last]++;
    if(l == r)
    {
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m)
    {
        add(p,C,l,m,ls[rt],ls[rt]);
    }
    else
    {
        add(p,C,m+1,r,rs[rt],rs[rt]);
    }
}
/*
12 6
3 8 13 15 5 8 12 9 3 6 21 22
1 4 6
4 7 9
6 7 7
3 1 2
9 1 7
4 1 9
##
*/
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
		hash[i]  = data[i];
	}
	sort(hash + 1, hash + 1 + n);
//	int len = unique(hash + 1, hash + 1 + n) - (hash + 1);
	for(int i = 1; i <= n; i++)
	{
		int res = lower_bound(hash + 1, hash + 1 + n,data[i]) - hash;
		printf("%d %d\n",data[i],res);
	}
	return 0;
}