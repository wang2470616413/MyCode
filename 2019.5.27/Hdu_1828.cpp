#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt << 1 | 1 
#define hash hash1
using namespace std;
const int N = 2e4;
struct node
{
    int l, r, h,mark;
    node()
    {

    };
    node(int p_l, int p_r, int p_h, int p_mark)
    {
        l = p_l;
        r = p_r;
        h = p_h;
        mark = p_mark;     
    }
    bool operator  < (const node two) const
    {
        return h < two.h;
    }
};
node data[N];
int hash[N], sum[N << 2], cnt[N<<2], num[N << 2];
bool ls[N << 2], rs[N <<2];
void pushUp(int l, int r, int rt)
{
    if(cnt[rt] > 0)
    {
        ls[rt] = rs[rt] = true;
        sum[rt] = hash[r + 1] - hash[l];
        num[rt] = 2;
    }
    else if(l == r)
    {
        sum[rt] = 0;
        num[rt] = 0;
        ls[rt] = rs[rt] = false;
    }
    else
    {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
        ls[rt] = ls[rt << 1];
        rs[rt] = rs[rt << 1 | 1];
        num[rt] = num[rt << 1] + num[rt << 1 | 1];
        if(ls[rt << 1 | 1] == true && rs[rt << 1])
        {
            num[rt] -= 2;
        }
    }
}
void update(int L, int R, int k, int l, int r, int rt)
{
    if(l >= L && r <= R)
    {
        cnt[rt] += k;
        pushUp(l,r,rt); 
        return; 
    }
    else
    {
        int m = (l + r) >> 1;
        if(L <= m)
        {
            update(L,R,k,lson);
        }
        if(R >= m + 1)
        {
            update(L,R,k,rson);
        }
        pushUp(l,r,rt);
    }
    
}

/*
7
-15 0 5 10
-5 8 20 25
15 -4 24 14
0 -6 16 4
2 15 10 22
30 10 36 20
34 0 40 16
228

2
10 10 20 20
15 15 25 25 
2
10 10 30 30
10 20 30 50
*/
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
    	mmset(sum,0);
    	mmset(cnt,0);
    	mmset(num,0);
        for(int i = 1; i <= 2 * n; i += 2)
        {
            int x1,y1,x2,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            data[i] = node(x1,x2,y1,1);
            data[i+1] = node(x1,x2,y2,-1);
            hash[i] = x1;
            hash[i+1] = x2;
        }
        sort(data + 1, data + 1 + 2 * n);
        sort(hash + 1, hash + 1 + 2 * n);
        int len = unique(hash + 1, hash + 1 + 2 * n) - (hash + 1);
        int res =  0, last = 0;
        data[2 * n + 1] = data[2 * n];
        for(int i = 1; i <= 2 * n; i++)
        {
            int L = lower_bound(hash + 1, hash + 1 + len, data[i].l) - hash;
            int R = lower_bound(hash + 1, hash + 1 + len, data[i].r) - hash;
            update(L,R-1,data[i].mark,1,len - 1, 1);
            res += abs(sum[1] - last);
            res += num[1] * (data[i+1].h - data[i].h);
            last = sum[1];
        }
        printf("%d\n",res);
    }
    return 0;
}