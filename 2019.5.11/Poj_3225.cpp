#include<stdio.h>
#include<algorithm>
#include<string.h>
#define  ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 7e4 + 5;
int col[N << 2], mark[N << 2];
int len;
void PushUp(int rt)
{
    if(col[rt << 1] == 0 && col[rt << 1 | 1] == 0)
    {
        col[rt] = 0;
    }
    else if(col[rt << 1] == 1 && col[rt << 1 | 1] == 1)
    {
        col[rt] = 1;
    }
    else
    {
        col[rt] = 2;
    }
}
void PushDown(int rt)
{
    if(mark[rt] != -1)
    {
        if(mark[rt] != 2)
        {
            col[rt] = col[rt] != 2 ? mark[rt] : col[rt];
            mark[rt << 1] = mark[rt << 1 | 1] = mark[rt];
        }
        else
        {
            col[rt] = col[rt] != 2 ? col[rt] ^ 1 : col[rt];
            mark[rt << 1] =  col[rt] !=2 ? -1 : mark[rt];
            mark[rt << 1 | 1] = col[rt] != 2 ? -1 : mark[rt];
        }
        mark[rt] = -1;
    }
    else
    {
        mark[rt<<1] = mark[rt<<1|1] =  -1;
    }
    
}
void update(int L, int R, int k, int l, int r, int rt)
{
    if(l >= L && r <= R)
    {
       if(k != 2)
        {
            col[rt] = col[rt] != 2 ? k : col[rt];
            mark[rt] = k; 
        }
        else
        {
            col[rt] = col[rt] != 2 ? col[rt] ^ 1 : col[rt];
            mark[rt] = col[rt] != 2 ? k : -1;
        }
    }
    else
    {
        int m = (l + r) >> 1;
        PushDown(rt);
        if(L <= m)
        {
            update(L,R,k,lson);
        }
        if(R >= m + 1)
        {
            update(L,R,k,rson);
        }
        PushUp(rt);
    }
    
}
void query(int L, int R, int l, int r, int rt)
{
    if(l >= L && r <= R && col[rt] == 1)
    {
        char ma,mb;
        int a,b;
        ma = l % 2 == 0 ? '[' :'(';
        mb = r % 2 == 0 ? ']' : ')';
        a = l % 2 == 0 ? l / 2 : (l - 1)  / 2;
        b = r % 2 == 0 ? r / 2 :(r + 1) / 2;
        printf("%c%d,%d%c\n",ma,a,b,mb);
    }
    if(l == r)
    {
        return ;
    }
    else
    {
        PushDown(rt);
        int m = (l + r) >> 1;
        if(L <= m)
        {
            query(L,R,lson);
        }
        if(R >= m + 1)
        {
            query(L,R,rson);
        }
        
        
    }
    
}

/*
U [1,5]
D [3,3]
S [2,4]
C (1,5)
I (2,3]
A (2,3]
*/
int main()
{
    char ma,mb,ch;
    int a,b;
    mmset(mark,-1) ;
    mmset(col,0);
    len = 1;
    while(~scanf(" %c %c%d,%d%c",&ch,&ma,&a,&b,&mb))
    {
    	if(ch == 'A')
    	{
    		break;
    	}
        a = ma == '[' ? a * 2 : a * 2 + 1;
        b = mb == ']' ? b * 2 : b * 2 - 1;
        if(ch == 'U')
        {
            update(a,b,1,0,N,1);
        }
        else if(ch == 'I')
        {
            update(0, a - 1,0,0,N,1);
            update(b+1,N,0,1,N,1);
        }
        else if(ch =='D')
        {
            update(a,b,0,0,N,1);
        }
        else if(ch == 'C')
        {
            update(0, a - 1,0,0,N,1);
            update(b+1,N,0,0,N,1);
            update(a,b,2,0,N,1);
        }
        else if(ch == 'S')
        {
            update(a,b,2,0,N,1);
        }
        query(1,N,0,N,1);
    }
     query(1,N,0,N,1);
    return 0;
}