# 2019.9.3
### 2019中国大学生程序设计竞赛（CCPC） - 网络选拔赛 B_arry
#### 题意:给出一个长度为n范围1~n的无序数组data，和一个值mark，刚开始mark 为0
#### 有两种操作:  1 a :把data[a ^ mark]变为data[a ^ mark] + 1e7;
#### &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;2 a, b:找出大于等于(b ^ mark)的最小值，且这个最小值不能属于data[1 ~ (a ^ mark)]。输出并使得mark等于这个值
#### 很容易想到用一个数据结构维护每个区间大于等于某数的最小值。后来选用了主席树来维护，但是操作1用主席树写比较麻烦，仔细观察可以知道当把某个数+1e7之后就相当于这个数不存在与data[1~n]里面了(那么也就是说这一部分数一定是合法的)。那么这一部分数可以用一个set来维护。在查询的时候可以取data[1 ~ (a ^ mark)]和set的最小值即可

### 今天学习了一维树状数组，找了一个水题练练
### Hdu1166
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    