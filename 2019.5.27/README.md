# 2019.5.27
## Hdu_1828
### 扫描线扫描周长
#### &emsp;&emsp;扫描线扫描周长比扫描面积要麻烦一些,需要解决的问题有两个
#### &emsp;&emsp;1.如何统计每条横线(<font color =red> 也就是平行于x轴的线段的长度 </font>)
#### &emsp;&emsp;2.如何统计每条竖线(<font color =red> 也就是平行于y轴的线段的长度 </font>)
### 如图
![](https://img-blog.csdnimg.cn/20190528160342966.png)
#### &emsp;&emsp;我们发现每次扫描线扫描后投影到根节点的总长度与上次扫描所投影的
#### &emsp;&emsp;总长度的绝对值之差就是本次扫描所多出的边长。
#### &emsp;&emsp;这样我们就解决了第一个问题
### 解决第二个问题的方法有两种
#### &emsp;&emsp;1.与解决第一种方法一样，将扫描线从左至右扫一遍，得到每次增加的竖直长度即可
#### &emsp;&emsp;&emsp;但是这种方法复杂度要高一点，代码也稍微有点冗长。
#### &emsp;&emsp;2.我们发现竖直线段的长度就是本次扫描线的高度与下一条扫描线的高度之差。关键
#### &emsp;&emsp;&emsp;关键在于我们要求出本次扫描线与下一条扫描线有多少个竖直线段。我们可以发现
#### &emsp;&emsp;&emsp;竖直线段的个数与本次扫描线的"裸露"的断点有关。因此我们需要用数组ls,rs记录
#### &emsp;&emsp;&emsp;区间的左端点或者右端点是否"裸露"。再用数组num记录区间有几个竖直线段