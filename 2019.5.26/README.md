# 2019.5.26
## Hdu_6288
### &emsp;此题整体思路就是二分，但是难点不是在二分上
### &emsp;难点是判断`a的b次方是否溢出`。我们可以先求出a的b次方，再利用快速幂得出
### &emsp;a的b次方模1e9 + 7的结果，然后该值与a的b次方模 1e9 + 7 比较，`相同说明`
### &emsp;`没有溢出，不同说明溢出`
### &emsp;需要注意的是如果直接用c++函数pow来求a的b次方是有误差的，所以我们应该
### &emsp;手写一个求a的b次方的函数。
### &emsp;<font color = red>该题需要注意如下几点</font>
#### &emsp;&emsp;1. <font color = 	#FF0000> 任何施加于整数的运算的结果，判断其是否溢出都可以用取余来判断</font>
#### &emsp;&emsp;2. <font color = red> pow运算对于整数来说有误差，消除误差的方法可以自己手写一个这样的函数</font>
#### &emsp;&emsp;3. <font color = red> __int128的范围是−170,141,183,460,469,231,731,687,303,715,884,105,728 (-2^127) ~ 170,141,183,460,469,231,731,687,303,715,884,105,727 (2^127 − 1),大概是-1e38 ~ 1e38。</font>
##### &emsp;&emsp;&emsp;以下是__int128的输入输出
##### &emsp;&emsp;&emsp;&emsp;
        ```
        void scan(__int128 &x)
        {
            int f = 1;
            char ch;
            x = 0;
            if (ch = getchar() == '-') f = -1;
            else x += ch - '0';
            while ((ch == getchar()) >= '0' && ch <= '9')
                x = x * 10 + ch - '0';
            x *= f;
        }
        void print(__int128 x)
        {
            if (!x) return ;
            if (x < 0) putchar('-'),x = -x;
            print(x / 10);
            putchar(x % 10 + '0');
        }
        ```
## Hdu_1542
### &emsp;该题是扫描线的模板题
### &emsp;
### 扫描线用于求多个不规则多边形相交的问题。
#### 例如给你如下图，让你求该图的总面积
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190527110253385.png)
为了解决此类为题，我们引入了<font color = red> 扫描线 </font>的概念.
##### &emsp;&emsp;扫描线是我们脑海中假象的一根线，它能够按照一个方向来扫描图形得到我们想要的信息；
&emsp;&emsp;例如具体到本次问题，那么扫描线的作用可以概述为:***扫描线从按平行于x轴的方向，自下而上的扫描每一个图***
&emsp;&emsp;***形，并得到每个图形的面积信息；***
那么经过扫描线的扫描后，得到的图形如下：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190527111621596.png)
很容易看出该图可以被三根扫描线扫描
![在这里插入图片描述](https://img-blog.csdnimg.cn/2019052711342685.png)
每个扫描线扫描的区域是离它上部最近的多边形边；
我们把10 ~15，15 ~ 20， 20 ~ 25划分为三个区间。并<font color =  red> 离散化 </font>为1,2,3;
我们每次扫描就是维护这三个区间
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190527143506942.png)
&emsp;&emsp;用第一根扫描线扫描的时候会把（10~20）投影到根节点，说明该扫描线能扫描到该区间。
&emsp;&emsp;用第二根扫描线扫描的时候会把  (15~25）投影到根节点，同时 (10~20）所在的区间因为没有
碰到该矩形的上边，所以不用把(10~20)删除。
&emsp;&emsp;用第三根扫描线扫描的时候会把（10&#126;20)从根节点删除，但是(15&#126;20)区间因为第二根扫描线
投影到了根节点（<font color = red>第一根扫描线也将该区间投影到了根节点</font>），所以(15~20)这个区间并不会被删除

综上，我们有必要记录用一个数组来记录一下该区间是否矩形的上边或者下边。
&emsp;&emsp;我们可以用cnt数组来实现这个作用，当我们扫描到上边，cnt[该区间]就+1，否者cnt就-1；
&emsp;&emsp;当cnt[rt] = k的时候说明该区间被k个矩形包裹
例如
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190527172202857.png)
再用红线扫描矩阵的时候，cnt[50&#126;70] = 4;因为这段区间（也就是左图被绿色包围的区域）被四个矩形包围；
此问题Hdu_1542所描述的问题。
代码如下

```
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define hash hash1 
using namespace std;
const int N = 2005;
struct node
{
	double l,r,h;
	int mark;
	node()
	{
		
	};
	node(double p_l, double p_r, double p_h, int p_mark)
	{
		l = p_l;
		r = p_r;
		h = p_h;
		mark = p_mark;
	}
	bool operator < (const node two) const
	{
		return h < two.h;
	}
};
int cnt[N << 2];
double sum[N << 2],hash[N];
node data[N];
void pushUp(int l, int r, int rt)
{
	if(cnt[rt] > 0)
	{
		sum[rt] = hash[r + 1] - hash[l];
	}
	else if(l == r)
	{
		sum[rt] = 0;
	}
	else
	{
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
	
}
void update(int L, int R, int k, int l, int r, int rt)
{
	if(l >= L && r <= R)
	{
		cnt[rt] += k;
		pushUp(l,r,rt); 
	}
	else
	{
		int m = (l + r) >> 1;
		if(L <= m)
		{
			update(L,R,k,lson); 
		}
		if(R >= m+1)
		{
			update(L,R,k,rson);
		}
		pushUp(l,r,rt);
	}
}
int main()
{
	int n, num = 1;
	while(scanf("%d",&n) && n != 0)
	{
		mmset(sum,0);
		mmset(cnt,0);
		for(int i = 1; i <= 2 * n; i += 2)
		{
			double x1,x2,y1,y2;
			scanf("%lf %lf %lf %lf",&x1,&y1,&x2, &y2);
			data[i] = node(x1,x2,y1,1);
			hash[i] = x1;
			data[i+1] = node(x1,x2,y2,-1);
			hash[i + 1] = x2;
		}
		sort(data + 1, data + 1 + 2 * n);
		sort(hash + 1, hash + 1 + 2 * n);
		int len = unique(hash + 1, hash + 1 + 2 * n) - (hash +  1);
		double res = 0;
		for(int i = 1; i < 2 * n; i++)
		{
			int L = lower_bound(hash + 1, hash + 1 + len, data[i].l) - hash;
			int R = lower_bound(hash + 1, hash + 1 + len, data[i].r) - hash;
			update(L,R - 1, data[i].mark,1,len - 1, 1);
			res += sum[1] * (data[i + 1].h - data[i].h);
		}
		printf("Test case #%d\n",num++);
		printf("Total explored area: %0.2lf\n\n",res);
	}

	return 0;
}
```


