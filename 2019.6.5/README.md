### 主席树又叫可持久化线段树
###### &emsp;&emsp;为了实现可持久化这一目的，主席树在建树或者更新的时候会建立多个历史版本，以便于在之后的查询可以随时回到某个历史版本
###### &emsp;&emsp;建立历史版本的方法有多种，但是为了实现空间和时间上的最优，我们采用下面的方法建立历史版本
###### &emsp;&emsp;假定我们现在有一个问题，给你一个长度n为的序列data，和一个序列aux。每一时刻按从左往右的顺序从data数组中拿一个数加入aux数组。求任意一个时刻序列aux中[a,b]范围内偶数的个数

###### &emsp;&emsp;很容易想到用线段树维护区间[a,b]的偶数的个数。题目上又说可是任意一个时刻，所以我们要实现回到某个历史版本的功能。
######  &emsp;&emsp;为了方便描述主席树的步骤，我们先对本篇博客所说的问题进行具体化；
###### &emsp;&emsp;&emsp;我们规定n为12，data里面的数分别为{3,8,13,15,5,8,12,9,3,6,21,22}；有6个查询，每一行有三个数，分别代表时刻，左端点，右端点。
1，4，6
4，7，9
6，7，7
3，1，2
9，1，7
4，1，9


##### 这是一个经典的主席树问题，一般的主席树(本片博客所说的主席树是指静态主席树)解题步骤分为三步：
###### &emsp;&emsp;1.离散化：
首先我们将区间离散化，<font color = red>离散化的目的为了节省空间，也为后面的步骤优化了代码</font>。那么data{3,8,13,15,5,8,12,9,3,6,21,22} -> hash{1,4,7,8,2,4,6,5,1,3,9,10}
###### &emsp;&emsp;2.建树并建立历史版本：
刚开的时候是一颗空树，如图
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190607210315357.png)
第1时刻的时候，把3离散化后对应的值1加入线段树，因为3是奇数，所以更新的节点的值 + 0，如图
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190607195906155.png)
第2时刻的时候，把8离散化后对应的值4加入线段树，因为8是偶数，所以更新的节点的值 + 1，如图
![在这里插入图片描述](https://img-blog.csdnimg.cn/2019060720084464.png)
第3时刻的时候，把13离散化后对应的值7加入线段树，因为13是奇数，所以更新的节点的值 + 0， 如图：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190607201756874.png)
可以看出每次更新的时间复杂度与空间复杂度都是log(n)
这个结论跟容易推出来，因为每次向下更新的时候，只有向左更新或者向右更新。假如我们要向右边更新，我们就往右边建一个
新节点，并使当前节点的右指针指向这个新节点，左指针还指向本节点原来的左儿子
###### &emsp;&emsp;3.查询
跟普通的线段树,这里就不再赘述

##### 接下来我们来看一个例题，也是一个经典的主席树问题，[求区间第k小](https://cn.vjudge.net/problem/POJ-2761)
在讲解之前，我们思考一个问题，就是普通的线段树如何解决区间第k小的问题
例如区间[1,5] = 3。代表在区间1~5之间，出现了3个范围在[1,5]的数。
那么我们该如何查找呢。
例如我们要查找长度为len且最小值为x，最大值为y的数组中区间下标[a,b]之间第k小的数，
那么我们能求出在[a,b]中范围在[x,(x + y) / 2]的数有cnt个，我们比较cnt与k的关系，来判断下一个查找区间在左边还是右边如果cnt小于等于k，那么说明最终答案一定在[x,(x+y)/2]里面，如果cnt比k大，说明答案一定在[(x+y) / 2 + 1, y]里面。然后往下查找
##### 整个查找过程用了二分的思想
##### 另外，这个题其实查找的过程是比较难理解的，其他的都很好理解。为了能得到区间[a,b]的情况，我们需要利用前缀和的思想，也就是区间[a,b]的情况可以用[l,b] - [l,a-1]得到。
代码如下:

```
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define hash hash1
using namespace std;
const int N = 1e5 + 5;
int ls[N * 30],rs[N * 30], ts[N * 30], root[N];
int tree[N * 30];
int data[N], hash[N];
int n,m,tot;
void build(int l,int r, int& rt)
{
	rt = tot++;
	tree[rt] = 0;
	if(l == r)
	{
		return;
	}
	else
	{
		int m = (l + r) >> 1;
		build(l,m,ls[rt]);
		build(m+1,r,rs[rt]);
	}
	
}
void add(int p, int C, int l, int r, int& rt, int last)
{
	rt = tot++;
	ls[rt] = ls[last];
	rs[rt] = rs[last];
	tree[rt] = tree[last] + C;
	if(l == r)
	{
		return;
	}
	else
	{
		int m = (l + r) >> 1;
		if(p <= m)
		{
			add(p,C,l,m,ls[rt],ls[rt]);
		}
		if(p >= m + 1)
		{
			add(p,C,m + 1, r, rs[rt], rs[rt]);
		}
	}
	
}
int query(int x, int y, int l, int r, int k)
{
	if(l == r)
	{
		return l;
	}
	else
	{
		int m = (l + r) >> 1;
		int cnt = tree[ls[y]] - tree[ls[x]];
		if(k <= cnt)
		{
			return query(ls[x],ls[y],l,m,k);
		}
		else
		{
			return query(rs[x],rs[y],m+1,r,k - cnt);
		}
	}
	

}

/*
7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
Sample Output
5
6
3
 */
int main()
{
	tot = 1;
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&data[i]);
		hash[i] = data[i];
	}
	sort(hash + 1, hash + 1 + n);
	int len = unique(hash + 1, hash + 1 + n) -  (hash + 1);
	build(1,len,root[0]);
	for(int i = 1; i <= n; i++)
	{
		int a = lower_bound(hash + 1, hash + 1 + n, data[i]) - hash;
		add(a,1,1,len,root[i],root[i-1]);
	}
	for(int i = 1; i <= m; i++)
	{
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);
		int res = hash[query(root[a-1],root[b],1,len,k)];
		printf("%d\n",res);
	}
	return 0;
}
```