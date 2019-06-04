# 2019.6.1 cometOJ六一欢乐赛
#### 本次比赛打的不是很好，有一些题做得太慢了，而且思路不是很明确
#### ，导致后面有些能做的题没有做
##复盘：
#### &emsp;&emsp;B题，B题是给你一个长度为n的序列，让你选出k个数，使得这k个数两两互质，求最大的k。
##### &emsp;&emsp;&emsp;1.根据题目范围很容易想到枚举序列，然后对序列进行判定。但是我想的枚举方法时用全排列，但是全排列复杂度太大。所以一直在想，导致浪费了很长时间。后来想到用dfs枚举（其实一开始就应该往dfs上去想的）。
##### &emsp;&emsp;&emsp;2.还有就是情况考虑不够周全，应该考虑一下n为0的情况的，这种情况下也要输出答案。
#
#### &emsp;&emsp;C题，C题是给你两个字符序列str1,str2.问str1删除两个字符后能否组成str2。
##### &emsp;&emsp;&emsp;1.将模拟过程转化为代码是出错了
##### &emsp;&emsp;&emsp;2.没有深刻理解问题的本质，导致自己的代码写的很麻烦，还容易出错。这个问题的本质就是按str2的顺序寻找str2[i]在str1里的位置。后来有些了againC.cpp代码看起来简洁多了，而且时间比原来快了50多倍左右
#
#### &emsp;&emsp;学一波大佬的输入输出外挂
````
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
````
加了输入输出外挂效果还是很明显的
例如c题，c题我一共ac了三发，
##### 第一发是在比赛时ac的，时间是840ms.
##### 第二发是在理解了问题的本质后写的一发，时间是18ms.
##### 第三发是在第二发的基础上加了一个输入输出外挂，时间是5ms;
##### 第四发是在第一发的基础上加了一个输入输出外挂，时间是1071ms.反而
##### 比原来慢了。有点想不明白
