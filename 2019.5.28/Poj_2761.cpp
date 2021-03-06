#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l, m , dep + 1
#define rson m + 1, r , dep + 1
using namespace std;
const int N = 1e5 + 10;
int tree[32][N], numLeft[32][N];
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
        for(int i = l; i <= r; i++) if(tree[dep][i] < sortData[m])
        {
            len--;
        }
        int indexLs = l,indexRs = m + 1;
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
                tree[dep + 1][indexRs] =  tree[dep][i];
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
            int newr = r + (numLeft[dep][R] - numLeft[dep][r]);
            int newl = newr - (r - l - cnt);
            return query(m + 1,R,newl, newr, dep + 1, k - cnt);
        }
    }
    
}
/*
12 13
1 9 4 5 8 3 4 6 5 2 5 7
4 9 4
5
*/
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int  i = 1; i <= n; i++)
    {
        scanf("%d",&sortData[i]);
        tree[1][i] = sortData[i];
    }
    sort(sortData + 1, sortData + 1 + n);
    build(1,n,1);
    for(int i = 1; i <= 7; i++)
    {
    	for(int j = 1; j <= n; j++)
    	{
    		printf("(%d,%d) ",tree[i][j],numLeft[i][j]);
    	}
    	printf("\n");
    }
    for(int i = 1; i <= m; i++)
    {
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);
        int res = query(1,n,a,b,1,k);
        printf("%d\n",res);
    }
    return 0;
}