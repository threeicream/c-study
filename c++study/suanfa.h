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
�ȶ��������ֵ��ͬ��Ԫ������������������ǰ��˳���������������㷨��
���ȶ�����

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