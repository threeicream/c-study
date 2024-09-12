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

排序算法：
时间复杂度O(n^2):冒泡排序、选择排序、插入排序、希尔排序（介于O(nlogn)和O(N^2)之间）
时间复杂度O(nlogn):快速排序、归并排序、堆排序
时间复杂度为线性：计数排序、桶排序、基数排序
排序算法还可以根据其稳定性，划分为稳定排序和不稳定排序。
即如果值相同的元素在排序后仍然保持着排序前的顺序，则这样的排序算法是
稳定排序；如果值相同的元素在排序后打乱了排序前的顺序，则这样的排序算法是
不稳定排序。

冒泡排序实现以及优化：
1.使用两段for循环，使每个元素都与后面的元素进行大小比较
2.加入标志位，判断后续是否还有值交换，若没有则跳转出二次循环
3.记录最后一次交换的位置，每次比较到这个位置，后面的元素就不进行比较，节约时间
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

//双边循环——快速排序
/*
void quickSort(vector<int>& arr, int left, int right)
{
    if (left > right)return;
    int pivot = arr[left];
    int i = left;
    int j = right;
    while (i < j)
    {
        while (i < j && arr[j] >= pivot)//先找右再找左，否则容易进入死循环
        {
            --j;
        }

        while (i < j && arr[i] <= pivot)
        {
            ++i;
        }

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[left]);
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
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