#include<stdio.h>
#include<algorithm>
#include<math.h> 
using namespace std;
const double PI = acos(-1.0);
const int INF = 100005;
 
struct node 
{
	double x,y;
};
 
node data[INF];
 
node res[INF];				//数组模拟栈(这里如果用stl自带的栈会比较麻烦) 
 
 
double Graham(node* data,node* res, int n);
 
double cross(node a, node b, node mark);  //求向量mark->a, 向量mark-> b的叉积；
 
double dis(node a, node b);    //求a,b两点距离；

double GetAng(node a,node b,node c);
 
long long  dis1(node a, node b); 
 
bool cmp(node a,node b)
{
     double ans = cross(a,b,data[0]);
     if(ans > 0 || (ans == 0 && dis(a,data[0]) < dis(b,data[0]))) return true;
     return false;
}
 
/*
8
0 0
2 0
4 0
4 2
4 4
2 4
0 4
0 2
4
0 1
0 2
0 3
0 4
*/
 
int main()
{
	int T;
	scanf("%d",&T);
	int numb = 1;
	while(T--)
	{
		int n;
		scanf("%d", &n);				//点集的大小
		for(int i = 0; i < n; i++)
		scanf("%lf %lf",&data[i].x,&data[i].y);
		
		int len = Graham(data,res,n);	//凸包的大小(也就是凸包所包含点的数目) 
		double ans = 1000;
		if(len <= 2)
		{
			ans = 0;
		}
		else 
		{
			res[len] = res[0];
			res[len + 1] = res[1];
			for(int i = 1; i <= len; i++ )
			{
				double key = GetAng(res[i-1],res[i+1],res[i]);
				ans =  min(key,ans);
			}
		}
		printf("Case %d: %.12lf\n",numb++,ans);
		
	}	
	return 0;
}
 
 
double Graham(node* data,node* res, int n)
{
	//求出最左下的那个点(原点或参照点)，并将此点和data[0]交换一下-------------------------
	int t = 0;
	
	for(int i = 1; i <n; i++)
	{
		if(data[t].y > data[i].y || (data[t].y == data[i].y) && data[t].x > data[i].x)
		t = i;
	} 
	
	node temp = data[t];
	data[t] = data[0];
	data[0] = temp;
	
	//将除了data[0]之外的点按与data[0]的极角从小到大排序-----------------------
	
	/*	如果用注释的部分来排序会很慢，所以用快排 
	for(int i = 1; i < n; i++)
	{
		int t = i;
		
		for(int j =i+1; j < n; j++)
		{
			double flag = cross(data[t],data[j],data[0]);
			if(flag < 0 || ( flag == 0 && dis(data[t],data[0]) > dis(data[j], data[0]) ) )
			t = j;
		}
		node temp1 = data[t];
		data[t] = data[i];
		data[i] = temp1;
	} 
	*/
	sort(data + 1,data + n,cmp);
 
	
	//初始化栈res----------------------------------------------------------------
	res[0] = data[0];
 
	int top = 0;
	
	//利用栈不断维护凸壳---------------------------------------------------------- 
	
	for(int i = 1; i < n; i++)
	{
		while(top > 0 && cross(res[top-1], data[i] ,res[top]) >= 0)				//找出所有右转的点，然后弹出栈 
		top--;
		res[++top] = data[i];
	}
	
	return top + 1;
	 
	
}
double cross(node a, node b, node mark)
{
	return (a.x - mark.x) * (b.y - mark.y) - (b.x - mark.x) * (a.y - mark.y);
} 
 
double dis(node a, node b)
{
	return sqrt( (a.x -b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
} 

double GetAng(node a,node b,node c)
{
	double x1 = a.x - c.x, y1 = a.y - c.y;
	double x2 = b.x - c.x, y2 = b.y - c.y;
	node p1,p2;
	p1.x = x1, p1.y = y1, p2.x = x2, p2.y = y2;
	double temp = atan2(fabs(p1.x * p2.y - p1.y * p2.x),(p1.x * p2.x + p1.y * p2.y));
	temp = fabs(temp);
	return temp * (180.0 / PI);
}
