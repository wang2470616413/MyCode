# 2019.9.1 
## The Preliminary Contest for ICPC Asia Nanjing 2019

### F_Greedy Sequence
#### 此题难在题意上,以下为题意：
#### &emsp;&emsp;&emsp;给出一个长度为n数组A和一个数k,让你通过以下规则创建n个数组，其中第i个数组为si.
#### &emsp;&emsp;&emsp;&emsp;&emsp;1.si[1] = i;
#### &emsp;&emsp;&emsp;&emsp;&emsp;1.si数组是非严格递减
#### &emsp;&emsp;&emsp;&emsp;&emsp;3.假定aux[w] = index表示w在A数组的下标为index,那么abs(aux[si[j]] - aux[si[j-1]]) <= k
#### &emsp;&emsp;&emsp;&emsp;&emsp;4.经过前三点规则创建处的si可能有多个，以字典序最大的那个si为合法数组
#### &emsp;&emsp;&emsp;数组Si的权值是里面数的个数，题目要求是输出s1 ~ sn数组的权值
#### &emsp;&emsp;&emsp;知道题意以后就很简单了，用dp(递推)即可

### H_Holy Grail
#### 题意为给出一个有向无负环的图，让你在里面按顺序添加6个从si -> ti的边，并且此边的权值必须最小可以为负，但要保证图中不能添加负环。
#### 最短路即可，注意每次添加后的边要及时加入图中


