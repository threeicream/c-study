/*
动态规划：1.穷举法->2.记忆化搜索/剪枝->3.dp迭代形式
0/1背包问题
如果有n个物品和容量为v的背包。每个物品只能用一次，第i个物品的价值为vi，体积为wi，求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。
解法：
1.如果装不下当前物品，那么前n个物品的最佳组合和前n-1个物品的最佳组合是一样的
2.如果装得下当前物品
2.1装当前，物品，在给当前物品预留了相应空间的情况下，前n-1个物品的最佳组合加上当前物品的价值就是总价值
2.2不装当前物品，那么前n个物品的最佳组合和前n-1个物品的最佳组合是一样的
选取2.1和2.2中较大的价值，就为当前最佳组合的价值
回溯问题
如果知道价值，如何知道背包装了哪些物品
解法：
从表的右下角开始回溯，如果发现前n个物品的最佳组合的价值和前n-1个物品最佳组合的价值一样，说明第n个物品没有被装入
否则，第n个物品被装入

递增问题：
给一个数组，选出其中递增长度最大的结果

评价算法好坏：
1.空间复杂度
2.时间复杂度
算法应用：
1.查找；2.排序；3.运算；4.最优决策
如何推导时间复杂度：
1.常量量级为1
2.只保留时间函数中的最高阶项
3.若最高阶项存在，则省去最高阶项前面的系数
O(1)<)(logn)<O(n)<O(n^2)
如何推导空间复杂度：
1.算法存储空间大小固定，与输入规模无直接关系，O(1)
void fun1(int n){int var = 3;}
2.算法分配空间是一个线性集合（如数组），并且集合大小与输入规模n成正比，O(n)
void fun2(int n){int[] array = new int[n];}
3.算法分配空间是一个二维数组集合，并且集合长度宽度斗鱼输入规模n成正比，O(n^2)
void fun3(int n){ int[][] matrix = new int[n][n];}
3.函数为递归函数。虽然没有显式地声明变量或者集合，但是会有内存存储“方法调用栈”，方法调用栈包括出栈和进栈两个行为
void fun4(int n){if(n<=1){return;} fun4(n-1);}
若递归深度为n，O(n)
时间与空间的取舍
*/