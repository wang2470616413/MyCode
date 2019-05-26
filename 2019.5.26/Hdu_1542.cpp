#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define hash hash1
#define  lson l,m,rt<<1
#define  rson m+1,r,rt<<1|1
using namespace std;
const int N = 20002;

struct node
{
	double l,r,h;
	int mark;
	node()
	{
		
	}
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
double X[N];
double hash[N];
double sum[N  << 2];
int cnt[N << 2];
node data[N];
int n;
void pushUp(int l, int r,int rt)
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
int bind_search(int a, int b, double* data,double key)
{
	int m;
	while(a <= b)
	{
		m = (a + b) >> 1;
		if(data[m] == key)
		{
			return m;
		}
		else if(data[m] > key)
		{
			b = m - 1;
		}
		else
		{
			a = m + 1;
		}
	}
	return -1;
}

/*
2
10 10 20 20
15 15 25 25
0
*/

int main()
{
	int num = 1;
	while(scanf("%d",&n) && n)
	{
		mmset(sum,0);
		mmset(cnt,0);
		for(int i = 1; i <= 2 * n; i+=2)
		{
			double x1,y1,x2,y2;
			scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
			data[i] = node(x1,x2,y1,1);
			hash[i]= x1;
			data[i + 1] = node(x1,x2,y2,-1);
			hash[i+1]= x2;
		}
		sort(data + 1, data + 1 + 2 * n);
		sort(hash + 1, hash + 1 + 2 * n);
		int len = unique(hash + 1, hash + 1 + 2 * n)- (hash + 1);
		double res = 0;
		for(int i = 1; i  <= 2 * n - 1; i++)
		{
			int L = bind_search(1,len,hash,data[i].l);
			int R = bind_search(1,len,hash,data[i].r);
			update(L,R-1,data[i].mark,1,len - 1,1);
			res += (data[i+1].h - data[i].h) * sum[1];
		}

		printf("Test case #%d\n",num++);
		printf("Total explored area: %0.2lf\n\n",res);
	}
	
	return 0;
}