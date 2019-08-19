#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#define ll unsigned long long
#define LL unsigned long long  
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int S = 8;
int data[(int)1e4];
LL prime[6] = {2, 3, 5, 233, 331};
LL qmul(LL x, LL y, LL mod) 
{ // 乘法防止溢出， 如果p * p不爆LL的话可以直接乘； O(1)乘法或者转化成二进制加法 
    return (x * y - (long long)(x / (long double)mod * y + 1e-3) *mod + mod) % mod;
}
LL qpow(LL a, LL n, LL mod) 
{
    LL ret = 1;
    while(n) 
    {
        if(n & 1) ret = qmul(ret, a, mod);
        a = qmul(a, a, mod);
        n >>= 1;
    }
    return ret;
}
bool MR(LL p) 
{
    if(p < 2) return 0;
    if(p != 2 && p % 2 == 0) return 0;
    LL s = p - 1;
    while(! (s & 1)) s >>= 1;
    for(int i = 0; i < 5; ++i) 
    {
        if(p == prime[i]) return 1;
        LL t = s, m = qpow(prime[i], s, p);
        while(t != p - 1 && m != 1 && m != p - 1) 
        {
            m = qmul(m, m, p);
            t <<= 1;
        }
        if(m != p - 1 && !(t & 1)) return 0;
    }
    return 1;
}
int main()
{
    int T;
    scanf("%d",&T);
    int index = 1;
    for(int i = 1; i <= 10000; i++)
    {
        if(MR(i) == true)
        {
            data[index] = i;
            index++;
        }
    }
    while(T--)
    {
        ll num = 0;
        scanf("%llu",&num);
        for(int i = 1; i < index; i++)
        {
            if(MR(num - data[i]) == true)
            {
                printf("%d %llu\n",data[i],num - data[i]);
                break;
            }
        }
    }
    return 0;
}