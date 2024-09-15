/*
组成方式：
1.线性结构：数组、链表、栈、队列、哈希表
2.树：二叉树、二叉堆
3.图：多对多关联
4.其他：跳表、哈希链表、位图等

数组的结构：存储方式为顺序存储，在连续内存中存储数据
数组基本操作：
1.读取元素 O(1) 根据下标查询
2.更新元素 O(1)
3.插入元素 O(n) 头部插入、尾部插入、中间插入
4.删除元素 O(n) 头部删除、尾部删除、中间删除
数组的优势和劣势：
随机访问能力强，有下标就可以快速找到对应元素，二分法即是使用此优势
插入、删除元素耗时多，所以其适合读操作多、写操作少的场景

链表的结构：一部分为存放数据的变量data，另一部分是指向下一节点的指针next，存储方式为随机存储
双向链表的结构：多了个指向前置节点的prev指针
链表的基本操作：
1.查找结点： O(n) 从头节点逐一查找 
2.更新节点： O(1) 不考虑查找节点，直接更新
3.插入节点： O(1) 头部插入、尾部插入、中间插入
4.删除元素： O(1) 头部删除、尾部删除、中间删除
链表的优势：
适合读操作少、写操作多的场景

逻辑结构：物理实现依赖物理结构
1.线性结构：顺序表、栈、队列
2.非线性结构：树、图
物理结构：
1.顺序存储结构：数组
2.链式存储结构：链表

栈的定义：
FILO，元素先入后出。最早进入的元素存放位置叫栈底bottom，最后进入的元素存放位置叫栈顶top
栈的基本操作：
1.入栈push O(1) 新元素放入栈
2.出栈pop  O(1) 新元素弹出栈

队列的定义：
FIFO，元素先入先出。队列的出口端叫作队头（front），队列的入口端叫作队尾（rear）
队列的基本操作：
1.入队enqueue O(1) 队尾放入元素
2.出队dequeue O(1) 队头弹出元素

散列表（哈希表）：其实就是c++中的关联容器map ，由键key和值value共同组成，通过key来查找匹配的value
哈希表的操作：
1.写操作put  将key存入到数组中
由于数组长度有限，容易发生哈希冲突（不同的key存入到数组同一位置），通过其他方式解决问题
1.1开放寻址法：冲突的key向后移动一位，查找是否有空
1.2链表法：数组的每个位置都是链表的头节点，将冲突的key插入到对应的链表中
2.读操作get 对数组进行逐个查询
3.扩容resize 数据过多就需要 
3.1先创建一个新数组，是原数组的两倍长度，遍历原数组，将key重新映射到新数组上

树：家谱、职级关系 定义为：树（tree）是n（n≥0）个节点的有限集。当n=0时，称为空树。
非空树的特点：
1. 有且仅有一个特定的称为根的节点。
2. 当n>1时，其余节点可分为m（m>0）个互不相交的有限集，每一个集合本身又是一个树，并称为根的子树。
二叉树定义：每个阶段最多有2个孩子节点
二叉树还有两种特殊形式，一个叫作满二叉树，另一个叫作完全二叉树
简单点说，满二叉树的每一个分支都是满的                 高度h与节点数量n的关系：h=log(n+1) 需要用到等比数列求和公式
完全二叉树只需保证最后一个节点之前的节点都齐全即可     高度h与节点数量n的关系：h=log(n)+1
二叉树表达方式：
1. 链式存储结构 一个data，一个左指针，一个右指针
2. 数组  使用数组存储时，会按照层级顺序把二叉树的节点放到数组中对应的位置上。如果某一个节点的左孩子或右孩子空缺，则数组的相应位置也空出来
稀疏的二叉树不适合用数组表示，空间浪费
二叉树的功能：
1.查找  二叉查找树：左子树上所有节点的值均小于根节点的值 右子树上所有节点的值均大于根节点的值 O(logn)
二叉树的遍历方式：
1.前序遍历 深度优先 O(n) O(n) O(n)
2.中序遍历 深度优先 O(n) O(n) O(n)
3.后序遍历 深度优先 O(n) O(n) O(n)
4.层序遍历 广度优先 O(n) O(n) O(n)
深度优先：
1.前序优先：二叉树的前序遍历，输出顺序是根节点、左子树、右子树
2.中序遍历：二叉树的中序遍历，输出顺序是左子树、根节点、右子树
3.后序遍历：二叉树的后序遍历，输出顺序是左子树、右子树、根节点
可以通过递归、栈实现
广度优先：
4.层次遍历：先在各个方向上各走出1步，再在各个方向上走出第2步、第3步……一直到各个方向全部走完
可以通过队列实现

二叉堆：是一种完全二叉树，分为两个类型(通过数组实现)
1.最大堆：任何一个父节点的值，都>=它左、右孩子节点的值
2.最小堆：任何一个父节点的值，都<=它左、右孩子节点的值
二叉堆的根节点叫做堆顶
二叉堆的操作：完全二叉树的高度为logn
1.插入节点 插入后数据后根据是最大堆还是最小堆数据进行上浮 O(logn)
2.删除节点 删除数据后将最后一个节点放到堆顶数据进行下沉 O(logn)
3.构建二叉堆 也就是把一个无序的完全二叉树调整为二叉堆，本质就是让所有非叶子节点依次“下沉” O(n) Sn = a(1-q^n) / (1-q) 原因：https://blog.csdn.net/2302_80220453/article/details/139068636
二叉堆的存储方式：顺序存储，使用数组
二叉堆是实现堆排序及优先队列的基础

优先队列：
1.最大优先队列：无论入队顺序，最大元素优先出队
2.最小优先队列：无论入队顺序，最小元素优先出队
优先队列实现：
使用二叉堆中的最大堆实现最大优先队列。每一次入队操作就是堆的插入操作，每一次出队操作就是删除堆顶节点
使用二叉堆中的最小堆实现最小优先队列


*/

//链表
/*
在 C++ 中实现链表功能通常涉及以下几个步骤。我们以单链表（Singly Linked List）为例来说明：

定义节点结构： 每个节点包含数据部分和指向下一个节点的指针。
class Node {
public:
    int data;
    Node* next;

    // 构造函数
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

定义链表类： 链表类包含指向链表头部的指针和一些基本操作函数。
class LinkedList {
private:
    Node* head;

public:
    // 构造函数
    LinkedList() {
        head = nullptr;
    }

    // 在链表头部插入节点
    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // 打印链表
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // 其他操作函数可以根据需要添加，例如删除节点、查找节点等
};

使用链表类： 创建链表对象并进行操作。
int main() {
    LinkedList list;
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);

    std::cout << "链表中的元素: ";
    list.print();

    return 0;
}
*/

//二叉树的递归
/*
在 C++ 中实现二叉树的前序遍历、中序遍历和后序遍历可以通过递归来完成。以下是每种遍历方法的实现：

1. 定义二叉树节点结构
首先，我们需要定义一个二叉树节点的结构：

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

2. 前序遍历（Preorder Traversal）
前序遍历的顺序是：根节点 -> 左子树 -> 右子树。

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    std::cout << root->val << " "; // 访问根节点
    preorderTraversal(root->left); // 递归遍历左子树
    preorderTraversal(root->right); // 递归遍历右子树
}

3. 中序遍历（Inorder Traversal）
中序遍历的顺序是：左子树 -> 根节点 -> 右子树。

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left); // 递归遍历左子树
    std::cout << root->val << " "; // 访问根节点
    inorderTraversal(root->right); // 递归遍历右子树
}

4. 后序遍历（Postorder Traversal）
后序遍历的顺序是：左子树 -> 右子树 -> 根节点。

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left); // 递归遍历左子树
    postorderTraversal(root->right); // 递归遍历右子树
    std::cout << root->val << " "; // 访问根节点
}

示例使用
下面是一个示例程序，展示如何使用这些遍历方法：

int main() {
    // 创建一个简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "前序遍历: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "中序遍历: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "后序遍历: ";
    postorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
*/

//二叉树的非递归
/*
使用栈来实现二叉树的功能，特别是遍历操作，是一种常见的技术。下面是如何使用栈来实现二叉树的前序、中序和后序遍历的示例。

二叉树节点定义
首先，我们定义一个二叉树节点的结构：

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

前序遍历（Preorder Traversal）
前序遍历的顺序是：根节点 -> 左子树 -> 右子树。使用栈来实现前序遍历：

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        cout << node->val << " ";

        // 先压入右子树，再压入左子树
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
}

中序遍历（Inorder Traversal）
中序遍历的顺序是：左子树 -> 根节点 -> 右子树。使用栈来实现中序遍历：

void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        // 先遍历左子树
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->val << " ";

        // 遍历右子树
        current = current->right;
    }
}

后序遍历（Postorder Traversal）
后序遍历的顺序是：左子树 -> 右子树 -> 根节点。使用两个栈来实现后序遍历：

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left) s1.push(node->left);//1 3 7 6 2 5 4
        if (node->right) s1.push(node->right);
    }

    while (!s2.empty()) {
        TreeNode* node = s2.top();
        s2.pop();
        cout << node->val << " ";
    }
}

示例
以下是一个完整的示例程序，展示了如何使用上述遍历方法：

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
*/

//二叉树的层次遍历
/*
void guangdu(tree_2* root)//层次遍历
{
    if (root == nullptr)return;
    queue<tree_2*>x;
    tree_2* node = root;
    x.push(node);
    while (!x.empty())
    {
        if (node->left)x.push(node->left);
        if (node->right)x.push(node->right);
        node = x.front();
        cout << node->val << " ";
        x.pop();
        if(!x.empty())node = x.front();
    }
}
*/

//二叉堆
/*
二叉堆的插入、删除、构建操作实现
class maxheap
{
private:
    vector<int>heap;
    void shiftup(int index)
    {
        while (index > 0 && heap[index] > heap[(index - 1) / 2])
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
            if (leftchild < heap.size() && heap[leftchild] > heap[large])
                large = leftchild;
            if (rightchild < heap.size() && heap[rightchild] > heap[large])
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
    maxheap(const vector<int>&x) :heap(x) {}
    void insert(int value)
    {
        heap.push_back(value);
        shiftup(heap.size()-1);
    }

    void delete_heap(int index)
    {
        if (heap.size() == 0)return;
        swap(heap[index], heap[heap.size() - 1]);
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
maxheap maxHeap(nums);
maxHeap.sort_heap();
maxHeap.print_heap();

return 0;
}
*/
