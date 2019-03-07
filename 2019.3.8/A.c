#include<stdio.h>
#include<algorithm>
#include<string.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
	int a,b,c,d;
	scanf("%d:%d",&a,&b);
	scanf("%d:%d",&c,&d);
	int sumH = a + c;
	int sumM = b + d;
	sumH += sumM / 60;
	sumM %= 60;
	sumM = sumM +( sumH % 2 == 0 ? 0 : 60);
	printf("%02d:%02d\n",sumH / 2,sumM / 2);

	return 0;
}
