# 2019南阳理工省赛预选赛第五场
## D_Poj_3264 简单RMQ
## F_Hdu_6322 找规律(表面上看是一道数论，其实是找规律)
## G_Hdu_6312 博弈(跟去年郑轻预选赛热身赛的一个题很想)
## I_Hdu_1172 枚举每一种情况，让后检查这种情况是否合法，如果找不到
##            一种情况合法或者有多种情况合法都是不符合题意的
# 以下是当时没有做出来的题
## E_Poj_1269
### &emsp;此题是个傻吊题
## H_Hdu_6024
### &emsp;此题是个简单dp,注意题意暗含了最左边的教室一定要做成超市的信息
### &emsp;dp[i][0]表示前i个教室(注意是按坐标顺序从小到大的前i个)在第i个
### &emsp;教室建立超市的情况下的最小花费，这种情况的状态转移方程很简单，
### &emsp;dp[i][1]表示前i个教室在第i个教室的不建立超市的情况的最小花费.
### &emsp;这种情况下的状态转移稍复杂一些
