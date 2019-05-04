#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) mesmet(a,b,sizeof(a))
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int flag = 1;
		for(int i = 1; i <= n; i++)
		{
			int num;
			scanf("%d",&num);
			int temp = sqrt(num);
			if(temp * temp != num)
			{
				flag = 0;
			}
		}
		if(flag == 1)
		{
			printf("Yes\n");
		}
		else 
		{
			printf("No\n");
		}

	}




	return 0;
}
