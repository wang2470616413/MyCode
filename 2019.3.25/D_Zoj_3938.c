#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a)) 
using namespace std;

struct node
{
	int mark,data[10];
	node()
	{
		
	};
	node(int m,int a, int b, int c, int d)
	{
		mark = m;
		data[1] = a;
		data[2] = b;
		data[3] = c;
		data[4] = d;
	};
};
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		node ans[100];
		node aux[100];
		for(int i = 1; i <= 5; i++)
		{
			int m,a,b,c,d;
			scanf("%d %d %d %d %d",&m,&a,&b,&c,&d);
			ans[i] = node(m,a,b,c,d);
			aux[i].mark = m;
			aux[i].data[a] = 1;
			aux[i].data[b] = 2;
			aux[i].data[c] = 3;
			aux[i].data[d] = 4;
			
		}
		int res[10][3];
		for(int i = 1; i <= 5; i++)
		{
			if(i == 1)
			{
				if(ans[i].mark == 1)
				{
					res[i][1] = 2;
					res[i][2] = ans[i].data[2];
				}
				if(ans[i].mark == 2)
				{
					res[i][1] = 2;
					res[i][2] = ans[i].data[2];
				}
				if(ans[i].mark == 3)
				{
					res[i][1] = 3;
					res[i][2] = ans[i].data[3];
				}
				if(ans[i].mark == 4)
				{
					res[i][1] = 4;
					res[i][2] = ans[i].data[4];
				}
				
			}
			if(i == 2)
			{
				if(ans[i].mark == 1)
				{
					res[i][1] = aux[i].data[4];
					res[i][2] = 4;
				}
				if(ans[i].mark == 2)
				{
					res[i][1] = res[1][1];
					res[i][2] = ans[i].data[res[1][1]];
					
				}
				if(ans[i].mark == 3)
				{
					res[i][1] = 1;
					res[i][2] = ans[i].data[1];
				}
				if(ans[i].mark == 4)
				{
					res[i][1] = res[1][1];
					res[i][2] = ans[i].data[res[1][1]];
				}
				
			}
			if(i == 3)
			{
				if(ans[i].mark == 1)
				{
					res[i][1] = aux[i].data[res[2][2]];
					res[i][2] = res[2][2];
				}
				if(ans[i].mark == 2)
				{
					res[i][1] = aux[i].data[res[1][2]];
					res[i][2] = res[1][2];
				}
				if(ans[i].mark == 3)
				{
					res[i][1] = 3;
					res[i][2] = ans[i].data[3];
				}
				if(ans[i].mark == 4)
				{
					res[i][1] = aux[i].data[4];
					res[i][2] = 4;
				}
				
			}
			if(i == 4)
			{
				if(ans[i].mark == 1)
				{
					res[i][1] = res[1][1];
					res[i][2] = ans[i].data[res[1][1]];
				}
				if(ans[i].mark == 2)
				{
					res[i][1] = 1;
					res[i][2] = ans[i].data[1];
				}
				if(ans[i].mark == 3)
				{
					res[i][1] = res[2][1];
					res[i][2] = ans[i].data[res[2][1]];
				}
				if(ans[i].mark == 4)
				{
					res[i][1] = res[2][1];
					res[i][2] = ans[i].data[res[2][1]];
				}
				
			}
			if(i == 5)
			{
				if(ans[i].mark == 1)
				{
					res[i][1] = aux[i].data[res[1][2]];
					res[i][2] = res[1][2];
				}
				if(ans[i].mark == 2)
				{
					res[i][1] = aux[i].data[res[2][2]];
					res[i][2] = res[2][2];
				}
				if(ans[i].mark == 3)
				{
					res[i][1] = aux[i].data[res[4][2]];
					res[i][2] = res[4][2];
				}
				if(ans[i].mark == 4)
				{
					res[i][1] = aux[i].data[res[3][2]];
					res[i][2] = res[3][2];
				}
				
			}
			
		}
		for(int i = 1; i <= 5; i++)
		{
			printf("%d %d\n",res[i][1],res[i][2]);
		}
	}
	
	
	
	return 0;
}
