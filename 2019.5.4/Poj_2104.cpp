#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l,m,lts[rt]
#define rson m + 1, r, rts[rt] 
using namespace std;
const int N = 1e5 + 5;
int rts[N * 30],lts[N * 30],roots[N];
int tree[N * 30],data[N],HashData[N];
int n,m;
int tot = 0;
void Build(int l, int r, int& rt)
{
    rt = ++tot;
    tree[rt] = 0;
    if(l == r)
    {
        return ;
    }
    int m = (l + r) >> 1; 
    Build(lson);
    Build(rson);
}
void Update(int p, int num, int l, int r, int& rt, int last)
{
    rt = ++tot;
    lts[rt] = lts[last], rts[rt] = rts[last];
    tree[rt] = tree[last] + num;
    if(l == r)
	{
		return ;
    }
    int m = (l + r) >> 1;
    if(p <= m)
    {
        Update(p,num,lson,lts[rt]);
    }
    else
    {
        Update(p,num,rson,rts[rt]);
    }
}
int query(int a, int b, int l, int r, int k)
{
    if(l == r)
    {
        return l;
    }
    else
    {
        int numc = tree[lts[b]] - tree[lts[a]];
        int m = (l + r) >> 1;
        if(k <= numc)
        {
            return query(lts[a],lts[b],l,m,k);
        }
        else
        {
            return query(rts[a],rts[b],m+1,r,k-numc);
        }
    }
}


/*
7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
*/
int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&data[i]);
        HashData[i] = data[i];
    }
    sort(HashData + 1, HashData + 1 + n);
    int len = unique(HashData + 1, HashData + 1 +n) - (HashData + 1);
    Build(1,len,roots[0]);
    for(int i =  1; i <= n; i++)
    {
        int num = lower_bound(HashData + 1, HashData + 1 + n,data[i]) - HashData;
        Update(num,1,1,len,roots[i], roots[i-1]);
    }
    for(int i = 1; i <= m; i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        printf("%d\n",HashData[query(roots[a-1],roots[b],1,len,c)]);
    }
    
    





    return 0;
}