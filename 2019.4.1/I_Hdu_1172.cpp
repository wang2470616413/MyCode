#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105;
struct node
{
	char str[100];
	int a,b;
};
int main()
{
	int n;

	while(~scanf("%d",&n) && n != 0)
	{
	
		node data[N];
		for(int i = 1; i <= n; i++) 
		{
			scanf("%s",data[i].str + 1);
			for(int j = 1; j <= 4; j++)
			{
				data[i].str[j] -= '0';
			}
			scanf("%d %d",&data[i].a,&data[i].b);
		}
		int num0 = 0;
		int res = 0;
		int aux[100];
		for(aux[1] = 0; aux[1] <= 9; aux[1]++)
		{
			for(aux[2] = 0; aux[2] <= 9; aux[2]++)
			{
				for(aux[3] = 0; aux[3] <= 9; aux[3]++)
				{
					for(aux[4] = 0; aux[4] <= 9; aux[4]++)
					{
					//	printf("%d %d %d %d\n",aux[1],aux[2],aux[3],aux[4]);
						int flag = 0;
					//	aux[1] = 3,aux[2] = 5,aux[3] = 8,aux[4] = 5;
						for(int i = 1; i <= n; i++)
						{
							int num0 = 0;
							int num1 = 0;
							int mark[10];
							mmset(mark,0);
							for(int j = 1; j <= 4; j++)
							{
								if(aux[j] == data[i].str[j])
								{
									num1++;
								}
							}
							for(int j = 1; j <= 4; j++) 
							{
								for(int k = 1; k <= 4; k++)if(mark[k] == 0 && aux[k] == data[i].str[j])
								{
									mark[k]++;
									num0++;
									break;
								}
							}
							if(num0 != data[i].a || num1 != data[i].b)
							{
								flag = 1;
								break;
							}
						}
						if(flag == 0)
						{
							num0++;
							res = aux[1] * 1000 + aux[2] * 100 + aux[3] * 10 + aux[4];
						}
						
					}
					
				}
			}
		}
		if(num0 == 1) 
		{
			printf("%d\n",res) ;
		}
		else
		{
			printf("Not sure\n");
		} 
	}

	return 0;
}
