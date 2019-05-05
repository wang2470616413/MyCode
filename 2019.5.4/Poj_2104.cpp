#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l,m,lts[rt]
#define rson m+1,r, rts[rt]
using namespace std;
const int N = 1005;
int lts[N << 2], rts[N << 2], root[N << 2];
int data[N << 2], Hash[N << 2];
int tot = 0,n,m;
void Build(int l ,int r, int &rt)
{
    rt = ++tot;
    root[rt] = 0;
    if(l == r)
    {
    	return ;
    }
    int m = (l + r) >> 1;
    Build(lson);
    Build(lson);
}
void Update(int p, int num, int l, int r, int& rt, int lst)
{
    rt = ++tot;
    lts[rt] = lts[lst];
    rts[rt] = rts[lst];
    root[rt] = root[lst] + num;
    if(l == r)
    {
        return ;
    }
    else
    {
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
    
}
int query(int a,int b, int l, int r, int k)
{
    if(l == r)
    {
            return l ;
    }
    else
    {
        int c = root[lts[b]] - root[lts[a]];
        int m = (l + r) >> 1;
        if(c >=k)
        {
            return query(lts[a],lts[b],1,m,k);
        }
        else
        {
            return query(rts[a],rts[b],1,m,k);
        }
        
    }
    
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        tot = 0;
        for(int i = 1;  i <= n; i++)
        {
            scanf("%d",&data[i]);
            Hash[i] = data[i];
        }
        sort(Hash + 1, Hash + n + 1);
        int len = unique(Hash + 1, Hash + n + 1) - (Hash + 1);
        // for(int i = 1; i <= len; i++)
        // {
        //     printf("%d ",Hash[i]);
        // }
        // printf("\n");
        Build(1,len,root[0]);
        for(int i = 1; i <= n; i++)
        {
            data[i] = lower_bound(Hash + 1, Hash + n + 1,data[i]) - Hash;
        }
        for(int i = 1; i <= n; i++)
        {
            printf("%d ",data[i]);
        }
        printf("\n");
        for(int i = 1; i <= n; i++)
        {
            Update(data[i],1,1,len,root[i],root[i-1]);
        }
        int a,b,c;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            printf("%d\n",Hash[query(root[a - 1],root[b],1,len,c)]);
    	}
    }





    return 0;
}