/*
��ɷ�ʽ��
1.���Խṹ�����顢����ջ�����С���ϣ��
2.�����������������
3.ͼ����Զ����
4.������������ϣ����λͼ��

����Ľṹ���洢��ʽΪ˳��洢���������ڴ��д洢����
�������������
1.��ȡԪ�� O(1) �����±��ѯ
2.����Ԫ�� O(1)
3.����Ԫ�� O(n) ͷ�����롢β�����롢�м����
4.ɾ��Ԫ�� O(n) ͷ��ɾ����β��ɾ�����м�ɾ��
��������ƺ����ƣ�
�����������ǿ�����±�Ϳ��Կ����ҵ���ӦԪ�أ����ַ�����ʹ�ô�����
���롢ɾ��Ԫ�غ�ʱ�࣬�������ʺ϶������ࡢд�����ٵĳ���

����Ľṹ��һ����Ϊ������ݵı���data����һ������ָ����һ�ڵ��ָ��next���洢��ʽΪ����洢
˫������Ľṹ�����˸�ָ��ǰ�ýڵ��prevָ��
����Ļ���������
1.���ҽ�㣺 O(n) ��ͷ�ڵ���һ���� 
2.���½ڵ㣺 O(1) �����ǲ��ҽڵ㣬ֱ�Ӹ���
3.����ڵ㣺 O(1) ͷ�����롢β�����롢�м����
4.ɾ��Ԫ�أ� O(1) ͷ��ɾ����β��ɾ�����м�ɾ��
��������ƣ�
�ʺ϶������١�д������ĳ���

�߼��ṹ������ʵ����������ṹ
1.���Խṹ��˳���ջ������
2.�����Խṹ������ͼ
����ṹ��
1.˳��洢�ṹ������
2.��ʽ�洢�ṹ������

ջ�Ķ��壺
FILO��Ԫ������������������Ԫ�ش��λ�ý�ջ��bottom���������Ԫ�ش��λ�ý�ջ��top
ջ�Ļ���������
1.��ջpush O(1) ��Ԫ�ط���ջ
2.��ջpop  O(1) ��Ԫ�ص���ջ

���еĶ��壺
FIFO��Ԫ�������ȳ������еĳ��ڶ˽�����ͷ��front�������е���ڶ˽�����β��rear��
���еĻ���������
1.���enqueue O(1) ��β����Ԫ��
2.����dequeue O(1) ��ͷ����Ԫ��

ɢ�б���ϣ������ʵ����c++�еĹ�������map ���ɼ�key��ֵvalue��ͬ��ɣ�ͨ��key������ƥ���value
��ϣ��Ĳ�����
1.д����put  ��key���뵽������
�������鳤�����ޣ����׷�����ϣ��ͻ����ͬ��key���뵽����ͬһλ�ã���ͨ��������ʽ�������
1.1����Ѱַ������ͻ��key����ƶ�һλ�������Ƿ��п�
1.2�����������ÿ��λ�ö��������ͷ�ڵ㣬����ͻ��key���뵽��Ӧ��������
2.������get ��������������ѯ
3.����resize ���ݹ������Ҫ 
3.1�ȴ���һ�������飬��ԭ������������ȣ�����ԭ���飬��key����ӳ�䵽��������

�������ס�ְ����ϵ ����Ϊ������tree����n��n��0�����ڵ�����޼�����n=0ʱ����Ϊ������
�ǿ������ص㣺
1. ���ҽ���һ���ض��ĳ�Ϊ���Ľڵ㡣
2. ��n>1ʱ������ڵ�ɷ�Ϊm��m>0���������ཻ�����޼���ÿһ�����ϱ�������һ����������Ϊ����������
���������壺ÿ���׶������2�����ӽڵ�
��������������������ʽ��һ������������������һ��������ȫ������
�򵥵�˵������������ÿһ����֧��������                 �߶�h��ڵ�����n�Ĺ�ϵ��h=log(n+1) ��Ҫ�õ��ȱ�������͹�ʽ
��ȫ������ֻ�豣֤���һ���ڵ�֮ǰ�Ľڵ㶼��ȫ����     �߶�h��ڵ�����n�Ĺ�ϵ��h=log(n)+1
��������﷽ʽ��
1. ��ʽ�洢�ṹ һ��data��һ����ָ�룬һ����ָ��
2. ����  ʹ������洢ʱ���ᰴ�ղ㼶˳��Ѷ������Ľڵ�ŵ������ж�Ӧ��λ���ϡ����ĳһ���ڵ�����ӻ��Һ��ӿ�ȱ�����������Ӧλ��Ҳ�ճ���
ϡ��Ķ��������ʺ��������ʾ���ռ��˷�
�������Ĺ��ܣ�
1.����  ����������������������нڵ��ֵ��С�ڸ��ڵ��ֵ �����������нڵ��ֵ�����ڸ��ڵ��ֵ O(logn)
�������ı�����ʽ��
1.ǰ����� ������� O(n) O(n) O(n)
2.������� ������� O(n) O(n) O(n)
3.������� ������� O(n) O(n) O(n)
4.������� ������� O(n) O(n) O(n)
������ȣ�
1.ǰ�����ȣ���������ǰ����������˳���Ǹ��ڵ㡢��������������
2.�����������������������������˳���������������ڵ㡢������
3.����������������ĺ�����������˳�����������������������ڵ�
����ͨ���ݹ顢ջʵ��
������ȣ�
4.��α��������ڸ��������ϸ��߳�1�������ڸ����������߳���2������3������һֱ����������ȫ������
����ͨ������ʵ��

����ѣ���һ����ȫ����������Ϊ��������(ͨ������ʵ��)
1.���ѣ��κ�һ�����ڵ��ֵ����>=�����Һ��ӽڵ��ֵ
2.��С�ѣ��κ�һ�����ڵ��ֵ����<=�����Һ��ӽڵ��ֵ
����ѵĸ��ڵ�����Ѷ�
����ѵĲ�������ȫ�������ĸ߶�Ϊlogn
1.����ڵ� ��������ݺ���������ѻ�����С�����ݽ����ϸ� O(logn)
2.ɾ���ڵ� ɾ�����ݺ����һ���ڵ�ŵ��Ѷ����ݽ����³� O(logn)
3.��������� Ҳ���ǰ�һ���������ȫ����������Ϊ����ѣ����ʾ��������з�Ҷ�ӽڵ����Ρ��³��� O(n) Sn = a(1-q^n) / (1-q) ԭ��https://blog.csdn.net/2302_80220453/article/details/139068636
����ѵĴ洢��ʽ��˳��洢��ʹ������
�������ʵ�ֶ��������ȶ��еĻ���

���ȶ��У�
1.������ȶ��У��������˳�����Ԫ�����ȳ���
2.��С���ȶ��У��������˳����СԪ�����ȳ���
���ȶ���ʵ�֣�
ʹ�ö�����е�����ʵ��������ȶ��С�ÿһ����Ӳ������ǶѵĲ��������ÿһ�γ��Ӳ�������ɾ���Ѷ��ڵ�
ʹ�ö�����е���С��ʵ����С���ȶ���


*/

//����
/*
�� C++ ��ʵ��������ͨ���漰���¼������衣�����Ե�����Singly Linked List��Ϊ����˵����

����ڵ�ṹ�� ÿ���ڵ�������ݲ��ֺ�ָ����һ���ڵ��ָ�롣
class Node {
public:
    int data;
    Node* next;

    // ���캯��
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

���������ࣺ ���������ָ������ͷ����ָ���һЩ��������������
class LinkedList {
private:
    Node* head;

public:
    // ���캯��
    LinkedList() {
        head = nullptr;
    }

    // ������ͷ������ڵ�
    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // ��ӡ����
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // ���������������Ը�����Ҫ��ӣ�����ɾ���ڵ㡢���ҽڵ��
};

ʹ�������ࣺ ����������󲢽��в�����
int main() {
    LinkedList list;
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);

    std::cout << "�����е�Ԫ��: ";
    list.print();

    return 0;
}
*/

//�������ĵݹ�
/*
�� C++ ��ʵ�ֶ�������ǰ���������������ͺ����������ͨ���ݹ�����ɡ�������ÿ�ֱ���������ʵ�֣�

1. ����������ڵ�ṹ
���ȣ�������Ҫ����һ���������ڵ�Ľṹ��

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

2. ǰ�������Preorder Traversal��
ǰ�������˳���ǣ����ڵ� -> ������ -> ��������

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    std::cout << root->val << " "; // ���ʸ��ڵ�
    preorderTraversal(root->left); // �ݹ����������
    preorderTraversal(root->right); // �ݹ����������
}

3. ���������Inorder Traversal��
���������˳���ǣ������� -> ���ڵ� -> ��������

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left); // �ݹ����������
    std::cout << root->val << " "; // ���ʸ��ڵ�
    inorderTraversal(root->right); // �ݹ����������
}

4. ���������Postorder Traversal��
���������˳���ǣ������� -> ������ -> ���ڵ㡣

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left); // �ݹ����������
    postorderTraversal(root->right); // �ݹ����������
    std::cout << root->val << " "; // ���ʸ��ڵ�
}

ʾ��ʹ��
������һ��ʾ������չʾ���ʹ����Щ����������

int main() {
    // ����һ���򵥵Ķ�����
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "ǰ�����: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "�������: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "�������: ";
    postorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
*/

//�������ķǵݹ�
/*
ʹ��ջ��ʵ�ֶ������Ĺ��ܣ��ر��Ǳ�����������һ�ֳ����ļ��������������ʹ��ջ��ʵ�ֶ�������ǰ������ͺ��������ʾ����

�������ڵ㶨��
���ȣ����Ƕ���һ���������ڵ�Ľṹ��

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

ǰ�������Preorder Traversal��
ǰ�������˳���ǣ����ڵ� -> ������ -> ��������ʹ��ջ��ʵ��ǰ�������

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        cout << node->val << " ";

        // ��ѹ������������ѹ��������
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
}

���������Inorder Traversal��
���������˳���ǣ������� -> ���ڵ� -> ��������ʹ��ջ��ʵ�����������

void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        // �ȱ���������
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->val << " ";

        // ����������
        current = current->right;
    }
}

���������Postorder Traversal��
���������˳���ǣ������� -> ������ -> ���ڵ㡣ʹ������ջ��ʵ�ֺ��������

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

ʾ��
������һ��������ʾ������չʾ�����ʹ����������������

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

    // �ͷ��ڴ�
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

//�������Ĳ�α���
/*
void guangdu(tree_2* root)//��α���
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

//�����
/*
����ѵĲ��롢ɾ������������ʵ��
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
                index = large;//˳�����Ҫ����Ҫ�����³����ڵ�
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
