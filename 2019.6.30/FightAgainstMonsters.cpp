#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e6 + 5;
struct node
{
    int h,a;
    bool operator < (const node two) const
    {
        return h * two.a < a * two.h;
    }
};
int n;
node data[N];
int count1(int k)
{
    int s = 1, count = 0;
        while (k > 0)
        {
            count++;
            k -= s;
            s++;
        }
        return count;
    
}
int main()
{
    int T;
    scanf("%d",&T);
    int num = 1;
    while(T--)
    {
        ll sum = 0, temp = 0;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d",&data[i].h, &data[i].a);
            data[i].h = count1(data[i].h);
            sum += data[i].a;
        }
        sort(data + 1, data + 1 + n);
        ll res = 0;
        for(int i = 1; i <= n; i++)
        {
            ll k = data[i].h;
            res += (sum * k);
            sum -= data[i].a;
        }
        printf("Case #%d: %lld\n",num++,res);
        
    }
    return 0;
}