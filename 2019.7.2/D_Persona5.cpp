#include<stdio.h>
#include<string.h>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define error printf("error\n")
using namespace std;
const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;
ll F[N];
ll data[N];
ll res = 1;
ll aux = 0;
void init(ll p)
{
    F[0] = 1;
    for(int i = 1;i <= p;i++)
        F[i] = F[i-1]*i % (MOD);
}
ll inv(ll a,ll m)
{
    if(a == 1)return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
ll pow(ll a, ll n, ll p)    //快速幂 a^n % p
{
    ll ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}
 
ll niYuan(ll a, ll b)   //费马小定理求逆元
{
    return pow(a, b - 2, b);
}

ll C(ll a, ll b)    //计算C(a, b)
{
    return F[a] * niYuan(F[b], MOD) % MOD
        * niYuan(F[a - b], MOD) % MOD;
}

ll Lucas(ll a, ll b)
{
    if(a < MOD && b < MOD)
        return C(a, b);
    return
        C(a % MOD, b % MOD) * Lucas(a / MOD, b / MOD);
}

ll modmul(ll ans,ll a)
{
    ll t=0;
    while (a)
    {
        if(a&1)
            t=(t+ans)%MOD;
        ans=(ans+ans)%MOD;
        a=a>>1;
    }
    return t;
}

/*
3
1 1 1
3
1 2 3
 */
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        res = 1, aux = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&data[i]);
            aux += data[i];
        }
        init(aux + 5);
        for(int i = 1; i <= n - 1; i++)
        {
            res =  modmul(res,(Lucas(aux,data[i])));
            aux -= data[i];
        }
        printf("%lld\n",res);
    }

    return 0;
}