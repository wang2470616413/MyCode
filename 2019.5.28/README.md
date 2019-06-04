划分树是专门用来求静态区间第k的一种数据结构
它主要利用快排的思想来进行建树和查询
比如给你一个长度为12序列{1，9，4，5，8，3，4，6，5，2，5，7}
我们要按照划分树来建树该怎么建呢
### 1.首先和快速排序一样，分而治之。
#### &emsp;&emsp;我们把平均分为两部分，左区间任何一个数都小于右区间的一个数
#### &emsp;&emsp;&emsp;同时左右两个区间的序列顺序和原来区间一样
#### &emsp;&emsp;我们还需要统计一下对于原区间[l,r]的任意一个数b,都要统计一下从
#### &emsp;&emsp;&emsp;[l,b]有多少个数进入左区间；
#### &emsp;&emsp;如图
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190604185224577.png)
### 2.查询的时候只需要注意一点就行。
##### &emsp;&emsp;在说这一点之前，我们先明白一个概念，存在区间[a,b],[b + 1,R]。如果在建树的过程中
##### &emsp;&emsp;[b,R]有x个数被划分给左区间，那么相应的[a,b]区间的每个被划分为右区间的数在下一层
##### &emsp;&emsp;的位置都要往右移动x位。
#### &emsp;明白这一点我们就解决了区间向右划分时如何得到新的左端点和右端点
####  &emsp;这体现在代码第68~69行
### 3.代码如下：

```
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
```
