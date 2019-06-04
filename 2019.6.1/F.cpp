#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
#define map map1
using namespace std;
const int N = 1e3 + 5;
int map[N][N];
int n,m,k;
int isCount(int a, int b, int n, int m)
{
	int sum = 0;
	if(map[a - 1][b] == 0 && map[a - 1][b + 1] == 0 && map[a][b + 1] == 0)
	{
		sum++;
	}
	if(map[a - 1][b] == 0 && map[a - 1][b-1] == 0 && map[a][b-1] == 0)
	{
		sum++;	
	}
	if(map[a][b +1] == 0 && map[a + 1][b + 1] == 0 && map[a + 1][b] == 0)
	{
		sum++;
	}
	if(map[a][b - 1] == 0 && map[a + 1][b] == 0 && map[a  + 1][b - 1] == 0)
	{
 		sum++;
	}
	map[a][b] = 1;
	return sum;
}
namespace io 
{
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () 
	{
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
// putchar
	inline void putc (char x) 
	{
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	inline bool read (signed &x) 
	{
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}

	inline bool read (long long &x) 
	{
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) 
	{
		x=gc();
		return x!=EOF;
	}
	inline bool read(char *x)
	{
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y)
	{
		return read(x)&&read(y...);
	}
	// print a signed integer
	inline bool write (signed x) 
	{
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}

	inline bool write (long long x) 
	{
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) 
	{
		putc(x);
		return 0;
	}
	inline bool write(const char *x)
	{
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x)
	{
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y)
	{
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
int main()
{
	mmset(map,0);
	read(n), read(m), read(k);
	for(int i = 0; i <= n; i++)
	{
		map[i][0] = map[i][m + 1] = 1;
	}
	for(int i = 0; i <= m; i++)
	{
		map[0][i] = map[n + 1][i] = 1;
	}
	int res = (n - 1) * (m - 1);
	for(int i = 1; i <= k; i++)
	{
		int a,b;
		read(a), read(b);
		res -= isCount(a,b,n,m);
		write(res,"\n");
	}
	return 0;
}