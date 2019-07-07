#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
char str[] = "Abiyoyo, Abiyoyo.";
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int num;
        scanf("%d",&num);
        for(int i = 1; i <= num; i++)
        {
            printf("%s\n",str);
        }
        printf("Abiyoyo, yo yoyo yo yoyo.\n");
        printf("Abiyoyo, yo yoyo yo yoyo.\n");
    }





    return 0;
}