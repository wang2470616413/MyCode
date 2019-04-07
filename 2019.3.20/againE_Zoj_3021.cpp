#include<bits/stdc++.h> 
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const double esp = 1e-12;
const int INF = 0x7f7f7f7f;
int main()
{
	ll n, m;
	double k, l;
	while(cin >> n >> k >> l >> m)
	{
		ll L = 0, R = INF;
		double s;
		if(n == k) s = floor(k * m);
		else s = floor((k + 0.049999999999) * m);
		while(L < R)
		{
			ll mid = (L + R) >> 1;
			if(((s + mid) / (m + mid)) < (l + 0.049999999999)) 
			{
				R = mid;
			}
			else 
			{
				L = mid + 1; 
			}
		} 
		cout << L << endl;
	}
}

