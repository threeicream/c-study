#include <iostream>//��д����������
#include<fstream>//��д�����ļ�������
//#include <filesystem>//C++17���ļ�ϵͳ��
#include<sstream>//��д�ڴ�string���������
#include <typeinfo>
//˳������
#include<string>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<array>
//��������
#include<map>
#include<set>
#include<utility>
//������
#include<stack>
#include<queue>
//�㷨
#include<algorithm>
#include<numeric>
#include<functional>

#include<cstring>
#include <initializer_list>
#include<stdexcept>
#include<cassert>//Ԥ�����  assert(x);xΪ�٣������Ϣ����ֹ��������
#include"test.h"
#include"cp.h"
//#include"person.h"

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::initializer_list;
typedef string::size_type sz;
using namespace std;//һ���Ͱ�����usingȫ��Ч��
using namespace placeholders;

 /*string xyy(string& x,string&y)
{
	 x = x + y;
	return x;
}*/

 //class X
 //{
	// Y y;
 //};
 //class Y
 //{
	// X* x;
 //};

//vector<int>::iterator asd(const vector<int>::iterator beg, const vector<int>::iterator en, int i)
//{
//    for (auto x = beg; x != en; ++x)
//        if (*x == i)
//            return x;
//    return en;
//}

//void vector_int_sum(const vector<string>& x,double &j)
//{
//    j = 0.0;
//    for (auto a : x)
//    {
//        j += stod(a);
//    }
//}

//class A
//{
//    int a;
//public:
//    A(int x = 0) :a(x) {}
//   const void show1() const
//    {
//        cout << a << endl;
//    }
//    void show2()
//    {
//        cout << a << endl;
//    }
//};
//
//struct A1 {
//    virtual ~A1(){}
//};
//
//struct A2 {
//    virtual ~A2(){}
//};
//struct B1 :A1, A2 {};

//class Base {
//public:
//    int Bar(char x) {
//        return (int)(x);
//    }
//    virtual int Bar(int x) {
//        return (2 * x);
//    }
//};
//class Derived : public Base {
//public:
//    int Bar(char x) {
//        return (int)(-x);
//    }
//    int Bar(int x) {
//        return (x / 2);
//    }
//};

int* funcii()
{
    int a = 10;
    int* p = new int(a);
    return p;
}

class Base
{
public:
    void header()
    {
        cout << "��ҳ" << endl;
    }
    void footer()
    {
        cout << "��������" << endl;
    }
    void left()
    {
        cout << "Java��python��c++" << endl;
    }
};

class Java :public Base
{
public:
    void content()
    {
        cout << "Javaѧ����Ƶ" << endl;
    }
};

void test1()
{
    Java ja;
    cout << "Java������Ƶҳ�����£�" << endl;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
}

//class tree_2
//{
//public:
//    int val;
//    tree_2* right;
//    tree_2* left;
//public:
//    tree_2(int a):val(a),right(nullptr),left(nullptr){}
//};
//
//void qianxiang(tree_2* root)
//{
//    if (root == nullptr)return;
//    cout << root->val << " ";
//    qianxiang(root->left);
//    qianxiang(root->right);
//}
//
//void zhongxiang(tree_2* root)
//{
//    if (root == nullptr)return;
//    zhongxiang(root->left);
//    cout << root->val << " ";
//    zhongxiang(root->right);
//}
//
//void houxiang(tree_2* root)
//{
//    if (root == nullptr)return;
//    houxiang(root->left);
//    houxiang(root->right);
//    cout << root->val << " ";
//}
//
//void qianxiang2(tree_2* root)
//{
//    if (root == nullptr)return;
//    stack<tree_2*>x;
//    x.push(root);
//    while (!x.empty())
//    {
//        tree_2* node = x.top();
//        x.pop();
//        cout << node->val << " ";
//
//        if (node->right)x.push(node->right);
//        if (node->left)x.push(node->left);
//    }
//}
//
//void zhongxiang2(tree_2* root)
//{
//    if (root == nullptr)return;
//    stack<tree_2*>x;
//    tree_2* node = root;
//    while (node != nullptr||!x.empty())
//    {
//        while (node != nullptr)
//        {
//            x.push(node);
//            node = node->left;
//        }
//        node = x.top();
//        x.pop();
//        cout << node->val << " ";
//
//        node = node->right;
//
//    }
//}
//
//void houxiang2(tree_2* root)
//{
//    if (root == nullptr)return;
//    stack<tree_2*>x,y;
//    x.push(root);
//
//    while (!x.empty())
//    {
//        tree_2* node = x.top();
//        x.pop();
//        y.push(node);
//
//        if (node->left)x.push(node->left);
//        if (node->right)x.push(node->right);
//    }
//    
//    while (!y.empty())
//    {
//        tree_2* node = y.top();
//        y.pop();
//        cout << node->val << " ";
//        
//    }
//}
//
//void guangdu(tree_2* root)
//{
//    if (root == nullptr)return;
//    queue<tree_2*>x;
//    tree_2* node = root;
//    x.push(node);
//    while (!x.empty())
//    {
//        if (node->left)x.push(node->left);
//        if (node->right)x.push(node->right);
//        node = x.front();
//        cout << node->val << " ";
//        x.pop();
//        if(!x.empty())node = x.front();
//    }
//}

int main()
{
    //B1 d;
    //A1* pb1 = &d;
    //A2* pb2 = dynamic_cast<A2*>(pb1);
    ////A2* pb22 = static_cast<A2*>(pb1);
    
    //map<string, vector<string>> families;
    ////add_family(families, "��");
    //add_child(families, "��", "ǿ");
    //add_child(families, "��", "��");
    //add_child(families, "��", "��");
    ////add_family(families, "��");
    //for (const auto &f : families) {
    //    cout << f.first << "�ҵĺ��ӣ�";
    //    for (const auto &c : f.second)
    //        cout << c << " ";
    //    cout << endl;
    //}
    /*screen p(1, 2);
    screen x = p.display(cout);
    x.set('u').display(cout);*/
    /*hero p[3];
    allocate_hero(p,3,cin);*/
    
    /*tree_2* p = new tree_2(1);
    p->left = new tree_2(2);
    p->right = new tree_2(3);
    p->left->left = new tree_2(4);
    p->left->right = new tree_2(5);
    p->right->left = new tree_2(6);
    p->right->right = new tree_2(7);

    cout << "ǰ�����" << endl;
    qianxiang2(p);
    cout << endl;

    cout << "�������" << endl;
    zhongxiang2(p);
    cout << endl;

    cout << "�������" << endl;
    houxiang2(p);
    cout << endl;

    cout << "��ȱ���" << endl;
    guangdu(p);
    cout << endl;*/

    test1();

    return 0;
}

//int main()
//{
//    string folderPath = "H://examtest//";
//    string fileName = "a.txt";
//    string fileName1 = "b.txt";
//    string filePath = folderPath + fileName;
//    string filePath1 = folderPath + fileName1;
//    fstream in(filePath, ios::in);
//    if (!in)
//    {
//        cerr << "�޷����ļ���" << filePath << endl;
//        return -1;
//    }
//    vector<string>xy = nn(in, "df", "pg");
//    in.close();
//    fstream out(filePath1, ios::out);
//    if (!out)
//    {
//        cerr << "�޷����ļ���" << filePath1 << endl;
//        return -1;
//    }
//    for (auto a : xy)
//        out << a << ' ';
//    out.close();
//    return 0;
//}

/*if (!in)
    {
        cerr << "can't open file" << endl;
        return -1;
    }
    string line;
    vector<string>words;
    while (in>>line)
        words.push_back(line);
    in.close();
    auto it = words.begin();
    while (it != words.end())
    {
        cout << *it << endl;
        ++it;
    }*/