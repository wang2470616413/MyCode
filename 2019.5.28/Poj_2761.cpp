#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l, m , dep + 1
#define rson m + 1, r , dep + 1
using namespace std;
const int N = 1e6 + 10;
int tree[20][N << 2], numLeft[20][N];
int sortData[N];
void build(int l ,int r, int dep)
{
    if(l == r)
    {
        return;
    }
    else
    {
        int m = (l + r) >> 1;
        int len = (m - l) + 1;
        for(int i = 1; i <= r; i++) if(tree[dep][i] < sortData[m])
        {
            len--;
        }
        int indexLs = l,indexRs = r;
        for(int i = l; i <= r; i++)
        {
            if(tree[dep][i] < sortData[m] || (tree[dep][i] == sortData[m] && len > 0))
            {
                tree[dep + 1][indexLs] = tree[dep][i];
                if(tree[dep][i] == sortData[m])
                {
                    len--;
                }
                indexLs++;
            }
            else
            {
                tree[dep + 1][i] =  tree[dep][i];
                indexRs++;
            }
            numLeft[dep][i] = numLeft[dep][l - 1] + (indexLs - l);
        }
        build(lson);
        build(rson);
        
    }
    
}
int query(int L, int R, int l, int r, int dep, int k)
{
    if(l == r)
    {
        return tree[dep][l];
    }
    else
    {
        int m = (L + R) >> 1;
        int cnt = numLeft[dep][r] - numLeft[dep][l - 1];
        if(k <= cnt)
        {
            int newl = L + (numLeft[dep][l - 1] - numLeft[dep][L- 1]);
            int newr = newl + cnt - 1;
            return query(L,m,newl,newr,dep + 1,k);
        }
        else
        {
            int newr = r + (numLeft[dep][R] - )
        }
    }
    
}
int main()
{





    return 0;
}