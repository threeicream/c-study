﻿/*
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

排序算法：
时间复杂度O(n^2):冒泡排序、选择排序（一趟既选取最大值，也选取最小值）、插入排序、希尔排序（介于O(nlogn)和O(N^2)之间）
时间复杂度O(nlogn):快速排序、归并排序、堆排序
时间复杂度为线性：计数排序、桶排序、基数排序
排序算法还可以根据其稳定性，划分为稳定排序和不稳定排序。
即如果值相同的元素在排序后仍然保持着排序前的顺序，则这样的排序算法是
稳定排序；如果值相同的元素在排序后打乱了排序前的顺序，则这样的排序算法是不稳定排序。

冒泡排序实现以及优化：
1.使用两段for循环，使每个元素都与后面的元素进行大小比较
2.加入标志位，判断后续是否还有值交换，若没有则跳转出大循环
3.记录最后一次交换的位置，每次比较到这个位置，后面的元素就不进行比较，节约时间，放在二次循环的范围
鸡尾酒排序（冒泡排序的升级版，双向冒泡排序）
排序过程就像钟摆一样，第1轮从左到右，第2轮从右到左，第3轮再从左到右

快速排序：
冒泡的升级版，使用了分治法
在每一轮挑选一个基准元素，并让其他比它大的元素移动到数列一边，比它小的元素移动到数列的另一边，从而把数列拆解成两个部分。
实现分治法的方法：
1.单边循环法
2.双边循环法
双边循环法的基本步骤
选择基准元素: 通常选择数组的第一个元素作为基准元素（pivot）。
初始化两个指针: 左指针（left）从数组的起始位置开始，右指针（right）从数组的末尾位置开始。
移动右指针: 从右向左移动右指针，直到找到一个小于基准元素的元素。
移动左指针: 从左向右移动左指针，直到找到一个大于基准元素的元素。
交换元素: 交换左指针和右指针指向的元素。
重复步骤3-5: 直到左指针和右指针相遇。
交换基准元素: 将基准元素与左指针或右指针相遇位置的元素交换。
递归排序: 对基准元素左右两侧的子数组递归进行上述步骤。

单边循环法：第一，把mark指针右移1位，因为小于pivot的区域边界增大了1；
第二，让最新遍历到的元素和mark指针所在位置的元素交换位置，因为最新遍历的元素归属于小于pivot的区域。

使用非递归方式实现快速排序：栈

堆排序：
1利用二叉堆实现，把删除的数值传入到另一个vector容器中
1构建初始堆: 将待排序的数组构造成一个大顶堆（或小顶堆）。
2交换堆顶元素与末尾元素: 将堆顶元素（最大值或最小值）与末尾元素交换，此时末尾元素就为最大值（或最小值）。
3调整堆: 将剩余的元素重新调整为大顶堆（或小顶堆）。
4重复步骤2和步骤3: 直到整个序列有序。

计数排序：
这种排序算法是利用数组下标来确定元素的正确位置
每一个下标位置的值代表数列中对应整数出现的次数
直接遍历数组，输出数组元素的下标值，元素的值是几，就输出几次

桶排序：
每一个桶（bucket）代表一个区间范围，里面可以承载一个或多个元素

动态规划（dp）和递归：
相同：
都能分解成若干子问题
不同：
dp存储子问题的结果
动规的处理方式：
1.从上往下：实际就是递归，通过调用函数，无法通过数组储存上一个结果的值
2.从下往上：迭代，也可以说是循环
dp注意点：1.状态转移方程2.问题边界3.从下往上，保存上一个结果的值
例子：1.斐波那契数列 2.金矿问题（见漫画算法P370）3.矩阵最小路径和
dp4要素：
1.状态（存储小规模问题的结果）
2.方程（状态之间的练习，怎么通过小的状态，来算大的状态）
3.初始化（最极限的小状态是什么）
4.答案（最大的状态是什么）
什么情况下使用dp？可拆解成规格更小但相似的子问题

记忆化搜索：递归靠哈希表记录 dp靠数组
模板：
T func(N node, Hash Table<N, T>& cache) {
If (cache.contains(node)) {
 return cache.get(node);
}
...
T sub _res = func(next _node, cache);
...
//当前子问题的解， 依赖于更小的子问题(s)
T res = G( sub_res ... );
cache.set(node, res);
return res;
}
dp常见算法策略比较：
分而治之Divide and Conquer 
动态规划Dynamic Programming 
贪婪算法Greedy Algorithm  局部最优解，
回溯法Backtracking 穷举法，暴力深度优先搜索（DFS，树tree和图graph）回溯和递归是相辅相成的
模式识别：
1.用DP（从下到上）解决收敛结构问题
将状态方程列出，有助于理清算法实现的思路
如果出现类似于“所有解”、“所有路径”等关键词，则用从上到下更为直接

动态规划的要点：确定全局最优解和最优子结构之间的关系，以及问题的边界。
这个关系用数学公式来表达的话，就叫作状态转移方程式

递归三要素：
1.确定函数的参数和返回值
2.确定终止条件
3.确定单层递归的逻辑

回溯模板：可以抽象为树形结构来分析，横向for，竖向递归
适合解决组合、排列、分割、子集等问题(剪枝问题，关键在于letters.size()  n - (k - path.size()) + 1）
void backtracking(深度大小，起始索引，集合大小（也就是循环次数）...)
思路：每个数字代表的数集是不一样的，第一层能选的数集
是digits第一个数字所以代表的字母集，每层的for循环的数
集是不一样的，所以要用一个索引表示当层循环的数集，
然后要把数字转换为字母，字母是就是可以选择的数集，
还要一个path记录路径一个result记录答案，一个参数记
录递归的深度(层数),   path也可写到参数里

const string digital_mapping[10] =  //映射每个数字所代表字母集合
{
	"", //0
	"", //1
	"abc", //2
	"def", //3
	"ghi", //4
	"jkl", //5
	"mno", //6
	"pqrs", //7
	"tuv", //8
	"wxyz", //9
};
vector<string>result;   //记录答案
string path; //记录路径
//1:确定函数参数
void backtracking(string digits, int index)
{
	//2：确定终止条件 处理结果 return
	if (index == digits.size())
	{
		result.push_back(path);
		return;
	}

	//3:选择本层集合中元素
	int digital_number = digits[index] - '0'; //取出digits中本层的数字
	string letters = digital_mapping[digital_number]; //从映射中取出字母集
	for (int i = 0; i < letters.size(); i++)
	{
		path.push_back(letters[i]); //处理
		backtracking(digits, index + 1); //递归
		path.pop_back(); //回溯
	}
}

vector<string> letterCombinations(string digits) {
	if (digits.empty())return result;
	backtracking(digits, 0);
	return result;
}

双指针：
1.两个指针，方向相反
2.两个指针，方向相同
3.两个指针，一快一慢
4.两个指针，方向相同，但是起点不同

KMP算法：解决字符串匹配问题
在主串中查找是否含有子串，例如 abababc  ababc
通过定义next数组，从而进行回溯子串的指针，然后重新对比，
next数组则是包含前缀后缀https://www.bilibili.com/video/BV1AY4y157yL/?vd_source=d5b56f8df14d8a6bf7960e35a0267866
	void getnext(vector<int>&next, string s) {
		next[0] = 0;
		int j = 0;
		for (int i = 1; i < s.size(); ++i) {
			while (j>0&&s[i] != s[j])
				j = next[j - 1];
			if (s[i]==s[j]) {
				++j;
			}
			next[i] = j;
		}

	}
	bool Substr(string a, string b) {
		vector<int>next(b.size(), 0);
		getnext(next, b);
		int i = 0, j = 0;
		while (i<a.size()) {
			while (j > 0 && a[i] != b[j])
				j = next[j - 1];

			if (a[i] == b[j]) {
				++i;
				++j;
			}
			else
				++i;
			if (j == b.size())
				return true;
		}
		return false;
	}
	借视频中例子说明一下 prefix_len = next【prefix_len - 1】 的原因。
例如，串 A B A C A B A B
　　　　 0 1 2 3 4 5 6 7
扫描到 6 号位的 A 时，最长公共前后缀是 ABA；而扫描到 7 号位的 B 时，ABAC 和 ABAB 不匹配了，即原来的最长公共前后缀失配。这时候我们要做的事情就是，找上一次匹配中次长的公共前后缀，看与 7 号位的 B 拼接起来是否能匹配。
这时候，注意到上一次扫描中 0 ~ 2 位的 ABA 是和 4 ~ 6 位的 ABA 完全相同的（贪心原则保证上次结果一定是包含前一位置字符的最长公共前后缀），所以考察上一次匹配中次长的公共前后缀，只能在考察上一次匹配中的最长公共前后缀中考察，也就是说，只能考察 ABA 中更短的 BA、A 是否是次长的，而这直接在前面一个 ABA 中考察都行，所以我们把 ABA C ABA 中中间部分（C）和后缀（ABA）直接抛弃，等效于一个串 ABA（也就是前缀）与 B 拼接成 ABAB。这样再来计算第 7 位的 B 的 next 值，等价于计算 ABAB 第 3 位的 B 的 next 值。prefix_len = next【prefix_len - 1】 也就是这个等效过程的代码展示。

单调队列：单调递增队列中的元素从队头到队尾单调不减，单调递减队列中的元素从队头到队尾单调不增。使用deque实现，头出尾入
优先级队列：std::priority_queue<int> pq; // 最大堆  还有最小堆
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;//less<int>是仿函数

二维前缀和：
规定一个数组pre，其中pre[i]表示数组[0,i]的累加和，求[i,j]的和，就是pre[j]-pre[j-1]
二维前缀和数组：sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]−sum[i][j]+grid[i][j] 当前矩阵和 = 左侧矩阵和 + 上方矩阵和 - 左上角矩阵和 + 当前格子。
子矩阵和：target=sum[i+1][j+1]−sum[i][j+1]−sum[i+1][j]+sum[i][j]  当前矩阵和 = 全部总和 - 左侧总和 - 上方总和 + 左上角矩阵和

单调栈：
https://www.bilibili.com/video/BV1VN411J7S7/?spm_id_from=333.337.search-card.all.click&vd_source=d5b56f8df14d8a6bf7960e35a0267866

并查集：
主要处理一些不相交集合的合并问题
基本操作：
1.初始化
2.查询
3.合并
非递归并查集

单源最短路径算法 Dijkstra:
https://leetcode.cn/problems/network-delay-time/solutions/909575/wang-luo-yan-chi-shi-jian-by-leetcode-so-6phc/?envType=daily-question&envId=2024-11-25

贪心算法：
取每个阶段的局部最优解

问题：
1.如何判断一个链表是否有环
①遍历法，每遍历一个节点，就将他和之前的所有节点做比较，时间O(n^2),空间O(1)
②建立哈希表，每遍历一个节点，就将他与哈希表的节点进行比较，时间O(n),空间O(n)
③追击法，创建两个指针p1和p2，同时指向头节点，p1一次移动1个节点，p2一次移动2个几点，比较两个指针是否相同，一直到尾节点，代码见链表
2.如何求出环的长度
3.如何求出入环节点
4.求两数最大公约数：
辗转相除法 10和25，25除以10商2余5，那么10和25的最大公约数，等同于10和5的最大公约数
更相减损术 10和25，25减10的差是15，那么10和25的最大公约数，等同于10和15的最大公约数
更相减损术+移位运算 通过移位将数据都转换为奇数，然后调用更相减损术
5.求数字是否是2的整数次幂：把2的整数次幂转换成二进制数，其最高位为1，其他为0，n&(n-1)
6.求无序数组排序后两个相邻元素的最大插值（使用桶排序的思路）
7.如何用栈实现队列操作（两个栈，一个入，一个出）
8.字典序算法 寻找在一个整数所包含数字的全部组合中，找到一个大于且仅大于原数的新整数
9.贪心算法（dp变种） 依次求得局部最优解，最终得到全局最优解  给出一个整数，从该整数中去掉k个数字，要求剩下的数字形成的新整数尽可能小
10.特大整数相加 创建两个数组，数组存入后进行加法
11.二分法 针对有规律的数组，得出中间值，比较要求值和中间值，变化两边边界 关键点：
①mid=left+(right-left)>>1;//避免直接使用 (left + right) 可能带来的整数溢出问题
②left = mid + 1;right = mid - 1;//不能包含mid，以确保搜索区间正确缩小并推进搜索过程
12.深度优先搜索 
*/

//冒泡排序
/*

void sort_array(int array[],int length)
{
    //记录最后一次交换位置
    int lastChange = 0;
    //记录边境
    int sortloca = length -1;

    for (int a = 0; a < length - 1; ++a)
    {
        bool flag = true;
        for (auto b = 0; b < sortloca; ++b)
        {
            int temp = 0;
            if (array[b] > array[b + 1])
            {
                temp = array[b];
                array[b] = array[b + 1];
                array[b + 1] = temp;
                //有交换，则flag变为false
                flag = false;
                lastChange = b;
            }
        }
        //最后一次交换的位置赋给边界，此后的元素不再比较
        sortloca = lastChange;
        if (flag == true)
            break;
    }
}
*/

//鸡尾酒排序,使用两个分开的for循环
/*
void sort_gas(int array[], int length)
{
    int start = 0;
    int end = length - 1;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int a = start; a < end; ++a)
        {
            if (array[a] > array[a + 1])
                swap(array[a], array[a + 1]);
            flag = true;
        }
        --end;
        if (flag == false)
            break;
        for (int b = end; b > start; --b)
        {
            if (array[b - 1] > array[b])
                swap(array[b - 1], array[b]);
            flag = true;
        }
        ++start;
    }
}
*/

//选择排序 比较首项和其他的大小，循环完了后交换首项和最小值，然后前进一位继续比较，优化就是加入最大值
/*
void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

 void selSort(vector<int>& nums) {
        for (int i = 0; i < nums.size()/2; ++i) {
            int minIndex = i;
            int maxIndex = i;
            for (int j = i; j < nums.size() - i; ++j) {
                if (nums[minIndex] > nums[j])
                    minIndex = j;
                if (nums[maxIndex] < nums[j])
                    maxIndex = j;
            }
            swap(nums[i], nums[minIndex]);
            // 如果最大值被交换到了最小值的位置，需要更新最大值的索引
            if (maxIndex == i) maxIndex = minIndex;
            swap(nums[nums.size() - i - 1], nums[maxIndex]);
        }
    }


*/

//插入排序 在一个有序数组中，插入剩下的元素
/*
void insSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            int key = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                --j;
            }
            nums[j + 1] = key;
        }
    }
*/

//希尔排序 可以说是升级版的插入排序
/*
void shellSort(vector<int>& nums) {
        int n = nums.size();
        int i, j, inc, key;
        //初始增量：n/2，每一趟之后除以2
        for (inc = n / 2; inc > 0; inc /= 2) {
            //每一趟采用插入排序
            for (i = inc; i < n; ++i) {
                key = nums[i];
                j = i - inc;
                while (j >= 0 && nums[j] > key) {
                    nums[j + inc] = nums[j];
                    j -= inc;
                }
                nums[j + inc] = key;
            }
        }
    }
*/

//选择排序
/*
template<typename T>
void choiceSort(T&a)
{
    for(int i=0;i<a.size();++i)
    {
        int max = i;
        for (int j = i + 1; j < a.size(); ++j)
        {
            if (a[j] > a[max])
            {
                max = j;
            }
        }
        if (max != i)
        {
            int temp = a[i];
            a[i] = a[max];
            a[max] = temp;
        }
    }
}
*/

//双边循环——快速排序
/*
void quickSort(vector<int>& nums,int left,int right) {
		if (left >= right)return;
		int pivot = nums[right];
		int i = left, j = right-1;
		while(i<=j)
		{
			while (i <= j && nums[i] <= pivot)//找到左边比pivot大的
				++i;
			while (i <= j && nums[j] > pivot)//找到右边比pivot小的
				--j;
			if (i < j)//交换两者，升序排序
				swap(nums[i], nums[j]);
		}
		swap(nums[i], nums[right]);//将pivot移动到正确的位置
		quickSort(nums, left, i - 1);
		quickSort(nums, i + 1, right);

	}
*/

//单边循环——快速排序
/*
void quicksort_l(vector<int>&arr, int left,int right)
{
    if (left > right)return;

    int pivot = arr[left];
    int mark = left + 1;

    for (int i = left + 1; i <= right; ++i)
    {
        if (arr[i] < pivot) {
            std::swap(arr[i], arr[mark]);
            ++mark;
        }
    }
    swap(arr[mark-1], arr[left]);
    quicksort_l(arr, left, mark - 2);
    quicksort_l(arr, mark, right);
}
*/

//非递归双边循环——快速排序（将low,high的数据存入到栈中）
/*
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (i < j && arr[j] >= pivot) {
            j--;
        }
        while (i < j && arr[i] <= pivot) {
            i++;
        }
        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[low], arr[i]);
    return i;
}

void quickSortNonRecursive(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    std::stack<int> stack;
    stack.push(left);
    stack.push(right);

    while (!stack.empty()) {
        int high = stack.top();
        stack.pop();
        int low = stack.top();
        stack.pop();

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low) {
            stack.push(low);
            stack.push(pivotIndex - 1);
        }
        if (pivotIndex + 1 < high) {
            stack.push(pivotIndex + 1);
            stack.push(high);
        }
    }
}
*/

//非递归单边循环——快速排序（将low,high的数据存入到栈中）
/*
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int mark = low + 1;

    for (int i = low + 1; i <= high; ++i) {
        if (arr[i] < pivot) {
            std::swap(arr[i], arr[mark]);
            ++mark;
        }
    }
    std::swap(arr[low], arr[mark - 1]);
    return mark - 1;
}

void quickSortNonRecursive(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    std::stack<int> stack;
    stack.push(left);
    stack.push(right);

    while (!stack.empty()) {
        int high = stack.top();
        stack.pop();
        int low = stack.top();
        stack.pop();

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low) {
            stack.push(low);
            stack.push(pivotIndex - 1);
        }
        if (pivotIndex + 1 < high) {
            stack.push(pivotIndex + 1);
            stack.push(high);
        }
    }
}

*/

//堆排序 1
/*
int asd = 0;

class maxheap
{
private:
    vector<int>heap;
    void shiftup(int index)
    {
        while (index > 0 && heap[index] < heap[(index - 1) / 2])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void shiftdown(int index)
    {
        int leftchild, rightchild, large;
        while (index * 2 + 1 < heap.size())
        {
            leftchild = index * 2 + 1;
            rightchild = index * 2 + 2;
            large = index;
            if (leftchild < heap.size() && heap[leftchild] < heap[large])
                large = leftchild;
            if (rightchild < heap.size() && heap[rightchild] < heap[large])
                large = rightchild;
            if (large != index)
            {
                swap(heap[large], heap[index]);
                //large = index;
                index = large;//顺序很重要，需要反复下沉父节点
            }
            else
                break;
        }
    }
public:
    maxheap() = default;
    maxheap(const vector<int>& x) :heap(x) {}
    void insert(int value)
    {
        heap.push_back(value);
        shiftup(heap.size() - 1);
    }

    void delete_heap(int index)
    {
        if (heap.size() == 0)return;
        swap(heap[index], heap[heap.size() - 1]);
        asd = heap[heap.size() - 1];
        heap.pop_back();
        shiftdown(index);
    }
    void sort_heap()
    {
        //heap = num;
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
            shiftdown(i);
    }
    void print_heap()
    {
        for (auto a : heap)
            cout << a << " ";
        cout << endl;
    }
};


int main()
{
    //maxheap maxHeap;
    //maxHeap.insert(10);
    //maxHeap.insert(20);
    //maxHeap.insert(5);
    //maxHeap.insert(30);
    //maxHeap.insert(40);
    //maxHeap.insert(35);
    //maxHeap.insert(80);
    //maxHeap.delete_heap(1);
    vector<int> nums = { 10, 20, 5, 30, 15 };
    vector<int>x;
    maxheap maxHeap(nums);
    maxHeap.sort_heap();
    maxHeap.print_heap();
    cout << endl;
    for(int i=0;i<nums.size();++i)
    {
        maxHeap.delete_heap(0);
        int y = asd;
        x.push_back(y);
    }
    for (auto& a : x)
        cout << a << " ";

    return 0;
}
*/

//堆排序 2
/*
// 向下调整函数
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // 初始化最大值为根节点
    int left = 2 * i + 1; // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点大于根节点
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于目前的最大值
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根节点
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // 递归地调整受影响的子树
        heapify(arr, n, largest);
    }
}

// 堆排序函数
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // 构建初始堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 一个个地从堆中取出元素
    for (int i = n - 1; i > 0; i--) {
        // 将当前根节点与末尾节点交换
        std::swap(arr[0], arr[i]);
        // 调整堆
        heapify(arr, i, 0);
    }
}

// 打印数组
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    heapSort(arr);
    printArray(arr);
    return 0;
}
*/
/*
void shiftdown(vector<int>&heap,int index, int n)
{
    int leftchild, rightchild, large;

    while(index<=n/2-1)
    {
        leftchild = index * 2 + 1;
        rightchild = index * 2 + 2;
        large = index;
        if (leftchild < n && heap[leftchild] > heap[large])
            large = leftchild;
        if (rightchild < n && heap[rightchild] > heap[large])
            large = rightchild;
        if (large != index)
        {
            swap(heap[large], heap[index]);
            //large = index;
            index = large;//顺序很重要，需要反复下沉父节点
            //shiftdown(heap, large, n);
        }
        else
            break;
    }
}

void heapsort(vector<int>& heap)
{
    int n = heap.size();

    for (auto a = n / 2 - 1; a >= 0; --a)
        shiftdown(heap, a, n);

    for (int i = n - 1; i > 0; --i)
    {
        swap(heap[i], heap[0]);
        shiftdown(heap, 0, i);
    }
}

int main()
{
    //maxheap maxHeap;
    //maxHeap.insert(10);
    //maxHeap.insert(20);
    //maxHeap.insert(5);
    //maxHeap.insert(30);
    //maxHeap.insert(40);
    //maxHeap.insert(35);
    //maxHeap.insert(80);
    //maxHeap.delete_heap(1);
    vector<int> nums = { 10, 20, 5, 30, 15 };
    heapsort(nums);
    for (auto& a : nums)
        cout << a << " ";

    return 0;
}
*/

//计数排序最终版
/*
 void countSort(vector<int>& nums, vector<int>& ans) {
		int Min = *min_element(nums.begin(), nums.end());
		int Max = *max_element(nums.begin(), nums.end());
		int d = Max - Min;
		vector<int>count(d + 1, 0);
		//计数数组
		for (auto i : nums)
			++count[i - Min];
		//累计数组
		for (int i = 1; i < count.size(); ++i)
			count[i] += count[i - 1];
		//最终结果
		for (int i = 0; i < nums.size(); ++i) {
			int a = count[nums[i] - Min];
			--count[nums[i] - Min];
			ans[a - 1] = nums[i];
		}
	}
int main()
{
    vector<int>x{ 55,52,58,60,54 };
    vector<int>y(x.size());
    countSort(x, y);
    for (auto i : y)
        cout << i << " ";
    return 0;
}
*/

//桶排序
/*
void bucketSort(vector<int>& arr)
{
    if(arr.empty()) return;
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    //确认桶数量
    int bucketnum = arr.size();
    vector<vector<int>>buckets(bucketnum);

    //分配数据到桶中
    for (int num : arr)
    {
        int bucketindex = (range - 1) / (bucketnum - 1);
        buckets[bucketindex].push_back(num);
    }

    //对每个桶进行排序
    for (auto& num : buckets)
    {
        sort(num.begin(), num.end());
    }

    int index = 0;
    for (const auto& bucket : buckets)
        for (int num : bucket)
            arr[index++] = num;
}

int main()
{
    vector<int> arr = { 4, 2, 2, 8, 3, 3, 1 };
    bucketSort(arr);
    for (auto a : arr)
        cout << a << " ";
    return 0;
}
*/

//求最大公约数
/*
int maxnum1(int a, int b)
{
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    int t = max % min;
    if (t == 0)
        return min;
    else
        maxnum1(min, t);
}

int maxnum2(int a, int b)
{
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    int t = max - min;
    if (t == 0)
        return min;
    else
        maxnum1(min, t);
}

int bestmaxnum(int a, int b)
{
    if (a == b)return a;
    if (a == 0)return b;
    if (b == 0)return a;

    // a 和 b 都是偶数
    if ((a & 1) == 0 && (b & 1) == 0)
        return bestmaxnum(a >> 1, b >> 1) << 1;

    // a 是偶数，b 是奇数
    if ((a & 1) == 0)
        return bestmaxnum(a >> 1, b);

    // a 是奇数，b 是偶数
    if ((b & 1) == 0)
        return bestmaxnum(a, b >> 1);

    // a 和 b 都是奇数，使用更相减损术
    if (a > b)
        return bestmaxnum((a - b) >> 1, b);
    else
        return bestmaxnum((b - a) >> 1, a);
}
*/

//无序数组 最大差值（桶排序思路）
/*
stack<int>tz;

struct Bucket
{
    int minval = INT_MAX;
    int maxval = INT_MIN;
    bool isempty = true;
};

int getMaxSortedDistance(vector<int>& x)
{
    int n = x.size();
    if (n < 2)
        return 0;
    int minval = *min_element(x.begin(), x.end());
    int maxval = *max_element(x.begin(), x.end());

    if (minval == maxval)
        return 0;

    int bucketsize = max(1,(maxval - minval) / (n - 1));//宽度
    int bucketcount = (maxval - minval) / bucketsize + 1;//桶数量

    vector<Bucket>buckets(bucketcount);

    for (int num : x)
    {
        int bucketindex = (num - minval) / bucketsize;//计算元素对应的桶
        buckets[bucketindex].minval = min(buckets[bucketindex].minval, num);
        buckets[bucketindex].maxval = max(buckets[bucketindex].maxval, num);
        buckets[bucketindex].isempty = false;//表示此桶非空
    }

    //计算临界差值
    int preMax = minval;
    int maxGap = 0;
    for (const Bucket& bu : buckets)
    {
        if (bu.isempty)
            continue;
        int t = maxGap;
        maxGap = max(maxGap, bu.minval - preMax);
        if (maxGap != t && maxGap != 0)//记录最大差值是哪两个数字
        {
            if (!tz.empty())
            {
                tz.pop();
                tz.pop();
            }
            tz.push(preMax);
            tz.push(bu.minval);
        }
        preMax = bu.maxval;
    }
    return maxGap;
}

int main()
{
    vector<int>x{2,5,6,1,8,6,9,3,7};
    cout << getMaxSortedDistance(x) << endl;
    int z = tz.top();
    tz.pop();
    int y = tz.top();
    tz.pop();
    cout << z << "-" << y << endl;
    return 0;
}
*/

//栈实现队列操作
/*
class Myqueue
{
private:
    stack<int>getin;
    stack<int>getout;

    void stack_queueOut()
    {
        while (!getin.empty())
        {
            getout.push(getin.top());
            getin.pop();
        }
    }

public:
    void push(int x)
    {
        getin.push(x);
    }

    int pop()
    {
        if (getout.empty())
            stack_queueOut();
        int topElement = getout.top();
        getout.pop();
        return topElement;
    }

    int peek()
    {
        if (getout.empty())
            stack_queueOut();
        return getout.top();
    }

    bool empty()
    {
        return getin.empty() && getout.empty();
    }


};


int main()
{
    Myqueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    cout << q.pop();
    return 0;
}
*/

//字典序算法 寻找在一个整数所包含数字的全部组合中，找到一个大于且仅大于原数的新整数
/*
int findBig(int num)
{
    vector<int>tq;
    while (num != 0)
    {
        int Bit = num % 10;
        tq.push_back(Bit);
        num /= 10;
    }

    int i = 1;
    for (i; i < tq.size(); ++i)
    {
        if(tq[0]>tq[i])
        {
            swap(tq[0], tq[i]);
            break;
        }
    }
    //sort(tq.begin(), tq.begin() + i, [](int a, int b) {return a > b; });
    reverse(tq.begin(), tq.begin() + i);

    int lastnum = 0;
    int flag = 1;
    for (int j = 0; j < tq.size(); ++j)
    {
        lastnum += tq[j] * flag;
        flag *= 10;
    }
    return lastnum;
}


int main()
{
    cout<<findBig(13452);
    return 0;
}
*/

//贪心算法 给出一个整数，从该整数中去掉k个数字，要求剩下的数字形成的新整数尽可能小
/*
string findsmall(string num, int del)
{
    int newlength = num.length() - del;
    if (newlength <= 0) return "0";

    stack<char> x;
    for (char c : num) {
        while (!x.empty() && x.top() > c && del > 0) {
            x.pop();
            --del;
        }
        x.push(c);
    }

    // 如果还有剩余的删除次数，继续从栈顶删除
    while (del > 0) {
        x.pop();
        --del;
    }

    string newnum;
    while (!x.empty()) {
        newnum.push_back(x.top());
        x.pop();
    }
    reverse(newnum.begin(), newnum.end());

    // 去掉前导零
    size_t startpos = newnum.find_first_not_of('0');
    if (string::npos != startpos) {
        newnum = newnum.substr(startpos);
    }
    else {
        newnum = "0";
    }

    return newnum;
}


int main()
{
    string num{ "541270936" };
    cin >> num;
    cout << findsmall(num, 3);
    return 0;
}
*/

//特大整数相加 两个数组
//1.比较笨的方法
/*
string bigNumSum(string bigA, string bigB)
{
    int maxnum = max(bigA.length(), bigB.length());

    vector<int>x, y;
    for (int i = 0; i < bigA.length(); ++i)
        x.push_back(bigA[bigA.length() - i - 1] - '0');
    for (int i = 0; i <= maxnum - bigA.length(); ++i)
        x.push_back(0);
    for (int i = 0; i < bigB.length(); ++i)
        y.push_back(bigB[bigB.length() - i - 1] - '0');
    for (int i = 0; i <= maxnum - bigB.length(); ++i)
        y.push_back(0);

    //vector<int>z(x.size(), 0);
    string z(x.size(), '0');
    for (int i = 0; i < x.size() - 1; ++i)
    {
        z[i] += (x[i] + y[i]) % 10;
        z[i + 1] += (x[i] + y[i]) / 10;
    }

    reverse(z.begin(), z.end());
    size_t startpos = z.find_first_not_of('0');
    if (string::npos != startpos)
        z = z.substr(startpos);
    else
        z = "0";
    return z;
}

int main()
{
    string num{ "5411111111211" };
    string num1{ "1231111114" };
    cout << bigNumSum(num, num1);
    return 0;
}
*/
//2.优化的方法
/*
string bigNumSum(string bigA, string bigB) {
    int lenA = bigA.length();
    int lenB = bigB.length();
    int maxLen = max(lenA, lenB);

    // 结果字符串，长度为 maxLen + 1 以处理可能的进位
    string result(maxLen + 1, '0');

    int carry = 0;
    for (int i = 0; i < maxLen; ++i) {
        int digitA = (i < lenA) ? (bigA[lenA - 1 - i] - '0') : 0;
        int digitB = (i < lenB) ? (bigB[lenB - 1 - i] - '0') : 0;
        int sum = digitA + digitB + carry;
        result[maxLen - i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // 处理最高位的进位
    if (carry > 0) {
        result[0] = carry + '0';
    } else {
        result.erase(result.begin()); // 去掉多余的最高位
    }

    // 去掉前导零
    size_t startpos = result.find_first_not_of('0');
    if (string::npos != startpos) {
        result = result.substr(startpos);
    } else {
        result = "0";
    }

    return result;
}

int main() {
    string num{ "5411111111211" };
    string num1{ "1231111114" };
    cout << bigNumSum(num, num1) << endl;
    return 0;
}
*/

//二叉搜索树转换为双向链表，通过中序遍历的思维进行
/*
// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 辅助函数：将 BST 转换为排序的双向链表
void convertBSTToDoublyList(TreeNode* root, TreeNode*& head, TreeNode*& prev) //通过中序遍历的思维进行
{
    if (!root) return;

    // 递归处理左子树
    convertBSTToDoublyList(root->left, head, prev);

    // 处理当前节点
    if (!head) {
        head = root; // 初始化链表头
    }
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    // 递归处理右子树
    convertBSTToDoublyList(root->right, head, prev);
}

// 主函数：调用辅助函数并返回链表头节点
TreeNode* convertBSTToDoublyList(TreeNode* root) {
    TreeNode* head = NULL;
    TreeNode* prev = NULL;
    convertBSTToDoublyList(root, head, prev);
    return head;
}

// 测试函数
int main() {
    // 构建示例二叉搜索树
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* head = convertBSTToDoublyList(root);

    // 输出双向链表
    TreeNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}
*/

//金矿问题 动态规划
/*
int moreGod(int godnum, int Mannum, vector<int>& needMan, vector<int>& haveGod)
{
    vector<vector<int>>bom(godnum + 1, vector<int>(Mannum + 1));//保证行和列为0的位置都是0
    for (int i = 1; i <= godnum; ++i)
    {
        for (int j = 1; j <= Mannum; ++j)
        {
            if (j < needMan[i-1])
                bom[i][j] = bom[i - 1][j];//保证有0可以赋值
            else
                bom[i][j] = max(bom[i - 1][j], bom[i - 1][j - needMan[i-1]] + haveGod[i-1]);
        }
    }
    int Maxgod = bom[godnum][Mannum];
    return Maxgod;
}

int bestMoreGod(int godnum, int Mannum, vector<int>& needMan, vector<int>& haveGod)
{
    vector<int>bom(Mannum + 1, 0);
    for (int i = 1; i <= godnum; ++i)
    {
        for (int j = Mannum; j >= 1; --j)//需要改成从后到前，否则会导致最后几位值计算错误
        {
            if (j >= needMan[i - 1])//触发方式修改，提高效率
                bom[j] = max(bom[j], bom[j - needMan[i - 1]] + haveGod[i - 1]);
        }
    }
    return bom[Mannum];
}

// 测试函数
int main()
{
    vector<int>needMan{ 5,5,3,4,3 };
    vector<int>haveGod{ 400,500,200,300,350 };
    int godnum = 5, Mannum = 10;
    int i = bestMoreGod(godnum, Mannum, needMan, haveGod);
    cout << i;
    return 0;
}
*/

//矩阵的最小路径和 动态规划
/*
int minPathSum(vector<vector<int> >& matrix) {
    //write code here
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int> > dp(col, vector<int>(row,0));
    dp[0][0] = matrix[0][0];

    for (int i = 1; i < row; ++i)//初始化第一行
        dp[0][i] = dp[0][i - 1] + matrix[0][i];

    for (int i = 1; i < col; ++i)//初始化第一列
        dp[i][0] = dp[i-1][0] + matrix[i][0];

    for(int i=1;i<row;++i)
        for (int j = 1; j < col; ++j)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
        }
    return dp[row - 1][col - 1];
}

int minPathSum1(vector<vector<int> >& matrix) //优化为一维数组
{
    // write code here
    int row = matrix.size();
    int col = matrix[0].size();
    //vector<vector<int> > dp(col, vector<int>(row, 0));
    vector<int>dp(row, 0);
    dp[0] = matrix[0][0];

    for (int i = 1; i < col; ++i)//初始化第一行
        dp[i] = dp[i - 1] + matrix[0][i];

    for (int i = 1; i < row; ++i)
        for (int j = 0; j < col; ++j)
        {
            int left = INT_MAX;//从左到达该点
            int up = dp[j];//从上到达该点
            if (j > 0)
                left = dp[j - 1];
            dp[j] = min(left,up) + matrix[i][j];
        }
    return dp[col - 1];
}

int minPathSum3(vector<vector<int> >& matrix) {//更优秀的方法，直接在原数组上进行修改
        // write code here

        int rowls = matrix.size();
        int cols = matrix[0].size();

        for (int i =0;i< rowls;i++)
        {
            for(int j=0;j< cols;j++)
            {
                if (i==0 && j>0)
                    matrix[i][j] =  matrix[i][j] + matrix[i][j - 1];
                else if (j == 0 && i> 0)
                {
                    matrix[i][j] =  matrix[i -1][j] + matrix[i][j];
                }
                else{
                    if (i ==0 && j==0) continue;
                    int min_v = matrix[i][j-1] > matrix[i-1][j]?matrix[i-1][j]:matrix[i][j-1];
                    matrix[i][j] = matrix[i][j] + min_v;
                }
            }
        }

        return matrix[rowls -1][cols-1];
    }

// 测试函数
int main()
{
    vector<vector<int>> grid = {
        {1, 3, 5, 9},
        {8, 1, 3, 4},
        {5, 0, 6, 1},
        {8, 8, 4, 0}
    };

    cout << "最小路径和: " << minPathSum1(grid) << endl;
    return 0;
}
*/

//字符串判断单词，添加空格  动态规划
/*
vector<int> wordBreak(string st, unordered_set<string>& dict)
{
    int begin = 0, end = 0;
    string word;
    vector<int>words(st.size() + 1, 0);
    words[0] = true;
    int t = 0;

    for (int i = 1; i < st.size() + 1; ++i)
    {
        words[i] = false;
        for (end = 0; end < st.size(); ++end)
        {
            begin = t;
            for (begin; begin < end; ++begin)
            {
                string test = st.substr(begin, end - begin + 1);
                if (words[begin] && dict.find(test) != dict.end())
                {
                    words[end + 1] = true;//标记空格位置
                    break;
                    t = end + 1;
                }
            }
        }
    }
    return words;
}

int main()
{
    unordered_set<string>dict{ "fuck","you","apple","pie" };
    string s{ "appleapplepiefuckyou" };
    vector<int> i = wordBreak(s, dict);
    int t = 0;
    for (int x = 1; x < i.size()-1; ++x)
    {
        if (i[x] == 1)
        {
            s.insert(x + t, " ");
            ++t;
        }
    }
    cout << s << endl;
    return 0;
}
*/

//寻找质数  动态规划
/*
int GetNthPrime(int n)
{
    vector<int>x{ 1,2 };
    int number = 3;
    while (x.size() != n)
    {
        bool flag = true;
        for (auto it = x.begin() + 1; it != x.end() && (*it) * (*it) <= number; ++it)
        {
            if (number % (*it) == 0)
                flag = false;
        }
        if (flag)
            x.push_back(number);
        number += 2;
    }
    return *(x.rbegin());
}
*/

//回文 dp
/*
void huiwen(string s)
{
	n=s.size();
		vector<vector<bool>>dp(n,vector<bool>(n,false));
		for(int i=0;i<n;++i)
			dp[i][i]=true;
		for(int i=0;i<n-1;++i){
			if(s[i]==s[i+1])
				dp[i][i+1]=true;
		}
		for(int len=3;len<=n;++len){
			for(int i=0;i<=n-len;++i){
				int j=i+len-1;
				if(s[i]==s[j]&&dp[i+1][j-1])
					dp[i][j]=true;
			}
		}
}

*/

//二分查找
/*
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {//这种要考虑区间为[l,r)还是[l,r]
        int mid = left + (right - left) / 2;//为了避免直接使用 (left + right) / 2 可能带来的整数溢出问题
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            left = mid + 1; //这样可以确保不会重复检查 mid 位置
        }
        else {
            right = mid - 1;//这样可以确保不会重复检查 mid 位置
        }
    }
    return -1;
}
*/

//图：DFS和BFS
/*
#define MaxVertex 8
using E = char;

struct Node//节点和头节点分开定义，普通节点记录邻接顶点信息
{
    int nextVertex;
    struct Node* next;
};
using Tnode = Node*;

struct HeadNode//头节点记录元素
{
    E element;
    struct Node* next;
};

struct AdjacencyGraph
{
    int vertexCount;//顶点数
    int edgeCount;//边数
    struct HeadNode vertex[MaxVertex];

    AdjacencyGraph() :vertexCount(0), edgeCount(0) {}

    void addVertex(E element)
    {
        vertex[vertexCount].element = element;
        vertex[vertexCount].next = nullptr;
        ++vertexCount;
    }

    void addEdge(int a, int b)
    {
        Tnode node = vertex[a].next;
        Tnode newNode = new Node;
        newNode->next = nullptr;
        newNode->nextVertex = b;
        if (!node)
            vertex[a].next = newNode;
        else
        {
            while (true)
            {
                if (node->nextVertex == b) { delete newNode; return; }//如果已经连接了对应的顶点，释放内存返回
                if (node->next)node = node->next;//否则继续往后遍历
                else break;//没有下一个直接结束
            }
            node->next = newNode;
        }
        ++edgeCount;
    }


};
using Graph = AdjacencyGraph*;

void printGraph(Graph graph)
{
    for (int i = 0; i < graph->vertexCount; ++i)
    {
        cout << i << "  " << graph->vertex[i].element;
        Tnode node = graph->vertex[i].next;
        while (node) {
            cout << " -> " << node->nextVertex;
            node = node->next;
        }
        cout << endl;
    }
}
 

bool dfs(Graph graph, int startVertex, int targetVertex, vector<int> visited) {
    visited[startVertex] = 1;   //走过之后一定记得mark一下
    //printf("%c -> ", graph->vertex[startVertex].element);   //打印当前顶点值
    cout << graph->vertex[startVertex].element << " -> ";
    if (startVertex == targetVertex)return true;
    Tnode node = graph->vertex[startVertex].next;   //遍历当前顶点所有的分支
    while (node) {
        if (!visited[node->nextVertex])   //如果已经到过（有可能是走其他分支到过，或是回头路）那就不继续了
            if(dfs(graph, node->nextVertex, targetVertex, visited))//没到过就继续往下走，这里将startVertex设定为对于分支的下一个顶点，按照同样的方式去寻找
                return true;
        node = node->next;
    }
    return false;
}

queue<int>x;
bool bfs(Graph graph, int startVertex, int targetVertex, vector<int>visited)
{
    x.push(startVertex);
    visited[startVertex] = 1;
    cout << graph->vertex[startVertex].element << " -> ";
    Tnode newNode = graph->vertex[startVertex].next;
    while(!x.empty())
    {
        while (newNode)
        {
            if (!visited[newNode->nextVertex])
            {
                int flag = newNode->nextVertex;
                x.push(flag);
                visited[flag] = 1;
                cout << graph->vertex[flag].element << " -> ";
            }
            newNode = newNode->next;
        }
        x.pop();
        if (!x.empty())
            newNode = graph->vertex[x.front()].next;
        if (visited[targetVertex] == 1)
        {
            cout << endl;
            return true;
        }
    }
    cout << endl;
    return false;
}



// 测试函数
int main()
{
    Graph graph = new AdjacencyGraph;
    for (int c = 'A'; c <= 'G'; ++c)
        graph->addVertex((char)c);
    graph->addEdge(0, 1);//a->b
    graph->addEdge(1, 4);//b->c
    graph->addEdge(1, 3);//c->d
    graph->addEdge(1, 2);//c->e
    graph->addEdge(4, 5);//c->f
    printGraph(graph);
    cout << endl;
    vector<int>arr(graph->vertexCount, 0);
    cout<<bfs(graph, 0, 6, arr);
    return 0;
}
*/

//滑动窗口模板，确保left指针和right指针不相同（相当于求两个相同字符之间的距离）注意移动右为终点
/*
//外层循环扩展右边界，内层循环扩展左边界
for (int l = 0, r = 0 ; r < n ; r++) {
    //当前考虑的元素
    while (l <= r && check()) {//区间[left,right]不符合题意
        //扩展左边界
    }
    //区间[left,right]符合题意，统计相关信息
}
*/

