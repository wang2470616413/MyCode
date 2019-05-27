# 2019.5.26
## Hdu_6288
### &emsp;此题整体思路就是二分，但是难点不是在二分上
### &emsp;难点是判断`a的b次方是否溢出`。我们可以先求出a的b次方，再利用快速幂得出
### &emsp;a的b次方模1e9 + 7的结果，然后该值与a的b次方模 1e9 + 7 比较，`相同说明`
### &emsp;`没有溢出，不同说明溢出`
### &emsp;需要注意的是如果直接用c++函数pow来求a的b次方是有误差的，所以我们应该
### &emsp;手写一个求a的b次方的函数。
### &emsp;<font color = red>该题需要注意如下几点</font>
#### &emsp;&emsp;1. <font color = 	#FF0000> 任何施加于整数的运算的结果，判断其是否溢出都可以用取余来判断</font>
#### &emsp;&emsp;2. <font color = red> pow运算对于整数来说有误差，消除误差的方法可以自己手写一个这样的函数</font>
#### &emsp;&emsp;3. <font color = red> __int128的范围是−170,141,183,460,469,231,731,687,303,715,884,105,728 (-2^127) ~ 170,141,183,460,469,231,731,687,303,715,884,105,727 (2^127 − 1),大概是-1e38 ~ 1e38。</font>
##### &emsp;&emsp;&emsp;以下是__int128的输入输出
##### &emsp;&emsp;&emsp;&emsp;
        ```
        void scan(__int128 &x)
        {
            int f = 1;
            char ch;
            x = 0;
            if (ch = getchar() == '-') f = -1;
            else x += ch - '0';
            while ((ch == getchar()) >= '0' && ch <= '9')
                x = x * 10 + ch - '0';
            x *= f;
        }
        void print(__int128 x)
        {
            if (!x) return ;
            if (x < 0) putchar('-'),x = -x;
            print(x / 10);
            putchar(x % 10 + '0');
        }
        ```
## Hdu_1542
### &emsp;该题是扫描线的模板题
### &emsp;[扫描线讲解](https://blog.csdn.net/u013377068/article/details/90602782)



