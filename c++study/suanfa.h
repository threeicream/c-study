/*
��̬�滮��1.��ٷ�->2.���仯����/��֦->3.dp������ʽ
0/1��������
�����n����Ʒ������Ϊv�ı�����ÿ����Ʒֻ����һ�Σ���i����Ʒ�ļ�ֵΪvi�����Ϊwi����⽫��Щ��Ʒװ�뱳������ʹ��Щ��Ʒ��������������������������ܼ�ֵ����������ֵ��
�ⷨ��
1.���װ���µ�ǰ��Ʒ����ôǰn����Ʒ�������Ϻ�ǰn-1����Ʒ����������һ����
2.���װ���µ�ǰ��Ʒ
2.1װ��ǰ����Ʒ���ڸ���ǰ��ƷԤ������Ӧ�ռ������£�ǰn-1����Ʒ�������ϼ��ϵ�ǰ��Ʒ�ļ�ֵ�����ܼ�ֵ
2.2��װ��ǰ��Ʒ����ôǰn����Ʒ�������Ϻ�ǰn-1����Ʒ����������һ����
ѡȡ2.1��2.2�нϴ�ļ�ֵ����Ϊ��ǰ�����ϵļ�ֵ
��������
���֪����ֵ�����֪������װ����Щ��Ʒ
�ⷨ��
�ӱ�����½ǿ�ʼ���ݣ��������ǰn����Ʒ�������ϵļ�ֵ��ǰn-1����Ʒ�����ϵļ�ֵһ����˵����n����Ʒû�б�װ��
���򣬵�n����Ʒ��װ��

�������⣺
��һ�����飬ѡ�����е����������Ľ��

�����㷨�û���
1.�ռ临�Ӷ�
2.ʱ�临�Ӷ�
�㷨Ӧ�ã�
1.���ң�2.����3.���㣻4.���ž���
����Ƶ�ʱ�临�Ӷȣ�
1.��������Ϊ1
2.ֻ����ʱ�亯���е���߽���
3.����߽�����ڣ���ʡȥ��߽���ǰ���ϵ��
O(1)<)(logn)<O(n)<O(n^2)
����Ƶ��ռ临�Ӷȣ�
1.�㷨�洢�ռ��С�̶����������ģ��ֱ�ӹ�ϵ��O(1)
void fun1(int n){int var = 3;}
2.�㷨����ռ���һ�����Լ��ϣ������飩�����Ҽ��ϴ�С�������ģn�����ȣ�O(n)
void fun2(int n){int[] array = new int[n];}
3.�㷨����ռ���һ����ά���鼯�ϣ����Ҽ��ϳ��ȿ�ȶ��������ģn�����ȣ�O(n^2)
void fun3(int n){ int[][] matrix = new int[n][n];}
3.����Ϊ�ݹ麯������Ȼû����ʽ�������������߼��ϣ����ǻ����ڴ�洢����������ջ������������ջ������ջ�ͽ�ջ������Ϊ
void fun4(int n){if(n<=1){return;} fun4(n-1);}
���ݹ����Ϊn��O(n)
ʱ����ռ��ȡ��

�����㷨��
ʱ�临�Ӷ�O(n^2):ð������ѡ�����򡢲�������ϣ�����򣨽���O(nlogn)��O(N^2)֮�䣩
ʱ�临�Ӷ�O(nlogn):�������򡢹鲢���򡢶�����
ʱ�临�Ӷ�Ϊ���ԣ���������Ͱ���򡢻�������
�����㷨�����Ը������ȶ��ԣ�����Ϊ�ȶ�����Ͳ��ȶ�����
�����ֵ��ͬ��Ԫ�����������Ȼ����������ǰ��˳���������������㷨��
�ȶ��������ֵ��ͬ��Ԫ������������������ǰ��˳���������������㷨�ǲ��ȶ�����

ð������ʵ���Լ��Ż���
1.ʹ������forѭ����ʹÿ��Ԫ�ض�������Ԫ�ؽ��д�С�Ƚ�
2.�����־λ���жϺ����Ƿ���ֵ��������û������ת������ѭ��
3.��¼���һ�ν�����λ�ã�ÿ�αȽϵ����λ�ã������Ԫ�ؾͲ����бȽϣ���Լʱ��
��β������ð������������棬˫��ð������
������̾����Ӱ�һ������1�ִ����ң���2�ִ��ҵ��󣬵�3���ٴ�����

��������
ð�ݵ������棬ʹ���˷��η�
��ÿһ����ѡһ����׼Ԫ�أ����������������Ԫ���ƶ�������һ�ߣ�����С��Ԫ���ƶ������е���һ�ߣ��Ӷ������в����������֡�
ʵ�ַ��η��ķ�����
1.����ѭ����
2.˫��ѭ����
˫��ѭ�����Ļ�������
ѡ���׼Ԫ��: ͨ��ѡ������ĵ�һ��Ԫ����Ϊ��׼Ԫ�أ�pivot����
��ʼ������ָ��: ��ָ�루left�����������ʼλ�ÿ�ʼ����ָ�루right���������ĩβλ�ÿ�ʼ��
�ƶ���ָ��: ���������ƶ���ָ�룬ֱ���ҵ�һ��С�ڻ�׼Ԫ�ص�Ԫ�ء�
�ƶ���ָ��: ���������ƶ���ָ�룬ֱ���ҵ�һ�����ڻ�׼Ԫ�ص�Ԫ�ء�
����Ԫ��: ������ָ�����ָ��ָ���Ԫ�ء�
�ظ�����3-5: ֱ����ָ�����ָ��������
������׼Ԫ��: ����׼Ԫ������ָ�����ָ������λ�õ�Ԫ�ؽ�����
�ݹ�����: �Ի�׼Ԫ�����������������ݹ�����������衣

����ѭ��������һ����markָ������1λ����ΪС��pivot������߽�������1��
�ڶ��������±�������Ԫ�غ�markָ������λ�õ�Ԫ�ؽ���λ�ã���Ϊ���±�����Ԫ�ع�����С��pivot������

ʹ�÷ǵݹ鷽ʽʵ�ֿ�������ջ

������
1���ö����ʵ�֣���ɾ������ֵ���뵽��һ��vector������
1������ʼ��: ������������鹹���һ���󶥶ѣ���С���ѣ���
2�����Ѷ�Ԫ����ĩβԪ��: ���Ѷ�Ԫ�أ����ֵ����Сֵ����ĩβԪ�ؽ�������ʱĩβԪ�ؾ�Ϊ���ֵ������Сֵ����
3������: ��ʣ���Ԫ�����µ���Ϊ�󶥶ѣ���С���ѣ���
4�ظ�����2�Ͳ���3: ֱ��������������

��������
���������㷨�����������±���ȷ��Ԫ�ص���ȷλ��
ÿһ���±�λ�õ�ֵ���������ж�Ӧ�������ֵĴ���
ֱ�ӱ������飬�������Ԫ�ص��±�ֵ��Ԫ�ص�ֵ�Ǽ������������

Ͱ����
ÿһ��Ͱ��bucket������һ�����䷶Χ��������Գ���һ������Ԫ��



���⣺
1.����ж�һ�������Ƿ��л�
�ٱ�������ÿ����һ���ڵ㣬�ͽ�����֮ǰ�����нڵ����Ƚϣ�ʱ��O(n^2),�ռ�O(1)
�ڽ�����ϣ��ÿ����һ���ڵ㣬�ͽ������ϣ��Ľڵ���бȽϣ�ʱ��O(n),�ռ�O(n)
��׷��������������ָ��p1��p2��ͬʱָ��ͷ�ڵ㣬p1һ���ƶ�1���ڵ㣬p2һ���ƶ�2�����㣬�Ƚ�����ָ���Ƿ���ͬ��һֱ��β�ڵ㣬���������
2.���������ĳ���
3.�������뻷�ڵ�
4.���������Լ����
շת����� 10��25��25����10��2��5����ô10��25�����Լ������ͬ��10��5�����Լ��
��������� 10��25��25��10�Ĳ���15����ô10��25�����Լ������ͬ��10��15�����Լ��
���������+��λ���� ͨ����λ�����ݶ�ת��Ϊ������Ȼ����ø��������
5.�������Ƿ���2���������ݣ���2����������ת���ɶ��������������λΪ1������Ϊ0��n&(n-1)
6.�����������������������Ԫ�ص�����ֵ��ʹ��Ͱ�����˼·��
7.�����ջʵ�ֶ��в���������ջ��һ���룬һ������
8.�ֵ����㷨 Ѱ����һ���������������ֵ�ȫ������У��ҵ�һ�������ҽ�����ԭ����������
9.̰���㷨 ������þֲ����Ž⣬���յõ�ȫ�����Ž�  ����һ���������Ӹ�������ȥ��k�����֣�Ҫ��ʣ�µ������γɵ�������������С
10.���������� �����������飬����������мӷ�
*/

//ð������
/*

void sort_array(int array[],int length)
{
    //��¼���һ�ν���λ��
    int lastChange = 0;
    //��¼�߾�
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
                //�н�������flag��Ϊfalse
                flag = false;
                lastChange = b;
            }
        }
        //���һ�ν�����λ�ø����߽磬�˺��Ԫ�ز��ٱȽ�
        sortloca = lastChange;
        if (flag == true)
            break;
    }
}
*/

//��β������,ʹ�������ֿ���forѭ��
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

//ѡ������
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

//˫��ѭ��������������
/*
void quickSort(vector<int>& arr, int left, int right)
{
    if (left > right)return;
    int pivot = arr[left];
    int i = left;
    int j = right;
    while (i < j)
    {
        while (i < j && arr[j] >= pivot)//�����������󣬷������׽�����ѭ��
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

//����ѭ��������������
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

//�ǵݹ�˫��ѭ�������������򣨽�low,high�����ݴ��뵽ջ�У�
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

//�ǵݹ鵥��ѭ�������������򣨽�low,high�����ݴ��뵽ջ�У�
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

//������ 1
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
                index = large;//˳�����Ҫ����Ҫ�����³����ڵ�
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

//������ 2
/*
// ���µ�������
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // ��ʼ�����ֵΪ���ڵ�
    int left = 2 * i + 1; // ���ӽڵ�
    int right = 2 * i + 2; // ���ӽڵ�

    // ������ӽڵ���ڸ��ڵ�
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // ������ӽڵ����Ŀǰ�����ֵ
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // ������ֵ���Ǹ��ڵ�
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // �ݹ�ص�����Ӱ�������
        heapify(arr, n, largest);
    }
}

// ��������
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // ������ʼ��
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // һ�����شӶ���ȡ��Ԫ��
    for (int i = n - 1; i > 0; i--) {
        // ����ǰ���ڵ���ĩβ�ڵ㽻��
        std::swap(arr[0], arr[i]);
        // ������
        heapify(arr, i, 0);
    }
}

// ��ӡ����
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
            index = large;//˳�����Ҫ����Ҫ�����³����ڵ�
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

//�����������հ�
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

//Ͱ����
/*
void bucketSort(vector<int>& arr)
{
    if(arr.empty()) return;
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    //ȷ��Ͱ����
    int bucketnum = arr.size();
    vector<vector<int>>buckets(bucketnum);

    //�������ݵ�Ͱ��
    for (int num : arr)
    {
        int bucketindex = (range - 1) / (bucketnum - 1);
        buckets[bucketindex].push_back(num);
    }

    //��ÿ��Ͱ��������
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

//�����Լ��
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

    // a �� b ����ż��
    if ((a & 1) == 0 && (b & 1) == 0)
        return bestmaxnum(a >> 1, b >> 1) << 1;

    // a ��ż����b ������
    if ((a & 1) == 0)
        return bestmaxnum(a >> 1, b);

    // a ��������b ��ż��
    if ((b & 1) == 0)
        return bestmaxnum(a, b >> 1);

    // a �� b ����������ʹ�ø��������
    if (a > b)
        return bestmaxnum((a - b) >> 1, b);
    else
        return bestmaxnum((b - a) >> 1, a);
}
*/

//�������� ����ֵ��Ͱ����˼·��
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

    int bucketsize = max(1,(maxval - minval) / (n - 1));//���
    int bucketcount = (maxval - minval) / bucketsize + 1;//Ͱ����

    vector<Bucket>buckets(bucketcount);

    for (int num : x)
    {
        int bucketindex = (num - minval) / bucketsize;//����Ԫ�ض�Ӧ��Ͱ
        buckets[bucketindex].minval = min(buckets[bucketindex].minval, num);
        buckets[bucketindex].maxval = max(buckets[bucketindex].maxval, num);
        buckets[bucketindex].isempty = false;//��ʾ��Ͱ�ǿ�
    }

    //�����ٽ��ֵ
    int preMax = minval;
    int maxGap = 0;
    for (const Bucket& bu : buckets)
    {
        if (bu.isempty)
            continue;
        int t = maxGap;
        maxGap = max(maxGap, bu.minval - preMax);
        if (maxGap != t && maxGap != 0)//��¼����ֵ������������
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

//ջʵ�ֶ��в���
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

//�ֵ����㷨 Ѱ����һ���������������ֵ�ȫ������У��ҵ�һ�������ҽ�����ԭ����������
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

//̰���㷨 ����һ���������Ӹ�������ȥ��k�����֣�Ҫ��ʣ�µ������γɵ�������������С
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

    // �������ʣ���ɾ��������������ջ��ɾ��
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

    // ȥ��ǰ����
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

//�ش�������� ��������
//1.�Ƚϱ��ķ���
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
//2.�Ż��ķ���
/*
string bigNumSum(string bigA, string bigB) {
    int lenA = bigA.length();
    int lenB = bigB.length();
    int maxLen = max(lenA, lenB);

    // ����ַ���������Ϊ maxLen + 1 �Դ�����ܵĽ�λ
    string result(maxLen + 1, '0');

    int carry = 0;
    for (int i = 0; i < maxLen; ++i) {
        int digitA = (i < lenA) ? (bigA[lenA - 1 - i] - '0') : 0;
        int digitB = (i < lenB) ? (bigB[lenB - 1 - i] - '0') : 0;
        int sum = digitA + digitB + carry;
        result[maxLen - i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // �������λ�Ľ�λ
    if (carry > 0) {
        result[0] = carry + '0';
    } else {
        result.erase(result.begin()); // ȥ����������λ
    }

    // ȥ��ǰ����
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

