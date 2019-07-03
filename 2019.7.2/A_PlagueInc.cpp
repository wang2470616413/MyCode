#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2e3 + 10;
struct node
{
    int x, y ,m ;
    node()
    {

    };
    node(int p_x, int p_y, int p_m)
    {
        x = p_x;
        y = p_y;
        m = p_m;
    }
    bool operator < (const node two) const 
    {
        return x  == two.x ? y < two.y : x < two.x;
    }
};
int mark[N][N];
int n,m,k;
int num;
/*
3 3
1
2 2
3 3
2
1 1
3 3
 */
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        scanf("%d",&k);
        mmset(mark,0);
        node data[15];
        for(int i = 1; i <= k; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            mark[a][b] = 1;
            data[i] = node(a,b,0);
        }
        node res = node(n + 1, m +1, -1);
        sort(data + 1, data + 1 + k);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                node temp = node(n + 1,m  + 1, 2 * (n + m));
                for(int p = 1; p <= k; p++) if(abs(i - data[p].x) + abs(j - data[p].y) <  temp.m)
                {
                    temp = node(i,j,abs(i - data[p].x) + abs(j - data[p].y));
                }
                if(res.m < temp.m)
                {
                    res = temp;
                }
            }
        }
        printf("%d %d\n",res.x, res.y);
 

    }
    return  0;
}