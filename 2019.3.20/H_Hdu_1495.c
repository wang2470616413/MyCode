#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105;
struct node
{
	int sta[4];	
	int step;
	node()
	{
	};
	node(int p1,int p2,int p3,int pstep)
	{
		sta[1] = p1;
		sta[2] = p2;
		sta[3] = p3;
		step = pstep;
	};
};
int status[N][N][N];
int dir[7][4] = {0,1,2,3,0,1,3,2,0,2,1,3,0,2,3,1,0,3,2,1,0,3,1,2};
int s1,s2,s3,e1,e2,e3;
int s[4];
int main()
{
	
	while(scanf("%d %d %d",&s[1],&s[2],&s[3]) && s[1] + s[2] + s[3] != 0)
	{
		mmset(status,0);
		if(s[1] % 2 == 0)
		{
			int temp1 = s[1] / 2;
			e1 = temp1;
			e2 = temp1;
			e3 = 0;
			node data[N];
			queue <node> que;
			que.push(node(s[1],0,0,0));
			status[s[1]][0][0] = 1;
			int res = -1;		
			while(!que.empty())
			{
				node fro = que.front();
				que.pop();
				if((fro.sta[1] == e1 && fro.sta[2] == e2 && fro.sta[3] == e3) || (fro.sta[1] == e1 && fro.sta[2] == e3 && fro.sta[3] == e2)||((fro.sta[1] == e3 && fro.sta[2] == e1 && fro.sta[3] == e2)))
				{
					res = fro.step;
					break;
				}
				else 
				{
					int t[4];
					for(int i = 0; i < 6; i++)
					{
						s2 = s[dir[i][2]];
						t[dir[i][1]] = fro.sta[dir[i][2]] + fro.sta[dir[i][1]] <= s2 ? 0 : fro.sta[dir[i][1]] - s2 + fro.sta[dir[i][2]];
						t[dir[i][2]] = fro.sta[dir[i][2]] + fro.sta[dir[i][1]] <= s2 ? fro.sta[dir[i][1]] + fro.sta[dir[i][2]]: s2;	
						t[dir[i][3]] = fro.sta[dir[i][3]];
						if(status[t[1]][t[2]][t[3]] == 0)
						{
							status[t[1]][t[2]][t[3]] = 1;
							que.push(node(t[1],t[2],t[3],fro.step + 1));
						}
					}
				}
			}
			if(res == -1)
			{
				printf("NO\n");
			}
			else 
			{
				printf("%d\n",res);
			}
			
			
		}
		else 
		{
	
			printf("NO\n");
		}
			
	}
	return 0;

}
