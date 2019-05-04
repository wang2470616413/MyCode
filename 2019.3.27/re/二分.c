#include<stdio.h>
int lower_bound(int* data,int l,int r,int key);		//lower_bound返回第一个大于或等于关键字的下标 也就是查找下界 
int upper_bound(int* data,int l,int r,int key);		//upper_bound返回第一个大于关键字的下标，也就是查找上界  
int main()
{
	int data[10] ={0,1,1,2,2,2,2,3,4,7};
	int res = upper_bound(data,0,9,2) ;	
	int res1 = lower_bound(data,0,9,5) ;	
	printf("%d %d\n",res,res1);
	
	
	return 0;
} 
 
int lower_bound(int* data,int l,int r,int key)
{
	int m = 0;
	while(l < r)
	{
		m = (l + r) / 2;
		if(data[m] >= key)
		r = m;
		else
		l = m + 1;
	} 
	return l;
}
int upper_bound(int* data,int l,int r,int key)
{
	int m = 0;
	while(l < r)
	{
		m = (l + r) / 2;
		if(data[m] <= key)
		l = m + 1;
		else
		r = m; 
	}
	return l;
}
