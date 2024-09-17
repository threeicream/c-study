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
稳定排序；如果值相同的元素在排序后打乱了排序前的顺序，则这样的排序算法是不稳定排序。

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
9.贪心算法 依次求得局部最优解，最终得到全局最优解  给出一个整数，从该整数中去掉k个数字，要求剩下的数字形成的新整数尽可能小
10.最大整数相加 创建两个数组，数组存入后进行加法
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
void rememberNumSort(vector<int>& x, vector<int>& y)
{
    int max = x[0];
    int min = x[0];
    for (auto a = 1; a < x.size(); ++a)
    {
        if (x[a] > max)
            max = x[a];
        if (x[a] < min)
            min = x[a];
    }
    int d = max - min;
    //int* com = new int[d+1];
    vector<int>com(d+1,0);
    for (auto& flag : x)
    {
        ++com[flag - min];
    }
    for (auto i = 0; i < d; ++i)
    {
        com[i + 1] += com[i];
    }

    for (auto i = 0; i < x.size(); ++i)
    {
        int c = com[x[i] - min];
        y[c-1] = x[i];
    }
}
int main()
{
    vector<int>x{ 55,52,58,60,54 };
    vector<int>y(x.size());
    rememberNumSort(x, y);
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

